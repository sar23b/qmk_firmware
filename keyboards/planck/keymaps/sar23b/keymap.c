/* plack keymap 
 * numbers and moved keys on left mod
 * arrow keys on rigth mod
 * f keys and rgb controls on rigth bottom
 * numpad on toggle layer
 */

#include QMK_KEYBOARD_H
#include "muse.h"

#include "unicodemap.h"

enum planck_layers {
  // basic layers
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  // specials
  _NUMPAD,
  _MOUSE,
  _MUSIC,
  _MUSCTL,
  _GAME,
  _LIGHT,
  _SONG,
  // stage 2 layer
  _KEEP,
  _UNICODE
};

enum planck_keycodes {
  NUMPAD = SAFE_RANGE,
  MOUSE,
  EXT_NUM,
  EXT_MSE,
  LIGHT,
  EXT_LGT,
  GAME,
  EXT_GME,
  SONG,
  EXT_SNG,
  // color test keycodes
  xff8000,
  xffff00,
  x7fff00,
  x00ff7f,
  x007fff,
  x00ffff,
  x8080ff,
  xc080ff,
  x4e019b,
  x0b019b,
  x144efc,
  x14c2fc,
  xeabe0e,
  x5e4d08,
  xd4fc76,
  x85ad1f
};


// some shortcuts for readabilty
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SUPENT LGUI_T(KC_ENT)
#define ADJUST MO(_ADJUST)
#define COPY LCTL(KC_C)
#define CUT LCTL(KC_X)
#define PASTE LCTL(KC_V)
#define MSCTRL MO(_MUSCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Et(Gu)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Play |  GUI | Esc  | Alt  |Lower |    Space    |Raise | AltG | Mouse| Num  | Adju |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_1x2uC( 
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, SUPENT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_MPLY, KC_LGUI, KC_ESC,  KC_LALT, LOWER,   KC_SPC,           RAISE,   KC_RALT, MOUSE,   NUMPAD,  ADJUST
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   '  |   [  |   ]  |   _  |   |  | XXXX |   =  |   +  |   -  | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   {  |   }  |   ~  | XXXX | XXXX |   "  | XXXX | XXXX | XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |      | XXXX |      |      |      `      |      |      | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_1x2uC( //missing keys
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_QUOT, KC_LBRC, KC_RBRC, KC_UNDS, KC_PIPE, XXXXXXX, KC_EQL,  KC_PLUS, KC_MINS, XXXXXXX, XXXXXXX,
    _______, KC_BSLS, KC_LCBR, KC_RCBR, KC_TILD, XXXXXXX, XXXXXXX, KC_DQUO, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, _______, XXXXXXX, _______, _______, KC_GRV,           _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | Next |  Up  | Prev | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Rigth| XXXX | XXXX | Left | Down |  Up  |Right | XXXX |  GUI |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Vol- | Vol+ | Mute | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | Disp+| Disp-|      |      |     XXXX    |      | XXXX | XXXX | XXXX |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_1x2uC( //navigation
    XXXXXXX, KC_MPRV, KC_UP,   KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_LGUI,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, KC_BRID, KC_BRIU, _______, _______, XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX, _______
),

