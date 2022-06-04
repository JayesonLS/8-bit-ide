// Copyright (C) 2021 Titanium Studios Pty Ltd 

#pragma once

// This framework could be much better. Just something quick so we can
// write some tests now and worry about framework later.
class UnitTest
{
public:
    static void Assert(bool condition); 
    static void Assert(bool condition, const char *string, ...);

    static void TestDeviceId();
    static void TestLbaTranslation();

    // Modules should be initalized before running these tests.
    // Some tests will access hardware resources.
    static void RunAllTests();
};
