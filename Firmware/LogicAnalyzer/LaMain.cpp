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

#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/pio.h>
#include <DeviceId.h>
#include "LogicAnalyzer.h"

static const LogicAnalyzer::CaptureType CAPTURE_TYPE = LogicAnalyzer::CaptureType::DataValues;
static const size_t CAPTURE_MAX_SAMPLES = 48 * 1024;
static const LogicAnalyzer::CpuClock OVERCLOCK_TYPE = LogicAnalyzer::CpuClock::Standard;

static const bool DISPLAY_RAW = false;

const uint LED_PIN = PICO_DEFAULT_LED_PIN;
const uint INV_DRIVE_ACTIVE_PIN = 1;
const uint BOOT_OVERRIDE_BUTTON_PIN = 2;

void InitLed()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(INV_DRIVE_ACTIVE_PIN);
    gpio_set_dir(INV_DRIVE_ACTIVE_PIN, GPIO_OUT);
    gpio_put(INV_DRIVE_ACTIVE_PIN, 1);
}

void SetLed(bool on)
{
    gpio_put(LED_PIN, on ? 1 : 0);
    gpio_put(INV_DRIVE_ACTIVE_PIN, on ? 0 : 1);
}

void DelayAndBlink(uint seconds)
{
    do
    {
        SetLed(true);
        sleep_ms(500);
        SetLed(false);
        sleep_ms(500);
    } while (--seconds != 0);
}

void WaitForButtonPress()
{
    gpio_init(BOOT_OVERRIDE_BUTTON_PIN);
    gpio_set_dir(BOOT_OVERRIDE_BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BOOT_OVERRIDE_BUTTON_PIN);

    static const uint32_t STATE_HOLD_TIME_MS = 250;
    uint32_t lastEventStart = time_us_32();
    bool lastLedState = true;

    while (gpio_get(BOOT_OVERRIDE_BUTTON_PIN) == true)
    {
        if (time_us_32() - lastEventStart > STATE_HOLD_TIME_MS * 1000)
        {
            lastLedState = !lastLedState;
            SetLed(lastLedState);
            lastEventStart = time_us_32();
        }
    }
}

void OutputSamplesHeader()
{
    if (CAPTURE_TYPE == LogicAnalyzer::CaptureType::DataValues)
    {
        printf("Type, Addr, Data, Info, Repeat\n");
    }
    else
    {
        printf("Timestamp, Addr, Data, ~CS, AEN, ~IOR, ~IOW, DRQ, ~DACK, IRQ, ~RESET, DATA_DIR\n");
    }
}

void OutputDataValueSample(const LogicAnalyzer::Sample &sample, uint repeat)
{
    if (!sample.IsValid())
    {
        return;
    }

    bool isIoRead = false;
    bool isIoWrite = false;
    bool isDmaRead = false;
    bool isDmaWrite = false;

    if (!sample.GetInvIor() && sample.GetInvIow() && !sample.GetInvCs() && sample.GetInvDack())
    {
        printf("IO R, ");
        isIoRead = true;
    }
    else if (sample.GetInvIor() && !sample.GetInvIow() && !sample.GetInvCs() && sample.GetInvDack())
    {
        printf("IO W, ");
        isIoWrite = true;
    }
    else if (!sample.GetInvIor() && sample.GetInvIow() && sample.GetInvCs() && !sample.GetInvDack())
    {
        printf("DMA R, ");
        isDmaRead = true;
    }
    else if (sample.GetInvIor() && sample.GetInvIow() && sample.GetInvCs() && !sample.GetInvDack())
    {
        printf("DMA W, ");
        isDmaWrite = true;
    }
    else
    {
        printf("???, ");
    }

    const char *info = "";
    uint addr = sample.GetAddr();

    if (isIoRead)
    {
        switch (addr)
        {
            case 0:
                info = "data";
                break;
            case 1:
                info = "status";
                break;
            case 2:
                info = "config";
                break;
            case 3:
                info = "no register";
                break;
            default:
                panic("Bad address switch.");
                break;
        }
    }
    else if (isIoWrite)
    {
        switch (addr)
        {
            case 0:
                info = "data";
                break;
            case 1:
                info = "reset";
                break;
            case 2:
                info = "select";
                break;
            case 3:
                info = "dma/irq";
                break;
            default:
                panic("Bad address switch.");
                break;
        }
    }
    else if (isDmaRead || isDmaWrite)
    {
        info = "data";
    }

    printf("%01X, 0x%02X, %s, ", sample.GetAddr(), sample.GetData(), info);

    if (repeat > 1)
    {
        printf("%d", repeat);
    }
    printf("\n");
}

