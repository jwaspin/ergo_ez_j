#include QMK_KEYBOARD_H
#include "version.h"

#define RGBLIGHT_COLOR_LAYER_0 RGB_CYAN     // MAC
#define RGBLIGHT_COLOR_LAYER_1 RGB_GOLD     // LIX
#define RGBLIGHT_COLOR_LAYER_2 RGB_PURPLE   // WIN
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
 * ,--------------------------------------------------.                 ,--------------------------------------------------.
 * | DEL    |CLeft |CDown | CUp  |CRight| CmdR |  ESC |                 |  ESC |  F6  | Prev | Play | Next |  F10 |Backspac|
 * |--------+------+------+------+------+-------------|                 |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |Toggle|                 |Toggle|   Y  |   U  |   I  |   O  |   P  | Enter  |
 * |--------+------+------+------+------+------|Lower |                 |Raise |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|                 |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|Space |                 |      |------+------+------+------+------+--------|
 * | LSPO   |   Z  |   X  |   C  |   V  |   B  |      |                 |      |   N  |   M  |   ,  |   .  |   /  | RSPC   |
 * `--------+------+------+------+------+-------------'                 `-------------+------+------+------+------+--------'
 *   | ESC  |      |      | LOpt | LCmd |                                             | RCmd | ROpt |      |      | ESC  |
 *   `----------------------------------'                                             `----------------------------------'
 *                                        ,-------------.             ,-------------.
 *                                        |Enter | LIX  |             | Mute |      |
 *                                 ,------+------+------|             |------+------+------.
 *                                 |      |Raise | WIN  |             | Vol+ |Lower |      |
 *                                 |Backsp|      |------|             |------|      |Space |
 *                                 |ace   | SYMB |ARROW |             | Vol- | NUMB |      |
 *                                 `--------------------'             `--------------------'
 */
[MAC] = LAYOUT_ergodox_pretty(
  KC_DEL,   C(KC_LEFT), C(KC_DOWN), C(KC_UP), C(KC_RIGHT),  G(KC_R), KC_ESC,        KC_ESC,   KC_F6, KC_MPRV, KC_MPLY, KC_MNXT, KC_F10,  KC_BSPC,
  KC_TAB,   KC_Q,       KC_W,       KC_E,     KC_R,         KC_T,    TG(NUMB),      TG(SYMB), KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
  KC_LCTRL, KC_A,       KC_S,       KC_D,     KC_F,         KC_G,                             KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSPO,  KC_Z,       KC_X,       KC_C,     KC_V,         KC_B,    KC_SPC,        KC_MEH,   KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
  KC_ESC,   RGB_TOG,    RGB_TOG,    KC_LOPT,  KC_LCMD,                                               KC_RCMD, KC_ROPT, RGB_TOG, RGB_TOG, KC_ESC,
                                                            KC_ENT, TG(LIX),        KC_MUTE,  KC_MEH,
                                                                    TG(WIN),        KC_VOLU,
                                                 KC_BSPC, MO(SYMB), MO(ARROW),      KC_VOLD,  MO(NUMB), KC_SPC
),
/* Keymap 1: Linux layer
 *
 * ,--------------------------------------------------.                 ,--------------------------------------------------.
 * | DEL    |  F1  |  F2  |  F3  |  F4  |  F5  |  ESC |                 |  ESC |  F6  |  F7  |  F8  |  F9  | F10  |Backspac|
 * |--------+------+------+------+------+-------------|                 |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |Toggle|                 |Toggle|   Y  |   U  |   I  |   O  |   P  | Enter  |
 * |--------+------+------+------+------+------|Lower |                 |Raise |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|                 |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|Space |                 |      |------+------+------+------+------+--------|
 * | LSPO   |   Z  |   X  |   C  |   V  |   B  |      |                 |      |   N  |   M  |   ,  |   .  |   /  | RSPC   |
 * `--------+------+------+------+------+-------------'                 `-------------+------+------+------+------+--------'
 *   | ESC  |      |      | LAlt | LGUI |                                             | RGUI | RAlt |      |      | ESC  |
 *   `----------------------------------'                                             `----------------------------------'
 *                                        ,-------------.             ,-------------.
 *                                        |Enter |XXXXXX|             | Mute |      |
 *                                 ,------+------+------|             |------+------+------.
 *                                 |      |Raise |      |             | Vol+ |Lower |      |
 *                                 |Backsp|      |------|             |------|      |Space |
 *                                 |ace   | SYMB |ARROW |             | Vol- | NUMB |      |
 *                                 `--------------------'             `--------------------'
 */
