/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_LBRC
#define LAPO_KEYS KC_LALT, KC_TRNS, KC_Z
#define LCPO_KEYS KC_LCTL, KC_TRNS, KC_GRAVE
// #define RSPC_KEY KC_RIGHT_CURLY_BRACE

// #undef  TAPPING_TERM
#define TAPPING_TERM 175
#define PERMISSIVE_HOLD
#define RETRO_TAPPING

#define ONESHOT_TAP_TOGGLE 2
#define TAPPING_TOGGLE 2

#endif
