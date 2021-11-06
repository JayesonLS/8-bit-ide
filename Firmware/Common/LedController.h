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

// Led controller with layered priorities.
class LedController
{
    enum class ErrorType
    {
        None = -1,

        NoPrimarySdCard,
        PrimarySdCommunicationError,
        PrimarySdTooSmall,

        Num
    };

    static LedController instance;

    void Initialize();

    // Lowest priority: drive activity.
    void SetDriveActivity(bool active);

    // Medium priority: Set on/off. 
    void SetLed(bool on);

    // Highest priority. This will flash a sequence
    // corresponding to the error code.
    // Use ErrorType.None to disable flashing.
    void FlashErrorSequence(ErrorType errorType);

    // Call this regularly from main loop (not from interrupt).
    void Update(); 

private:
    bool driveActiveState = 0;
    bool setState = 0;
    ErrorType errorType = ErrorType::None;
};
