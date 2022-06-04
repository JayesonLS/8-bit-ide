// Copyright (C) 2021 Titanium Studios Pty Ltd 

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
