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
        printf("Type, Addr, Data, , ");
    }

    printf("Timestamp, Addr, Data, ~CS, AEN, ~IOR, ~IOW, DRQ, ~DACK, IRQ, ~RESET, DATA_DIR\n");
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
                    if (CAPTURE_TYPE == LogicAnalyzer::CaptureType::DataValues)
                    {
                        if (!sample.GetInvIor() && sample.GetInvIow() && !sample.GetInvCs() && sample.GetInvDack())
                        {
                            printf("IO R, ");
                        }
                        else if (sample.GetInvIor() && !sample.GetInvIow() && !sample.GetInvCs() && sample.GetInvDack())
                        {
                            printf("IO W, ");
                        }
                        else if (!sample.GetInvIor() && sample.GetInvIow() && sample.GetInvCs() && !sample.GetInvDack())
                        {
                            printf("DMA R, ");
                        }
                        else if (sample.GetInvIor() && sample.GetInvIow() && sample.GetInvCs() && !sample.GetInvDack())
                        {
                            printf("DMA W, ");
                        }
                        else
                        {
                            printf("???, ");
                        }

                        printf("%01X, 0x%02X, , ", 
                                sample.GetAddr(),
                                sample.GetData()
                        );
                    }

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
