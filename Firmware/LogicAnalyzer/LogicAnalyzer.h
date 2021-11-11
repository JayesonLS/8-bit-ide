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
    static const uint CAPTURE_PIN_COUNT = 25; // This value should match num_pin_bits in LogicAnalyzer.pio. 

    // Do not initialize these pins for PIO.
    // BOOT_OVERRIDE, ~DRIVE_ACTIVE, 3x Pico internal pins including LED.
    // TODO: Final hardware will move BOOT_OVERRIDE and ~DRIVE_ACTIVE  
    static const uint SKIP_PIN_MASK = (1 << 2) | (1 << 3) | (1 << 23) | (1 << 24) | (1 << 25);
    
    // Set these pins to pullup.
    // DATA_DIR, ~IRQ, ~DRQ.
    // TODO: Final hardware will flip the direction of DATA_DIR
    static const uint PULLUP_PIN_MASK = (1 << 22) | (1 << 27) | (1 << 28);

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
    public:
        // These should match the values in logic_analyzer.pio.
        static const int NUM_DATA_BITS = 8;
        static const int NUM_ADDR_BITS = 2;
        static const uint NUM_PIN_BITS = CAPTURE_PIN_COUNT;
        static const uint NUM_TIMESTAMP_BITS = 32-NUM_PIN_BITS;

        bool IsValid() const { return *((const uint32_t *)this) != 0xFFFFFFFF; }

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
        uint GetDataDir() const { return data_dir; }
        uint GetTimeStamp() const { return -timeStamp & ((1 << NUM_TIMESTAMP_BITS)-1); }

        uint GetRawPinBits() const { return *((uint32_t *)this) & ((1 << NUM_PIN_BITS)-1); }

        bool operator==(const Sample& other) const;

        void MarkInvalid() { *((uint32_t *)this) = 0xFFFFFFFF; }

    private:
        uint data : NUM_DATA_BITS;
        uint addr : NUM_ADDR_BITS;
        uint aen : 1;
        uint inv_dack : 1;
        uint ingore1 : 1; //SPI_RX
        uint inv_iow : 1;
        uint ignore2 : 1; // SPI_SCK
        uint ignore3 : 1; // SPI_TX
        uint inv_ior : 1;
        uint inv_reset : 1;
        uint data_dir : 1;
        uint ignore5 : 3; // Internal GPIOs.
        uint inv_cs : 1;
        uint irq : 1;
        uint drq : 1;
        uint timeStamp : NUM_TIMESTAMP_BITS;

        static_assert(NUM_PIN_BITS + NUM_TIMESTAMP_BITS == 32); 
    };

    static_assert(sizeof(Sample) == 4);

    LogicAnalyzer(PIO pio, CaptureType captureType, size_t maxSampleCount);
    ~LogicAnalyzer();

    void InitSampling();
    void StartSampling(CpuClock cpuClock);
    void StopSampling();
    
    bool IsSamplingComplete();

    void PostProcessSamples();

    const std::vector<Sample> &GetSamples() const { return samples; }

private:
    void InitPins();
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