/* Keep (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | XXXX |  F1  |  F2  |  F3  |  F4  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  | XXXX | XXXX |  Del | Home |  pUP | XXXX | prSrc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 | XXXX | XXXX |  Ins |  End | pDown| XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |      | XXXX |      |      |     XXXX    |      |      | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_KEEP] = LAYOUT_planck_1x2uC(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_DEL,  KC_HOME, KC_PGUP, XXXXXXX, KC_PSCR,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_INS,  KC_END,  KC_PGDN, XXXXXXX, _______,
    XXXXXXX, _______, XXXXXXX, _______, _______, XXXXXXX,          _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust 
 * ,-----------------------------------------------------------------------------------.
 * | Music| Light| XXXX | XXXX | XXXX | XXXX | XXXX | Mode+| Mode-| XXXX | XXXX | Sleep|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Game | Song | XXXX | XXXX | XXXX | XXXX | Hue+ | Sat+ | Brt+ | Spd+ | XXXX | Wake |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | Hue- | Sat- | Brt- | Spd- | XXXX | Power|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX |     RGB     |      | AUD1 | AUD0 | Reset|      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_1x2uC( //keeb control
    MU_ON,   LIGHT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_RMOD, XXXXXXX, XXXXXXX, KC_SLEP,
    GAME,    SONG,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI,  RGB_SPI, XXXXXXX, KC_WAKE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD,  RGB_SPD, XXXXXXX, KC_PWR,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,          _______, AU_ON,    AU_OFF,  RESET,   _______
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * | Tab  | XXXX |   7  |   8  |   9  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |   *  |   4  |   5  |   6  |   +  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   /  |   1  |   2  |   3  |   -  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lock | XXXX | XXXX |   .  |   0  |     Ent     | XXXX | XXXX | XXXX | Exit | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_1x2uC( 
    KC_TAB,  XXXXXXX, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_BSPC, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_NLCK, XXXXXXX, XXXXXXX, KC_PDOT, KC_P0,   KC_PENT,          XXXXXXX, XXXXXXX, XXXXXXX, EXT_NUM, XXXXXXX
),

/* Mouse 
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  M3  |  MU  |  M2  |  MWU |  MWL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  ML  |  MD  |  MR  |  MWD |  MWR |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  M4  |  M5  | CUT  | COPY | PASTE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX |     XXXX    |  M1  | Acl3 | Exit | Acl1 | Acl2 |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_1x2uC( //mouse layer 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, KC_MS_U, KC_BTN2, KC_WH_U, KC_WH_L,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_WH_R,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, CUT,     COPY,    PASTE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_BTN1, KC_ACL0, EXT_MSE, KC_ACL1, KC_ACL2
),

/* Unicode
 * ,-----------------------------------------------------------------------------------.
 * | XXXX |  ⚧   |  ✨  |  🦄  |  🐛  |  🐧  |  🐢  | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | VS16 |  🌈  |  💜  |  ❄   |  🙃  |  🦕  |  🦋  | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ZWJ |  🏳  |  💅  |  🌨  |  😶  |  🐍  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift| XXXX | XXXX | XXXX | XXXX |    🐬/🐋    |      | XXXX | XXXX | XXXX |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UNICODE] = LAYOUT_planck_1x2uC( //unicode char layer
    XXXXXXX, X(TRANS), X(GLITT),  X(UNICRN), X(CATPIL), X(PENGU),  X(TURTLE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    X(VS16), X(GAY),   X(PHEART), X(FLKE),   X(UPDF),   X(SAUWIA), X(BUTFLY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    X(ZWJ),  X(FLAG),  X(NAILS),  X(SNOW),   X(NMOF),   X(SNEK),   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XP(DOLPI,WHALE),      _______, XXXXXXX, XXXXXXX, XXXXXXX, _______
),

/* Music
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |MSCTRL|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX |     XXXX    | XXXX | XXXX | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_MUSIC] = LAYOUT_planck_1x2uC( //Music map layer
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MSCTRL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Music control
 * ,-----------------------------------------------------------------------------------.
 * | Exit | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | CYCLE| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX |  REC |     STOP    | PLAY | FAST | SLOW | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_MUSCTL] = LAYOUT_planck_1x2uC( //Music map control layer
    MU_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MU_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT,          KC_LGUI, KC_UP,   KC_DOWN, XXXXXXX, XXXXXXX
),

/* Game 
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX |     XXXX    | XXXX | XXXX | XXXX | XXXX | Exit |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_planck_1x2uC( //layout for gaming
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EXT_GME 
),

/* RGB light test mode 
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX |     XXXX    | XXXX | XXXX | XXXX | XXXX | Exit |
 * `-----------------------------------------------------------------------------------'
 */
[_LIGHT] = LAYOUT_planck_1x2uC( // mode to test out colors
    XXXXXXX, xff8000, x00ff7f, x8080ff, x0b019b, xeabe0e, x85ad1f, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, xffff00, x007fff, xc080ff, x144efc, x5e4d08, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, x7fff00, x00ffff, x4e019b, x14c2fc, xd4fc76, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EXT_LGT 
),

/* Song test mode 
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX |     XXXX    | XXXX | XXXX | XXXX | XXXX | Exit |
 * `-----------------------------------------------------------------------------------'
 */
[_SONG] = LAYOUT_planck_1x2uC( // testing songs
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EXT_SNG
)

