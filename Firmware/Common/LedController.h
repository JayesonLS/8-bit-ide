// Copyright (C) 2021 Titanium Studios Pty Ltd 

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
