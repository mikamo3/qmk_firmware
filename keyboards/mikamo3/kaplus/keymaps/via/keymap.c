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
    _BASE,_NUM,_CUR,_SETTING
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

enum { TD_GUI = 0 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
    KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_1,   KC_2, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_EQL,
    KC_LCTL,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_3,   KC_4, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
    KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0
    ),
    [_NUM] = LAYOUT(
    KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_1,   KC_2, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_EQL,
    KC_LCTL,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_3,   KC_4, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
    KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0
    ),
    [_CUR] = LAYOUT(
    KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_1,   KC_2, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_EQL,
    KC_LCTL,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_3,   KC_4, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
    KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0
    ),
    [_SETTING] = LAYOUT(
    KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_1,   KC_2, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_EQL,
    KC_LCTL,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_3,   KC_4, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
    KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0
    )
};

void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    register_code(KC_LGUI);
    if (state->count == 1) {
    } else if (state->count == 2) {
        register_code(KC_LSFT);
    } else {
        register_code(KC_LCTL);
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LGUI);
    if (state->count == 1) {
    } else if (state->count == 2) {
        unregister_code(KC_LSFT);
    } else {
        unregister_code(KC_LCTL);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {[TD_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset)};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    }
    return true;
}
