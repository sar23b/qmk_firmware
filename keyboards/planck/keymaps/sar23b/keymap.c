/* plack keymap 
 * numbers and moved keys on left mod
 * arrow keys on rigth mod
 * f keys and rgb controls on rigth bottom
 * numpad on toggle layer
 */

#include QMK_KEYBOARD_H
#include "muse.h"

#include "unicodemap.h"
#include "planck_custom_keycodes.h"
#include "planck_code.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Et(Gu)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Play |  GUI | Esc  | Alt  |Lower | Bksp | Spce |Raise | AltG | Mouse| Num  | Adju |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( 
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, SUPENT,
    SC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
    KC_MPLY, KC_LGUI, KC_ESC,  KC_LALT, LOWER,   KC_BSPC, KC_SPC,  RAISE,   KC_RALT, MOUSE,   NUMPAD,  ADJUST
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   '  |   [  |   ]  |   _  |   |  | XXXX |   =  |   +  |   -  | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   {  |   }  |   ~  | XXXX | XXXX |   "  | XXXX | XXXX | XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |      | XXXX |      |      |   `  |   `  |      |      | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( //missing keys
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_QUOT, KC_LBRC, KC_RBRC, KC_UNDS, KC_PIPE, XXXXXXX, KC_EQL,  KC_PLUS, KC_MINS, XXXXXXX, XXXXXXX,
    _______, KC_BSLS, KC_LCBR, KC_RCBR, KC_TILD, XXXXXXX, XXXXXXX, KC_DQUO, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, _______, XXXXXXX, _______, _______, KC_GRV,  KC_GRV,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | Next |  Up  | Prev | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Rigth| XXXX | XXXX | Left | Down |  Up  |Right | XXXX |  GUI |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Vol- | Vol+ | Mute | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | Disp+| Disp-|      |      | XXXX | XXXX |      | XXXX | XXXX | XXXX |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( //navigation
    XXXXXXX, KC_MPRV, KC_UP,   KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_LGUI,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, KC_BRID, KC_BRIU, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______
),

