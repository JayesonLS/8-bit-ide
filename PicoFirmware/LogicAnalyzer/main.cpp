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

const size_t CAPTURE_MAX_SAMPLES = 24 * 1024;
const uint CAPTURE_START_PIN = 0;
const uint CAPTURE_PIN_COUNT = 29;
const bool OVERCLOCK = false;

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

void DelayAndBlink(uint seconds)
{
#ifndef PICO_DEFAULT_LED_PIN
#warning blink requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    do
    {
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        sleep_ms(500);
    } while (--seconds != 0);
#endif
}

void OutputSamples(const LogicAnalyzer &logicAnalyzer)
{
    const std::vector<LogicAnalyzer::Sample>& samples = logicAnalyzer.GetSamples();
    for (size_t i = 0; i < samples.size(); i++)
    {
        printf("Sample: %08X %08X\n", -samples[i].timeStamp, samples[i].bits);
    }
}

int main()
{
    stdio_init_all();

    LogicAnalyzer logicAnalyzer(pio1, CAPTURE_START_PIN, CAPTURE_PIN_COUNT, CAPTURE_MAX_SAMPLES);
    logicAnalyzer.InitPins();

    PIO isaOutPio = pio0;
    uint isaOutSm = 0xAA55;
    InitIsaOut(isaOutPio, isaOutSm);

    logicAnalyzer.InitSampling();

    DelayAndBlink(2);

    logicAnalyzer.StartSampling(OVERCLOCK);

    for (int ledValue = 1289; ; ledValue++)
    {
        //printf("8bit_ide_drive heartbeat.\n");

        IsaOutOutputValue(isaOutPio, isaOutSm, ledValue);
        
//        sleep_ms(100);
        if (logicAnalyzer.SamplingComplete())
        {
            break;
        }
    }

    logicAnalyzer.StopSampling();

    OutputSamples(logicAnalyzer);

    DelayAndBlink(0xFFFFFFFF); // Effectively forever.

    return 0;
}
