#define TAPPING_TERM 150

#define LAYOUT_atreus_grid_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

#define _______ KC_TRNS

#define ______________BLANK_______________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

/*
 * ,----------------------------------.                     ,----------------------------------.
 * |  Q   |   W  |   E  |   R  |   T  |                     |   Y  |   U  |   I  |   O  |   P  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |  A   |   S  |   D  |   F  |   G  |                     |   H  |   J  |   K  |   L  |   ;  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |  Z   |   X  |   C  |   V  |   B  |                     |   N  |   M  |   ,  |   .  |   /  |
 * `------+------+------+------+------´                     `------+------+------+------+------´
 */
#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

/*
 * ,----------------------------------.
 * | PgUp | Home |   Up |  End |      |
 * +------+------+------+------+------|
 * | PgDn | Left | Down | Right|      |
 * `------+------+------+------+------´
 */
#define ___________NAVIGATION_R1__________ KC_PGUP, LGUI(KC_LEFT), KC_UP,   LGUI(KC_RIGHT), KC_TRNS
#define ___________NAVIGATION_R2__________ KC_PGDN, KC_LEFT,       KC_DOWN, KC_RGHT,        KC_TRNS

/*
 * ,----------------------------------.                     ,----------------------------------.
 * |      |   @  |   {  |   }  |   &  |                     |   /  |   7  |   8  |   9  |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |   $  |   (  |   )  |   ~  |                     |   |  |   4  |   5  |   6  |   .  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * | SHFT |   ^  |   [  |   ]  |   `  |                     |   \  |   1  |   2  |   3  |   0  |
 * `------+------+------+------+------´                     `------+------+------+------+------´
 */
#define _________NUMS_AND_SYMS_L1_________ KC_TRNS,   KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR
#define _________NUMS_AND_SYMS_L2_________ KC_TRNS,   KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD
#define _________NUMS_AND_SYMS_L3_________ KC_LSHIFT, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV

#define _________NUMS_AND_SYMS_R1_________ KC_SLSH, KC_7,    KC_8,   KC_9,   KC_TRNS
#define _________NUMS_AND_SYMS_R2_________ KC_PIPE, KC_4,    KC_5,   KC_6,   GUI_T(KC_DOT)
#define _________NUMS_AND_SYMS_R3_________ KC_BSLS, KC_1,    KC_2,   KC_3,   KC_0

/*
 * ,----------------------------------.                     ,----------------------------------.
 * |      |  F9  |  F10 |  F11 |  F12 |                     |      | Vol v|      | Vol ^|      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |                     |      |M_prev| >||  |M_nxt |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |                     |      |      |      |      |      |
 * `------+------+------+------+------´                     `------+------+------+------+------´
*/
#define ____________FUNCTION_L1___________ KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12
#define ____________FUNCTION_L2___________ KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8
#define ____________FUNCTION_L3___________ KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4

#define ____________FUNCTION_R1___________ KC_TRNS, KC_VOLD, KC_TRNS, KC_VOLU, KC_TRNS
#define ____________FUNCTION_R2___________ KC_TRNS, KC_MRWD, KC_MPLY, KC_MFFD, KC_TRNS