/* Keep (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | XXXX |  F1  |  F2  |  F3  |  F4  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  | XXXX | XXXX |  Del | Home |  pUP | XXXX | prSrc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 | XXXX | XXXX |  Ins |  End | pDown| XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |      | XXXX |      |      | XXXX | XXXX |      |      | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_KEEP] = LAYOUT_ortho_4x12(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_DEL,  KC_HOME, KC_PGUP, XXXXXXX, KC_PSCR,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_INS,  KC_END,  KC_PGDN, XXXXXXX, _______,
    XXXXXXX, _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust 
 * ,-----------------------------------------------------------------------------------.
 * | Music| Light| XXXX | XXXX | XXXX | XXXX | XXXX | Mode+| Mode-| XXXX | XXXX | Sleep|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Game | Song | XXXX | XXXX | XXXX | XXXX | Hue+ | Sat+ | Brt+ | Spd+ | XXXX | Wake |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | Hue- | Sat- | Brt- | Spd- | XXXX | Power|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | RGB  |      | AUD1 | AUD0 | Reset|      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12( //keeb control
    MU_ON,   LIGHT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_RMOD, XXXXXXX, XXXXXXX, KC_SLEP,
    GAME,    SONG,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI,  RGB_SPI, XXXXXXX, KC_WAKE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD,  RGB_SPD, XXXXXXX, KC_PWR,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_TOG, _______, AU_ON,    AU_OFF,  RESET,   _______
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * | Tab  | XXXX |   7  |   8  |   9  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |   *  |   4  |   5  |   6  |   +  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   /  |   1  |   2  |   3  |   -  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lock | XXXX | XXXX |   .  |   0  |  Ent |  Ent | XXXX | XXXX | XXXX | Exit | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12( 
    KC_TAB,  XXXXXXX, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_BSPC, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LNUM, XXXXXXX, XXXXXXX, KC_PDOT, KC_P0,   KC_PENT, KC_PENT, XXXXXXX, XXXXXXX, XXXXXXX, EXT_NUM, XXXXXXX
),

/* Mouse 
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  M3  |  MU  |  M2  |  MWU |  MWL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  ML  |  MD  |  MR  |  MWD |  MWR |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  M4  |  M5  | CUT  | COPY | PASTE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  M1  | Acl3 | Exit | Acl1 | Acl2 |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12( //mouse layer 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, KC_MS_U, KC_BTN2, KC_WH_U, KC_WH_L,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_WH_R,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, CUT,     COPY,    PASTE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_ACL0, EXT_MSE, KC_ACL1, KC_ACL2
),

/* Unicode
 * ,-----------------------------------------------------------------------------------.
 * | XXXX |  ⚧   |  ✨  |  🦄  |  🐛  |  🐧  | YYYY |  🐢  |  🪐  |  🌃  |  🌉  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | VS16 |  🌈  |  💜  |  ❄   |  🙃  |  🦕  |  🎁  |  🦋  |  🛰  |  🌠  |  🎆  | Entr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ZWJ |  🏳  |  💅  |  🌨  |  😶  |  🐍  | YYYY |  👾  |  🌌  |  🔥  |  🌆  | YYYY |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift| XXXX | XXXX |  🧇  | XXXX |  🐬  |  🐋  |      | XXXX | XXXX |  🌇  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UNICODE] = LAYOUT_ortho_4x12( //unicode char layer
    XXXXXXX, X(TRANS), X(GLITT),  X(UNICRN), X(CATPIL), X(PENGU),  XXXXXXX,  X(TURTLE), X(SATURN), X(NISTA), X(NBRI),   KC_BSPC,
    X(VS16), X(GAY),   X(PHEART), X(FLKE),   X(UPDF),   X(SAUWIA), X(GIFT),  X(BUTFLY), X(SAT),    X(STARS), X(FIRWRK), KC_ENT,
    X(ZWJ),  X(FLAG),  X(NAILS),  X(SNOW),   X(NMOF),   X(SNEK),   XXXXXXX,  X(ALIEN),  X(MIKWAY), X(LIT),   X(CDUSK),  XXXXXXX,
    KC_LSFT, XXXXXXX,  X(WAFLE),  XXXXXXX,   XXXXXXX,   X(DOLPI),  X(WHALE), _______,   XXXXXXX,   XXXXXXX,  X(SUNST),  _______
),

/* Music
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |MSCTRL|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_MUSIC] = LAYOUT_ortho_4x12( //Music map layer
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MSCTRL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Music control
 * ,-----------------------------------------------------------------------------------.
 * | Exit | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | CYCLE| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX |  REC | STOP | STOP | PLAY | FAST | SLOW | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_MUSCTL] = LAYOUT_ortho_4x12( //Music map control layer
    MU_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MI_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT, KC_LALT, KC_LGUI, KC_UP,   KC_DOWN, XXXXXXX, XXXXXXX
),

/* Game 
 * ,-----------------------------------------------------------------------------------.
 * | ESC  | Tab  |   Q  |   W  |   E  |   R  | XXXX | XXXX | XXXX | XXXX | XXXX | Play |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | Ctrl |   A  |   S  |   D  |   F  | XXXX |  Del | Home |  pUP | XXXX | Prev |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | Shift|   Z  |   X  |   C  |   V  | XXXX |  Ins |  End | pDown| XXXX | Next |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | Caps | XXXX | XXXX | Alt  | Spce | Spce | XXXX | XXXX | XXXX | XXXX | Exit |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_ortho_4x12( //layout for gaming
    KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY,
    XXXXXXX, KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   XXXXXXX, KC_DEL,  KC_HOME, KC_PGUP, XXXXXXX, KC_MPRV,
    XXXXXXX, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   XXXXXXX, KC_INS,  KC_END,  KC_PGDN, XXXXXXX, KC_MNXT,
    XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, KC_LALT, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EXT_GME 
),

/* RGB light test mode 
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | Exit |
 * `-----------------------------------------------------------------------------------'
 */
[_LIGHT] = LAYOUT_ortho_4x12( // mode to test out colors
    XXXXXXX, S_DYELLOW, S_LBLUE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       S_ORANGE, S_GOLDENROD, S_GOLD,  S_AZURE,      S_OFF,
    XXXXXXX, S_BWHITE,  S_CWHITE, XXXXXXX, XXXXXXX, XXXXXXX, S_RED,         S_PINK,   S_GREEN,     S_CYAN,  S_BLUE,       XXXXXXX,
    XXXXXXX, S_GWHITE,  S_CGREEN, XXXXXXX, XXXXXXX, XXXXXXX, S_SPRINGGREEN, S_PURPLE, S_MAGENTA,   S_CORAL, S_CHARTREUSE, XXXXXXX,
    XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       S_TEAL,   S_TURQUOISE, S_WHITE, S_YELLOW,     EXT_LGT 
),

/* Song test mode 
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | Exit |
 * `-----------------------------------------------------------------------------------'
 */
[_SONG] = LAYOUT_ortho_4x12( // testing songs
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EXT_SNG
)

/* Layout 
 * ,-----------------------------------------------------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 * /
[_LAYER] = LAYOUT_ortho_4x12( //generic layout
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
*/
};

