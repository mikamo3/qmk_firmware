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
#include "keycode.h"
#include "quantum_keycodes.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,_LOWER,_RAISE,
    //_BASE_JP,_LOWER_JP,_ADJUST_JP,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

enum { TD_LGUI = 0, TD_RGUI = 1 };
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,KC_MINS,KC_EQL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TAB,KC_A, KC_S, KC_D, KC_F, KC_G,KC_LBRC,KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
    KC_LCTL,  KC_Z, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
            KC_LSFT,C(KC_SPC),TD(TD_LGUI),LT(_LOWER,KC_SPC),LCTL_T(KC_ESC),LSFT_T(KC_BSPC),LT(_RAISE,KC_ENT),TD(TD_RGUI),KC_RALT,KC_RSFT

    ),
    [_LOWER] = LAYOUT(
        _______,KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,KC_DQUO,KC_QUOT,KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,KC_DEL,
        _______, KC_1, KC_2, KC_3, KC_4, KC_5,KC_LCBR,KC_RCBR, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
    _______,  _______, _______, KC_GRV, KC_PLUS, KC_MINS,               KC_ASTR, KC_SLSH, KC_GT, KC_LT, KC_QUES, _______,
    _______,_______,_______,_______,KC_DEL,_______,_______,_______,_______,_______

    ),
    [_RAISE] = LAYOUT(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,KC_F11,KC_F12,KC_F6,KC_F7, KC_F8, KC_F9, KC_F10,  _______,
_______,_______,KC_END,KC_PGDN,KC_PGUP,KC_HOME,_______,_______,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,_______,_______,
_______,_______,KC_PSCR,KC_INS,KC_SLCK,KC_PAUS,_______,_______,_______,_______,_______,_______,
    KC_LSFT,A(KC_GRV),KC_LGUI,LT(_LOWER,KC_SPC),C(KC_ESC),S(KC_BSPC),LT(_RAISE,KC_ENT),KC_RGUI,KC_RALT,KC_RSFT

    ),
};

typedef struct {
    bool    is_press_action;
    uint8_t state;
} tap;

enum { SINGLE = 1, DOUBLE, TRIPLE };
uint8_t    cur_dance(qk_tap_dance_state_t *state);
void       lgui_finished(qk_tap_dance_state_t *state, void *user_data);
void       rgui_finished(qk_tap_dance_state_t *state, void *user_data);
void       lgui_reset(qk_tap_dance_state_t *state, void *user_data);
void       rgui_reset(qk_tap_dance_state_t *state, void *user_data);

static tap lgui_tap_state = {.is_press_action = true, .state = 0};
static tap rgui_tap_state = {.is_press_action = true, .state = 0};

uint8_t    cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        return SINGLE;
    } else if (state->count == 2) {
        return DOUBLE;
    } else if (state->count == 3) {
        return TRIPLE;
    } else{
        return 8;
    }
}

void lgui_finished(qk_tap_dance_state_t *state, void *user_data) {
    lgui_tap_state.state = cur_dance(state);
    switch (lgui_tap_state.state) {
        case SINGLE:
            register_code(KC_LGUI);
            break;
        case DOUBLE:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            break;
        case TRIPLE:
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            break;
    }
}

void rgui_finished(qk_tap_dance_state_t *state, void *user_data) {
    rgui_tap_state.state = cur_dance(state);
    switch (rgui_tap_state.state) {
        case SINGLE:
            register_code(KC_RGUI);
            break;
        case DOUBLE:
            register_code(KC_RGUI);
            register_code(KC_RSFT);
            break;
        case TRIPLE:
            register_code(KC_RGUI);
            register_code(KC_RCTL);
            break;
    }
}

void lgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lgui_tap_state.state) {
        case SINGLE:
            break;
            unregister_code(KC_LGUI);
        case DOUBLE:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            break;
        case TRIPLE:
            unregister_code(KC_LGUI);
            unregister_code(KC_LCTL);
            break;
    }
    lgui_tap_state.state = 0;
}

void rgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (rgui_tap_state.state) {
        case SINGLE:
            unregister_code(KC_RGUI);
            break;
        case DOUBLE:
            unregister_code(KC_RGUI);
            unregister_code(KC_RSFT);
            break;
        case TRIPLE:
            unregister_code(KC_RGUI);
            unregister_code(KC_RCTL);
            break;
    }
    rgui_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lgui_finished, lgui_reset),
    [TD_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rgui_finished, rgui_reset)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        break;
    }
    return true;
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
