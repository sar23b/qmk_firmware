#ifndef PLANCK_CODE_H
#define PLANCK_CODE_H

#include "custom_colors.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _KEEP);
    state = update_tri_layer_state(state, _ADJUST, _RAISE, _UNICODE);
    
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
        rgblight_setrgb (RGB_YELLOW);
        break;
    case _MOUSE:
        rgblight_setrgb (RGB_MAGENTA);
        break;
    case _UNICODE:
        rgblight_setrgb (RGB_GREEN);
        break;
    case _MUSIC:
        rgblight_setrgb (RGB_TEAL);
        break;
    case _GAME:
        rgblight_setrgb (RGB_MAGENTA);
        break;
    case _MUSCTL:
        rgblight_setrgb (RGB_BTEAL);
        break;
    case _SONG:
        rgblight_setrgb (RGB_DYELLOW);
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

    case S_DYELLOW:
        rgblight_setrgb (RGB_DYELLOW);
        return false;
        break;

    case S_LBLUE:
        rgblight_setrgb (RGB_LBLUE);
        return false;
        break;

    case S_BWHITE:
        rgblight_setrgb (RGB_BWHITE);
        return false;
        break;

    case S_CWHITE:
        rgblight_setrgb (RGB_CWHITE);
        return false;
        break;

    case S_GWHITE:
        rgblight_setrgb (RGB_GWHITE);
        return false;
        break;

    case S_CGREEN:
        rgblight_setrgb (RGB_CGREEN);
        return false;
        break;

    case S_AZURE:
        rgblight_setrgb (RGB_AZURE);
        return false;
        break;

    case S_BLUE:
        rgblight_setrgb (RGB_BLUE);
        return false;
        break;

    case S_CHARTREUSE:
        rgblight_setrgb (RGB_CHARTREUSE);
        return false;
        break;

    case S_CORAL:
        rgblight_setrgb (RGB_CORAL);
        return false;
        break;

    case S_CYAN:
        rgblight_setrgb (RGB_CYAN);
        return false;
        break;

    case S_GOLD:
        rgblight_setrgb (RGB_GOLD);
        return false;
        break;

    case S_GOLDENROD:
        rgblight_setrgb (RGB_GOLDENROD);
        return false;
        break;

    case S_GREEN:
        rgblight_setrgb (RGB_GREEN);
        return false;
        break;

    case S_MAGENTA:
        rgblight_setrgb (RGB_MAGENTA);
        return false;
        break;

    case S_ORANGE:
        rgblight_setrgb (RGB_ORANGE);
        return false;
        break;

    case S_PINK:
        rgblight_setrgb (RGB_PINK);
        return false;
        break;

    case S_PURPLE:
        rgblight_setrgb (RGB_PURPLE);
        return false;
        break;

    case S_RED:
        rgblight_setrgb (RGB_RED);
        return false;
        break;

    case S_SPRINGGREEN:
        rgblight_setrgb (RGB_SPRINGGREEN);
        return false;
        break;

    case S_TEAL:
        rgblight_setrgb (RGB_TEAL);
        return false;
        break;

    case S_TURQUOISE:
        rgblight_setrgb (RGB_TURQUOISE);
        return false;
        break;

    case S_WHITE:
        rgblight_setrgb (RGB_WHITE);
        return false;
        break;

    case S_YELLOW:
        rgblight_setrgb (RGB_YELLOW);
        return false;
        break;

    case S_OFF:
        rgblight_setrgb (RGB_OFF);
        return false;
        break;
  }
  return true;
}

#endif /* PLANCK_CODE_H */
