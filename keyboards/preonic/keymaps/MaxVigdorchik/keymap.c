/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _PLOVER,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV       , KC_1  ,  KC_2,    KC_3,    KC_4,    KC_5 ,  KC_6,   KC_7,   KC_8   ,  KC_9,    KC_0   ,    KC_BSPC,    \
  KC_TAB       , KC_Q  ,  KC_W,    KC_E,    KC_R,    KC_T ,  KC_Y,   KC_U,   KC_I   ,  KC_O,    KC_P   ,    KC_BSLS,    \
  ALL_T(KC_ESC), KC_A  ,  KC_S,    KC_D,    KC_F,    KC_G ,  KC_H,   KC_J,   KC_K   ,  KC_L,    KC_SCLN,    KC_QUOT   , \
  KC_LSFT      , KC_Z   , KC_X,    KC_C,    KC_V,    KC_B ,  KC_N,   KC_M,   KC_COMM,  KC_DOT , KC_SLSH  ,  KC_SFTENT , \
  KC_LCTL      , KC_LCTL, KC_LGUI, KC_LALT, LOWER  , KC_SPC, KC_SPC, RAISE , KC_LEFT , KC_DOWN, KC_UP     , KC_RGHT  \
),

/* PLOVER
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,  \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),


/* Lower
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_F11,         KC_F1 ,     KC_F2,      KC_F3,      KC_F4,      KC_F5,   KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, \
  KC_F12,         KC_F6 ,     KC_F7,      KC_F8,      KC_F9,      KC_F10,  KC_INS,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_DEL , \
  ALL_T(KC_CAPS), MEH(KC_F1), MEH(KC_F2), MEH(KC_F3), MEH(KC_F4), KC_BSLS, KC_PSCR, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_PEQL, \
  _______,        KC_LBRC,    KC_RBRC,    KC_MINS,    KC_EQL,     KC_SLSH, KC_PAUS, KC_P0,   KC_PDOT,KC_PCMM,  KC_PSLS, _______, \
  _______,        _______,    _______,    _______,    _______,    _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
),

/* Raise
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_F11 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6       , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_TRNS, \
  KC_F12 , KC_LPRN, KC_RPRN, KC_MINS, KC_UNDS, KC_BSLS, KC_PIPE     , KC_NO  , KC_UP  , KC_NO  , KC_NO  , KC_DEL , \
  KC_TRNS, KC_LBRC, KC_RBRC, KC_EQL , KC_PLUS, KC_GRV , LSFT(KC_GRV), KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  , KC_DEL , \
  KC_TRNS, KC_LCBR, KC_RCBR, KC_LT  , KC_GT  , KC_SCLN, KC_COLN     , KC_NO  , KC_MUTE, KC_MPLY, KC_VOLU, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS     , KC_TRNS, KC_APP , KC_MPRV, KC_VOLD, KC_MNXT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
	KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, KC_PSCR, KC_SLCK, KC_PAUS, KC_INS,  KC_MAIL,         KC_MYCM,           KC_MSEL, KC_CALC, \
	_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,        _______,           _______, KC_DEL,  \
	_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, DF(0),           DF(1),             _______, _______, \
	_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, MAGIC_HOST_NKRO, MAGIC_UNHOST_NKRO, _______, _______, \
	_______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,           _______, _______ \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case PLOVER:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_PLOVER);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