[LIX] = LAYOUT_ergodox_pretty(
  KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5, KC_ESC,              KC_ESC,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,  TG(NUMB),            TG(SYMB), KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,     KC_ENT,
  KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                                 KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,  KC_SPC,              KC_MEH,   KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC,
  KC_ESC,   RGB_TOG, RGB_TOG, KC_LALT, KC_LGUI,                                                 KC_RGUI, KC_RALT, RGB_TOG, RGB_TOG,  KC_ESC,
                                           KC_ENT, KC_TRNS,              KC_MUTE, KC_MEH,
                                                   KC_MEH,               KC_VOLU,
                                KC_BSPC, MO(SYMB), MO(ARROW),            KC_VOLD, MO(NUMB), KC_SPC
),
/* Keymap 2: Windows layer
 *
 * ,--------------------------------------------------.                 ,--------------------------------------------------.
 * | DEL    |  F1  |  F2  |  F3  |  F4  |  F5  |  ESC |                 |  ESC |  F6  |  F7  |  F8  |  F9  | F10  |Backspac|
 * |--------+------+------+------+------+-------------|                 |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |Toggle|                 |Toggle|   Y  |   U  |   I  |   O  |   P  | Enter  |
 * |--------+------+------+------+------+------|Lower |                 |Raise |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|                 |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|Space |                 |      |------+------+------+------+------+--------|
 * | LSPO   |   Z  |   X  |   C  |   V  |   B  |      |                 |      |   N  |   M  |   ,  |   .  |   /  | RSPC   |
 * `--------+------+------+------+------+-------------'                 `-------------+------+------+------+------+--------'
 *   | ESC  |      |      | LAlt | LWin |                                             | RWin | RAlt |      |      | ESC  |
 *   `----------------------------------'                                             `----------------------------------'
 *                                        ,-------------.             ,-------------.
 *                                        |Enter |      |             | Mute |      |
 *                                 ,------+------+------|             |------+------+------.
 *                                 |      |Raise |XXXXXX|             | Vol+ |Lower |      |
 *                                 |Backsp|      |------|             |------|      |Space |
 *                                 |ace   | SYMB |ARROW |             | Vol- | NUMB |      |
 *                                 `--------------------'             `--------------------'
 */
