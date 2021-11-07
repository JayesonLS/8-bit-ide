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
#include <string.h>
#include <vector>
#include <DeviceId.h>
#include "UnitTest.h"

/*static*/ void UnitTest::TestDeviceId()
{
    static const size_t GENERATE_COUNT = 128;
    
    std::vector<DeviceId> previousIds;

    previousIds.reserve(GENERATE_COUNT);

    for (size_t generateCount = 0; generateCount < GENERATE_COUNT; generateCount++)
    {
        DeviceId id = DeviceId::GenerateNewUnique();
        
        //printf("    Generated ID: %02X%02X%02X%02X\n", id.GetSerialId()[0], id.GetSerialId()[1], id.GetSerialId()[2], id.GetSerialId()[3]);
        Assert(id.IsValid(), "ID is valid.");
        Assert(id.IsUnique(), "ID is (likely) unique.");
        Assert(id.checkHash != 0, "Hash is (likely) non-zero");

        //  Check that the serial ID does not match a previous ID's serial ID.
        for (DeviceId &previousId : previousIds)
        {
            Assert(memcmp(previousId.GetSerialId(), id.GetSerialId(), sizeof(uint16_t) * DeviceId::NUM_SERIAL_ID_WORDS)!=0, "SerialId does not match previous.");
            Assert(previousId.checkHash != id.checkHash, "CheckHash unlikely to match previous.");
        }

        previousIds.push_back(id);
    }
}