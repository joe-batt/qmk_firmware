/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LAYERS
#define COMBO_COUNT 4
//#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
//#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
//#define RETRO_TAPPING
//#define RETRO_TAPPING_PER_KEY
#define NKRO_ENABLE
#define TAPPING_TOGGLE 3
#define TAPPING_TERM 190
#define DYNAMIC_MACRO_NO_NESTING
//#define MK_3_SPEED
//#define MK_C_OFFSET_0 8
//#define MK_C_INTERVAL_0 16
//#define MK_C_OFFSET_1 12
//#define MK_C_INTERVAL_1 16
//#define MK_C_OFFSET_2 16
//#define MK_C_INTERVAL_2 16
//
//#define MK_KINETIC_SPEED
#define RGBLIGHT_LAYER_BLINK
//#define MOUSEKEY_INTERVAL 8
//#define MOUSEKEY_MOVE_DELTA 1
//#define MOUSEKEY_INITIAL_SPEED 2
//#define MOUSEKEY_BASE_SPEED 32
#define USB_POLLING_INTERVAL_MS 2
