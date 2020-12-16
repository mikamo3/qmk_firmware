/* Copyright 2020 mikamo3
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_A, KC_B, KC_C, KC_D,
        KC_1, KC_2, KC_3, KC_4,
        KC_W, KC_X, KC_Y, KC_Z
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    }
    return true;
}
void keyboard_post_init_user(void) {
    int cnt = 0;
    rgblight_enable_noeeprom();
    while (true){
        _delay_ms(500);
        switch (cnt) {
            case 0:
                rgblight_setrgb(RGB_RED);
                cnt++;
                break;
            case 1:
                rgblight_setrgb(RGB_GREEN);
                cnt++;
                break;
            case 2:
                rgblight_setrgb(RGB_BLUE);
                cnt++;
                break;
            default:
                rgblight_setrgb(RGB_WHITE);
                cnt = 0;
                break;
        }
    }
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
