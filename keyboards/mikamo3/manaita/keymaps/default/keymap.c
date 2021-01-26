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
#include "jtu_custom_keycodes.h"
#include "keymap_jp.h"
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _BASE_JP,
    _LOWER_JP,
    _RAISE_JP

};
enum { TD_LCTLGUI = 0, TD_RALTGUI = 1,TD_RSFTJP =2 };
enum manaita_keycodes {
    KC_LOWER=SAFE_RANGE,
    KC_RAISE,
    KC_BASE_JP,
    KC_LOWER_JP,
    KC_RAISE_JP,
    KC_BASE};
// Defines the keycodes used by our macros in process_record_user
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE]     = LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_BSPC,
        LCTL_T(KC_TAB),KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
         KC_LSFT,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(TD_RSFTJP),
        TD(TD_LCTLGUI), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT), TD(TD_RALTGUI)),
    [_LOWER]    = LAYOUT(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_QUOT, KC_DEL,
        C(KC_SPC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
        _______, KC_EQL, KC_LT, KC_LCBR, KC_LBRC, KC_MINS, KC_RBRC, KC_RCBR, KC_GT, _______, _______, _______,
         _______, _______, _______, _______),
    [_RAISE]    = LAYOUT(_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    C(KC_SPC), KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
     _______, KC_PSCR, KC_INS, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______),
    [_BASE_JP]  = LAYOUT(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, JP_YEN, KC_BSPC,
     LCTL_T(KC_TAB),KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, JU_SCLN, KC_ENT,
      KC_LSFT,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, JP_SLSH, TD(TD_RSFTJP),
    TD(TD_LCTLGUI), LT(_LOWER_JP, KC_SPC), LT(_RAISE_JP, KC_ENT), TD(TD_RALTGUI)),
    [_LOWER_JP] = LAYOUT(JU_GRV, JP_EXLM, JP_AT, JP_HASH, JP_DLR, JP_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JU_QUOT, KC_DEL,
     JP_ZKHK,KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______,
      JU_EQL, JP_LT, JP_LCBR, JP_LBRC, JU_MINS, JP_RBRC, JP_RCBR, KC_GT, _______, _______, _______,
      _______, _______, _______, _______),
    [_RAISE_JP] = LAYOUT(_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
     JP_ZKHK, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
      _______, KC_PSCR, KC_INS, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______)};

typedef struct {
    bool    is_press_action;
    uint8_t state;
} tap;

enum { SINGLE = 1, DOUBLE, TRIPLE, QUAD };
uint8_t    cur_dance(qk_tap_dance_state_t *state);
void       lgui_finished(qk_tap_dance_state_t *state, void *user_data);
void       rgui_finished(qk_tap_dance_state_t *state, void *user_data);
void       rsft_finished(qk_tap_dance_state_t *state, void *user_data);
void       lgui_reset(qk_tap_dance_state_t *state, void *user_data);
void       rgui_reset(qk_tap_dance_state_t *state, void *user_data);
void       rsft_reset(qk_tap_dance_state_t *state, void *user_data);

static tap lgui_tap_state = {.is_press_action = true, .state = 0};
static tap rgui_tap_state = {.is_press_action = true, .state = 0};
static tap rsft_tap_state = {.is_press_action = true, .state = 0};

uint8_t    cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        return SINGLE;
    } else if (state->count == 2) {
        return DOUBLE;
    } else if (state->count == 3) {
        return TRIPLE;
    } else if (state->count == 4) {
        return QUAD;
    }else{
        return 8;
    }
}

void lgui_finished(qk_tap_dance_state_t *state, void *user_data) {
    lgui_tap_state.state = cur_dance(state);
    switch (lgui_tap_state.state) {
        case SINGLE:
            register_code(KC_LCTL);
            break;
        case DOUBLE:
            register_code(KC_LGUI);
            break;
        case TRIPLE:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            break;
        case QUAD:
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            break;
    }
}

void rgui_finished(qk_tap_dance_state_t *state, void *user_data) {
    rgui_tap_state.state = cur_dance(state);
    switch (rgui_tap_state.state) {
        case SINGLE:
            register_code(KC_RALT);
            break;
        case DOUBLE:
            register_code(KC_RGUI);
            break;
        case TRIPLE:
            register_code(KC_RGUI);
            register_code(KC_RSFT);
            break;
        case QUAD:
            register_code(KC_RGUI);
            register_code(KC_RCTL);
            break;
    }
}


void rsft_finished(qk_tap_dance_state_t *state, void *user_data) {
    rsft_tap_state.state = cur_dance(state);
    switch (rsft_tap_state.state) {
        case SINGLE:
            register_code(KC_RSFT);
            break;
        case DOUBLE:
            if(IS_LAYER_ON(_BASE)){
                layer_on(_BASE_JP);
                layer_off(_BASE);
            }else{
                layer_on(_BASE);
                layer_off(_BASE_JP);
            }
            break;
    }
}
void lgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lgui_tap_state.state) {
        case SINGLE:
            unregister_code(KC_LCTL);
            break;
        case DOUBLE:
            unregister_code(KC_LGUI);
            break;
        case TRIPLE:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            break;
        case QUAD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LCTL);
            break;
    }
    lgui_tap_state.state = 0;
}

void rgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (rgui_tap_state.state) {
        case SINGLE:
            unregister_code(KC_RALT);
            break;
        case DOUBLE:
            unregister_code(KC_RGUI);
            break;
        case TRIPLE:
            unregister_code(KC_RGUI);
            unregister_code(KC_RSFT);
            break;
        case QUAD:
            unregister_code(KC_RGUI);
            unregister_code(KC_RCTL);
            break;
    }
    rgui_tap_state.state = 0;
}


void rsft_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (rsft_tap_state.state) {
        case SINGLE:
            unregister_code(KC_RSFT);
            break;
    }
    rsft_tap_state.state = 0;
}
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LCTLGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lgui_finished, lgui_reset),
    [TD_RALTGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rgui_finished, rgui_reset),
    [TD_RSFTJP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rsft_finished, rsft_reset)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool continue_process = process_record_user_jtu(keycode, record);
    if (continue_process == false) {
        return false;
    }
    switch (keycode) {}
    return true;
}
