/* Copyright 2020 HAMANO Tsukasa
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

enum custom_keycodes {
  AUTH_PW = SAFE_RANGE,
  AUTH_UP
};


// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _BASE,
  _RAISE
};

#define RAISE MO(_RAISE)
#define MT_CS MT(MOD_LCTL, KC_SPACE) // Tap for Space, hold for Control
#define MT_LSS MT(MOD_LSFT, KC_SPACE) // Tap for Space, hold for LShift

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
    KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_ENT,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_NO,
    KC_NO, KC_LALT,KC_LGUI,MT_CS,           MT_LSS,         RAISE,  RAISE,  KC_RALT,AUTH_UP
  ),
  [_RAISE] = LAYOUT(
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,          KC_NO,  KC_NO,  KC_NO,  AUTH_PW
  )
};

void keyboard_post_init_user(void) {
    akb_init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case AUTH_PW:
        akb_pw(record);
        break;
    case AUTH_UP:
        akb_up(record);
        break;
    }
    return true;
}
