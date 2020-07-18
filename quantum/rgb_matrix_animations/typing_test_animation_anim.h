#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_TEST_ANIMATION)
RGB_MATRIX_EFFECT(TYPING_TEST_ANIMATION)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

void process_rgb_matrix_typing_test_animation(keyrecord_t *record) {
    // uint8_t row = record->event.key.row;
    // uint8_t col = record->event.key.col;
    // rgb_frame_buffer[row][col] = qadd8(rgb_frame_buffer[row][col], 254);
}

int test_anim_delay = 5;
int test_anim_init_delay = 100;
int test_anim_init_timer;
int test_anim_timer;
int test_anim_val = 0;

bool TYPING_TEST_ANIMATION(effect_params_t* params) {
  // Modified version of RGB_MATRIX_USE_LIMITS to work off of matrix row / col size
  uint8_t led_min = RGB_MATRIX_LED_PROCESS_LIMIT * params->iter;
  uint8_t led_max = led_min + RGB_MATRIX_LED_PROCESS_LIMIT;
  if (led_max > sizeof(rgb_frame_buffer))
    led_max = sizeof(rgb_frame_buffer);

  if (params->init) {
    rgb_matrix_set_color_all(0, 0, 0);
    test_anim_timer = timer_read();
    memset(rgb_frame_buffer, 0, sizeof rgb_frame_buffer);
  }

  if (timer_elapsed(test_anim_init_timer) && timer_elapsed(test_anim_timer) > test_anim_delay)
  {
    test_anim_timer = timer_read();
    // rgb_matrix_set_color_all(test_anim_color, test_anim_color, test_anim_color);
    if (test_anim_val < 255)
    {
      test_anim_val++;
    }
  }

    int val = 128;
  for (int i = led_min; i < led_max; i++) {
    uint8_t row = i % MATRIX_ROWS;
    uint8_t col = i / MATRIX_ROWS;
    // float alpha = .05;

    // set the pixel colour
    uint8_t led[LED_HITS_TO_REMEMBER];
    uint8_t led_count = rgb_matrix_map_row_column_to_led(row, col, led);
    for (uint8_t j = 0; j < led_count; ++j)
    {
      if (!HAS_ANY_FLAGS(g_led_config.flags[led[j]], params->flags))
        continue;

    //   HSV hsv = { 170 - qsub8(val, 85), rgb_matrix_config.sat, scale8((qadd8(170, val) - 170) * 3, rgb_matrix_config.val) };

      HSV hsv = { val, 255, test_anim_val};
      RGB rgb = hsv_to_rgb(hsv);
      rgb_matrix_set_color(led[j], rgb.r, rgb.g, rgb.b);
    }

    rgb_frame_buffer[row][col] = val;
  }

  return led_max < sizeof(rgb_frame_buffer);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif // defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && !defined(DISABLE_RGB_MATRIX_TYPING_HEAT_EQ)
