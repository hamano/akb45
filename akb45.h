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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define XX KC_NO

#define LAYOUT( \
  A1, B1, C1, D1, E1, F1, G1, H1, I1, J1, K1, L1, \
  A2, B2, C2, D2, E2, F2, G2, H2, I2, J2, K2, L2, \
  A3, B3, C3, D3, E3, F3, G3, H3, I3, J3, K3, L3, \
  A4, B4, C4, D4, F4, I4, J4, K4, L4  \
) \
{ \
  { A1, B1, C1, D1, E1, F1, G1, H1, I1, J1, K1, L1 }, \
  { A2, B2, C2, D2, E2, F2, G2, H2, I2, J2, K2, L2 }, \
  { A3, B3, C3, D3, E3, F3, G3, H3, I3, J3, K3, L3 }, \
  { A4, B4, C4, D4, XX, F4, XX, XX, I4, J4, K4, L4 }  \
}

#define AUTH_PW_PIN D3
#define AUTH_UP_PIN D2

typedef union {
    uint32_t raw;
    struct {
        bool auth_pw_state :1;
    };
} user_config_t;

void akb_init(void);
void akb_pw(keyrecord_t *);
void akb_up(keyrecord_t *);
