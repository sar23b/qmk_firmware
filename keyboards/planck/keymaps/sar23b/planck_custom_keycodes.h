#include QMK_KEYBOARD_H

#ifndef PLANCK_CUSTOM_KEYCODES_H
#define PLANCK_CUSTOM_KEYCODES_H

enum planck_layers {
  // basic layers
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  // stage 2 layer
  _KEEP,
};

enum planck_keycodes {
  ADJUST = SAFE_RANGE,
};


// some shortcuts for readabilty
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SUPENT LGUI_T(KC_ENT)

#endif /*PLANCK_CUSTOM_KEYCODES_H*/
