// Copyright (C) 2021 Titanium Studios Pty Ltd 

#include <stdio.h>
#include <pico/stdlib.h>
#include <IoConfig.h>

int main()
{
    // We run this as early as possible just in case some output is driving something
    // in some way that it should not.  
    IoConfig::PreInitialzieIo();

    stdio_init_all();


    return 0;
}
