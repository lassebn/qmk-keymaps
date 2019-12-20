/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "lassebn.h"

enum layers {
    _QWERTY = 0,
    _NAV,
    _NUMSYM,
    _FUNCTION
};

#define NUTAB     LT(_NUMSYM, KC_TAB)
#define ALTBSP    ALT_T(KC_BSPC)
#define NAVEQL    LT(_NAV, KC_EQL)
#define SPCFUN    LT(_FUNCTION, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |RAIS/ESC|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |LShift|LShift|  |LShift|LShift|   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter| Space| Tab  | Bksp | AltGr|
 *                        |      |      | Alt  | Lower| Raise|  | Lower| Raise|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      _______, CTL_T(KC_Q), KC_W,    KC_E,     KC_R,    KC_T,                                     KC_Y,            KC_U,    KC_I,    KC_O,    CTL_T(KC_P),    _______,
      _______, GUI_T(KC_A), KC_S,    KC_D,     KC_F,    KC_G,                                     KC_H,            KC_J,    KC_K,    KC_L,    GUI_T(KC_SCLN), _______,
      _______, SFT_T(KC_Z), KC_X,    KC_C,     KC_V,    KC_B, _______, _______, _______, _______, KC_N,            KC_M,    KC_COMM, KC_DOT,  SFT_T(KC_SLSH), _______,
                                   _______, _______, _______, ALTBSP ,  NUTAB ,  NAVEQL, SPCFUN , _______, _______, _______
    ),

    [_NAV] = LAYOUT_kyria_grid_wrapper(
      _______, ______________BLANK_______________,                                     ___________NAVIGATION_R1__________, _______,
      _______, ______________BLANK_______________,                                     ___________NAVIGATION_R2__________, _______,
      _______, ______________BLANK_______________, _______, _______, _______, _______, ______________BLANK_______________, _______,
                                 _______, _______, _______, _______, _______,  _______,_______, _______, _______, _______
    ),

    [_NUMSYM] = LAYOUT_kyria_grid_wrapper(
      _______, _________NUMS_AND_SYMS_L1_________,                                     _________NUMS_AND_SYMS_R1_________, _______,
      _______, _________NUMS_AND_SYMS_L2_________,                                     _________NUMS_AND_SYMS_R2_________, _______,
      _______, _________NUMS_AND_SYMS_L3_________, _______, _______, _______, _______, _________NUMS_AND_SYMS_R3_________, _______,
                                 _______, _______, _______, _______, _______, _______,   KC_0 , KC_DOT, KC_EQL, _______
    ),

    [_FUNCTION] = LAYOUT_kyria_grid_wrapper(
      _______, ____________FUNCTION_L1___________,                                     ____________FUNCTION_R1___________, _______,
      _______, ____________FUNCTION_L2___________,                                     ____________FUNCTION_R2___________, _______,
      _______, ____________FUNCTION_L3___________, _______, _______, _______, _______, ______________BLANK_______________, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _NUMSYM, _FUNCTION);
}

