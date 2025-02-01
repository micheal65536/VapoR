#pragma once

#include "openvr/types_input.h"
#include "backend/legacy_input.h"

namespace openvr
{
    namespace utils
    {
        inline uint64_t makeLegacyInputButtonsBitmap(const vapor::LegacyInputButtonSet& buttonSet)
        {
            uint64_t buttons = 0;
            if (buttonSet.system)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_SYSTEM;
            }
            if (buttonSet.menu)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_MENU;
            }
            if (buttonSet.grip)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_GRIP;
            }
            if (buttonSet.dpadLeft)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_DPAD_LEFT;
            }
            if (buttonSet.dpadUp)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_DPAD_UP;
            }
            if (buttonSet.dpadRight)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_DPAD_RIGHT;
            }
            if (buttonSet.dpadDown)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_DPAD_DOWN;
            }
            if (buttonSet.buttonA)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_A;
            }
            if (buttonSet.axis0)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_AXIS_0;
            }
            if (buttonSet.axis1)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_AXIS_1;
            }
            if (buttonSet.axis2)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_AXIS_2;
            }
            if (buttonSet.axis3)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_AXIS_3;
            }
            if (buttonSet.axis4)
            {
                buttons |= (uint64_t) 1 << ButtonId::BUTTON_AXIS_4;
            }
            return buttons;
        }

        inline void decodeLegacyInputButtonsBitmap(uint64_t buttons, vapor::LegacyInputButtonSet& buttonSet)
        {
            buttonSet.system = buttons & ((uint64_t) 1 << ButtonId::BUTTON_SYSTEM);
            buttonSet.menu = buttons & ((uint64_t) 1 << ButtonId::BUTTON_MENU);
            buttonSet.grip = buttons & ((uint64_t) 1 << ButtonId::BUTTON_GRIP);
            buttonSet.dpadLeft = buttons & ((uint64_t) 1 << ButtonId::BUTTON_DPAD_LEFT);
            buttonSet.dpadUp = buttons & ((uint64_t) 1 << ButtonId::BUTTON_DPAD_UP);
            buttonSet.dpadRight = buttons & ((uint64_t) 1 << ButtonId::BUTTON_DPAD_RIGHT);
            buttonSet.dpadDown = buttons & ((uint64_t) 1 << ButtonId::BUTTON_DPAD_DOWN);
            buttonSet.buttonA = buttons & ((uint64_t) 1 << ButtonId::BUTTON_A);
            buttonSet.axis0 = buttons & ((uint64_t) 1 << ButtonId::BUTTON_AXIS_0);
            buttonSet.axis1 = buttons & ((uint64_t) 1 << ButtonId::BUTTON_AXIS_1);
            buttonSet.axis2 = buttons & ((uint64_t) 1 << ButtonId::BUTTON_AXIS_2);
            buttonSet.axis3 = buttons & ((uint64_t) 1 << ButtonId::BUTTON_AXIS_3);
            buttonSet.axis4 = buttons & ((uint64_t) 1 << ButtonId::BUTTON_AXIS_4);
        }
    }
}
