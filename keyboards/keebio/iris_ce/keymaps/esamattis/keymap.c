// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action.h"
#include "config.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
#include "report.h"
#include "rgb_matrix.h"
#include "send_string_keycodes.h"
#include QMK_KEYBOARD_H

// https://docs.qmk.fm/keycodes

enum custom_layers {
     _QWERTY,
     _LOWER,
     _RAISE,
     _MOUSE,
     _NUMBERS
};

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    BACKTICK,
    MY_RBG
};

void caps_word_set_user(bool active) {
    if (active) {
        rgb_matrix_sethsv_noeeprom(200, 255, 255);
    } else {
        rgb_matrix_sethsv_noeeprom(170, 255, 255);
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_sethsv_noeeprom(170, 255, 255);
}


bool caps_word_press_user(uint16_t keycode) {
    #ifdef CONSOLE_ENABLE
        uprintf("WORD CAPS KL: kc: 0x%04X\n", keycode);
    #endif


    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_SCLN: // ö
        case KC_QUOT: // ä
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_SLASH:
        case KC_LSFT:
        case KC_RSFT:
        case KC_BSPC:
        case KC_DEL:
        case 0x0238: // Underscore from MO(_LOWER)
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

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
#define L1A_6 KC_SCLN // ö
#define L1A_7 KC_QUOT // ä

#define L1A_8  KC_LSFT
#define L1KC_Z KC_Z
#define L1KC_X MT(MOD_LCTL,KC_X)
#define L1KC_C MT(MOD_LALT,KC_C)
#define L1KC_V MT(MOD_LGUI,KC_V)

#define L1KC_B KC_B
#define L1KC_N KC_N
#define L1KC_M MT(MOD_LGUI,KC_M)
#define L1A_11 MT(MOD_LALT,KC_COMM) // Comma ,
#define L1A_12 MT(MOD_LCTL,KC_DOT) // Period .
#define L1A_13 KC_SLSH // Dash or hyphen -
#define L1A_14 KC_RSFT

#define L1A_9 _______
#define L1A_10 _______

#define L1A_15 _______
#define L1A_16 MO(_LOWER)
#define L1A_17 LT(_NUMBERS, KC_ENT)

#define L1A_18 KC_SPACE
#define L1A_19 MO(_RAISE)
#define L1A_20 _______

// Layer 2
#define L2A_1 MY_RBG
#define L2KC_1 _______
#define L2KC_2 _______
#define L2KC_3 _______
#define L2KC_4 _______
#define L2KC_5 _______
#define L2KC_6 _______
#define L2KC_7 _______
#define L2KC_8 _______
#define L2KC_9 _______
#define L2KC_0 _______
#define L2A_2 QK_BOOT

#define L2A_3 _______
#define L2KC_Q LCAG(KC_Q) // Rectagle, Left Control + Alt + GUI
#define L2KC_W LCAG(KC_W) // ...
#define L2KC_E LCAG(KC_E) // ...
#define L2KC_R _______
#define L2KC_T _______
#define L2KC_Y LALT(KC_7) // Pipe |
#define L2KC_U LSFT(KC_3) // Hash #
#define L2KC_I LSFT(KC_MINS) // Question mark ?
#define L2KC_O LSFT(KC_1) // Exclamation mark !
#define L2KC_P _______
#define L2A_4 _______

#define L2A_5 _______
#define L2KC_A LCAG(KC_A) // Rectagle, Left Control + Alt + GUI
#define L2KC_S LCAG(KC_S) // ...
#define L2KC_D LCAG(KC_D) // ...
#define L2KC_F LGUI(KC_C)
#define L2KC_G LGUI(KC_V)
#define L2KC_H KC_NUHS // Single quote '
#define L2KC_J LSFT(KC_SLASH) // Underscore _
#define L2KC_K LSFT(KC_2) // Double quote "
#define L2KC_L BACKTICK // Backtick ` (macro)
#define L2A_6 LSFT(KC_NUHS) // Asterisk *
#define L2A_7 _______

#define L2A_8  _______
#define L2KC_Z LCAG(KC_Z) // Rectagle, Left Control + Alt + GUI
#define L2KC_X LCAG(KC_X) // ...
#define L2KC_C LCAG(KC_C) // ...
#define L2KC_V _______

#define L2KC_B _______
#define L2KC_N _______
#define L2KC_M ALGR(KC_RBRC)
#define L2A_11 LSFT(KC_5)
#define L2A_12 LSFT(KC_6)
#define L2A_13 _______
#define L2A_14 _______

#define L2A_9 _______
#define L2A_10 _______

#define L2A_15 _______
#define L2A_16 _______
#define L2A_17 _______

#define L2A_18 KC_ESC
#define L2A_19 _______
#define L2A_20 _______

// Layer 2
#define L3A_1 _______
#define L3KC_1 _______
#define L3KC_2 _______
#define L3KC_3 LALT(KC_8) // [
#define L3KC_4 LALT(KC_9) // ]
#define L3KC_5 _______
#define L3KC_6 _______
#define L3KC_7 _______
#define L3KC_8 _______
#define L3KC_9 _______
#define L3KC_0 _______
#define L3A_2 _______

#define L3A_3 _______
#define L3KC_Q _______
#define L3KC_W _______
#define L3KC_E RSFT(KC_8) // (
#define L3KC_R RSFT(KC_9) // )
#define L3KC_T LSFT(LALT(KC_7)) // Backslash

#define L3KC_Y _______
#define L3KC_U _______
#define L3KC_I _______
#define L3KC_O _______
#define L3KC_P _______
#define L3A_4 _______

#define L3A_5 _______
#define L3KC_A LALT(KC_2)
#define L3KC_S _______
#define L3KC_D LSA(KC_8) // {
#define L3KC_F LSA(KC_9) // }
#define L3KC_G LSFT(KC_7) // /

#define L3KC_H KC_LEFT
#define L3KC_J KC_DOWN
#define L3KC_K KC_UP
#define L3KC_L KC_RGHT
#define L3A_6 KC_HOME
#define L3A_7 KC_END

#define L3A_8  _______
#define L3KC_Z _______
#define L3KC_X _______
#define L3KC_C KC_GRV  // <
#define L3KC_V RSFT(KC_GRV)  // >
#define L3KC_B LSFT(KC_0) // =

#define L3KC_N _______
#define L3KC_M _______
#define L3A_11 _______
#define L3A_12 _______
#define L3A_13 _______
#define L3A_14 _______

#define L3A_9 _______
#define L3A_10 _______

#define L3A_15 _______
#define L3A_16 _______
#define L3A_17 _______

#define L3A_18 _______
#define L3A_19 _______
#define L3A_20 _______

// Layer 4
#define L4A_1 _______
#define L4KC_1 _______
#define L4KC_2 _______
#define L4KC_3 _______
#define L4KC_4 _______
#define L4KC_5 _______
#define L4KC_6 _______
#define L4KC_7 _______
#define L4KC_8 _______
#define L4KC_9 _______
#define L4KC_0 _______
#define L4A_2 _______

#define L4A_3 _______
#define L4KC_Q KC_1
#define L4KC_W KC_2
#define L4KC_E KC_3
#define L4KC_R KC_4
#define L4KC_T KC_5

#define L4KC_Y KC_6
#define L4KC_U KC_7
#define L4KC_I KC_8
#define L4KC_O KC_9
#define L4KC_P KC_0
#define L4A_4 _______

#define L4A_5 _______
#define L4KC_A _______
#define L4KC_S _______
#define L4KC_D _______
#define L4KC_F TO(_QWERTY)
#define L4KC_G _______

#define L4KC_H _______
#define L4KC_J _______
#define L4KC_K _______
#define L4KC_L _______
#define L4A_6 _______
#define L4A_7 _______

#define L4A_8  _______
#define L4KC_Z _______
#define L4KC_X _______
#define L4KC_C _______
#define L4KC_V _______

#define L4KC_B _______
#define L4KC_N _______
#define L4KC_M _______
#define L4A_11 _______
#define L4A_12 _______
#define L4A_13 _______
#define L4A_14 _______

#define L4A_9 _______
#define L4A_10 _______

#define L4A_15 _______
#define L4A_16 _______
#define L4A_17 _______

#define L4A_18 _______
#define L4A_19 _______
#define L4A_20 _______

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
     // _______, _______, _______,   _______, _______,  _______,                  _______, _______, _______, _______, _______, QK_BOOT,
     // _______,  LCAG(KC_Q), LCAG(KC_W),  LCAG(KC_E), _______, _______,                  LALT(KC_7), LSFT(KC_3),   LSFT(KC_MINS),   LSFT(KC_1),   _______,   _______,
     // _______,  LCAG(KC_A), LCAG(KC_S),  LCAG(KC_D), COPY, PASTE,                  KC_NUHS, LSFT(KC_SLASH),   LSFT(KC_2),   BACKTICK,   LSFT(KC_NUHS), _______,
     // _______, LCAG(KC_Z), LCAG(KC_X),  LCAG(KC_C), _______, _______, _______,         _______, _______, ALGR(KC_RBRC),   LSFT(KC_5),   LSFT(KC_6),   _______, _______,
     //                                _______, _______, _______,               KC_ESC,  _______, _______
     //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                          ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        L2A_1,     L2KC_1,    L2KC_2,    L2KC_3,    L2KC_4,    L2KC_5,                               L2KC_6,    L2KC_7,    L2KC_8,    L2KC_9,    L2KC_0,    L2A_2,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                          ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L2A_3,     L2KC_Q,    L2KC_W,    L2KC_E,    L2KC_R,    L2KC_T,                               L2KC_Y,    L2KC_U,    L2KC_I,    L2KC_O,    L2KC_P,    L2A_4,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                          ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L2A_5,     L2KC_A,    L2KC_S,    L2KC_D,    L2KC_F,    L2KC_G,                               L2KC_H,    L2KC_J,    L2KC_K,    L2KC_L,    L2A_6,     L2A_7,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼────────┐         ┌───────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L2A_8,     L2KC_Z,    L2KC_X,    L2KC_C,    L2KC_V,    L2KC_B,    L2A_9,             L2A_10, L2KC_N,    L2KC_M,    L2A_11,    L2A_12,    L2A_13,    L2A_14,
     //└──────────┴──────────┴──────────┴──────┬───┴────┬─────┴───┬──────┴─────┬──┘         └────┬──┴─────┬────┴───┬──────┴───┬──────┴──────────┴──────────┴────────┘
                                       L2A_15,  L2A_16,  L2A_17,                                   L2A_18,  L2A_19,   L2A_20
                                   // └────────┴────────┴────  ────┘                             └────────┴────────┴──────────┘
  ),

  [_RAISE] = LAYOUT(
     // _______,  _______,   _______,   LALT(KC_8), LALT(KC_9)  ,   _______,         _______,   _______,   _______,   _______,   _______,  _______,
     // _______, _______, _______,   RSFT(KC_8), RSFT(KC_9),  LSFT(LALT(KC_7))/* \ */,               _______, _______,     _______,  _______, _______, _______,
     // _______, LALT(KC_2), _______, LSA(KC_8)/* { */, LSA(KC_9)/* } */, LSFT(KC_7)/* / */,                  KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT, KC_HOME, KC_END,
     // _______, _______, _______, KC_GRV, RSFT(KC_GRV), LSFT(KC_0), _______,          _______, _______, _______,  _______, _______, _______, _______,
     //                                _______, _______, _______,                   _______, _______, _______
    //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                          ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        L3A_1,     L3KC_1,    L3KC_2,    L3KC_3,    L3KC_4,    L3KC_5,                               L3KC_6,    L3KC_7,    L3KC_8,    L3KC_9,    L3KC_0,    L3A_2,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                          ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L3A_3,     L3KC_Q,    L3KC_W,    L3KC_E,    L3KC_R,    L3KC_T,                               L3KC_Y,    L3KC_U,    L3KC_I,    L3KC_O,    L3KC_P,    L3A_4,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                          ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L3A_5,     L3KC_A,    L3KC_S,    L3KC_D,    L3KC_F,    L3KC_G,                               L3KC_H,    L3KC_J,    L3KC_K,    L3KC_L,    L3A_6,     L3A_7,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼────────┐         ┌───────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L3A_8,     L3KC_Z,    L3KC_X,    L3KC_C,    L3KC_V,    L3KC_B,    L3A_9,             L3A_10, L3KC_N,    L3KC_M,    L3A_11,    L3A_12,    L3A_13,    L3A_14,
    //└──────────┴──────────┴──────────┴──────┬───┴────┬─────┴───┬──────┴─────┬──┘         └────┬──┴─────┬────┴───┬──────┴───┬──────┴──────────┴──────────┴────────┘
                                        L3A_15,  L3A_16,  L3A_17,                                   L3A_18,  L3A_19,   L3A_20
                                    // └────────┴────────┴────  ────┘                             └────────┴────────┴──────────┘
  ),

  [_MOUSE] = LAYOUT(
     _______,  _______,   _______,   _______, _______,   _______,         _______,                          _______,             _______,   _______,   _______,  _______,
     _______, _______, _______,   _______, _______,  _______,               _______, _______,               QK_MOUSE_CURSOR_UP,  _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                  QK_MOUSE_WHEEL_RIGHT,  QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_RIGHT, QK_MOUSE_WHEEL_LEFT, _______,
     _______, _______, _______, _______, _______, _______, _______,          _______, QK_MOUSE_WHEEL_RIGHT, QK_MOUSE_WHEEL_UP,  QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_LEFT, _______, _______,
                                    _______, _______, _______,                   MS_BTN1, MS_BTN2, _______
  ),

  [_NUMBERS] = LAYOUT(
    //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                          ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        L4A_1,     L4KC_1,    L4KC_2,    L4KC_3,    L4KC_4,    L4KC_5,                               L4KC_6,    L4KC_7,    L4KC_8,    L4KC_9,    L4KC_0,    L4A_2,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                          ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L4A_3,     L4KC_Q,    L4KC_W,    L4KC_E,    L4KC_R,    L4KC_T,                               L4KC_Y,    L4KC_U,    L4KC_I,    L4KC_O,    L4KC_P,    L4A_4,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                          ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L4A_5,     L4KC_A,    L4KC_S,    L4KC_D,    L4KC_F,    L4KC_G,                               L4KC_H,    L4KC_J,    L4KC_K,    L4KC_L,    L4A_6,     L4A_7,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼────────┐         ┌───────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        L4A_8,     L4KC_Z,    L4KC_X,    L4KC_C,    L4KC_V,    L4KC_B,    L4A_9,             L4A_10, L4KC_N,    L4KC_M,    L4A_11,    L4A_12,    L4A_13,    L4A_14,
    //└──────────┴──────────┴──────────┴──────┬───┴────┬─────┴───┬──────┴─────┬──┘         └────┬──┴─────┬────┴───┬──────┴───┬──────┴──────────┴──────────┴────────┘
                                        L4A_15,  L4A_16,  L4A_17,                                   L4A_18,  L4A_19,   L4A_20
                                    // └────────┴────────┴────  ────┘                             └────────┴────────┴──────────┘
  )

};
