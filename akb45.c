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

#include "akb45.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.
user_config_t user_config = { true };

void akb_init() {
    setPinOutput(AUTH_UP_PIN);
    writePin(AUTH_UP_PIN, 0);
    setPinOutput(AUTH_PW_PIN);
    if (user_config.auth_pw_state) {
        writePin(AUTH_PW_PIN, user_config.auth_pw_state);
    }
}

void akb_pw(keyrecord_t *record) {
    if (record->event.pressed) {
        user_config.auth_pw_state ^= 1;
        writePin(AUTH_PW_PIN, user_config.auth_pw_state);
        //eeconfig_update_user(user_config.raw);
    }
}

void akb_up(keyrecord_t *record) {
    if (record->event.pressed) {
        writePin(AUTH_UP_PIN, 1);
    } else {
        writePin(AUTH_UP_PIN, 0);
    }
}


/*
void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    matrix_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware

    return process_record_user(keycode, record);
}

bool led_update_kb(led_t led_state) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    return led_update_user(led_state);
}
*/
