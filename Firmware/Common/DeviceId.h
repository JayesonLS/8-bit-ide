// Copyright (C) 2021 Titanium Studios Pty Ltd 

#pragma once

#include <pico/stdlib.h>
#include <sha1/sha1.h>

class DeviceId
{
public:
    static const size_t NUM_SERIAL_ID_WORDS = 4;
    static const size_t NUM_GUID_BYTES = 20;    

    bool IsValid() const; // Generates a hash, takes around 50us.
    bool IsUnique() const;

    const uint16_t *GetSerialId() const { return serialId; }

    static DeviceId GenerateNewUnique();

private:
    static const size_t GENERATE_REPEAT_COUNT = 2;
    static const size_t GENERATE_ADC_SAMPLE_COUNT = 4096;

    uint16_t serialId[NUM_SERIAL_ID_WORDS];
    uint8_t guid[NUM_GUID_BYTES];
    uint32_t checkHash; // Must be at the end of the data.

    uint32_t CalulateCheckHash() const;

    friend class UnitTest;
};
