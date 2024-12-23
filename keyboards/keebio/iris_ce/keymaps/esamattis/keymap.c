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
     _QWERTY2
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


#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)

// Layer 1
#define L1A_1 _______
#define L1KC_1 KC_1
#define L1KC_2 KC_2
#define L1KC_3 KC_3
#define L1KC_4 KC_4
#define L1KC_5 KC_5
#define L1KC_6 KC_6
#define L1KC_7 KC_7
#define L1KC_8 KC_8
#define L1KC_9 KC_9
#define L1KC_0 KC_0
#define L1A_2 _______

#define L1A_3 MO(_MOUSE)
#define L1KC_Q KC_Q
#define L1KC_W KC_W
#define L1KC_E KC_E
#define L1KC_R KC_R
#define L1KC_T KC_T
#define L1KC_Y KC_Y
#define L1KC_U KC_U
#define L1KC_I KC_I
#define L1KC_O KC_O
#define L1KC_P KC_P
#define L1A_4 KC_BACKSPACE

#define L1A_5 KC_TAB
#define L1KC_A KC_A
#define L1KC_S KC_S
#define L1KC_D KC_D
#define L1KC_F KC_F
#define L1KC_G KC_G
#define L1KC_H KC_H
#define L1KC_J KC_J
#define L1KC_K KC_K
#define L1KC_L KC_L
#define L1A_6 _______
#define L1A_7 _______

#define L1A_8  KC_LSFT
#define L1KC_Z KC_Z
#define L1KC_X MT(MOD_LCTL,KC_X)
#define L1KC_C MT(MOD_LALT,KC_C)
#define L1KC_V MT(MOD_LGUI,KC_V)

#define L1KC_B KC_B
#define L1KC_N KC_N
#define L1KC_M MT(MOD_LGUI,KC_M)
#define L1A_11 MT(MOD_LALT,KC_COMM)
#define L1A_12 MT(MOD_LCTL,KC_DOT)
#define L1A_13 KC_SLSH
#define L1A_14 KC_RSFT

#define L1A_9 _______
#define L1A_10 _______

#define L1A_15 _______
#define L1A_16 MO(_LOWER)
#define L1A_17 KC_ENT

#define L1A_18 KC_SPACE
#define L1A_19 MO(_RAISE)
#define L1A_20 _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
     // _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            /* */     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
     // MO(_MOUSE),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            /* */     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BACKSPACE,
     // KC_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            /* */     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     // KC_LSFT, KC_Z,    MT_X, MT_C, MT_V, KC_B, MO(_MOUSE),            /* */    _______ , KC_N, MT_M, MT_KOMM, MT_DOT, KC_SLSH, KC_RSFT,
     //                                _______, MO(_LOWER), KC_ENT,   /* */     KC_SPC,  MO(_RAISE), KC_BACKSPACE
     //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                          ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        L1A_1,     L1KC_1,    L1KC_2,    L1KC_3,    L1KC_4,    L1KC_5,                               L1KC_6,    L1KC_7,    L1KC_8,    L1KC_9,    L1KC_0,    L1A_2,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                          ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L1A_3,     L1KC_Q,    L1KC_W,    L1KC_E,    L1KC_R,    L1KC_T,                               L1KC_Y,    L1KC_U,    L1KC_I,    L1KC_O,    L1KC_P,    L1A_4,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                          ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L1A_5,     L1KC_A,    L1KC_S,    L1KC_D,    L1KC_F,    L1KC_G,                               L1KC_H,    L1KC_J,    L1KC_K,    L1KC_L,    L1A_6,     L1A_7,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼────────┐         ┌───────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L1A_8,     L1KC_Z,    L1KC_X,    L1KC_C,    L1KC_V,    L1KC_B,    L1A_9,             L1A_10, L1KC_N,    L1KC_M,    L1A_11,    L1A_12,    L1A_13,    L1A_14,
     //└──────────┴──────────┴──────────┴──────┬───┴────┬─────┴───┬──────┴─────┬──┘         └────┬──┴─────┬────┴───┬──────┴───┬──────┴──────────┴──────────┴────────┘
                                       L1A_15,  L1A_16,  L1A_17,                                   L1A_18,  L1A_19,   L1A_20
                                   // └────────┴────────┴────  ────┘                             └────────┴────────┴──────────┘
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
