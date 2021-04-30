#include QMK_KEYBOARD_H

/* plack keymap 
 * numbers and moved keys on left mod
 * arrow keys on rigth mod
 * f keys and rgb controls on rigth bottom
 * numpad on toggle layer
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_1x2uC( //mostly ansi
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LGUI_T(KC_ENT),
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_MPLY, KC_LGUI, KC_ESC,  KC_LALT, MO(1),   KC_SPC,           MO(2),   KC_RALT, XXXXXXX, TG(5),   MO(4)
    ),
	[1] = LAYOUT_planck_1x2uC( //missing keys
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_QUOT, KC_LBRC, KC_RBRC, KC_UNDS, KC_PIPE, XXXXXXX, KC_EQL,  KC_PLUS, KC_MINS, XXXXXXX, XXXXXXX,
    _______, KC_BSLS, KC_LCBR, KC_RCBR, KC_TILD, XXXXXXX, XXXXXXX, KC_DQUO, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, _______, XXXXXXX, _______, _______, KC_GRV,           MO(3),   _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [2] = LAYOUT_planck_1x2uC( //navigation
    XXXXXXX, KC_MPRV, KC_UP,   KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(6),   _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_LGUI,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, KC_BRID, KC_BRIU, _______, MO(3),   XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [3] = LAYOUT_planck_1x2uC(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_DEL,  KC_HOME, KC_PGUP, XXXXXXX, KC_PSCR,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_INS,  KC_END,  KC_PGDN, XXXXXXX, _______,
    XXXXXXX, _______, XXXXXXX, _______, _______, XXXXXXX,          _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
	[4] = LAYOUT_planck_1x2uC( //keeb control
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_SLEP,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI,  RGB_SPI, XXXXXXX, KC_WAKE,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD,  RGB_SPD, XXXXXXX, KC_PWR,
    XXXXXXX, _______, XXXXXXX, _______, XXXXXXX, RGB_TOG,          RGB_MOD, RGB_RMOD, XXXXXXX, RESET,   _______
    ),
	[5] = LAYOUT_planck_1x2uC( //numpad layer
    KC_NLCK, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_BSPC, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_PDOT, KC_P0,   KC_PENT,          XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX
    ),
    [6] = LAYOUT_planck_1x2uC( //mouse layer
    XXXXXXX, KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, _______, XXXXXXX,
    KC_WH_L, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_WH_R, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};