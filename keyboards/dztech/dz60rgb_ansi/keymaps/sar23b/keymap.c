#include QMK_KEYBOARD_H

/* Layout for dz60rgb_ansi hotswap 
*  uses capslock key to enter RGB and power Layen 
*  and menu key for numpad
*/

enum layers {
  _QWERTY,
  _FN,
  _ADJUST,
  _NUMPAD
};

// some layer switching aliase
#define SUPENT LGUI_T(KC_ENT)
#define ADJUST MO(_ADJUST)
#define FN MO(_FN)
#define NUM TG(_NUMPAD)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,----------------------------------------------------------------------------------------------------.
 * | `/ESC|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |     \   |
 * |------+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  | Bksp |
 * |---------+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+------|
 * |   Ctrl    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |  Ent(GUI) | 
 * |-----------+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+-----------|
 * |   Shift      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      Shift    | 
 * |---------+----+----+-+------++-----+------+------+------+-----------+-+------+------+-+------+------|
 * |   CAPS  |   GUI   |    Alt  |                 Space                |  AltG  |    FN  |  NUM |ADJUST| 
 * `----------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_60_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,    KC_5,  KC_6,  KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,  KC_Y,  KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,  KC_H,  KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, SUPENT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,  KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
    KC_CAPS, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, FN,    NUM,   ADJUST
),
/* FN
 * ,----------------------------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |         |
 * |------+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+------|
 * |         | Prev |  Up  | Next |      |      |      |      |      |      |      | Home |  End | Print|
 * |---------+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+------|
 * |           | Left | Down | Right|      |      | Left |  Up  | Down | Right|  PG+ |  PG- |           | 
 * |-----------+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+-----------|
 * |              | Mute | Vol- | Vol+ |      |      |      |      |      |  Ins |  Del |               | 
 * |---------+----+----+-+------++-----+------+------+------+-----------+-+------+------+-+------+------|
 * |   Brt+  |  Brt-   |         |                                      |  Play  |        | Play | XXXX | 
 * `----------------------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12, _______,
    _______, KC_MPRV, KC_UP,   KC_MNXT, _______, _______, _______, _______, _______, _______,  _______, KC_HOME, KC_END, KC_PSCR,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_PGUP, KC_PGDN, _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, KC_INS,   KC_DEL,  _______,
    KC_BRID, KC_BRIU, _______, _______, KC_MPLY, _______, KC_MPLY, XXXXXXX
),
/* Adjust
 * ,----------------------------------------------------------------------------------------------------.
 * |  ESC | RGB_P| RGB_B| RGB_R|RGB_SW| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |   Sleep |
 * |------+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+------|
 * |   XXXX  |Toggle| Hue+ | Hue- | Mode+| Mode-| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | Wake |
 * |---------+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+------|
 * |   XXXX    | XXXX | Sat+ | Sat- | Spd+ | Spd- | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |      Pwr  | 
 * |-----------+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+-----------|
 * |   XXXX       | XXXX |  Va+ |  Va- | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |       XXXX    | 
 * |---------+----+----+-+------++-----+------+------+------+-----------+-+------+------+-+------+------|
 * |   XXXX   |  XXXX   |   XXXX |                 XXXX                 |  XXXX  |  XXXX  | RESET|      | 
 * `----------------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_60_ansi(
  KC_ESC,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
  XXXXXXX, RGB_TOG, RGB_HUI, RGB_HUD, RGB_MOD, RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE,
  XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD, RGB_SPI, RGB_SPD,  XXXXXXX, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, KC_PWR,
  XXXXXXX, XXXXXXX, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  RESET, _______
),
/* Numpad 
 * ,----------------------------------------------------------------------------------------------------.
 * | Lock |   /  |   /  |   =  |   .  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |   XXXX  |
 * |------+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+------|
 * |   XXXX  |   *  |   7  |   8  |   9  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |---------+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+------|
 * |   XXXX    |   +  |   4  |   5  |   6  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  XXXX     | 
 * |-----------+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+-----------|
 * |     0        |   -  |   1  |   2  |   3  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |       XXXX    | 
 * |---------+----+----+-+------++-----+------+------+------+-----------+-+------+------+-+------+------|
 * |   Bksp  |   Del   |   XXXX  |                 Ent                  |  XXXX  |  XXXX  |  NUM | XXXX | 
 * `----------------------------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_60_ansi(
  KC_NLCK, KC_PSLS, KC_PSLS, KC_PEQL, KC_PDOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_PAST, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_PPLS, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_P0,   KC_PMNS, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  KC_BSPC, KC_DEL,  XXXXXXX, KC_PENT, XXXXXXX, XXXXXXX, _______, XXXXXXX
)
};
