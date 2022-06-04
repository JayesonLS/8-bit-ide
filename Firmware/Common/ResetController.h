// Copyright (C) 2021 Titanium Studios Pty Ltd 

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
