/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.	 If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "unicode_mapping.h"
#include "muse.h"
#include "keymap_steno.h"

enum preonic_layers { _QWERTY,
					  _NO_TRANSIENT,
					  _PLOVER,
					  _MOUSE,
					  _LOWER,
					  _RAISE,
					  _MATH,
					  _ADJUST };

enum preonic_keycodes { QWERTY = SAFE_RANGE,
			PLOVER,
			EXT_SPCL,
			LOWER,
			RAISE,
			BACKLIT };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT_preonic_grid(KC_GRV,			KC_1,	 KC_2,	  KC_3,	   KC_4,  KC_5,	  KC_6,	  KC_7,	 KC_8,	  KC_9,	   KC_0,	KC_BSPC,
					KC_TAB,			KC_Q,	 KC_W,	  KC_E,	   KC_R,  KC_T,	  KC_Y,	  KC_U,	 KC_I,	  KC_O,	   KC_P,	KC_BSLS,
					RCTL_T(KC_ESC), KC_A,	 KC_S,	  KC_D,	   KC_F,  KC_G,	  KC_H,	  KC_J,	 KC_K,	  KC_L,	   KC_SCLN, RALT_T(KC_QUOT),
					KC_LSFT,		KC_Z,	 KC_X,	  KC_C,	   KC_V,  KC_B,	  KC_N,	  KC_M,	 KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
					KC_LCTL,		KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,	KC_RGHT),

	/*  Version of QWERTY removing the double keys such as right control+escape for better compatibility with some software */
	[_NO_TRANSIENT] = LAYOUT_preonic_grid(
		KC_GRV, 			KC_1,	 KC_2,	  KC_3,	   KC_4, KC_5,   	  KC_6,	  KC_7,	 KC_8,    	  KC_9,	   KC_0,    	KC_BSPC,
		KC_TAB,  			KC_Q,	 KC_W,	  KC_E,	   KC_R, KC_T,   	  KC_Y,	  KC_U,	 KC_I,    	  KC_O,	   KC_P,    	KC_BSLS,
		KC_ESC,  KC_A,            	 KC_S,	  KC_D,	   KC_F, KC_G,   	  KC_H,	  KC_J,	 KC_K,    	  KC_L,	   KC_SCLN, KC_QUOT,
		KC_LSFT, 		KC_Z,     	 KC_X,	  KC_C,	   KC_V, KC_B,   	  KC_N,	  KC_M,	 KC_COMM, KC_DOT,   KC_SLSH,    KC_ENT,
		KC_LCTL, 		KC_LCTL,  KC_LGUI, KC_LALT, LOWER,   KC_SPC, KC_SPC,    RAISE,  KC_LEFT,  KC_DOWN,  KC_UP,      	KC_RGHT),

	/* Lower
	 */
	[_LOWER] = LAYOUT_preonic_grid(
		KC_F11, 	KC_F1,  		KC_F2,		KC_F3,		KC_F4,		KC_F5,  	 KC_NLCK, KC_P7,   KC_P8,  	KC_P9,  	 KC_PMNS, KC_BSPC,
		KC_F12, 	KC_F6,  		KC_F7,		KC_F8,		KC_F9,		KC_F10, 	 KC_INS,  KC_P4,   KC_P5,  	KC_P6,  	 KC_PPLS, KC_DEL,
		KC_CAPS, MEH(KC_F1), MEH(KC_F2),   MEH(KC_F3), MEH(KC_F4), KC_BSLS,      KC_PSCR,     KC_P1,   KC_P2,  	KC_P3,  	 KC_PAST, KC_PEQL,
		_______, KC_LBRC,   	KC_RBRC,  	KC_MINS,  	KC_EQL,   		KC_SLSH, KC_PAUS,     KC_P0,   KC_PCMM, KC_PDOT, KC_PSLS,     RSFT_T(KC_PENT),
		_______, _______,   	_______,  	_______,  	_______,  	_______,     _______,     _______, KC_HOME, KC_PGDN, KC_PGUP,     KC_END),

	/* Raise */
	[_RAISE] = LAYOUT_preonic_grid(
		KC_F11,	KC_F1,	 KC_F2,	  KC_F3,   KC_F4,	KC_F5,	 KC_F6,		   KC_F7,	KC_F8,	 KC_F9,	  KC_F10,  KC_BSPC,
		KC_F12,	KC_LPRN, KC_RPRN, KC_MINS, KC_UNDS, KC_BSLS, KC_PIPE,	   KC_HOME, KC_UP,	 KC_END,  XXXXXXX, KC_DEL,
		_______, KC_LBRC, KC_RBRC, KC_EQL,  KC_PLUS, KC_GRV,	 LSFT(KC_GRV), KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_LOCK,
		_______, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,	KC_SCLN, KC_COLN,	   KC_MUTE, KC_MUTE, KC_MPLY, KC_VOLU, _______,
		_______, _______, _______, _______, _______, _______, _______,	   _______, KC_APP,	 KC_MPRV, KC_VOLD, KC_MNXT),

	/* Adjust (Lower + Raise)
	 */
	[_ADJUST] = LAYOUT_preonic_grid(
		KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, KC_PSCR, KC_SLCK,          KC_PAUS, KC_INS,            _______,     DM_REC1,         DM_REC2,           DM_RSTP,
		_______, RESET,   DEBUG,   _______, _______, UNICODE_MODE_OSX, _______, _______,           _______,     DM_PLY1,         DM_PLY2,           KC_DEL,
		_______, _______, MU_MOD,  AU_ON,   AU_OFF,  UNICODE_MODE_WIN, _______, DF(_NO_TRANSIENT), DF(_QWERTY), DF(_MOUSE),      PLOVER,            _______,
		_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  UNICODE_MODE_LNX, _______, TG(_MATH),         _______,     MAGIC_HOST_NKRO, MAGIC_UNHOST_NKRO, _______,
		_______, _______, _______, _______, _______, _______,          _______, _______,           _______,     _______,         _______,           _______),

	/* Mouse keys in case there is no mouse connected
	 */
	[_MOUSE] = LAYOUT_preonic_grid(
		XXXXXXX,  	 KC_MS_ACCEL0,KC_MS_ACCEL1,KC_MS_ACCEL2,     XXXXXXX,        	 XXXXXXX,	XXXXXXX,XXXXXXX,       	  XXXXXXX,     		 XXXXXXX,  		XXXXXXX,XXXXXXX,
		XXXXXXX,  	 KC_MS_BTN1,   KC_MS_UP,    	KC_MS_BTN2,  	 KC_MS_BTN3,KC_MS_BTN4,   XXXXXXX,   	 XXXXXXX,  	  KC_MS_WH_UP,	XXXXXXX,       		XXXXXXX,XXXXXXX,
		XXXXXXX,  	 KC_MS_LEFT,   KC_MS_DOWN,  	KC_MS_RIGHT, KC_MS_BTN5,     XXXXXXX,     	XXXXXXX,KC_MS_WH_LEFT,KC_MS_WH_DOWN,   KC_MS_WH_RIGHT,XXXXXXX,       XXXXXXX,
		XXXXXXX,  	 XXXXXXX,      	   XXXXXXX,		XXXXXXX,     	 XXXXXXX,    	 XXXXXXX,	XXXXXXX,XXXXXXX,       	  XXXXXXX,     		 XXXXXXX,  		XXXXXXX,XXXXXXX,
		EXT_SPCL, XXXXXXX,         	   XXXXXXX,		XXXXXXX,     	 XXXXXXX,    	 XXXXXXX,	XXXXXXX,XXXXXXX,       	  XXXXXXX,     		 XXXXXXX,  		XXXXXXX,XXXXXXX),

	/* Math (for greek symbols, etc. mostly unicode)
	 */
	[_MATH] = LAYOUT_preonic_grid(
		_______,   	 _______,         _______,                	 _______,           _______,         	_______,        _______,           _______,    _______,           _______,            _______,         _______,
		_______,   	 _______,         XP(OMEGA,C_OMEGA),      XP(EPSILON,ETA),      X(RHO),          X(TAU),            XP(THETA,C_THETA), X(PARTIAL),XP(IOTA, INTEGRAL),XP(PSI,  C_PSI),     XP(PI,    C_PI), _______,
		_______,   	 XP(ALPHA,ALEPH), XP(SIGMA,     C_SIGMA), XP(DELTA,   C_DELTA), XP(PHI,  C_PHI), XP(GAMMA,C_GAMMA), _______,           _______,    X(KAPPA),         XP(LAMBDA,C_LAMBDA), _______,         _______,
		_______,   	 X(ZETA),         X(CHI),                 	 XP(XI,  C_XI),     _______,         	X(BETA),        X(NU),             	 X(MU),    _______,           _______,            _______,         _______,
		TG(_MATH),_______,            _______,                	 _______,           _______,         	_______,        _______,           _______,    _______,           _______,            _______,         _______),

	/* PLOVER
	 */
	[_PLOVER] = LAYOUT_preonic_grid(STN_N1,	  STN_N2,  STN_N3,	STN_N4,	 STN_N5,  STN_N6,  STN_N7,	STN_N8,	 STN_N9,  STN_NA,  STN_NB,	STN_NC,
					STN_FN,	  STN_S1,  STN_TL,	STN_PL,	 STN_HL,  STN_ST1, STN_ST3, STN_FR,	 STN_PR,  STN_LR,  STN_TR,	STN_DR,
					XXXXXXX,  STN_S2,  STN_KL,	STN_WL,	 STN_RL,  STN_ST2, STN_ST4, STN_RR,	 STN_BR,  STN_GR,  STN_SR,	STN_ZR,
					XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_PWR, STN_RE1, STN_RE2,
					EXT_SPCL, KC_LCTL, KC_LGUI, KC_LALT, STN_A,	  STN_O,   STN_E,	STN_U,	 XXXXXXX, LOWER,   RAISE,	MO(_ADJUST))};

