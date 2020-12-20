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
    _BASE,_LOWER,_RAISE,
    _BASE_JP,_LOWER_JP,_RAISE_JP

};
enum { TD_LCTLGUI = 0,TD_RALTGUI=1 };
// Defines the keycodes used by our macros in process_record_user
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,KC_BSPC,
        LCTL_T(KC_TAB) ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,        KC_ENT ,
        KC_LSFT,KC_Z   ,KC_X,   KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,RSFT_T(KC_SLSH),_______,
                        TD(TD_LCTLGUI),LT(_LOWER,KC_SPC),LT(_RAISE,KC_ENT),TD(TD_RALTGUI)
    ),
    [_LOWER] = LAYOUT(
        KC_GRV ,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_QUOT,KC_DEL ,
      A(KC_GRV),KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,        _______,
        TO(_BASE_JP),KC_EQL ,KC_LT  ,KC_LCBR,KC_LBRC,KC_MINS,KC_RBRC,KC_RCBR,KC_GT  ,_______,_______,        _______,
                        _______,_______,_______,_______
    ),
    [_RAISE] = LAYOUT(
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
      A(KC_GRV),KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,        _______,
        TO(_BASE_JP),KC_PSCR,KC_INS ,KC_SLCK,KC_PAUS,_______,_______,_______,_______,_______,_______,        _______,
                        _______,_______,_______,_______
    ),
    [_BASE_JP] = LAYOUT(
        KC_ESC ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,JP_BSLS,KC_BSPC,
        LCTL_T(KC_TAB) ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,JU_SCLN,        KC_ENT ,
        KC_LSFT,KC_Z   ,KC_X,   KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,RSFT_T(JP_SLSH),_______,
                        TD(TD_LCTLGUI),LT(_LOWER_JP,KC_SPC),LT(_RAISE_JP,KC_ENT),TD(TD_RALTGUI)
    ),
    [_LOWER_JP] = LAYOUT(
        JP_GRV ,JP_EXLM,JP_AT  ,JP_HASH,JP_DLR ,JP_PERC,JP_CIRC,JP_AMPR,JP_ASTR,JP_LPRN,JP_RPRN,JU_QUOT,KC_DEL ,
        JP_KANA,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,        _______,
        TO(_BASE),JU_EQL ,JP_LT  ,JP_LCBR,JP_LBRC,JU_MINS,KC_RBRC,KC_RCBR,KC_GT  ,_______,_______,        _______,
                        _______,_______,_______,_______
    ),
    [_RAISE_JP] = LAYOUT(
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
        JP_KANA,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,        _______,
        TO(_BASE),KC_PSCR,KC_INS ,KC_SLCK,KC_PAUS,_______,_______,_______,_______,_______,_______,        _______,
                        _______,_______,_______,_______
    )
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LCTLGUI] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL,KC_LGUI),
    [TD_RALTGUI] = ACTION_TAP_DANCE_DOUBLE(KC_LALT,KC_LGUI),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool continue_process = process_record_user_jtu(keycode, record);
  if (continue_process == false) {
    return false;
  }
    switch (keycode) {
    }
    return true;
}
