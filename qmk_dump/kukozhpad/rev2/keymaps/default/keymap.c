/* Copyright 2021 Uselessful
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
    _BASE,
    _FN,
    _ADJ
};

// Defines the keycodes used by our macros in process_record_user
/* enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
}; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_P7,    KC_P8,    KC_P9,    KC_BSPC,  
        KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  
        KC_P1,    KC_P2,    KC_P3,    MO(_ADJ),  
        KC_P0,    KC_PCMM,  KC_PDOT,  KC_PENT
    ),
    [_ADJ] = LAYOUT(
        RGB_TOG,   RGB_MOD,  KC_SLCK,   KC_NUMLOCK,   
        RGB_SAI,   RGB_VAI,  RGB_HUI,   KC_CAPS,   
        RGB_SAD,   RGB_VAD,  RGB_HUD,   KC_RCTL,  
        KC_LEFT,   KC_DOWN,  KC_RIGHT,  KC_RSFT
    ),
    [_FN] = LAYOUT(
        KC_INS,    KC_HOME,  KC_PGUP,   KC_UNDO,   
        KC_DEL,    KC_END,   KC_PGDN,   KC_LGUI,   
        KC_LSFT,   KC_UP,    KC_LALT,   KC_LCTRL,  
        KC_LEFT,   KC_DOWN,  KC_RIGHT,  KC_RSFT
    )
};

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
            0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
            0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
} */
