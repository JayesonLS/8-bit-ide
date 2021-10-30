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

#pragma once

#include <pico/stdlib.h>
#include <hardware/pio.h>
#include <vector>

class LogicAnalyzer
{
public:
    enum CpuClock
    {
        Standard, // 125 MHz.
        Overclock2x,
        Overclock3x // Must execute from ram or make compile time changes for /4 flash clock speed.
    };

    struct Sample
    {
        uint bits;
        uint timeStamp;
    };

    LogicAnalyzer(PIO pio, uint captureStartPin, uint capturePinCount, size_t maxSampleCount);
    ~LogicAnalyzer();

    void InitPins(); // We allow pin init early to allow other state machines to change the configuration of the pins.
    void InitSampling();
    void StartSampling(CpuClock cpuClock);
    void StopSampling();
    
    bool IsSamplingComplete();

    const std::vector<Sample> &GetSamples() const { return samples; }

private:
    void InitStateMachines();
    void InitDma();
    void SetCpuClock(CpuClock cpuClock);

    bool initialized = false;
    CpuClock currentClock = CpuClock::Standard;

    std::vector<Sample> samples;

    uint startPin = 0xAA55;
    uint pinCount = 0xAA55;

    PIO pio = nullptr;
    uint sampleSm = 0xAA55;
    uint removeDupesSm = 0xAA55;
    uint bitReduceSm = 0xAA55;
    uint postProcessSm = 0xAA55;

    uint sampleProgramOffset = 0xAA55; 
    uint removeDupesProgramOffset = 0xAA55; 
    uint bitReduceProgramOffset = 0xAA55;
    uint postProcessProgramOffset = 0xAA55;

    uint sampleToRemoveDupesDmaChan = 0xAA55;
    uint filteredToMemDmaChan = 0xAA55;
};
