#include QMK_KEYBOARD_H
#include "bootloader.h"
#include "lassebn.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY     0
#define _NAVIGATION 1
#define _NUMSYM     2
#define _FUNCTION   3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  NUMSYM,
  FUNCTION
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_______    KC_TRNS
#define KC_XXXXX     KC_NO
#define KC_NAV       NAV
#define KC_NUMSYM    NUMSYM
#define KC_FUNCTION  FUNCTION
#define KC_RST       RESET
#define KC_NUTAB     LT(_NUMSYM, KC_TAB)
#define KC_ALTBSP    ALT_T(KC_BSPC)
#define KC_NAVEQL    LT(_NAVIGATION, KC_EQL)
#define KC_SPCFUN    LT(_FUNCTION, KC_SPC)
#define KC_MC_HM     LGUI(KC_LEFT)
#define KC_MC_END    LGUI(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      LCTRL,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P, RCTRL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LGUI,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  RGUI,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                 ALTBSP, NUTAB,  ESC,     ENT  ,NAVEQL,SPCFUN \
                              //`--------------------'  `--------------------'
  )

  [_NAVIGATION] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     ______,______,______,______,______,______,                   PGUP, MC_HM,  UP  ,MC_END,______,______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     ______,______,______,______,______,______,                   PGDN,  LEFT,  DOWN, RIGHT,______,______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     ______,______,______,______,______,______,                 ______,______,______,______,______,______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                 ______,______,______,   ______,______,______ \
                              //`--------------------'  `--------------------'
  ),

  [_NUMSYM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     ______,______,  AT  , LCBR , RCBR , AMPR ,                  SLSH ,  7   ,  8   ,  9   ,______,______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     ______,______,  DLR , LPRN , RPRN , TILD ,                  PIPE ,  4   ,  5   ,  6   ,  DOT ,______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     ______,______, CIRC , LBRC , RBRC ,  GRV ,                  BSLS ,  1   ,  2   ,  3   ,  0   ,______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                 ______,______,______,   ______,______,______ \
                              //`--------------------'  `--------------------'
  ),

  [_FUNCTION] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     ______,______,  F9  , F10  , F11  , F12  ,                 ______, VOLD ,______, VOLU ,______,______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     ______,______,  F5  ,  F6  ,  F7  ,  F8  ,                 ______, MRWD , MPLY , MFFD ,______,______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     ______,______,  F1  ,  F2  ,  F3  ,  F4  ,                 ______,______,______,______,______,______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                 ______,______,______,   ______,______,______ \
                              //`--------------------'  `--------------------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
