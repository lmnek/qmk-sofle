#include "luna.c"

static void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("lmnk\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("base"), false);
            break;
        case _CHARS:
            oled_write_ln_P(PSTR("chars"), false);
            break;
        case _VIM:
            oled_write_ln_P(PSTR("nvim"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("num"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_set_cursor(0, 5);
    oled_write("cpslk", led_usb_state.caps_lock);

    render_luna(0, 13);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        /*oled_write_P(arasaka_logo, false);*/
    }
    return false;
}
