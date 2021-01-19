#ifndef DISABLE_RGB_MATRIX_ALPHAS_MODS
RGB_MATRIX_EFFECT(ALPHAS_MODS)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// alphas = color1, mods = color2
bool ALPHAS_MODS(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 32);

    HSV hsv  = rgb_matrix_config.hsv;

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            hsv.h = g_led_config.point[i].y/2 + time + rgb_matrix_config.hsv.h;
            RGB rgb2 = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
        } else {
            // hsv.h += rgb_matrix_config.hsv.h;
            hsv.h = g_led_config.point[i].y/2 + time;
            RGB rgb1 = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_ALPHAS_MODS
