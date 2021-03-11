#include QMK_KEYBOARD_H

/* Layout for dz60rgb_ansi hotswap 
*  uses capslock key to enter RGB and power Layen 
*  and menu key for numpad
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_60_ansi(
		KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,    KC_5,  KC_6,  KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,  KC_Y,  KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,  KC_H,  KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, LGUI_T(KC_ENT),
		KC_LSPO, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,  KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
		MO(4),   KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), TG(3), MO(2)
		),
	[1] = LAYOUT_60_ansi(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
		_______, KC_MPRV, KC_UP,   KC_MNXT, _______, _______, _______, _______, KC_UP,   _______, _______, KC_HOME, KC_END,  KC_PSCR,
		_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PGDN, KC_MPLY,
		KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  KC_MPLY,
		_______, _______, _______, _______, KC_MPLY, _______, KC_MPLY, XXXXXXX
		),
	[2] = LAYOUT_60_ansi(
		KC_ESC,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
		XXXXXXX, RGB_TOG, RGB_HUI, RGB_HUD, RGB_MOD,  RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE,
		XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD, RGB_SPI,  RGB_SPD,  XXXXXXX, KC_BRIU, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, KC_PWR,
		KC_LSPO, XXXXXXX, RGB_VAI, RGB_VAD, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_LCTL, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX,  RESET,    XXXXXXX, _______
		),
	[3] = LAYOUT_60_ansi(
		KC_NLCK, KC_PSLS, KC_PEQL, KC_PDOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, KC_PAST, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, KC_PPLS, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_P0,   KC_PMNS, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_BSPC, KC_DEL,  XXXXXXX, KC_PENT, XXXXXXX, XXXXXXX, _______, XXXXXXX
		),
	[4] = LAYOUT_60_ansi(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, S(KC_BSLS),
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______
		)
};
