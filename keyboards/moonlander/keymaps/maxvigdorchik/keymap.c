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



#include QMK_KEYBOARD_H
#include "version.h"
#include "unicode_mapping.h"

enum layers {
    BASE,  // default layer
    LOWER,
    RAISE,
    ADJUST,
    MATH,
    MOUSE,
    NO_TRANSIENT
};

enum custom_keycodes {
    KC_BASE = ML_SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    RGB_HEAT,
    RGB_DROP,
    RGB_JELLY,
    RGB_SPLASH,
    RGB_RAIN
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    RGB_HUD,           RGB_HUI, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    RGB_VAD,           RGB_VAI, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
 RCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    RGB_SAD,           RGB_SAI, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RALT_T(KC_QUOT),
        KC_LSFT, KC_Z ,   KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
        KC_LCTL, KC_LCTL, KC_LGUI ,KC_LALT, XXXXXXX, KC_LGUI,                    KC_LGUI,          KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, XXXXXXX,
                                            KC_SPC,  KC_LOWER,KC_BSPC,           KC_LCTL, KC_ENT,  KC_RAISE
    ),

    [LOWER] = LAYOUT_moonlander(
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   RGB_RMOD,          RGB_MOD, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
        KC_F12,  KC_F6  , KC_F7,   KC_F8  , KC_F9  , KC_F10,  RGB_SPD,           RGB_SPI, KC_INS,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_DEL,
_______,MEH(KC_F1),MEH(KC_F2),MEH(KC_F3),MEH(KC_F4),KC_BSLS,  RGB_MODE_PLAIN,    RGB_M_R, KC_PSCR, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_PEQL,
        _______, KC_LBRC, KC_RBRC, KC_MINS,	KC_EQL,  KC_SLSH,                             KC_PAUS, KC_P0,   KC_PCMM, KC_PDOT, KC_PSLS, RSFT_T(KC_PENT),
        _______, _______, _______, _______, _______,          XXXXXXX,           KC_WREF,          KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
                                            XXXXXXX, _______, XXXXXXX,           KC_WBAK ,KC_WFWD, _______
    ),

    //TODO: Change raise to be its own thing instead of copy lower
    [RAISE] = LAYOUT_moonlander(
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   RGB_HEAT,         RGB_JELLY,KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
        KC_F12,  KC_LPRN, KC_RPRN, KC_MINS, KC_UNDS, KC_BSLS, RGB_DROP,         RGB_RAIN, KC_INS,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_DEL,
        _______, KC_LBRC, KC_RBRC, KC_EQL,  KC_PLUS, KC_SLSH, RGB_SPLASH,       RGB_M_G,  KC_PSCR, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_PEQL,
        _______, KC_LCBR, KC_RCBR, KC_LT  ,	KC_GT ,  KC_SCLN,                             KC_PAUS, KC_P0,   KC_PCMM, KC_PDOT, KC_PSLS, RSFT_T(KC_PENT),
        _______, _______, _______, _______, _______,          XXXXXXX,          KC_WREF,           KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
                                            XXXXXXX, _______, XXXXXXX,          KC_WBAK , KC_WFWD, _______
    ),

    [ADJUST] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        EEP_RST, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        RESET  , _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_LOWER:
        if (record->event.pressed) {
            layer_on(LOWER);
            update_tri_layer(LOWER, RAISE, ADJUST);
        } else {
            layer_off(LOWER);
            update_tri_layer(LOWER, RAISE, ADJUST);
        }
        return false;
    case KC_RAISE:
        if (record->event.pressed) {
            layer_on(RAISE);
            update_tri_layer(LOWER, RAISE, ADJUST);
        } else {
            layer_off(RAISE);
            update_tri_layer(LOWER, RAISE, ADJUST);
        }
        return false;

    // RGB Related key codes
    case RGB_HEAT:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
        }
        return false;

    case RGB_DROP:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINDROPS);
        }
        return false;

    case RGB_SPLASH:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
        }
        return false;

    case RGB_JELLY:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_JELLYBEAN_RAINDROPS);
        }
        return false;

    case RGB_RAIN:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_DIGITAL_RAIN);
        }
        return false;
    }
    return true;
}
