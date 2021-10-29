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
    struct Sample
    {
        uint bits;
        uint timeStamp;
    };

    LogicAnalyzer(size_t bufferSizeInts, PIO pio, uint captureStartPin, uint capturePinCount);
    ~LogicAnalyzer();

    void InitPins(); // We allow pin init early to allow other state machines to change the configuration of the pins.
    void InitSampling();
    void StartSampling();
    void StopSampling();
    
    bool SamplingComplete();

    const std::vector<Sample> &GetSamples() const { return samples; }

private:
    void InitStateMachines();
    void InitDma();

    bool initialized = false;

    std::vector<Sample> samples;

    uint startPin = 0xAA55;
    uint pinCount = 0xAA55;

    PIO pio = nullptr;
    uint sampleSm = 0xAA55;
    uint sampleProgramOffset = 0xAA55; 
    uint removeDupesSm = 0xAA55;
    uint removeDupesProgramOffset = 0xAA55; 
};
