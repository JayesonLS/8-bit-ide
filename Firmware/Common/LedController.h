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
public:
    enum class ErrorType
    {
        None,
        Invalid,
        NoPrimarySdCard,
        PrimarySdCommunicationError,
        PrimarySdTooSmall,

        Num
    };

    static uint const ERROR_FLASH_ON_MS = 500;
    static uint const ERROR_FLASH_OFF_MS = 500;
    static uint const ERROR_FLASH_BETWEEN_MS = 2000;

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

#ifndef DISABLE_TESTS
    static void RunLedDemo();
#endif

private:
    enum class FlashState
    {
        NotFlashing,
        FlashOn,
        FlashOff,
        DelayBetweenFlashes
    };

    bool driveActiveState = false;
    bool setState = false;
    ErrorType errorType = ErrorType::None;

    // For sequencing the flashes.
    FlashState flashState = FlashState::NotFlashing;
    size_t flashCount = 0;
    uint32_t lastStartTime = 0;

    bool lastLedState = false;
};
