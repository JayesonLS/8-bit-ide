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
#include <string.h>
#include <hardware/vreg.h>
#include <hardware/dma.h>
#include <hardware/structs/bus_ctrl.h>
#include "LogicAnalyzer.h"
#include "LogicAnalyzer.pio.h"

bool LogicAnalyzer::Sample::operator==(const Sample& other) const
{
    return data == other.data &&
           addr == other.addr &&
           aen == other.aen &&
           inv_dack == other.inv_dack &&
           inv_iow == other.inv_iow &&
           inv_ior == other.inv_ior &&
           inv_reset == other.inv_reset &&
           data_dir == other.data_dir &&
           inv_cs == other.inv_cs &&
           irq == other.irq &&
           drq == other.drq;
}

LogicAnalyzer::LogicAnalyzer(PIO pio, CaptureType captureType, size_t maxSampleCount)
    : captureType(captureType)
    , pio(pio)
{
    samples.resize(maxSampleCount);

    for (Sample &sample : samples)
    {
        sample.MarkInvalid();
    }
}   

LogicAnalyzer::~LogicAnalyzer()
{
    if (initialized)
    {
        StopSampling();
    }

    // Should really free up PIO and DMA resources but this class unlikley to be used in a way that needs it.
}

void LogicAnalyzer::InitPins()
{
    for (uint i = CAPTURE_START_PIN; i < CAPTURE_START_PIN+CAPTURE_PIN_COUNT; i++)
    {
        if ((SKIP_PIN_MASK & (1 << i)) == 0)
        {
            pio_gpio_init(pio, i);

            if ((PULLUP_PIN_MASK & (1 << i)) != 0)
            {
                gpio_pull_up(i);            
            }
        }
    }
}

void LogicAnalyzer::InitSampling()
{
    InitPins();
    InitStateMachines();
    InitDma();

    initialized = true;
}

void LogicAnalyzer::StartSampling(CpuClock cpuClock)
{
    SetCpuClock(cpuClock);

    pio_sm_clear_fifos(pio, sm);
    dma_channel_start(dmaChan);
    pio_sm_set_enabled(pio, sm, true);
}

void LogicAnalyzer::StopSampling()
{
    dma_channel_abort(dmaChan);
    pio_sm_set_enabled(pio, sm, false);

    SetCpuClock(CpuClock::Standard);
}

void LogicAnalyzer::PostProcessSamples()
{
    for (size_t i = 1, lastUniqueIndex = 0; i < samples.size(); i++)
    {
        if (samples[i] == samples[lastUniqueIndex])
        {
            samples[i].MarkInvalid();
        }
        else
        {
            lastUniqueIndex = i;
        }
    }
}

bool LogicAnalyzer::IsSamplingComplete()
{ 
    // We are complete if the memory buffer is full / 
    // the dma to the memory buffer has completed.
    return !dma_channel_is_busy(dmaChan);
}

inline static uintptr_t __attribute__((always_inline)) dma_channel_get_read_addr(uint channel)
{
//    check_dma_channel_param(channel);
    dma_channel_hw_t *hw = dma_channel_hw_addr(channel);
    return hw->write_addr;
}

/*private */ void LogicAnalyzer::InitStateMachines()
{
    sm = pio_claim_unused_sm(pio, true);
    pio_sm_set_consecutive_pindirs(pio, sm, CAPTURE_START_PIN, CAPTURE_PIN_COUNT, false);

    switch (captureType)
    {
        case CaptureType::Sample:
        {
            programOffset = pio_add_program(pio, &la_sample_program);
            pio_sm_config c = la_sample_program_get_default_config(programOffset);
            sm_config_set_in_pins(&c, CAPTURE_START_PIN);
            sm_config_set_in_shift(&c, true, true, 32);
            sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_RX);
            pio_sm_init(pio, sm, programOffset, &c);
            break;
        }
        case CaptureType::DataValues:
        {
            programOffset = pio_add_program(pio, &la_capture_data_values_program);
            pio_sm_config c = la_capture_data_values_program_get_default_config(programOffset);
            sm_config_set_in_pins(&c, CAPTURE_START_PIN);
            sm_config_set_in_shift(&c, true, false, 32);
            sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_RX);
            pio_sm_init(pio, sm, programOffset, &c);
            break;
        }
        default:
            panic("Invalid CpuClock enum");
            break;
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

    // DMA from state machine to memory.
    dmaChan = dma_claim_unused_channel(true);

    dma_channel_config c = dma_channel_get_default_config(dmaChan);
    channel_config_set_read_increment(&c, false);
    channel_config_set_write_increment(&c, true);
    channel_config_set_dreq(&c, pio_get_dreq(pio, sm, false));

    uint sampleSizeInLongs = samples.size() * (sizeof(Sample) / sizeof(uint32_t));
    dma_channel_configure(
        dmaChan, 
        &c,
        &samples[0],
        &pio->rxf[sm],
        sampleSizeInLongs,
        false                
    );
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

