/* Copyright 2019 SwanMatch
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

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//  QMKBEST = SAFE_RANGE,
//  QMKURL
//};
enum layer { _QWERTY, _LOWER, _RAISE };

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  LOWERSPC,
  RAISEENT,
  CTLESC,
  SFTBSPC
};
enum { TD_GUI = 0 };
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                                  ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  |   :  |  '   |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |-------.-------.  ,---------------|   N  |   M  |   ,  |   .  |   /  |  -   |
 * `-----------------------------------------/       /       /   \       \      \----------------------------------------'
 *                          | E/J  | GUI  | / Space /  Esc  /     \ Bksp  \ Enter\  | GUI  |  Alt  |
 *                          |      |      |/  Lower/  Ctrl /       \ Shift \ Upper\ |      |       |
 *                          `-----------------------------'         '------------------------------'
 */

  [_QWERTY] = LAYOUT(
    KC_TAB,   KC_Q,    KC_W,    KC_E,               KC_R,          KC_T,                         KC_Y,               KC_U,      KC_I,   KC_O,    KC_P,  KC_EQL,
    KC_LCTL,  KC_A,    KC_S,    KC_D,               KC_F,          KC_G,                         KC_H,               KC_J,      KC_K,   KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,               KC_V,          KC_B,                         KC_N,               KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
                    KC_KANA, TD(TD_GUI), LOWERSPC, CTLESC,     SFTBSPC,   RAISEENT,   TD(TD_GUI), KC_RALT
  ),

/* LOWER
 * ,-----------------------------------------.                                  ,-----------------------------------------.
 * |  `   |   !  |   @  |   #  |   $  |   %  |                                  |   ^  |   &  |   *  |   (  |   )  |   \  |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |   [  |
 * |------+------+------+------+------+------+                                  +------+------+------+------+------+------|
 * |      |      |      |   `  |   +  |   -  |-------.-------.  ,---------------|   *  |   /  |   <  |   >  |   ?  |   ]  |
 * `-----------------------------------------/       /       /   \       \      \----------------------------------------'
 *                          |Alt+` |      | /       /       /     \       \      \  |      | Ctrl |
 *                          |      |      |/       /       /       \       \      \ |      |      |
 *                          `-----------------------------'         '-----------------------------'
 */
  [_LOWER] = LAYOUT(
   KC_GRV, KC_EXLM,     KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
  _______,    KC_1,      KC_2,    KC_3,    KC_4,    KC_5,                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_LBRC,
  _______, _______,   _______,  KC_GRV, KC_PLUS, KC_MINS,                                KC_ASTR, KC_SLSH,   KC_LT,   KC_GT, KC_QUES, KC_RBRC,
                    A(KC_GRV), _______, _______, _______,                          SFT_T(KC_DEL), _______, _______, KC_RCTL
  ),

/* RAISE
 * ,-----------------------------------------.                                  ,-----------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |      | HOME | PGDN | PGUP |  END |                                  | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |      | PSCR |  INS | SLCK | PAUSE|-------.-------.  ,---------------|RGBTOG|RGBRST|RGBMOD|RGBHUE|RGBSAD|RGBVAL|
 * `-----------------------------------------/       /       /   \       \       \----------------------------------------'
 *                          |      |      | /       /       /     \       \       \  |      |      |
 *                          |      |      |/       /       /       \       \       \ |      |      |
 *                          `-----------------------------'         '------------------------------'
 */
  [_RAISE] = LAYOUT(
   KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                  KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,
  _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,                KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
  _______, _______, KC_PSCR,  KC_INS, KC_SLCK, KC_PAUS,                RGB_TOG,  RGBRST, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
                    _______, _______, _______, _______,                _______, _______, _______, _______
  )
};

void keyboard_post_init_user(void) {
    // post init コードを呼びます
    rgblight_enable_noeeprom();  // 設定を保存せずに Rgb を有効にします
    rgblight_set_effect_range(4, RGBLED_NUM - 4);
    for (int i = 0; i < RGBLED_NUM; i++) {
        _delay_ms(50);
        switch (i % 3) {
            case 0:
                rgblight_setrgb_at(RGB_WHITE, i);
                break;
            case 1:
                rgblight_setrgb_at(RGB_BLUE, i);
                break;
            case 2:
                rgblight_setrgb_at(RGB_GREEN, i);
                break;
        }
    }
}

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

int RGB_current_mode;

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

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RAISE:
            for (int i = 0; i < 4; i++) {
                rgblight_setrgb_at(RGB_WHITE, i);
            }
            break;
        case _LOWER:
            for (int i = 0; i < 4; i++) {
                rgblight_setrgb_at(RGB_RED, i);
            }
            break;
        default:  //  for any other layers, or the default layer
            for (int i = 0; i < 4; i++) {
                rgblight_setrgb_at(RGB_GREEN, i);
            }
            break;
    }
    return state;
}

static bool lowerspc_pressed = false;
static bool raiseent_pressed = false;
static bool ctlesc_pressed   = false;
static bool sftbspc_pressed  = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef RGBLIGHT_ENABLE
        case RGBRST:
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_mode = rgblight_config.mode;
            }
            break;
#endif
        case LOWERSPC:
            if (record->event.pressed) {
                lowerspc_pressed = true;
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
                if (lowerspc_pressed) {
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                }
                lowerspc_pressed = false;
            }
            return false;
            break;
        case CTLESC:
            if (record->event.pressed) {
                ctlesc_pressed = true;
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LCTL);
                if (ctlesc_pressed) {
                    register_code(KC_ESC);
                    unregister_code(KC_ESC);
                }
                ctlesc_pressed = false;
            }
            return false;
            break;
        case RAISEENT:
            if (record->event.pressed) {
                raiseent_pressed = true;
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
                if (raiseent_pressed) {
                    register_code(KC_ENT);
                    unregister_code(KC_ENT);
                }
                raiseent_pressed = false;
            }
            return false;
            break;
        case SFTBSPC:
            if (record->event.pressed) {
                sftbspc_pressed = true;
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
                if (sftbspc_pressed) {
                    register_code(KC_BSPC);
                    unregister_code(KC_BSPC);
                }
                sftbspc_pressed = false;
            }
            return false;
            break;
        default:
            lowerspc_pressed = false;
            raiseent_pressed = false;
            ctlesc_pressed   = false;
            sftbspc_pressed  = false;
            if (record->event.pressed) {
            } else {
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
#endif
}
