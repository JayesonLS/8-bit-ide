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

class ResetController
{
public:
    void Initialize();

    // Delay will depend on various state. Can often
    // return immediately.
    void WaitForStartupResetDelay();

    // The reset register was written to (XTA).
    void RegisterResetEdge();
    // The reset bit has been set (DBA8).
    void RegisterResetActive();
    // The reset bit has been cleared (DBA8).
    void RegisterResetRelease();

private:
    void ResetPinInterrupt();
};
