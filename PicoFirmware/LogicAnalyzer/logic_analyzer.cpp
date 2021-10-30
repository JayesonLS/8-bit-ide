// Copyright (C) 2021 Titanium Studios Pty Ltd 
// 
// This program is free software : you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.If not, see < https://www.gnu.org/licenses/>.

#include <random>
#include <hardware/vreg.h>
#include <hardware/dma.h>
#include <hardware/structs/bus_ctrl.h>
#include "logic_analyzer.h"
#include "logic_analyzer.pio.h"

LogicAnalyzer::LogicAnalyzer(PIO pio, uint captureStartPin, uint capturePinCount, size_t maxSampleCount)
    : startPin(captureStartPin)
    , pinCount(capturePinCount)
    , pio(pio)
{
    samples.resize(maxSampleCount);
}   

LogicAnalyzer::~LogicAnalyzer()
{
    if (initialized)
    {
        StopSampling();
    }

    // Should really free up PIO and DMA resources but this class unlikley to be used in a way that needs it.
}

// We do this early to allow other state machines to change the
// configuration of the pins.
void LogicAnalyzer::InitPins()
{
    for (uint i = 0; i < pinCount; i++)
    {
        pio_gpio_init(pio, startPin + i);
    }
}

void LogicAnalyzer::InitSampling()
{
    InitStateMachines();
    InitDma();

    initialized = true;
}

void LogicAnalyzer::StartSampling(CpuClock cpuClock)
{
    SetCpuClock(cpuClock);

    // Clear all fifos.
    pio_sm_clear_fifos(pio, sampleSm);
    pio_sm_clear_fifos(pio, removeDupesSm);
    pio_sm_clear_fifos(pio, bitReduceSm);
    pio_sm_clear_fifos(pio, postProcessSm);

    // Start DMAs.
    dma_channel_start(filteredToMemDmaChan);

    // Enable state machines.
    pio_sm_set_enabled(pio, removeDupesSm, true);
    pio_sm_set_enabled(pio, bitReduceSm, true);
    pio_sm_set_enabled(pio, postProcessSm, true);

    // Last step: enable the sampling state machine.
    // Everything else is waiting on samples from this.
    pio_sm_set_enabled(pio, sampleSm, true);
}

void LogicAnalyzer::StopSampling()
{

    // Stop DMA.
    dma_channel_abort(filteredToMemDmaChan);

    pio_sm_set_enabled(pio, sampleSm, false);
    pio_sm_set_enabled(pio, removeDupesSm, false);
    pio_sm_set_enabled(pio, bitReduceSm, false);
    pio_sm_set_enabled(pio, postProcessSm, false);

    SetCpuClock(CpuClock::Standard);
}

bool LogicAnalyzer::IsSamplingComplete()
{ 
    {
        // Manually pump fifos.
        if (!pio_sm_is_rx_fifo_empty(pio, sampleSm) && !pio_sm_is_tx_fifo_full(pio, removeDupesSm))
        {
            uint val = pio_sm_get(pio, sampleSm);
            pio_sm_put(pio, removeDupesSm, val);

            printf("sample -> removeDupes: %08X\n", val);
        }

        if (!pio_sm_is_rx_fifo_empty(pio, removeDupesSm) && !pio_sm_is_tx_fifo_full(pio, bitReduceSm))
        {
            uint val = pio_sm_get(pio, removeDupesSm);
            pio_sm_put(pio, bitReduceSm, val);

            printf("removeDupesSm -> bitReduceSm: %08X\n", val);
        }

        if (!pio_sm_is_rx_fifo_empty(pio, bitReduceSm) && !pio_sm_is_tx_fifo_full(pio, postProcessSm))
        {
            uint val = pio_sm_get(pio, bitReduceSm);
            pio_sm_put(pio, postProcessSm, val);

            printf("bitReduceSm -> postProcessSm: %08X\n", val);
        }
    }

    // We are complete if the memory buffer is full / 
    // the dma to the memory buffer has completed.
    return !dma_channel_is_busy(filteredToMemDmaChan);
}

