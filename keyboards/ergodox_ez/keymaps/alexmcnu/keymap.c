#include QMK_KEYBOARD_H
#include "version.h"

#define _______ KC_TRNS
#define WS_LEFT LGUI(LCTL(KC_LEFT))
#define WS_RGHT LGUI(LCTL(KC_RIGHT))

enum layers {
    BASE, // default layer
    FUNC, // fn layer
    GAME, // gaming layer
    SYMB, // special layer (from default layout)
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD,
  __UND__,
  MD_BOOT,
  MAC_ACC,
  MAC_2AC,
  SUP_TAB,
};

// Change lighting on layer
// Change lighting on Caps
// Test media keys
// Mic mute button
// Implement game layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap BASE: Basic layer
  *
  * ,--------------------------------------------------.                            ,--------------------------------------------------.
  * |  `/~   |   1  |   2  |   3  |   4  |   5  |      |                            |      |   6  |   7  |   8  |   9  |   0  |  BkSp  |
  * |--------+------+------+------+------+-------------|                            |------+------+------+------+------+------+--------|
  * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  _   |                            |      |   Y  |   U  |   I  |   O  |   P  |  \ |   |
  * |--------+------+------+------+------+------|(UNDR)|                            |      |------+------+------+------+------+--------|
  * |  Esc   |   A  |   S  |   D  |   F  |   G  |------|                            |------|   H  |   J  |   K  |   L  |  ;   |  ' "   |
  * |--------+------+------+------+------+------|  -   |                            |      |------+------+------+------+------+--------|
  * | LShift |   Z  |   X  |   C  |   V  |   B  |(HYPH)|                            |      |   N  |   M  |   ,  |   .  | / ?  | RShift |
  * `--------+------+------+------+------+-------------'                            `-------------+------+------+------+------+--------'
  *   |  = + | SYMB | FUNC | PWksp| NWksp|                                                        | Mute | Menu | Lock |      | EXTR |
  *   `----------------------------------'                                                        `----------------------------------'
  *                                        ,-------------.                        ,-------------.
  *                                        | GAME |      |                        | Acc  | 2ac  |
  *                                 ,------|------|------|                        |------+--------+------.
  *                                 |      |      |      |                        | Caps |        |      |
  *                                 | LCtrl| LAlt |------|                        |------|  FUNC  | Spc  |
  *                                 |      |      | LWin |                        | Entr |        |      |
  *                                 `--------------------'                        `----------------------'
  */
  [BASE] = LAYOUT_ergodox_pretty(
    KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,     __UND__,             __UND__, KC_6,         KC_7,    KC_8,       KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,     LSFT(KC_MINS),       __UND__, KC_Y,         KC_U,    KC_I,       KC_O,    KC_P,    KC_BSLS,
    KC_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,                                   KC_H,         KC_J,    KC_K,       KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,     KC_MINS,             __UND__, KC_N,         KC_M,    KC_COMM,    KC_DOT,  KC_SLSH, KC_RSFT,
    KC_EQL,  MO(SYMB), MO(FUNC), WS_LEFT, WS_RGHT,                                         LGUI(KC_APP), KC_APP,  RGUI(KC_L), _______, MO(SYMB),
                                                   TG(GAME), __UND__,             MAC_ACC, MAC_2AC,
                                                             __UND__,             KC_CAPS,
                                          KC_LCTL, KC_LALT,  KC_LGUI,             KC_ENT,  MO(FUNC), KC_SPC
  ),

  // Add menu key
  /* Keymap FUNC: General function layer
  *
  * ,--------------------------------------------------.                                        ,--------------------------------------------------.
  * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |                                        |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
  * |--------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+--------|
  * | 4_spc  |      |      |Ctrl->|      |      |      |                                        |      |      |      |      | Home | Play |   F12  |
  * |--------+------+------+------+------+------|      |                                        |      |------+------+------+------+------+--------|
  * |  Caps  | End  |      |      |      |      |------|                                        |------| Left | Down |  Up  |Right |      |        |
  * |--------+------+------+------+------+------|      |                                        |      |------+------+------+------+------+--------|
  * |        |      | Del  |      |      |Ctrl<-|      |                                        |      |      |      |      |      |      |        |
  * `--------+------+------+------+------+-------------'                                        `-------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                                                    | Prev |VolDn |VolUp | Next |      |
  *   `----------------------------------'                                                                    `----------------------------------'
  *                                        ,-------------.                                    ,-------------.
  *                                        |      |      |                                    |      |      |
  *                                 ,------|------|------|                                    |------+------+------.
  *                                 |      |      |      |                                    |      |      |      |
  *                                 |      |      |------|                                    |------|      |      |
  *                                 |      |      |      |                                    |      |      |      |
  *                                 `--------------------'                                    `--------------------'
  */
  [FUNC] = LAYOUT_ergodox_pretty(
    _______,   KC_F1,   KC_F2, KC_F3,         KC_F4,         KC_F5,         _______,          _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
    SUP_TAB, _______, _______, LCTL(KC_RGHT), _______,       _______,       _______,          _______, _______, _______, KC_HOME, _______,  KC_MPLY, KC_F12,
    KC_CAPS, KC_END,  _______, KC_LBRC,       KC_RBRC,       _______,                                  KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______, _______,
    _______, _______, KC_DEL,  LSFT(KC_LBRC), LSFT(KC_RBRC), LCTL(KC_LEFT), _______,          _______, _______, _______, _______, _______,  _______, _______,
    _______, _______, _______, _______,       _______,                                                 KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,  _______,
                                                             _______,       _______,          _______, _______,
                                                                            _______,          _______,
                                              _______,       _______,       _______,          _______, _______, _______
  ),

  /* Keymap GAME: Modified Left hand to be playable in games
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
  *   | LCtrl|      |      |      |      |                                       |      |      |      |      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 | Space|      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */

  [GAME] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                 _______, _______,     _______, _______,
                                                          _______,     _______,
                                         KC_SPC, _______, _______,     _______, _______, _______
  ),

  /* Keymap SYMB: Symbol Layer, unchanged from default SYMB layer
  *
  * ,---------------------------------------------------.           ,--------------------------------------------------.
  * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | Boot |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
  * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
  * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
  * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
  * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
  * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
  *   `-----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |Animat|      |       |Toggle|Solid |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
  *                                 |ness- |ness+ |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [SYMB] = LAYOUT_ergodox_pretty(
    VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     MD_BOOT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,     _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,               KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,     _______, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
    EEP_RST, _______, _______, _______, _______,                                         _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                                 RGB_MOD, _______,     RGB_TOG, RGB_SLD,
                                                          _______,     _______,
                                        RGB_VAD, RGB_VAI, _______,     _______, RGB_HUD, RGB_HUI
  ),
};

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
      case MD_BOOT:
        if (record->event.pressed) {
          reset_keyboard();
        }
        return false;
      case MAC_ACC:
        send_string("acc\notter");
        return false;
      case MAC_2AC:
        send_string("2ac\ntail");
        return false;
      case SUP_TAB:
        send_string("    ");
        return false;
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
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
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
