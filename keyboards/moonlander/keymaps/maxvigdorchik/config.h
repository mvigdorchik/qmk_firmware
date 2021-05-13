/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Enables layer lights even when backlight is disabled
#define ORYX_CONFIGURATOR

#define MOUSEKEY_TIME_TO_MAX 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 2

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define LEADER_TIMEOUT 400
#define LEADER_PER_KEY_TIMING

#define RGBLIGHT_ANIMAITONS
