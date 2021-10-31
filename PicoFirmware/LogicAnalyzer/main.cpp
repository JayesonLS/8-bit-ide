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
#include "logic_analyzer.h"
#include "isaout.pio.h"

static const size_t CAPTURE_MAX_SAMPLES = 48 * 1024;
static const LogicAnalyzer::CpuClock OVERCLOCK_TYPE = LogicAnalyzer::CpuClock::Standard;

#ifndef PICO_DEFAULT_LED_PIN
#error Board with a regular LED required.
#else
const uint LED_PIN = PICO_DEFAULT_LED_PIN;
#endif

void InitIsaOut(PIO pio, uint &isaOutSm)
{
    uint programOffset = pio_add_program(pio, &isaout_program);
    isaOutSm = pio_claim_unused_sm(pio, true);
    isaout_program_init(pio, isaOutSm, programOffset, 0, 8, 2, 10);
}

void IsaOutOutputValue(PIO pio, uint isaOutSm, uint value)
{
    pio_sm_put_blocking(pio, isaOutSm, value); 
}

void InitLed()
{
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void SetLed(bool on)
{
    gpio_put(LED_PIN, on ? 1 : 0);
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

    LogicAnalyzer logicAnalyzer(pio1, CAPTURE_MAX_SAMPLES);
    logicAnalyzer.InitPins();
    logicAnalyzer.InitSampling();

    // TODO: Wait for button down here.
    // Blink led whie waiting.

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
            if (false /* TODO: Button released */)
            {
                needRelease = false;
            }
        }
        else
        {
            if (false /* TODO: Button pressed */)
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
