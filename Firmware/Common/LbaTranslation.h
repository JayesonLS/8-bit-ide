// Copyright (C) 2021 Titanium Studios Pty Ltd 

#pragma once

class LbaTranslation
{
public:
    static const uint32_t MAX_SECTORS_PER_TRACK = 32;
    static const uint32_t MAX_HEADS = 6;
    static const uint32_t MAX_CYLINDERS = 1024;
    static const uint32_t MAX_LBA_SECTORS = MAX_SECTORS_PER_TRACK * MAX_HEADS  * MAX_CYLINDERS;
    static const uint32_t INVALID_LBA_SECTOR = (uint32_t)-1;

    LbaTranslation(uint32_t numHeads, uint32_t numSectorsPerTrack);

    uint32_t LbaFromChsZeroBased(uint32_t cylinder, uint32_t head, uint32_t sector) const
    {
        if (sector >= MAX_SECTORS_PER_TRACK || head >= MAX_HEADS || cylinder >= MAX_CYLINDERS)
        {
            return INVALID_LBA_SECTOR;
        }

        if (sector >= numSectorsPerTrack)
        {
            sector -= numSectorsPerTrack;
            if (head >= numHeads)
            {
                // Sector and head overflow.
                head -= numHeads;
                return sectorAndHeadOverFlowStartLbaOffset + cylinder * overflowNumHeads * overflowNumSectorsPerTrack + head * overflowNumSectorsPerTrack + sector;
            }
            else
            {
                // Sector overflow only.
                return sectorOverFlowStartLbaOffset + cylinder * numHeads * overflowNumSectorsPerTrack + head * overflowNumSectorsPerTrack + sector;
            }
        }
        else if (head >= numHeads)
        {
            // Head overflow only.
            head -= numHeads;
            return headOverFlowStartLbaOffset + cylinder * overflowNumHeads * numSectorsPerTrack + head * numSectorsPerTrack + sector;
        }
        else
        {
            // No overflow.
            return cylinder * numHeads * numSectorsPerTrack + head * numSectorsPerTrack + sector;
        }
    }

    uint32_t GetNumHeads() const { return numHeads; }
    uint32_t GetNumSectorsPerTrack() const { return numSectorsPerTrack; }

private:
    uint32_t numHeads;
    uint32_t numSectorsPerTrack;

    uint32_t overflowNumHeads;
    uint32_t overflowNumSectorsPerTrack;

    uint32_t sectorOverFlowStartLbaOffset;
    uint32_t headOverFlowStartLbaOffset;
    uint32_t sectorAndHeadOverFlowStartLbaOffset;
};
