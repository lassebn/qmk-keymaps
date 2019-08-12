#include QMK_KEYBOARD_H
#include "muse.h"
#include "eeprom.h"
#include "lassebn.h"

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
  TOGGLE_LAYER_COLOR,
  EPRM,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_planck_grid_wrapper(
    LCTL_T(KC_TAB)   , _________________QWERTY_L1_________________         , _________________QWERTY_R1_________________               , RCTL_T(KC_BSPACE),
    LGUI_T(KC_ESCAPE), _________________QWERTY_L2_________________         , _________________QWERTY_R2_________________               , RGUI_T(KC_QUOTE),
    KC_LSHIFT        , _________________QWERTY_L3_________________         , _________________QWERTY_R3_________________               , KC_RSHIFT,
    KC_ESCAPE        , KC_LCTRL , KC_LALT , LALT_T(KC_LGUI) ,LOWER , LT(4,KC_SPACE) , KC_NO , RAISE , LALT_T(KC_LEFT) , KC_DOWN, KC_UP , KC_ENT),

  [_LOWER] = LAYOUT_planck_grid_wrapper(
    LCTL_T(KC_EXLM), _____________NUMS_AND_SYMS_L1______________, _____________NUMS_AND_SYMS_R1______________, RCTL_T(KC_DELETE),
    _______,         _____________NUMS_AND_SYMS_L2______________, _____________NUMS_AND_SYMS_R2______________, RGUI_T(KC_KP_MINUS),
    _______,         _____________NUMS_AND_SYMS_L3______________, _____________NUMS_AND_SYMS_R3______________, RSFT_T(KC_PLUS),
    _______,         ___________________BLANK___________________, KC_NO, _______, KC_0, _______, KC_EQUAL,     _______),

  [_RAISE] = LAYOUT_planck_grid_wrapper(
    _______, ________________FUNCTION_L1________________, ________________FUNCTION_R1________________, _______,
    _______, ________________FUNCTION_L2________________, ________________FUNCTION_R2________________, _______,
    _______, ________________FUNCTION_L3________________, ___________________BLANK___________________, _______,
    _______, _______, _______, _______, _______, _______, KC_NO, _______, _______, _______, _______,   _______),

  [_ADJUST] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, AU_ON,   AU_OFF,  AU_TOG,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, MU_ON,   MU_OFF,  MU_TOG,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,   _______, _______, _______, _______, RESET),

  [_LAYER4] = LAYOUT_planck_grid_wrapper(
    _______, ___________________BLANK___________________, _______________NAVIGATION_R1_______________, _______,
    _______, ___________________BLANK___________________, _______________NAVIGATION_R1_______________, _______,
    _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,_______, _______, _______, _______,    _______),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
    case RGB_SLD:
        return false;
}
return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
