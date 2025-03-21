
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // zoom in/out
        if (clockwise) {
            tap_code16(LCTL(KC_PPLS));
        } else {
            tap_code16(LCTL(KC_PMNS));
        }
        /*if (clockwise) {*/
        /*    tap_code(KC_WH_D);*/
        /*} else {*/
        /*    tap_code(KC_WH_U);*/
        /*}*/
    }
    return true;
}