/* Layout 
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX |     XXXX    | XXXX | XXXX | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 * /
[_LAYER] = LAYOUT_planck_1x2uC( //generic layout
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
*/
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float on_short[][2] = SONG(STARTUP_SOUND);
  float off_short[][2] = SONG(GOODBYE_SOUND);
  float test_long[][2] = SONG(FANTASIE_IMPROMPTU);
  float song_song[][2] = SONG(PLANCK_SOUND);
  float song_song_end[][2] = SONG(PREONIC_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _KEEP);
    state = update_tri_layer_state(state, _ADJUST, _RAISE, _UNICODE);
    
    // set backlight based on active layer
    switch (get_highest_layer(state)) {
    case _RAISE:
        rgblight_setrgb (0x00, 0x00, 0xFF);
        break;
    case _LOWER:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    case _KEEP:
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    case _ADJUST:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _NUMPAD:
        rgblight_setrgb (0xFF,  0x90, 0x00);
        break;
    case _MOUSE:
        rgblight_setrgb (0xFF,  0x00, 0xFF);
        break;
    case _UNICODE:
        rgblight_setrgb (0x00, 0xFF, 0x00);
        break;
    case _MUSIC:
        rgblight_setrgb (0x00, 0x80, 0x80);
        break;
    case _GAME:
        rgblight_setrgb (0xFF, 0x00, 0xF0);
        break;
    case _MUSCTL:
        rgblight_setrgb (0x00, 0x40, 0x80);
        break;
    case _SONG:
        rgblight_setrgb (0xFF, 0x80, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0x00, 0x00);
        break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Activate Numpad layer
    case NUMPAD:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(on_short);
            #endif
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_KEEP);
            layer_off(_ADJUST);
            layer_on(_NUMPAD);
        }
        return false;
        break;
    
    // Exit numpad layer
    case EXT_NUM:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(off_short);
            #endif
            layer_off(_NUMPAD);
        }
        return false;
        break;

    // Go into mouse Mode
    case MOUSE:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_song);
            #endif
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_KEEP);
            layer_off(_ADJUST);
            layer_on(_MOUSE);
        }
        return false;
        break;

    // Exit Mouse mode
    case EXT_MSE:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(off_short);
            #endif
            layer_off(_MOUSE);
        }
        return false;
        break;

    // Music Mode on and activate Music layer
    case MU_ON:
        if (record->event.pressed) {
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_KEEP);
            layer_off(_ADJUST);
            layer_on(_MUSIC);
        }
        return true;
        break;

    // Turn MM of and return to default
    case MU_OFF:
        if (record->event.pressed) {
            layer_off(_MUSIC);
            layer_off(_MUSCTL);
        }
        return true;
        break;

    // enter Game mode
    case GAME:
        if (record->event.pressed) {
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_KEEP);
            layer_off(_ADJUST);
            layer_on(_GAME);
        }
        return false;
        break;

    // Exit Game Mode 
    case EXT_GME:
        if (record->event.pressed) {
            layer_off(_GAME);
        }
        return false;
        break;

    // Enter RGB Test control mode
    case LIGHT:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(test_long);
            #endif
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_KEEP);
            layer_off(_ADJUST);
            layer_on(_LIGHT);
        }
        return false;
        break;

    // Exit RGB control mode 
    case EXT_LGT:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(test_long);
            #endif
            layer_off(_LIGHT);
        }
        return false;
        break;

    // Songt test mode 
    case SONG:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(song_song);
            #endif
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_KEEP);
            layer_off(_ADJUST);
            layer_on(_SONG);
        }
        return false;
        break;

    // Exit song mode
    case EXT_SNG:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(song_song_end);
            #endif
            layer_off(_SONG);
        }
        return false;
        break;

    // color test buttons

    case xff8000:
        rgblight_setrgb (0xff, 0x80, 0x00);
        return false;
        break;

    case xffff00:
        rgblight_setrgb (0xff, 0xff, 0x00);
        return false;
        break;

    case x7fff00:
        rgblight_setrgb (0x7f, 0xff, 0x00);
        return false;
        break;

    case x00ff7f:
        rgblight_setrgb (0x00, 0x7f, 0xff);
        return false;
        break;

    case x007fff:
        rgblight_setrgb (0x00, 0x7f, 0xff);
        return false;
        break;

    case x00ffff:
        rgblight_setrgb (0x00, 0xff, 0xff);
        return false;
        break;

    case x8080ff:
        rgblight_setrgb (0x7f, 0x7f, 0xff);
        return false;
        break;

    case xc080ff:
        rgblight_setrgb (0xc0, 0x7f, 0xff);
        return false;
        break;

    case x4e019b:
        rgblight_setrgb (0x4e, 0x01, 0x9b);
        return false;
        break;

    case x0b019b:
        rgblight_setrgb (0x0b, 0x01, 0x9b);
        return false;
        break;

    case x144efc:
        rgblight_setrgb (0x14, 0x4e, 0xfc);
        return false;
        break;

    case x14c2fc:
        rgblight_setrgb (0x14, 0xc2, 0xfc);
        return false;
        break;

    case xeabe0e:
        rgblight_setrgb (0xea, 0xbe, 0x0e);
        return false;
        break;

    case x5e4d08:
        rgblight_setrgb (0x5e, 0x4d, 0x08);
        return false;
        break;

    case xd4fc76:
        rgblight_setrgb (0xd4, 0xfc, 0x76);
        return false;
        break;

    case x85ad1f:
        rgblight_setrgb (0x85, 0xad, 0x1f);
        return false;
        break;
  }
  return true;
}

