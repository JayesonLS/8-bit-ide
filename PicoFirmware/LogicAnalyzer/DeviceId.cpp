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

#include <hardware/adc.h>
#include "DeviceId.h"

static const int HASH_BYTES = 20;

static_assert(sizeof(DeviceId) == 32);

// TODO: We will need to put this somewhere where other code can get to it.
// TODO: This is probably a bit heavy and uses a bunch of stack space. We do
// already have the code though.
static uint32_t HashBytes32(uint8_t *data, size_t size)
{
    static const int HASH_BYTES = 20;

    SHA1_CTX context;
    uint8_t results[HASH_BYTES];

    SHA1Init(&context);
    SHA1Update(&context, data, size);
    SHA1Final(results, &context);

    uint32_t result = 0;

    for (size_t i = 0; i < HASH_BYTES / sizeof(uint32_t); i++)
    {
        result ^= ((uint32_t *)results)[i];
    }

    return result;
}

/*private*/ uint32_t DeviceId::CalulateCheckHash()
{    
    static const HASH_SIZE = sizeof(DeviceId) - sizeof(checkHash);
    static_assert(HASH_SIZE > 0 && HASH_SIZE % sizeof(uint32_t) == 0);

    return HashBytes32(&this, HASH_SIZE);
}

bool DeviceId::IsValid()
{
    return CalulateCheckHash() == checkHashl
}

bool DeviceId::IsUnique()
{
    for (size_t i = 0; i < NUM_GUID_BYTES; i++)
    {
        if (guid[i] != 0)
        {
            return true;
        }
    }

    // The GUID is all zeros which means we failed to properly generate a unique one.
    return false;
}

/*static*/ DeviceId DeviceId::GenerateNewUnique()
{
    DeviceId result;
    memset (&result, 0, sizeof(result));

    // We are going to use the ADC to sample the VSYS voltage input.
    // This input is VSYS / 3 ~= 1.67V and will return values around 1024
    // (half of 2048).

    adc_init();
    adc_gpio_init(29);
    adc_select_input(3);

    // We hash the ADC values  multiple of two times and xor the results together.
    // If the ADC is returning constant results, the final GUID will be all 0's
    // which is how we determine if the GUID is unique. It is not super important
    // that it be unique - it could cause issues if there are multiple of these drives
    // present AND somehow it booted from a controller at a later address. With all known
    // BIOSes this should not be possible.
    static_assert(GENERATE_REPEAT_COUNT > 0 && GENERATE_REPEAT_COUNT % 2 == 0);
    static_assert(NUM_GUID_BYTES == HASH_BYTES); // Make sure same as SHA-1 hash length.

    // Generate the GUID.
    {
        SHA1_CTX context;
        uint8_t results[HASH_BYTES];

        for (size_t repeatCount = GENERATE_REPEAT_COUNT; repeatCount; repeatCount--)
        {
            SHA1Init(&context);

            for (size_t sampleCount = GENERATE_ADC_SAMPLE_COUNT; sampleCount; sampleCount--)
            {
                uint16_t val = adc_read();
                SHA1Update(&context, (uint8_t *)&val, sizeof(uint16_t));
            }

            SHA1Final(results, &context);

            for (size_t mergeIndex = 0; mergeIndex < NUM_GUID_BYTES; mergeIndex++)
            {
                guid[mergeIndex] ^= results[mergeIndex];
            }
        }
    }

    // Generate the serial ID. This has the property that the first sequence of 16 bits does
    // not repeat anywhere in the other bits, including with wrap-around. This is because the
    // drive detect code will pull bits continuously, looking for the first 16 bits.  
    {
        SHA1_CTX context;
        uint8_t results[HASH_BYTES];

        // Start with the current hash bytes. We will keep hashing these numbers until
        // we generate a valid serialId.
        memcpy(results, guid, HASH_BYTES);

        for (;;)
        {
            // Rehash the GUID.
            SHA1Init(&context);
            SHA1Update(&context, (uint8_t *)&val, sizeof(uint16_t));
            SHA1Final(results, &context);

            // Combine into serialId.
            static_assert(HASH_BYTES % sizeof(uint16_t) == 0);
            memset(serialId, 0, sizeof(serialId);
            for (size_t i = 0; i < HASH_BYTES / sizeof(uint16_t); i++)
            {
                serialId[i % NUM_SERIAL_ID_WORDS] ^= ((uint16_t *)results)[i];
            }

            // Check to see if the first 16 bits are repeated.
            static_assert(sizeof(serialId) == 64);
            uint64_t serialId64 = *((uint64_t *)serialId);
            for (...)
            { 
                if (...)
                {
                    no good, 
                    continue;
                }
            }

            // Serial ID is good so break.
            break;
        }
    }

    checkHash = CalulateCheckHash();
}
