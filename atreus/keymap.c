#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Note that whatever is set as layer 0 will be the default layer of the keyboard.

#define _QW 0 // QWERTY
#define _MW 1 // Mouse and windown management
#define _EX 2 // Extend
#define _NU 3 // Numpad
#define _FN 4 // Function

// Some quick aliases, just to make it look pretty
#define _______ KC_TRNS
#define KCX_LST LSFT(KC_TAB)
#define KX_COPY LGUI(KC_C)
#define KX_CUT  LGUI(KC_X)
#define KX_PAST LGUI(KC_V)
#define KX_UNDO LGUI(KC_Z)

#define _USER 0 // User macro

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base layer
 *
 * ,----------------------------------.                     ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                     |   Y  |   U  |   I  |   O  |   P  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |Ctrl A|   S  |   D  |   F  |   G  |                     |   H  |   J  |   K  |   L  |GUI  ;|
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |Z Shft|   X  |   C  |   V  |   B  | ,------.   ,------. |   N  |   M  |   ,  |   .  |/ Shft|
 * +------+------+------+------+------| | _NU  |   |  _EX | +------+------+------+------+------|
 * |  Esc |  Alt |  Tab |  _MW |Alt/Bs| | TAB  |   |  `   | |Sp/_FN| GUI  |   -  |   '  | Enter|
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */
[_QW] = LAYOUT( /* Qwerty */
  KC_Q,        KC_W,    KC_E,    KC_R,    KC_T,                                             KC_Y,            KC_U,    KC_I,    KC_O,    KC_P,
  CTL_T(KC_A), KC_S,    KC_D,    KC_F,    KC_G,                                             KC_H,            KC_J,    KC_K,    KC_L,    GUI_T(KC_SCLN),
  SFT_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,                                             KC_N,            KC_M,    KC_COMM, KC_DOT,  SFT_T(KC_SLSH),
  KC_ESC,      KC_LALT, KC_TAB,  MO(_MW), ALT_T(KC_BSPC), LT(_NU, KC_TAB), LT(_EX, KC_GRV), LT(_FN, KC_SPC), KC_LGUI, KC_MINS, KC_QUOT, KC_ENT
),

/*
 * Extend / Edit
 *
 *
 * ,----------------------------------.                     ,----------------------------------.
 * |      |      |      |      |      |                     | PgUp | Home |   Up |  End |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |  Alt | Ctrl |      |                     | PgDn | Left | Down | Right|      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |  Cut | Copy |Paste |      | ,------.   ,------. |      |      |      |      |      |
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |      |      |      |      |      | |XXXXXX|   |      | | Space|      |      |      |      |
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */
[_EX] = LAYOUT( /* Extend */
  _______, _______, _______, _______, _______,                    KC_PGUP, LGUI(KC_LEFT), KC_UP,   LGUI(KC_RIGHT),  _______,
  _______, _______, KC_LALT, KC_LCTL, _______,                    KC_PGDN, KC_LEFT,       KC_DOWN, KC_RGHT,         _______,
  _______, KX_CUT,  KX_COPY, KX_PAST, _______,                    _______, _______,       _______,  _______,        _______,
  _______, _______, _______, _______, _______, _______,  _______, KC_SPC,  _______,       _______, _______,         _______
),

/*
 * Numbers and symbols
 *
 * ,----------------------------------.                     ,----------------------------------.
 * |   !  |   @  |   {  |   }  |   &  |                     |   /  |   7  |   8  |   9  |   *  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |   #  |   $  |   (  |   )  |   ~  |                     |   |  |   4  |   5  |   6  |   -  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |   %  |   ^  |   [  |   ]  |   `  | ,------.   ,------. |   \  |   1  |   2  |   3  |   +  |
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |      |  _MW |      |      |      | |      |   |XXXXXX| |      |   0  |   .  |   =  |      |
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */
[_NU] = LAYOUT( /* Numbers and symbols */
  KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR,                           KC_SLSH, KC_7,    KC_8,   KC_9,   KC_ASTR,
  CTL_T(KC_HASH), KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                    KC_PIPE, KC_4,    KC_5,   KC_6,   GUI_T(KC_MINS),
  SFT_T(KC_PERC), KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV,                     KC_BSLS, KC_1,    KC_2,   KC_3,   SFT_T(KC_PLUS),
  _______, TG(_MW), _______, _______, _______, _______,  _______, _______, KC_0,    KC_DOT, KC_EQL, _______
),

/*
 * Functions
 *
 * ,----------------------------------.                     ,----------------------------------.
 * |      |  F9  |  F10 |  F11 |  F12 |                     | _USER| Vol v|      | Vol ^|      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |                     |      |M_prev| >||  |M_nxt |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  | ,------.   ,------. |      |      |      |      |      |
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |      |      |      |      |      | |      |   |      | |XXXXXX|      |      |      | RESET|
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */
[_FN] = LAYOUT( /* Functions */
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,                    M(_USER),KC_VOLD, _______, KC_VOLU, _______,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,                     _______, KC_MRWD, KC_MPLY, KC_MFFD, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,                     _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
),

/*
 * Mouse and window management
 *
 * ,----------------------------------.                     ,----------------------------------.
 * |      |      |      |      |      |                     |      |Whl Up|  MUp |Whl Dn|      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |      |      |      |                     |      | MLeft| MDown|MRight|      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |      |      |      | ,------.   ,------. |MClick|      |      |      |      |
 * +------+------+------+------+------| |      |   |LClick| +------+------+------+------+------|
 * |      |  _MW |      |      |      | |      |   |      | |RClick|      |      |      |      |
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */
[_MW] = LAYOUT( /* Mouse and window management */
  _______, LCTL(LGUI(KC_LEFT)),    LALT(LGUI(KC_UP)),   LCTL(LGUI(KC_RIGHT)),    _______,           _______, KC_WH_U, KC_MS_U, KC_WH_D, _______,
  _______, LALT(LGUI(KC_LEFT)),    LALT(LGUI(KC_F)),    LALT(LGUI(KC_RIGHT)),    _______,           _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
  _______, S(LCTL(LGUI(KC_LEFT))), LALT(LGUI(KC_DOWN)), S(LCTL(LGUI(KC_RIGHT))),                    KC_BTN3, _______, _______, KC_MS_D, _______, _______,
  _______, TG(_MW),                _______,             _______,                 _______,  _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______
)};

/*
 * Template
 *
 * ,----------------------------------.                     ,----------------------------------.
 * |      |      |      |      |      |                     |      |      |      |      |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |      |      |      |                     |      |      |      |      |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |      |      |      | ,------.   ,------. |      |      |      |      |      |
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |      |      |      |      |      | |      |   |      | |      |      |      |      |      |
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case _USER:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
