/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ GESC │   1  │   2  │   3  │   4  │   5  │   -  │  │   =  │   6  │   7  │   8  │   9  │   0  │ BkSp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │   [  │  │   ]  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │FNCAPS│   A  │   S  │   D  │   F  │   G  │   (  │  │   )  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   B  │   {  │  │   }  │   N  │   M  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │  Win │  Alt │  RGB │ ADJ  │      │ DEL  │  │ Enter│      │  FN  │ Left │ Down │ Up   │Right │
 * └──────┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Space├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ DEL  │  │ Enter│      │
 *                                    └──────┴──────┘  └──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│                │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│
 * └──────┴──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│ Prev │ Play │ Next │                              │Vol Dn│Vol Up│ Prev │ Play │ Next │
 * └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
 */

enum sol_layers {
    _QWERTY,
    _NO_TRANSIENT,
    _LOWER,
    _RAISE,
    _ADJUST,
    _BLANK
};

enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST,
    NEXT_TAB,
    PREV_TAB
};

#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define ADJUST   MO(_ADJUST)
#define QWERTY   DF(_QWERTY)
#define NO_TRNS TG(_NO_TRANSIENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,                  MENU_BTN,KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                  XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
 RCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX,                  XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RALT_T(KC_QUOT),
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,                  RGB_TOG, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
        KC_LCTL,  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  RAISE,   LOWER,  KC_BSPC,  KC_ENT, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RCTL,

        KC_LEFT, KC_RIGHT,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_WH_L, KC_WH_R, XXXXXXX, XXXXXXX, MENU_DN, MENU_UP,
        KC_WH_D, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX,                                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NO_TRANSIENT] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        KC_ESC,  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, KC_QUOT,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_LOWER] = LAYOUT(
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,                   _______, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
        KC_F12,  KC_F6  , KC_F7,   KC_F8  , KC_F9  , KC_F10,  XXXXXXX,                   XXXXXXX, KC_INS,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_DEL,
_______,MEH(KC_F1),MEH(KC_F2),MEH(KC_F3),MEH(KC_F4),KC_BSLS,  XXXXXXX,                   XXXXXXX, KC_PSCR, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_PEQL,
        _______, KC_LBRC, KC_RBRC, KC_MINS,	KC_EQL,  KC_SLSH, XXXXXXX,                   _______, KC_PAUS, KC_P0,   KC_PCMM, KC_PDOT, KC_PSLS, RSFT_T(KC_PENT),
        _______, _______, _______, _______, ADJUST,  _______, ADJUST,  _______, _______, _______, ADJUST,  KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,

        PREV_TAB,NEXT_TAB,_______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        KC_F12,  KC_LPRN, KC_RPRN, KC_MINS, KC_UNDS, KC_BSLS, XXXXXXX,                   XXXXXXX, KC_PIPE, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_DEL,
        _______, KC_LBRC, KC_RBRC, KC_EQL,  KC_PLUS, KC_SLSH, XXXXXXX,                   XXXXXXX, KC_GRV,  KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX, KC_LOCK,
        _______, KC_LCBR, KC_RCBR, KC_LT  ,	KC_GT ,  KC_SCLN, XXXXXXX,                   _______, KC_COLN, KC_MUTE, KC_MPLY, KC_MPLY, KC_MPLY, _______,
        _______, _______, _______, _______, ADJUST,  _______, _______, ADJUST,  _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_APP,

        KC_VOLD, KC_VOLU, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        KC_F11 , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  DYN_REC_STOP,
        KC_F12 , RGB_SAD, RGB_VAI, RGB_SAI, RESET,   _______, XXXXXXX,                   _______, _______, KC_P7,   KC_P8,   KC_P9,   DM_REC1, DM_REC2,
        KC_CAPS, RGB_HUD, RGB_VAD, RGB_HUI, RGB_RST, _______, XXXXXXX,                   _______, _______, KC_P4,   KC_P5,   KC_P6,   DM_PLY1, DM_PLY2,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, XXXXXXX,                   _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
        _______, RGB_RMOD,RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, NO_TRNS, KC_P0,   KC_PDOT, KC_NLCK, QWERTY,  _______,

        MENU_DN, MENU_UP, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_BLANK] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case MENU_BTN:
            if (record->event.pressed) {
                rgb_menu_selection();
            }
            return false;
        case MENU_UP:
            if (record->event.pressed) {
                rgb_menu_action(true);
            }
            return false;
        case MENU_DN:
            if (record->event.pressed) {
                rgb_menu_action(false);
            }
            return false;
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        case NEXT_TAB:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("\t"));
            }
            return false;
        case PREV_TAB:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT("\t")));
            }
            return false;
        default:
            return true;
    }
}

void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWRTY"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}
