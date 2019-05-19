#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

int keycode_to_led(uint16_t kc);
int update_heatmap_led_val(uint16_t kc);
void led_set_solid(int color_r, int color_g, int color_b);

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  TOGGLE_LAYER_COLOR,
  EPRM,
  HSV_172_255_255,
  HSV_86_255_128,
  HSV_27_255_255,
  CUSTOM_LOGIN,
  CUSTOM_BYPASS_INSECURE,
  CUSTOM_RESET_KB,
};

bool CAPS_ON = 0;
const uint8_t PROGMEM capsmap[DRIVER_LED_TOTAL][3] = {
  {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {235,255,255}, {235,255,255}, {235,255,255}, {235,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {235,255,255}, {235,255,255}, {235,255,255}, {235,255,255},
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,
                       KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_UNDS,
                       KC_ESCAPE,KC_A,KC_S,KC_D,KC_F,KC_G,
                       KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_MINUS,
                       KC_EQUAL,KC_LCTRL,KC_LGUI,KC_LALT,LALT(KC_LCTRL),
                       CUSTOM_LOGIN,CUSTOM_BYPASS_INSECURE,KC_TRANSPARENT,KC_LCTRL,KC_LALT,KC_LGUI,

                       KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPACE,
                       KC_DQUO,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,
                       KC_H,KC_J,KC_K,KC_L,LT(3,KC_SCOLON),KC_QUOTE,
                       KC_QUOTE,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,
                       RGUI(KC_RALT),KC_RALT,KC_RGUI,KC_RCTRL,MO(2),
                       KC_TRANSPARENT,TG(4),KC_CAPSLOCK,KC_QUOTE,LT(1,KC_ENTER),KC_SPACE),

  [1] = LAYOUT_ergodox(KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
                       KC_TRANSPARENT,LCTL(KC_PGUP),LCTL(KC_PGDOWN),LCTL(KC_RIGHT),KC_INSERT,KC_UNDS,KC_TRANSPARENT,
                       KC_CAPSLOCK,KC_END,KC_TRANSPARENT,KC_LBRACKET,KC_RBRACKET,KC_MINUS,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_DELETE,KC_LCBR,KC_RCBR,LCTL(KC_LEFT),KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                       
                       KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,
                       LSFT(KC_LBRACKET),KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_TRANSPARENT,KC_TRANSPARENT,KC_F12,
                       KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,
                       LSFT(KC_RBRACKET),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [2] = LAYOUT_ergodox(CUSTOM_RESET_KB,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_SYSTEM_SLEEP,KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,KC_TRANSPARENT,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRANSPARENT,KC_SYSTEM_POWER,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGB_MOD,HSV_172_255_255,HSV_86_255_128,RGB_VAD,RGB_VAI,HSV_27_255_255,KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRANSPARENT,KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_F12,KC_DOWN,KC_4,KC_5,KC_6,KC_PLUS,KC_TRANSPARENT,KC_TRANSPARENT,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_DOT,KC_0,KC_EQUAL,KC_TRANSPARENT,RGB_TOG,RGB_SLD,KC_TRANSPARENT,KC_TRANSPARENT,RGB_HUD,RGB_HUI),

  [3] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,KC_MS_RIGHT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_WWW_BACK),

  [4] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_ENTER,KC_LCTRL,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;
bool disable_layer_color = 0;
long total_keypresses = 0;
long heatmap_vals[48] = {0};


void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {183,255,255}, {183,255,255}, {183,255,255}, {183,255,255}, {183,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {235,255,255}, {235,255,255}, {235,255,255}, {235,255,255}, {183,255,255}, {183,255,255}, {183,255,255}, {183,255,255}, {183,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {206,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {220,255,255}, {235,255,255}, {235,255,255}, {235,255,255}, {235,255,255} },

    // [1] = { {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255}, {217,255,255} },

    // [2] = { {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255}, {96,255,255} },

    // [3] = { {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255}, {170,254,255} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {202,255,255}, {202,255,255}, {243,222,234}, {202,255,255}, {202,255,255}, {202,255,255}, {243,222,234}, {243,222,234}, {243,222,234}, {202,255,255}, {202,255,255}, {202,255,255}, {202,255,255}, {202,255,255}, {202,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        if (CAPS_ON) {
          rgb_matrix_set_color( i, 255, 255, 255);
        } else {
          rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
        }
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || disable_layer_color) { return; }
  switch (biton32(layer_state)) {
    case 0:
      // set_layer_color(0);
      break;
    case 1:
      led_set_solid(128,0,255);
      break;
    case 2:
      led_set_solid(32,255,32);
      break;
    case 3:
      led_set_solid(32,32,255);
      break;
    case 4:
      set_layer_color(1);
      break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {update_heatmap_led_val(keycode);}
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
    case CUSTOM_RESET_KB:
      if (record->event.pressed) {
        reset_keyboard();
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case RGB_TOG:
      if (record->event.pressed) {
        if (rgb_matrix_config.val) {
          rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, 0);
        } else {
          rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, 255);
        }
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(27,255,255);
      }
      return false;
    case CUSTOM_LOGIN:
      if (record->event.pressed) {
        SEND_STRING("SuperUser\tAsdf123$");
      }
      return false;
    case CUSTOM_BYPASS_INSECURE:
      if (record->event.pressed) {
        SEND_STRING("\t\t\t\t\t\t \t\n");
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

void led_set_user(uint8_t usb_led) {
  CAPS_ON = IS_LED_ON(usb_led, USB_LED_CAPS_LOCK);
}

void led_set_solid(int color_r, int color_g, int color_b) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    rgb_matrix_set_color(i, color_r, color_g, color_b);
  }
}
 
void suspend_power_down_user(void)
{
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    rgb_matrix_set_color(i, 0, 0, 0);
  }
  rgb_matrix_set_color(11, 0, 128, 128);  // J key
  rgb_matrix_set_color(keycode_to_led(KC_F), 0, 128, 128);
}

void suspend_wakeup_init_user(void)
{
  set_layer_color(0);
}

int keycode_to_led(uint16_t kc) {
  switch (kc) {
    case KC_A:
      return 38;
    case KC_S:
      return 37;
    case KC_D:
      return 36;
    case KC_F:
      return 35;
    default:
      return 0;
  }
}

int update_heatmap_led_val(uint16_t kc) {
  int led_num = keycode_to_led(kc);
  if (!led_num) {return 0;}
  long old_keypresses = total_keypresses;
  total_keypresses++;
  // Prevent overflow, probably
  if (old_keypresses > total_keypresses) {
    total_keypresses = old_keypresses;
  }
  heatmap_vals[led_num] += 1;
  HSV hsv = {
    .h = (float)heatmap_vals[led_num]*255/(float)total_keypresses,
    .s = 0,
    .v = 0,
  };
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(led_num, rgb.r, rgb.g, rgb.b);
  return led_num;
}

// TODO: Set base layer to heatmap