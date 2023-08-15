////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2022 Mateusz Malinowski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////////////////////////

#include "GamepadDriveAdapter.h"


static constexpr float MAX_SHORT = 32767.0f;


GamepadDriveAdapter::GamepadDriveAdapter(const int steeringAxis, const int throttleAxis)
: mSteeringAxis(steeringAxis),
  mThrottleAxis(throttleAxis)
{
}

GamepadDriveAdapter::~GamepadDriveAdapter()
{
}

void GamepadDriveAdapter::update(const GamepadEventData& eventData)
{
    if (eventData.mIsAxis)
    {
        if (eventData.mNumber == mSteeringAxis)
        {
            mDriveCommand.mSteering = static_cast<float>(-eventData.mValue) / MAX_SHORT;
        }
        else if (eventData.mNumber == mThrottleAxis)
        {
            mDriveCommand.mThrottle = static_cast<float>( eventData.mValue) / MAX_SHORT;
        }
        else
        {
            // nothing to do in here
        }
        notifyListeners(mDriveCommand);
    }
}