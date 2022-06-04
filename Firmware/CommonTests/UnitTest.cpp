// Copyright (C) 2021 Titanium Studios Pty Ltd 

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
        printf("Failed: ");

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

    printf("--------------------------------------------------------\n"
           "Starting Unit Tests\n"
           "\n");

    RunTestWithPrint("DeviceId", TestDeviceId);
    RunTestWithPrint("LbaTranslation", TestLbaTranslation);

    printf("\n"
           "Unit tests completed successfully.\n"
           "--------------------------------------------------------\n");
}

