#include QMK_KEYBOARD_H
#include "version.h"

#define RGBLIGHT_COLOR_LAYER_0 RGB_CYAN     // MAC
#define RGBLIGHT_COLOR_LAYER_1 RGB_GOLD     // LIX
#define RGBLIGHT_COLOR_LAYER_2 RGB_MAGENTA  // WIN
#define RGBLIGHT_COLOR_LAYER_3 RGB_GREEN    // SYMB
#define RGBLIGHT_COLOR_LAYER_4 RGB_BLUE     // NUMB
#define RGBLIGHT_COLOR_LAYER_5 RGB_RED      // ARROW

enum layers {
    MAC,
    LIX,
    WIN,
    SYMB,
    NUMB,
    ARROW,
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: macOS layer
 *
 * ,--------------------------------------------------.                               ,--------------------------------------------------.
 * | LIX    |CLeft |CDown | CUp  |CRight| CmdR |  ESC |                               |  ESC |Termin| Prev | Play | Next | Exit |Backspac|
 * |--------+------+------+------+------+-------------|                               |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |Toggle|                               | Hyper|   Y  |   U  |   I  |   O  |   P  |   '    |
 * |--------+------+------+------+------+------|ARROW |                               |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|                               |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| MO   |                               | Meh  |------+------+------+------+------+--------|
 * | LSPO   |   Z  |   X  |   C  |   V  |   B  |ARROW |                               |      |   N  |   M  |   ,  |   .  |   /  | RSPC   |
 * `--------+------+------+------+------+-------------'                               `-------------+------+------+------+------+--------'
 *   | Del  |RGBTOG|RGBVAD| LOpt | LCmd |                                                           | RCmd | ROpt |RGBVAI|RGBTOG| Del  |
 *   `----------------------------------'                                                           `----------------------------------'
 *                                        ,-------------.                           ,-------------.
 *                                        |Lower |Space |                           | Mute |Raise |
 *                                 ,------+------+------|                           |------+------+------.
 *                                 |      |Raise | Copy |                           | Vol+ |Lower |      |
 *                                 |Backsp|      |------|                           |------|      |Space |
 *                                 |ace   | SYMB | Paste|                           | Vol- | NUMB |      |
 *                                 `--------------------'                           `--------------------'
 */
[MAC] = LAYOUT_ergodox_pretty(
  DF(LIX),  C(KC_LEFT), C(KC_DOWN), C(KC_UP), C(KC_RIGHT), G(KC_R), KC_ESC,         KC_ESC,  KC_F6, KC_MPRV, KC_MPLY, KC_MNXT, G(KC_Q), KC_BSPC,
  KC_TAB,   KC_Q,       KC_W,       KC_E,     KC_R,        KC_T,    TG(ARROW),      KC_HYPR, KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  KC_LCTRL, KC_A,       KC_S,       KC_D,     KC_F,        KC_G,                             KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSPO,  KC_Z,       KC_X,       KC_C,     KC_V,        KC_B,    MO(ARROW),      KC_MEH,  KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
  KC_DEL,   RGB_TOG,    RGB_VAD,    KC_LOPT,  KC_LCMD,                                              KC_RCMD, KC_ROPT, RGB_VAI, RGB_TOG, KC_DEL,
                                                         OSL(NUMB), KC_SPC,         KC_MUTE, OSL(SYMB),
                                                                    G(KC_C),        KC_VOLU,
                                                 KC_BSPC, MO(SYMB), G(KC_V),        KC_VOLD, MO(NUMB), KC_SPC
),
/* Keymap 1: Linux layer
 *
 * ,--------------------------------------------------.                 ,--------------------------------------------------.
 * | WIN    |  F1  |  F2  |  F3  |  F4  |  F5  |  ESC |                 |  ESC |Termin| Prev | Play | Next | Exit |Backspac|
 * |--------+------+------+------+------+-------------|                 |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |Toggle|                 | Hyper|   Y  |   U  |   I  |   O  |   P  |   '    |
 * |--------+------+------+------+------+------|ARROW |                 |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|                 |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| MO   |                 | Meh  |------+------+------+------+------+--------|
 * | LSPO   |   Z  |   X  |   C  |   V  |   B  |ARROW |                 |      |   N  |   M  |   ,  |   .  |   /  | RSPC   |
 * `--------+------+------+------+------+-------------'                 `-------------+------+------+------+------+--------'
 *   | Del  |RGBTOG|RGBVAD| LAlt | LGUI |                                             | RGUI | RAlt |RGBVAI|RGBTOG| Del  |
 *   `----------------------------------'                                             `----------------------------------'
 *                                        ,-------------.             ,-------------.
 *                                        |Lower |Space |             | Mute |Raise |
 *                                 ,------+------+------|             |------+------+------.
 *                                 |      |Raise | Copy |             | Vol+ |Lower |      |
 *                                 |Backsp|      |------|             |------|      |Space |
 *                                 |ace   | SYMB | Paste|             | Vol- | NUMB |      |
 *                                 `--------------------'             `--------------------'
 */
[LIX] = LAYOUT_ergodox_pretty(
  DF(WIN),  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5, KC_ESC,               KC_ESC,  LCA(KC_T), KC_MPRV, KC_MPLY, KC_MNXT, A(KC_F4), KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,  TG(ARROW),            KC_HYPR, KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,     KC_QUOT,
  KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                                 KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
  KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,  MO(ARROW),            KC_MEH,  KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC,
  KC_DEL,   RGB_TOG, RGB_VAD, KC_LALT, KC_LGUI,                                                 KC_RGUI, KC_RALT, RGB_VAI, RGB_TOG,  KC_DEL,
                                        OSL(NUMB), KC_SPC,               KC_MUTE, OSL(SYMB),
                                                   C(KC_C),              KC_VOLU,
                                KC_BSPC, MO(SYMB), C(KC_V),              KC_VOLD, MO(NUMB), KC_SPC
),
/* Keymap 2: Windows layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | MAC    |      |      |      |      |  F5  |  ESC |           |  ESC |      |      |      |      | Exit |Backspac|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LSPO   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RSPC   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Del  |      |      | LAlt | LWin |                                       | RWin | RAlt |      |      | Del  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Lower |Space |       | Mute |Raise |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |Raise |      |       | Vol+ |Lower |      |
 *                                 |Backsp|      |------|       |------|      |Space |
 *                                 |ace   | SYMB |      |       | Vol- | NUMB |      |
 *                                 `--------------------'       `--------------------'
 */
[WIN] = LAYOUT_ergodox_pretty(
  DF(MAC),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_ESC,            KC_ESC,  KC_F6, KC_MPRV, KC_MPLY, KC_MNXT, A(KC_F4), KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  TG(ARROW),         KC_HYPR, KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,     KC_QUOT,
  KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
  KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  MO(ARROW),         KC_MEH,  KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC,
  KC_DEL,   RGB_TOG, RGB_VAD, KC_LALT, KC_LWIN,                                           KC_RWIN, KC_RALT, RGB_VAI, RGB_TOG,  KC_DEL,
                                         OSL(NUMB), KC_SPC,            KC_MUTE, OSL(SYMB),
                                                    C(KC_C),           KC_VOLU,
                                 KC_BSPC, MO(SYMB), C(KC_V),           KC_VOLD, MO(NUMB), KC_SPC
),
/* Keymap 3: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   *  |   -  |   +  |      |      |           |      |      |      |   |  |   {  |   }  |   `    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |   [  |   ]  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |   _  |   =  |      |      |           |      |      |   ~  |      |      |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_ASTR, KC_MINS, KC_PLUS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_PIPE, KC_LCBR, KC_RCBR, KC_GRV,
  KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_EQL,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Number Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   *  |   -  |   +  |      |      |           |      |      |      |   |  |   {  |   }  |   `    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   _  |   =  |      |      |           |      |      |   ~  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMB] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_ASTR, KC_MINS, KC_PLUS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_PIPE, KC_LCBR, KC_RCBR, KC_GRV,
  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_EQL,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 5: Direction / Arrow keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  Up  |      |      |      |      |           |      |OpShL |OpShD |OpShU |OpShR |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Left | Down | Right|      |      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |CmShL |CmShD |CmShU |CmShR |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ARROW] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
};

/* Keymap X: Transparent Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/*
[TRANS] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case MAC:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case LIX:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case WIN:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case SYMB:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case NUMB:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case ARROW:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
