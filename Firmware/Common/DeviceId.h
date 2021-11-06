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

#pragma once

#include <pico/stdlib.h>
#include <sha1/sha1.h>

class DeviceId
{
    static const size_t NUM_SERIAL_ID_WORDS = 4;
    static const size_t NUM_GUID_BYTES = 20;
    
private:
    static const size_t GENERATE_REPEAT_COUNT = 2;
    static const size_t GENERATE_ADC_SAMPLE_COUNT = 4096;

    uint16_t serialId[NUM_SERIAL_ID_WORDS];
    uint8_t guid[NUM_GUID_BYTES];
    uint32_t checkHash; // Must be at the end of the data.

    uint32_t CalulateCheckHash() const;

public:
    bool IsValid() const;  
    bool IsUnique() const;

    const uint16_t *GetSerialId() const { return serialId; }

    static DeviceId GenerateNewUnique();
};