/*private */ void LogicAnalyzer::InitStateMachines()
{
    // Sample state machine.
    {
        sampleProgramOffset = pio_add_program(pio, &la_sample_program);
        sampleSm = pio_claim_unused_sm(pio, true);

        pio_sm_set_consecutive_pindirs(pio, sampleSm, startPin, pinCount, false);

        pio_sm_config c = la_sample_program_get_default_config(sampleProgramOffset);
        sm_config_set_in_pins(&c, startPin);
        sm_config_set_in_shift(&c, true, true, 32);
        sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_RX);
        pio_sm_init(pio, sampleSm, sampleProgramOffset, &c);
    }

    // Remove-dupes state machine.
    {
        removeDupesProgramOffset = pio_add_program(pio, &la_remove_dupes_program);
        removeDupesSm = pio_claim_unused_sm(pio, true);

        pio_sm_config c = la_remove_dupes_program_get_default_config(removeDupesProgramOffset);
        sm_config_set_in_shift(&c, true, true, 32);
        sm_config_set_out_shift(&c, true, true, 32);
        pio_sm_init(pio, removeDupesSm, removeDupesProgramOffset, &c);
    }

    // Bit reduction state machine.
    {
        bitReduceProgramOffset = pio_add_program(pio, &la_bit_reduce_program);
        bitReduceSm = pio_claim_unused_sm(pio, true);

        pio_sm_config c = la_bit_reduce_program_get_default_config(bitReduceProgramOffset);
        sm_config_set_in_shift(&c, true, false, 32);
        sm_config_set_out_shift(&c, true, false, 32);
        pio_sm_init(pio, bitReduceSm, bitReduceProgramOffset, &c);
    }

    // Post process state machine.
    {
        postProcessProgramOffset = pio_add_program(pio, &la_post_process_program);
        postProcessSm = pio_claim_unused_sm(pio, true);

        pio_sm_config c = la_post_process_program_get_default_config(postProcessProgramOffset);
        sm_config_set_in_shift(&c, true, false, 32);
        sm_config_set_out_shift(&c, true, false, 32);
        pio_sm_init(pio, postProcessSm, postProcessProgramOffset, &c);
    }  
}

// This was not implemented in the Pico SDK. Perhaps it does not work properly?
static inline void channel_config_set_priority(dma_channel_config *c, bool high)
{
    c->ctrl = high ? (c->ctrl | DMA_CH0_CTRL_TRIG_HIGH_PRIORITY_BITS) : (c->ctrl & ~DMA_CH0_CTRL_TRIG_HIGH_PRIORITY_BITS);
}

/*private */ void LogicAnalyzer::InitDma()
{
    // Give bus priority to DMA.
    bus_ctrl_hw->priority = BUSCTRL_BUS_PRIORITY_DMA_W_BITS | BUSCTRL_BUS_PRIORITY_DMA_R_BITS;

    // DMA from final state machine to memory.
    {
        filteredToMemDmaChan = dma_claim_unused_channel(true);

        dma_channel_config c = dma_channel_get_default_config(filteredToMemDmaChan);
        channel_config_set_read_increment(&c, false);
        channel_config_set_write_increment(&c, true);
        channel_config_set_dreq(&c, pio_get_dreq(pio, sampleSm, false));
//        channel_config_set_priority(&c, true);

        uint sampleSizeInLongs = samples.size() * (sizeof(Sample) / sizeof(uint32_t));
        dma_channel_configure(
            filteredToMemDmaChan, 
            &c,
            &samples[0],
            &pio->rxf[postProcessSm],
            sampleSizeInLongs,
            false                
        );
    }
}

/*private */ void LogicAnalyzer::SetCpuClock(CpuClock cpuClock)
{
    const uint32_t standardClockKHz = 125000;

    switch (cpuClock)
    {
        case CpuClock::Standard:
            set_sys_clock_khz(standardClockKHz, true);
            vreg_set_voltage(VREG_VOLTAGE_DEFAULT);
            break;

        case CpuClock::Overclock2x:
            if (currentClock == CpuClock::Overclock3x)
            {
                set_sys_clock_khz(standardClockKHz * 2, true);
                vreg_set_voltage(VREG_VOLTAGE_1_15);
            }
            else
            {
                vreg_set_voltage(VREG_VOLTAGE_1_15);
                set_sys_clock_khz(standardClockKHz * 2, true);
            }
            break;
        case CpuClock::Overclock3x:
            vreg_set_voltage(VREG_VOLTAGE_1_30);
            set_sys_clock_khz(standardClockKHz * 3, true);
            break;

        default:
            panic("Invalid CpuClock enum");
            break;
    }

    currentClock = cpuClock;
}

