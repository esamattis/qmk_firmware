// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
#include "report.h"
#include "send_string_keycodes.h"
#include QMK_KEYBOARD_H

// https://docs.qmk.fm/keycodes

enum custom_layers {
     _QWERTY,
     _LOWER,
     _RAISE,
     _MOUSE
};

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    BACKTICK,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BACKTICK:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            tap_code(KC_EQL);
            unregister_code(KC_LSFT);
            tap_code(KC_SPC);
        }
        break;
    }

    return true;
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_LSFT:
        case KC_RSFT:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

#define MT_X MT(MOD_LCTL,KC_X)
#define MT_C MT(MOD_LALT,KC_C)
#define MT_V MT(MOD_LGUI,KC_V)

#define MT_M MT(MOD_LGUI,KC_M)
#define MT_KOMM MT(MOD_LALT,KC_COMM)
#define MT_DOT MT(MOD_LCTL,KC_DOT)

#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            /* */     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
     MO(_MOUSE),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            /* */     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BACKSPACE,
     KC_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            /* */     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LSFT, KC_Z,    MT_X, MT_C, MT_V, KC_B, MO(_MOUSE),            /* */    _______ , KC_N, MT_M, MT_KOMM, MT_DOT, KC_SLSH, KC_RSFT,
                                    _______, MO(_LOWER), KC_ENT,   /* */     KC_SPC,  MO(_RAISE), KC_BACKSPACE
  ),

  [_LOWER] = LAYOUT(
     _______, _______, _______,   _______, _______,  _______,                  _______, _______, _______, _______, _______, QK_BOOT,
     _______,  LCAG(KC_Q), LCAG(KC_W),  LCAG(KC_E), _______, _______,                  LALT(KC_7), LSFT(KC_3),   LSFT(KC_MINS),   LSFT(KC_1),   _______,   _______,
     _______,  LCAG(KC_A), LCAG(KC_S),  LCAG(KC_D), COPY, PASTE,                  KC_NUHS, LSFT(KC_SLASH),   LSFT(KC_2),   BACKTICK,   LSFT(KC_NUHS), _______,
     _______, LCAG(KC_Z), LCAG(KC_X),  LCAG(KC_C), _______, _______, _______,         _______, _______, ALGR(KC_RBRC),   LSFT(KC_5),   LSFT(KC_6),   _______, _______,
                                    _______, _______, _______,               KC_ESC,  _______, _______
  ),

  [_RAISE] = LAYOUT(
     _______,  _______,   _______,   LALT(KC_8), LALT(KC_9)  ,   _______,         _______,   _______,   _______,   _______,   _______,  _______,
     _______, _______, _______,   RSFT(KC_8), RSFT(KC_9),  LSFT(LALT(KC_7))/* \ */,               _______, _______,     _______,  _______, _______, _______,
     _______, LALT(KC_2), _______, LSA(KC_8)/* { */, LSA(KC_9)/* } */, LSFT(KC_7)/* / */,                  KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT, KC_HOME, KC_END,
     _______, _______, _______, KC_GRV, RSFT(KC_GRV), LSFT(KC_0), _______,          _______, _______, _______,  _______, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  ),

  [_MOUSE] = LAYOUT(
     _______,  _______,   _______,   _______, _______,   _______,         _______,                          _______,             _______,   _______,   _______,  _______,
     _______, _______, _______,   _______, _______,  _______,               _______, _______,               QK_MOUSE_CURSOR_UP,  _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                  QK_MOUSE_WHEEL_RIGHT,  QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_RIGHT, QK_MOUSE_WHEEL_LEFT, _______,
     _______, _______, _______, _______, _______, _______, _______,          _______, QK_MOUSE_WHEEL_RIGHT, QK_MOUSE_WHEEL_UP,  QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_LEFT, _______, _______,
                                    _______, _______, _______,                   MS_BTN1, MS_BTN2, _______
  )
};
