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
#include <IoConfig.h>
#include "LedController.h"

/*static*/ LedController LedController::instance;

void LedController::Initialize()
{
    // TODO
}

void LedController::SetDriveActivity(bool active)
{
    driveActiveState = active;
    Update();
}

void LedController::SetLed(bool on)
{
    setState = on;
    Update();
}

void LedController::FlashErrorSequence(ErrorType flashCount)
{
    assert(flashCount >= ErrorType::None && flashCount < ErrorType::Num);

    errorType = errorType;
    Update();
}

void LedController::Update()
{
    // TODO
}