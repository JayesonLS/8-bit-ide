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
#include <LbaTranslation.h>
#include "UnitTest.h"

struct KnownChs
{
    size_t numCyliders;
    size_t numHeads;
    size_t numSectorsPerTrack;
};

static KnownChs knownChss[] =
{
    // Extracted from BIOSes.
    {0x3D4, 5, 17},      // Seagate ST05X BIOS [0], [2]
    {0x267, 6, 17},      // Seagate ST05X BIOS [1]
    {0x267, 4, 17},      // Seagate ST05X BIOS [3]
    {0x325, 4, 26},      // Tandy 1000 TL/2 BIOS [0]    
    {0x325, 2, 26},      // Tandy 1000 TL/2 BIOS [1]    
    {0x30E, 4, 27},      // Tandy 1000 TL/2 BIOS [2]    
    {0x30E, 2, 27},      // Tandy 1000 TL/2 BIOS [3]    
    {0x267, 4, 17},      // VTI / Miniscribe BIOS [0]
    {0x325, 2, 26},      // VTI / Miniscribe BIOS [1]
    {0x325, 4, 26},      // VTI / Miniscribe BIOS [2]
    {0x325, 4, 17},      // VTI / Miniscribe BIOS [3]
    {0x134, 4, 17},      // VTI / Miniscribe BIOS [4]
    {0x264, 4, 17},      // WD BIOS [0]
    {0x267, 6, 17},      // WD BIOS [1]
    {0x3D1, 5, 17},      // WD BIOS [2]
    {0x267, 4, 17},      // WD BIOS [3]
    {0x267, 4, 17},      // WD BIOS alt [0]
    {0x30E, 3, 27},      // WD BIOS alt [1]
    {0x30E, 4, 27},      // WD BIOS alt [2]
    {0x30E, 2, 27},      // WD BIOS alt [3]
    {0x264, 4, 17},      // Zenith BIOS (old) [0]
    {0x39D, 4, 17},      // Zenith BIOS (old) [1]
    {0x264, 4, 17},      // Zenith BIOS (old) [2]
    {0x264, 4, 17},      // Zenith BIOS (old) [3]

    // From drive documentation.
    {615, 4, 17},       // Connor CP-2024XT 2.5" (translation)
    {615, 4, 17},       // Seagate ST325-X (translation)
    {820, 6, 17},       // Seagate ST351-A/X (translation)
    {782, 2, 27},       // WD93024-X (physical)
    {782, 3, 27},       // WD93034-X (physical)
    {782, 4, 27},       // WD93044-X (physical)
    {615, 4, 17},       // WD93024-X (translation)
    {615, 6, 17},       // WD93034-X (translation)
    {977, 5, 17},       // WD93044-X (translation)
    
    // Some extras.
    {0x325, 3, 26},  
    {LbaTranslation::MAX_CYLINDERS, LbaTranslation::MAX_HEADS, LbaTranslation::MAX_SECTORS_PER_TRACK}
};

/*static*/ void UnitTest::TestLbaTranslation()
{
    for (KnownChs &chs : knownChss)
    {
        // See if we have already done this heads and sector combination.
        bool skip = false;
        for (KnownChs &previousChs : knownChss)
        {
            if (&previousChs == &chs)
            {
                break;
            }
            else if (previousChs.numHeads == chs.numHeads &&
                     previousChs.numSectorsPerTrack == chs.numSectorsPerTrack)
            {
                skip = true;
                break;
            }
        }

        if (!skip)
        {
            printf("    Testing %d heads, %d sectors per track.\n", chs.numHeads, chs.numSectorsPerTrack);
        }
    }
}