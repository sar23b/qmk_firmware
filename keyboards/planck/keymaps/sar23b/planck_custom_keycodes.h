#include QMK_KEYBOARD_H

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
  // stage 2 layer
  _KEEP,
};

enum planck_keycodes {
  NUMPAD = SAFE_RANGE,
  EXT_NUM,
};


// some shortcuts for readabilty
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SUPENT LGUI_T(KC_ENT)
#define ADJUST MO(_ADJUST)

#endif /*PLANCK_CUSTOM_KEYCODES_H*/
