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
