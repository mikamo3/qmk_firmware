#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define EISU LALT(KC_GRV)

enum custom_keycodes {
  LOWERSPC,
  RAISEENT,
  CTLESC,
  SFTBSPC,
};
enum { TD_GUI = 0 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   6  |   7  |   8  |   9  |   0  |   `  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |  GUI |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Shift|                    | Ctrl |   N  |   M  |   ,  |   .  |   /  | Ctrl |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space| Ctrl |||||||| Shift| Enter| Raise||||||||Alt+` | Alt  | GUI  | Shift|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,   KC_1,     KC_2,     KC_3,  KC_4,  KC_5,    KC_MINS,                                                            KC_EQL,   KC_6,   KC_7,  KC_8,       KC_9,     KC_0,     KC_GRV,  \
    KC_TAB,   KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,    KC_LBRC,                                                            KC_RBRC,  KC_Y,   KC_U,  KC_I,       KC_O,     KC_P,     KC_BSLS, \
    KC_LCTL,  KC_A,     KC_S,     KC_D,  KC_F,  KC_G,    KC_QUOT,                                                            KC_BSPC,  KC_H,   KC_J,  KC_K,       KC_L,     KC_SCLN,  KC_QUOT, \
    KC_LSFT,  KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,    KC_LSFT,                                                            KC_LCTL,  KC_N,   KC_M,  KC_COMM,    KC_DOT,   KC_SLSH,  KC_RCTL, \
    KC_LCTL,  KC_LGUI,  KC_LALT,  EISU,         TD(TD_GUI), LOWERSPC, CTLESC,     SFTBSPC,   RAISEENT,   TD(TD_GUI),         KC_KANA,  KC_RALT,  KC_RGUI,  KC_RSFT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   _  |                    |   +  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   1  |   2  |   3  |   4  |   5  |  GUI |                    | Del  |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Shift|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Ctrl |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | Alt+`|||||||| Lower| Space| Ctrl |||||||| Shift| Enter| Raise|||||||| EISU | Alt  | GUI  | Shift|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */

  [_LOWER] = LAYOUT(
    KC_F11,   KC_F1,    KC_F2,    KC_F3,      KC_F4,    KC_F5,    KC_UNDS,                        KC_PLUS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,  \
    _______,  KC_EXLM,  KC_AT,    KC_HASH,    KC_DLR,   KC_PERC,  KC_LCBR,                        KC_RCBR,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PIPE, \
    _______,  KC_1,     KC_2,     KC_3,       KC_4,     KC_5,     KC_DQT,                        KC_DEL,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DQT,  \
    _______,  _______,  _______,  _______,    _______,  _______,  _______,                        _______,  _______,  _______,  KC_LT,    KC_GT,    KC_QUES,  _______, \
    _______,  _______,  _______,  A(KC_GRV),            _______,  _______,  _______,    _______,  _______,  _______,            EISU,     _______,  _______,  _______  \
  ),
  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   _  |                    |   +  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  | Left | Down |  Up  | Right|  GUI |                    | Bksp | Left | Down |  Up  | Right|   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  | Pscr |  INS | SLCK | PAUS | Shift|                    | Ctrl |   N  |   M  |   <  |   >  |   ?  | Ctrl |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space| Ctrl |||||||| Shift| Enter| Raise||||||||Alt+` | Alt  | GUI  | Shift|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F11,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_UNDS,                        KC_PLUS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,  \
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_LCBR,                        KC_RCBR,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PIPE, \
    _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_DQT,                        KC_PIPE,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_COLN,  KC_DQT,  \
    _______,  _______,  KC_PSCR,   KC_INS,  KC_SLCK,  KC_PAUS,  _______,                        _______,  _______,  _______,  KC_LT,    KC_GT,    KC_QUES,  _______, \
    _______,  _______,  _______,  _______,            _______,  _______,  _______,     _______, _______,  _______,            _______,  _______,  _______,  _______  \
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

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
static bool           lowerspc_pressed    = false;
static bool           raiseent_pressed    = false;
static bool           ctlesc_pressed      = false;
static bool           sftbspc_pressed     = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
