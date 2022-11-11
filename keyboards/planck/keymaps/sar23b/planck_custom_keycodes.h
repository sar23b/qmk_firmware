#ifndef PLANCK_CUSTOM_KEYCODES_H
#define PLANCK_CUSTOM_KEYCODES_H

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
  S_AZURE,
  S_BLUE,
  S_CHARTREUSE,
  S_CORAL,
  S_CYAN,
  S_GOLD,
  S_GOLDENROD,
  S_GREEN,
  S_MAGENTA,
  S_ORANGE,
  S_PINK,
  S_PURPLE,
  S_RED,
  S_SPRINGGREEN,
  S_TEAL,
  S_TURQUOISE,
  S_WHITE,
  S_YELLOW,
  S_OFF,
  S_DYELLOW, // dYellow
  S_LBLUE, // light blue 
  S_BWHITE, // bwhite 
  S_CWHITE, // cwhite
  S_GWHITE, // gwhite 
  S_CGREEN // cgreen   
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

#endif /*PLANCK_CUSTOM_KEYCODES_H*/
