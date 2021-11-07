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

#include <pico/stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "UnitTest.h"

/*static*/ void UnitTest::Assert(bool condition)
{
    if (!condition)
    {
        panic("Test assert failed");
    }
}

/*static*/ void UnitTest::Assert(bool condition, const char *string, ...)
{
    if (!condition)
    {
        va_list args;
        va_start(args, string);
        vprintf(string, args);
        va_end(args);

        panic("Test assert failed");
    }
}

static void RunTestWithPrint(const char *name, void (*testMethod)())
{
    printf("Testing %s\n", name);
    testMethod();
}

/*static*/ void UnitTest::RunAllTests()
{
    // Allow time to connect USB serial monitor.
    for (int i = 0; i < 6; i++)
    {
        printf("Waiting...\n");
        sleep_ms(500);
    }

    printf("Starting Unit Tests\n");

    RunTestWithPrint("DeviceId", TestDeviceId);
}

