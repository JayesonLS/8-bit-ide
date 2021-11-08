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

static const LogicAnalyzer::CaptureType CAPTURE_TYPE = LogicAnalyzer::CaptureType::Sample;
static const size_t CAPTURE_MAX_SAMPLES = 48 * 1024;
static const LogicAnalyzer::CpuClock OVERCLOCK_TYPE = LogicAnalyzer::CpuClock::Standard;

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
    printf("Timestamp, Addr, Data, ~CS, AEN, ~IOR, ~IOW, DRQ, ~DACK, IRQ, ~RESET\n");
}

void OutputSamples(const LogicAnalyzer &logicAnalyzer)
{
    const std::vector<LogicAnalyzer::Sample>& samples = logicAnalyzer.GetSamples();
    for (size_t i = 0; i < samples.size(); i++)
    {
        printf("%08X, %01X, %02X, %01X, %01X, %01X, %01X, %01X, %01X, %01X, %01\n", 
                samples[i].GetTimeStamp(), 
                samples[i].GetAddr(),
                samples[i].GetData(),
                samples[i].GetInvCs(),
                samples[i].GetAen(),
                samples[i].GetInvIor(),
                samples[i].GetInvIow(),
                samples[i].GetDrq(),
                samples[i].GetInvDack(),
                samples[i].GetIrq(),
                samples[i].GetInvReset()
                );
    }
}


int main()
{
    stdio_init_all();

    InitLed();
    SetLed(true);

    LogicAnalyzer logicAnalyzer(pio1, CAPTURE_TYPE, CAPTURE_MAX_SAMPLES);
    logicAnalyzer.InitPins();
    logicAnalyzer.InitSampling();

    WaitForButtonPress();

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

    OutputSamples(logicAnalyzer);

    DelayAndBlink(0xFFFFFFFF); // Effectively forever.

    return 0;
}
