/*Copyright 2017 Benjamin Kesselring
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
#include "xd75.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define SFT_ENT MT(MOD_RSFT, KC_ENT)
#define F1_SPC  LT(1, KC_SPC)
#define SFT_BSL MT(MOD_LSFT, KC_NUBS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
  /* QWERTY
   * .--------------------------------------------------------------------------------------------------------------------------------------.
   * | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | BACKSP | DEL    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | INS    | PG UP  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * | ESC/CTL| A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | \      | ENTER  | PG DN  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | SFT/ENT| HOME   | UP     | END    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * | LCTRL  | LAYR 2 | LGUI   | LAYR 1 | LALT   | SPACE  | SPC/L1 | RALT   | LAYR 2 | RGUI   | MENU   | RCTRL  | LEFT   | DOWN   | RIGHT  |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  { /* QWERTY */
    { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_INS,  KC_BSPC },
    { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP },
    { CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_DEL,  KC_PGDN },
    { SFT_BSL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, KC_HOME, KC_UP,   KC_END  },
    { KC_LCTL, KC_NUBS, KC_PAUS, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_RALT, KC_RGUI, KC_APP,  OSL(1),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT }
  },

  /* LAYER 1
   * .--------------------------------------------------------------------------------------------------------------------------------------.
   * | RESET  | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | MWHL U | XXXXX  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * | XXXXX  | F5     | F6     | F7     | F8     | XXXXXX | XXXXXX | XXXXX  | XXXXX  | XXXXX  | XXXXXX | XXXXX  | MWHL L | MWHL D | MWHL R |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * | CAPS   | F9     | F10    | F11    | F12    | XXXXXX | XXXXXX | XXXXX  | XXXXX  | XXXXX  | XXXXXX | XXXXX  | MBTN 4 | MBTN 3 | MBTN 5 |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * | CAPS   | PRTSCR | SCRLCK | PAUSE  | XXXXXX | XXXXXX | XXXXXX | XXXXX  | XXXXX  | XXXXX  | XXXXXX | XXXXXX | MBTN 1 | M UP   | MBTN 2 |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |        |        |        |        |        | M LEFT | M DOWN | M RGHT |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  { /* LAYER 1 */
    { RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_WH_U, XXXXXXX },
    { XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R },
    { KC_CAPS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5 },
    { KC_CAPS, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2 },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R }
  }
};


