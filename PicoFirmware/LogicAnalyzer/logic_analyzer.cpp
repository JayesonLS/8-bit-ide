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

#include "logic_analyzer.h"
#include "logic_analyzer.pio.h"


LogicAnalyzer::LogicAnalyzer(size_t maxSampleCount, PIO pio, uint captureStartPin, uint capturePinCount)
    : maxSampleCount(maxSampleCount)
    , startPin(captureStartPin)
    , pinCount(capturePinCount)
    , pio(pio)
{
}   

LogicAnalyzer::~LogicAnalyzer()
{
    if (initialized)
    {
        StopSampling();
    }

    // Should really free up PIO and DMA resources but this destructor will probably never be used.

    delete [] buffer;
    buffer = nullptr;
}

// We do this early to allow other state machines to change the
// configuration of the pins.
void LogicAnalyzer::IntializePins()
{
    for (uint i = 0; i < pinCount; i++)
    {
        pio_gpio_init(pio, startPin + i);
    }
}

void LogicAnalyzer::InitializeSampling()
{
    buffer = new Sample[maxSampleCount];

    IntializeStateMachines();
    InitializeDma();

    initialized = true;
}

void LogicAnalyzer::StartSampling()
{
    // TODO: Clear all fifos.

    // TODO: Start DMAs.

    // pio_sm_set_enabled(pio, removeDupesSm, true);

    // Last step: enable the sampling state machine.
    pio_sm_set_enabled(pio, sampleSm, true);
}

void LogicAnalyzer::StopSampling()
{
    pio_sm_set_enabled(pio, sampleSm, false);
    pio_sm_set_enabled(pio, removeDupesSm, false);

    // TODO: Stop DMA.
}

/*private */ void LogicAnalyzer::IntializeStateMachines()
{
    // Sample state machine.
    {
        sampleProgramOffset = pio_add_program(pio, &la_sample_program);
        sampleSm = pio_claim_unused_sm(pio, true);

        pio_sm_set_consecutive_pindirs(pio, sampleSm, startPin, pinCount, false);

        pio_sm_config c = la_sample_program_get_default_config(sampleProgramOffset);
        sm_config_set_in_pins(&c, startPin);
        pio_sm_init(pio, sampleSm, sampleProgramOffset, &c);
    }

    // Remove-dupes state machine.
    {

    }
}

/*private */ void LogicAnalyzer::InitializeDma()
{

}