[WIN] = LAYOUT_ergodox_pretty(
  KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_ESC,              KC_ESC,   KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  TG(NUMB),            TG(SYMB), KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,     KC_ENT,
  KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_SPC,              KC_MEH,   KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC,
  KC_ESC,   RGB_TOG, RGB_TOG, KC_LALT, KC_LWIN,                                              KC_RWIN, KC_RALT, RGB_TOG, RGB_TOG,  KC_ESC,
                                            KC_ENT, KC_MEH,            KC_MUTE, KC_MEH,
                                                    KC_TRNS,           KC_VOLU,
                                 KC_BSPC, MO(SYMB), MO(ARROW),         KC_VOLD, MO(NUMB), KC_SPC
),
/* Keymap 3: Symbol Layer (Raise)
 *
 * ,---------------------------------------------------.                ,--------------------------------------------------.
 * |         |   ^  |   &  |   *  |   [  |   ]  |      |                |      |   !  |   @  |   #  |   $  |   %  |        |
 * |---------+------+------+------+------+------+------|                |------+------+------+------+------+------+--------|
 * |         |      |   *  |   -  |   +  |   ~  |  {   |                |XXXXXX|      |      |   |  |   {  |   }  |        |
 * |---------+------+------+------+------+------|      |                |XXXXXX|------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |------|                |------|   ^  |   &  |   *  |   [  |   ]  |   `    |
 * |---------+------+------+------+------+------|  }   |                |      |------+------+------+------+------+--------|
 * |         |      |      |   _  |   =  |   |  |      |                |      |      |   ~  |      |      |   \  |        |
 * `---------+------+------+------+------+-------------'                `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                            |      |      |      |      |      |
 *   `-----------------------------------'                                            `----------------------------------'
 *                                        ,-------------.             ,-------------.
 *                                        |      |      |             |      |      |
 *                                 ,------|------|------|             |------+------+------.
 *                                 |      |XXXXXX|      |             |      |      |      |
 *                                 |      |XXXXXX|------|             |------|      |      |
 *                                 |      |XXXXXX|      |             |      |      |      |
 *                                 `--------------------'             `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_TRNS,     KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_ASTR, KC_MINS, KC_PLUS, KC_TILD, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_PIPE, KC_LCBR, KC_RCBR, KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_GRV,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_EQL,  KC_PIPE, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Number Layer (Lower)
 *
 * ,--------------------------------------------------.                 ,--------------------------------------------------.
 * |        |   6  |   7  |   8  |   9  |   0  |      |                 |      |   1  |   2  |   3  |   4  |   5  |        |
 * |--------+------+------+------+------+-------------|                 |------+------+------+------+------+------+--------|
 * |        |      |   *  |   -  |   +  |   ~  |XXXXXX|                 |      |      |      |   |  |   {  |   }  |        |
 * |--------+------+------+------+------+------|XXXXXX|                 |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|                 |------|   6  |   7  |   8  |   9  |   0  |   `    |
 * |--------+------+------+------+------+------|      |                 |      |------+------+------+------+------+--------|
 * |        |      |      |   _  |   =  |   |  |      |                 |      |      |   ~  |      |      |      |        |
 * `--------+------+------+------+------+-------------'                 `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                             |      |      |      |      |      |
 *   `----------------------------------'                                             `----------------------------------'
 *                                        ,-------------.             ,-------------.
 *                                        |      |      |             |      |      |
 *                                 ,------|------|------|             |------+------+------.
 *                                 |      |      |      |             |      |XXXXXX|      |
 *                                 |      |      |------|             |------|XXXXXX|      |
 *                                 |      |      |      |             |      |XXXXXX|      |
 *                                 `--------------------'             `--------------------'
 */
[NUMB] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,     KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_ASTR, KC_MINS, KC_PLUS, KC_TILD, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_PIPE, KC_LCBR, KC_RCBR, KC_TRNS,
  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_EQL,  KC_PIPE, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 5: Arrow Layer
 *
 * ,--------------------------------------------------.                 ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                 |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|                 |------+------+------+------+------+------+--------|
 * |        |      |  Up  |      |      |      |      |                 |      |Opt-L |Opt-D |Opt-U |Opt-R |      |        |
 * |--------+------+------+------+------+------|      |                 |      |------+------+------+------+------+--------|
 * |        | Left | Down | Right|      |      |------|                 |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |                 |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                 |      |Cmd-L |Cmd-D |Cmd-U |Cmd-R |      |        |
 * `--------+------+------+------+------+-------------'                 `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                             |      |      |      |      |      |
 *   `----------------------------------'                                             `----------------------------------'
 *                                        ,-------------.             ,-------------.
 *                                        |      |      |             |      |      |
 *                                 ,------|------|------|             |------+------+------.
 *                                 |      |      |      |             |      |      |      |
 *                                 |      |      |------|             |------|      |      |
 *                                 |      |      |XXXXXX|             |      |      |      |
 *                                 `--------------------'             `--------------------'
 */
[ARROW] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, A(KC_LEFT), A(KC_DOWN), A(KC_UP),   A(KC_RGHT), KC_TRNS, KC_TRNS,
  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,                       KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, G(KC_LEFT), G(KC_DOWN), G(KC_UP),   G(KC_RGHT), KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,

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
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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