#ifdef AUDIO_ENABLE
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
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

	case QWERTY:
		if (record->event.pressed) {
			/* set_single_persistent_default_layer(_QWERTY); */
			// Don't write to the EEPROM since I always want QWERTY on boot
			// If new layouts are added this should be changed to be persistant
			default_layer_set(1U << _QWERTY);
		}
		return false;
		break;
	case PLOVER:
		if (record->event.pressed) {
			// Don't write to EEPROM to save write cycles since I never want PLOVER on boot
			default_layer_set(1U << _PLOVER);
			// This is defined as a special key to ensure nkro is enabled when PLOVER is
			keymap_config.nkro = 1;
		}
		return false;
		break;

	case EXT_SPCL:
		if (record->event.pressed) {
			default_layer_set(1U << _QWERTY);
#ifdef AUDIO_ENABLE
			PLAY_SONG(plover_gb_song);
#endif
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

void matrix_init_user() {
	steno_set_mode(STENO_MODE_GEMINI);	// or STENO_MODE_BOLT
	set_single_persistent_default_layer(_QWERTY);
}
void eeconfig_init_user(void) {
	set_unicode_input_mode(UC_LNX);
}

bool	 muse_mode	= false;
uint8_t	 last_muse_note = 0;
uint16_t muse_counter	= 0;
uint8_t	 muse_offset	= 70;
uint16_t muse_tempo	= 50;

/* LEADER_EXTERNS(); */

void matrix_scan_user(void) {
	/* LEADER Key Configuration */
	/* LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		SEQ_ONE_KEY(KC_T) { SEND_STRING(SS_LCTRL(SS_LSFT("t"))); }
		SEQ_TWO_KEYS(KC_C, KC_A) { SEND_STRING(SS_LCTL("a") SS_LCTL("c")); }
	*/

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

/* void encoder_update_user(uint8_t index, bool clockwise) { */
/*	 if (muse_mode) { */
/*	   if (IS_LAYER_ON(_RAISE)) { */
/*	 if (clockwise) { */
/*	   muse_offset++; */
/*	 } else { */
/*	   muse_offset--; */
/*	 } */
/*	   } else { */
/*	 if (clockwise) { */
/*	   muse_tempo+=1; */
/*	 } else { */
/*	   muse_tempo-=1; */
/*	 } */
/*	   } */
/*	 } else { */
/*	   if (clockwise) { */
/*	 register_code(KC_PGDN); */
/*	 unregister_code(KC_PGDN); */
/*	   } else { */
/*	 register_code(KC_PGUP); */
/*	 unregister_code(KC_PGUP); */
/*	   } */
/*	 } */
/* } */

bool music_mask_user(uint16_t keycode) {
	switch (keycode) {
	case RAISE:
	case LOWER:
		return false;
	default:
		return true;
	}
}
