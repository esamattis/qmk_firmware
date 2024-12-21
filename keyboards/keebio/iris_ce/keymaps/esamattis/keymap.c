// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
#include "send_string_keycodes.h"
#include QMK_KEYBOARD_H

// https://docs.qmk.fm/keycodes

enum custom_layers {
     _QWERTY,
     _LOWER,
     _RAISE
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
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            /* */     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QK_BOOT,
     _______,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            /* */     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
     KC_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            /* */     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LSFT, KC_Z,    MT_X, MT_C, MT_V, KC_B, _______,            /* */     _______, KC_N, MT_M, MT_KOMM, MT_DOT, KC_SLSH, KC_RSFT,
                                    KC_LGUI, MO(_LOWER), KC_ENT,   /* */     KC_SPC,  MO(_RAISE), KC_BACKSPACE
  ),

  [_LOWER] = LAYOUT(
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
     KC_GRV,  LCAG(KC_Q), LCAG(KC_W),  LCAG(KC_E), _______, _______,                  _______, LSFT(KC_3),   LSFT(KC_BACKSLASH),   KC_P9,   KC_P0,   KC_PGDN,
     KC_DEL,  LCAG(KC_A), LCAG(KC_S),  LCAG(KC_D), COPY, PASTE,                  KC_NUHS, LSFT(KC_SLASH),   LSFT(KC_2),   BACKTICK,   LSFT(KC_NUHS), KC_PIPE,
     RM_NEXT, LCAG(KC_Z), LCAG(KC_X),  LCAG(KC_C), _______, KC_LCBR, KC_LPRN,         KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
                                    _______, _______, KC_DEL,               KC_ESC,  _______, KC_P0
  ),

  [_RAISE] = LAYOUT(
     KC_F12,  KC_F1,   KC_F2,   LALT(KC_8), LALT(KC_9)  ,   KC_F5,              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
     RM_TOGG, KC_EXLM, KC_AT,   RSFT(KC_8), RSFT(KC_9),  KC_PERC,               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_BOOT,
     RM_NEXT, KC_MPRV, KC_MNXT, LSA(KC_8), LSA(KC_9), KC_UNDS,                  KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT, KC_HOME, KC_END,
     KC_MUTE, KC_MSTP, KC_MPLY, KC_GRV, RSFT(KC_GRV), KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RM_HUED, RM_SATD, RM_VALD, EE_CLR,
                                    _______, _______, _______,                   _______, _______, _______
  )
};
