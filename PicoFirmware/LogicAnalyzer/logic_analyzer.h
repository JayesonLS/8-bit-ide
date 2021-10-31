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
    static const uint CAPTURE_START_PIN = 4;
    static const uint CAPTURE_PIN_COUNT = 25;

    enum class CaptureType
    {
        Sample,
        DataValues
    };

    enum class CpuClock
    {
        Standard, // 125 MHz.
        Overclock2x,
        Overclock3x // Must execute from ram or make compile time changes for /4 flash clock speed.
    };

    class Sample
    {    
    private:
        // These should match the values in logic_analyzer.pio.
        static const int num_data_bits = 8;
        static const int num_addr_bits = 2;
        static const uint num_pin_bits = CAPTURE_PIN_COUNT;
        static const uint num_timestamp_bits = 32-num_pin_bits;

        uint data : num_data_bits;
        uint addr : num_addr_bits;
        uint aen : 1;
        uint inv_dack : 1;
        uint ingore1 : 1; //SPI_RX
        uint inv_iow : 1;
        uint ignore2 : 1; // SPI_SCK
        uint ignore3 : 1; // SPI_TX
        uint inv_ior : 1;
        uint inv_reset : 1;
        uint ignore4 : 1; // DATA_DIR
        uint ignore5 : 3; // Internal GPIOs.
        uint inv_cs : 1;
        uint irq : 1;
        uint drq : 1;
        uint timeStamp : num_timestamp_bits;

        static_assert(num_pin_bits + num_timestamp_bits == 32);

    public:
        uint GetData() const { return data; }
        uint GetAddr() const { return addr; }
        uint GetAen() const { return aen; }
        uint GetInvDack() const { return inv_dack; }
        uint GetInvIow() const { return inv_iow; }
        uint GetInvIor() const { return inv_ior; }
        uint GetInvReset() const { return inv_reset; }
        uint GetInvCs() const { return inv_cs; }
        uint GetIrq() const { return irq; }
        uint GetDrq() const { return drq; }
        uint GetTimeStamp() const { return -timeStamp & ((1 << num_timestamp_bits)-1); }
   };

    static_assert(sizeof(Sample) == 4);

    LogicAnalyzer(PIO pio, CaptureType captureType, size_t maxSampleCount);
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

    CaptureType captureType;

    PIO pio = nullptr;
    uint sm = 0xAA55;
    uint programOffset = 0xAA55; 

    uint dmaChan = 0xAA55;
};
