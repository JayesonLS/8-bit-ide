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
#include <LbaTranslation.h>

LbaTranslation::LbaTranslation(uint32_t numHeads, uint32_t numSectorsPerTrack)
    : numHeads(numHeads)
    , numSectorsPerTrack(numSectorsPerTrack)
{
    if (numSectorsPerTrack > MAX_SECTORS_PER_TRACK || numHeads > MAX_HEADS)
    {
        panic("Heads (%d) and/or cylinders (%d) exceeds maxium.\n", numHeads, numSectorsPerTrack);
    }

    overflowNumHeads = MAX_HEADS - numHeads;
    overflowNumSectorsPerTrack = MAX_SECTORS_PER_TRACK - numSectorsPerTrack;

    // Each offset is the start of the previous + size of the previous.
    sectorOverFlowStartLbaOffset = 0 + MAX_CYLINDERS * numHeads * numSectorsPerTrack;
    headOverFlowStartLbaOffset = sectorOverFlowStartLbaOffset + MAX_CYLINDERS * numHeads * overflowNumSectorsPerTrack;
    sectorAndHeadOverFlowStartLbaOffset = headOverFlowStartLbaOffset + MAX_CYLINDERS * overflowNumHeads * numSectorsPerTrack;
}
