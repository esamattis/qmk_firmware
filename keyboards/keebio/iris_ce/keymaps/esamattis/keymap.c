// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

// https://docs.qmk.fm/keycodes

enum custom_layers {
     _QWERTY,
     _LOWER,
     _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QK_BOOT,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                    KC_LGUI, MO(_LOWER), KC_ENT,                    KC_SPC,  MO(_RAISE), KC_BACKSPACE
  ),

  [_LOWER] = LAYOUT(
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
     KC_GRV,  _______, KC_UP,   _______, _______, _______,                  _______, KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PGDN,
     KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LBRC,                  KC_RBRC, LSFT(KC_SLASH),   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
     RM_NEXT, EE_CLR,  _______, _______, _______, KC_LCBR, KC_LPRN,         KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
                                    _______, _______, KC_DEL,               KC_DEL,  _______, KC_P0
  ),

  [_RAISE] = LAYOUT(
     KC_F12,  KC_F1,   KC_F2,   LALT(KC_8), LALT(KC_9)  ,   KC_F5,              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
     RM_TOGG, KC_EXLM, KC_AT,   RSFT(KC_8), RSFT(KC_9),  KC_PERC,               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_BOOT,
     RM_NEXT, KC_MPRV, KC_MNXT, LSA(KC_8), LSA(KC_9), KC_UNDS,                  KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT, RM_VALU, KC_BSLS,
     KC_MUTE, KC_MSTP, KC_MPLY, KC_GRV, RSFT(KC_GRV), KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RM_HUED, RM_SATD, RM_VALD, EE_CLR,
                                    _______, _______, _______,                   _______, _______, _______
  )
};
