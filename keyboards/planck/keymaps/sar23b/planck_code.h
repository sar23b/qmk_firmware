#include QMK_KEYBOARD_H
#include "planck_custom_keycodes.h"

#ifndef PLANCK_CODE_H
#define PLANCK_CODE_H

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _KEEP);
    
    // set backlight based on active layer
    switch (get_highest_layer(state)) {
    case _RAISE:
        rgblight_setrgb (RGB_BLUE);
        break;
    case _LOWER:
        rgblight_setrgb (RGB_PURPLE);
        break;
    case _KEEP:
        rgblight_setrgb (RGB_CYAN);
        break;
    case _ADJUST:
        rgblight_setrgb (RGB_RED);
        break;
    case _NUMPAD:
        rgblight_setrgb (RGB_ORANGE);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (RGB_OFF);
        break;
    }
    return state;
}

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float on_short[][2] = SONG(STARTUP_SOUND);
  float off_short[][2] = SONG(GOODBYE_SOUND);
  float test_long[][2] = SONG(FANTASIE_IMPROMPTU);
  float song_song[][2] = SONG(PLANCK_SOUND);
  float song_song_end[][2] = SONG(PREONIC_SOUND);
#endif

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
    }

  return true;
}

#endif /* PLANCK_CODE_H */
