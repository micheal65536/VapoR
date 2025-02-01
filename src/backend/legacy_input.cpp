#include "legacy_input.h"

#include "frame_state.h"
#include "event_queue.h"

#include "openvr/types_input.h"

using namespace vapor;

static int buttonsCount = 13;
static openvr::ButtonId buttonIds[] = {
    openvr::ButtonId::BUTTON_SYSTEM,
    openvr::ButtonId::BUTTON_MENU,
    openvr::ButtonId::BUTTON_GRIP,
    openvr::ButtonId::BUTTON_DPAD_LEFT,
    openvr::ButtonId::BUTTON_DPAD_UP,
    openvr::ButtonId::BUTTON_DPAD_RIGHT,
    openvr::ButtonId::BUTTON_DPAD_DOWN,
    openvr::ButtonId::BUTTON_A,
    openvr::ButtonId::BUTTON_AXIS_0,
    openvr::ButtonId::BUTTON_AXIS_1,
    openvr::ButtonId::BUTTON_AXIS_2,
    openvr::ButtonId::BUTTON_AXIS_3,
    openvr::ButtonId::BUTTON_AXIS_4
};
static inline bool getButtonState(const LegacyInputButtonSet& buttons, int buttonIndex)
{
    switch (buttonIndex)
    {
        case 0:
            return buttons.system;
        case 1:
            return buttons.menu;
        case 2:
            return buttons.grip;
        case 3:
            return buttons.dpadLeft;
        case 4:
            return buttons.dpadUp;
        case 5:
            return buttons.dpadRight;
        case 6:
            return buttons.dpadDown;
        case 7:
            return buttons.buttonA;
        case 8:
            return buttons.axis0;
        case 9:
            return buttons.axis1;
        case 10:
            return buttons.axis2;
        case 11:
            return buttons.axis3;
        case 12:
            return buttons.axis4;
        default:
            return false;
    }
}

// CHECK: legacy input events on SteamVR
// CHECK: determine how ageSeconds is supposed to work (is it relative to when the client requests the event, or is it monotonically increasing since app start, etc.)
bool LegacyInputHelper::emitChangeEvents(FrameStateStore& frameStates, EventQueue& eventQueue)
{
    const FrameState& currentFrame = frameStates.getFrame(0);
    const FrameState& previousFrame = frameStates.getFrame(1);

    bool changed = false;
    for (int controllerIndex = 0; controllerIndex < 2; controllerIndex++)
    {
        for (int buttonIndex = 0; buttonIndex < buttonsCount; buttonIndex++)
        {
            bool currentFrameTouched = getButtonState(currentFrame.legacyInputStates[controllerIndex].touch, buttonIndex);
            bool currentFramePressed = getButtonState(currentFrame.legacyInputStates[controllerIndex].click, buttonIndex);
            bool previousFrameTouched = getButtonState(previousFrame.legacyInputStates[controllerIndex].touch, buttonIndex);
            bool previousFramePressed = getButtonState(previousFrame.legacyInputStates[controllerIndex].click, buttonIndex);
            currentFrameTouched |= currentFramePressed;
            previousFrameTouched |= previousFramePressed;

            openvr::Event_0_9_15 event {
                .type = openvr::EventType::EVENT_NONE,
                .trackedDeviceIndex = (uint32_t) controllerIndex + 1,
                .ageSeconds = 0.0f,
                .data {
                    .button {
                        .button = buttonIds[buttonIndex]
                    }
                }
            };

            if (currentFrameTouched && !previousFrameTouched)
            {
                event.type = openvr::EventType::EVENT_BUTTON_TOUCH;
                eventQueue.putEvent(event, currentFrame.controllerPoses[controllerIndex]);
                changed = true;
            }

            if (currentFramePressed && !previousFramePressed)
            {
                event.type = openvr::EventType::EVENT_BUTTON_PRESS;
                eventQueue.putEvent(event, currentFrame.controllerPoses[controllerIndex]);
                changed = true;
            }

            if (!currentFramePressed && previousFramePressed)
            {
                event.type = openvr::EventType::EVENT_BUTTON_RELEASE;
                eventQueue.putEvent(event, currentFrame.controllerPoses[controllerIndex]);
                changed = true;
            }

            if (!currentFrameTouched && previousFrameTouched)
            {
                event.type = openvr::EventType::EVENT_BUTTON_UNTOUCH;
                eventQueue.putEvent(event, currentFrame.controllerPoses[controllerIndex]);
                changed = true;
            }
        }
    }

    return changed;
}