void OutputSamples(const LogicAnalyzer &logicAnalyzer)
{
    const std::vector<LogicAnalyzer::Sample>& samples = logicAnalyzer.GetSamples();

    if (!samples.size())
    {
        printf("No samples.\n");
    }
    else
    {
        if (CAPTURE_TYPE == LogicAnalyzer::CaptureType::DataValues && !DISPLAY_RAW)
        {
            uint repeatCount = 1;

            for (size_t i = 1; i < samples.size(); i++)
            {
                if (samples[i].GetInvIor() == samples[i-1].GetInvIor() &&
                    samples[i].GetInvIow() == samples[i-1].GetInvIow() &&
                    samples[i].GetInvCs() == samples[i-1].GetInvCs() &&
                    samples[i].GetInvDack() == samples[i-1].GetInvDack() &&
                    samples[i].GetAddr() == samples[i-1].GetAddr() &&
                    samples[i].GetData() == samples[i-1].GetData())
                {
                    repeatCount++;
                }
                else
                {
                    OutputDataValueSample(samples[i-1], repeatCount);
                    repeatCount = 1;
                }
            }
            OutputDataValueSample(samples[samples.size()-1], repeatCount);
        }
        else
        {
            for (const LogicAnalyzer::Sample &sample : samples)
            {
                if (sample.IsValid())
                {
                    if (DISPLAY_RAW)
                    {
                        uint rawPinBits = sample.GetRawPinBits();
                        //for (int bitMask = 1 << (LogicAnalyzer::Sample::NUM_PIN_BITS-1); bitMask; bitMask >>= 1)
                        for (int bitMask = 1 ; bitMask < (1 << LogicAnalyzer::Sample::NUM_PIN_BITS); bitMask <<= 1)
                        {
                            printf("%c", rawPinBits & bitMask ? '1' : '0');
                        }
                        printf("\n");
                    }
                    else
                    {
                        printf("%d, %01X, %02X, %01X, %01X, %01X, %01X, %01X, %01X, %01X, %01X, %01X\n", 
                                sample.GetTimeStamp(), 
                                sample.GetAddr(),
                                sample.GetData(),
                                sample.GetInvCs(),
                                sample.GetAen(),
                                sample.GetInvIor(),
                                sample.GetInvIow(),
                                sample.GetDrq(),
                                sample.GetInvDack(),
                                sample.GetIrq(),
                                sample.GetInvReset(),
                                sample.GetDataDir()
                                );
                    }
                }
            }
        }

        printf("Done.\n");
    }
}


int main()
{
    stdio_init_all();

    InitLed();
    SetLed(true);

    WaitForButtonPress();

    LogicAnalyzer logicAnalyzer(pio1, CAPTURE_TYPE, CAPTURE_MAX_SAMPLES);
    logicAnalyzer.InitSampling();
    logicAnalyzer.StartSampling(OVERCLOCK_TYPE);
    SetLed(true);

    // Output header now so there is something on the console
    // to show activity.
    OutputSamplesHeader();

    // Loop until sampling complete (sample buffer full) or 
    // butt pressed again.
    bool needRelease = true;
    do
    {
        sleep_ms(100); // Lazy debounce.

        if (needRelease)
        {
            if (gpio_get(BOOT_OVERRIDE_BUTTON_PIN) == 1)
            {
                needRelease = false;
            }
        }
        else
        {
            if (gpio_get(BOOT_OVERRIDE_BUTTON_PIN) == 0)
            {
                logicAnalyzer.StopSampling();
                break;    
            }
        }
    } while (!logicAnalyzer.IsSamplingComplete());
    
    SetLed(false);

    logicAnalyzer.PostProcessSamples();

    OutputSamples(logicAnalyzer);

    DelayAndBlink(0xFFFFFFFF); // Effectively forever.

    return 0;
}
