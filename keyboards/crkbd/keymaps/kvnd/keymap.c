#include QMK_KEYBOARD_H
#include "secrets.h"

#define ___NO__ KC_NO


#define KC_XNEW LCTL(LGUI(KC_T)) // XCode - New Editor
#define KC_XCLOSE LALT(LCTL(LGUI(KC_W))) // XCode - Close Editor
#define KC_XFOCUS LSFT(LCTL(LGUI(KC_ENT))) // XCode - Focus Editor
#define MINIMAP LSFT(LCTL(LGUI(KC_M))) // XCode - Toggle Minimap
#define AUTHORS LSFT(LCTL(LGUI(KC_A))) // XCode - Toggle Minimap

#define KC_XNEXT LCTL(KC_GRAVE) // XCode - Change Editor
#define KC_CLAE HYPR(KC_GRAVE) // XCode - Close Editor
#define KC_XBACK LCTL(LGUI(KC_LEFT)) // XCode - History Back
#define KC_XFORWD LCTL(LGUI(KC_RIGHT)) // XCode - History Forward

#define TAB_LEFT LSFT(LGUI(KC_LBRC))
#define TAB_RIGHT LSFT(LGUI(KC_RBRC))

#define KC_SWAP LCTL(KC_T)
#define KC_ALRD LGUI(KC_SPACE) // Toggle Alfred
#define KC_CMDE LGUI(KC_ENTER) // CMD + Enter


#define KC_LOCK HYPR(KC_L) // Lock the screen via Alfred
#define KC_SCST SHOT_MACRO // Screenshot Macro
#define KC_FCS HYPR(KC_F) // Trigger Focus

#define KC_XCODE TT(_XCODE)
#define KC_RLD LT(_RAISE, KC_LEAD) // LEAD, RAISE

#define _QWERTY 0
#define _RAISE 1
#define _XCODE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  ADJUST,
  SHOT_MACRO,
  PWD_MACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_BSLASH,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              LT(_RAISE, KC_GRV), KC_LGUI,  KC_ENT,     KC_SPC,MO(_RAISE),  KC_XCODE \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX,KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,                     KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT,XXXXXXX,  _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_GRV, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,   _______,  KC_LEAD,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_XCODE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     PWD_MACRO,XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9,                     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, TAB_RIGHT, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_MPLY,TAB_LEFT,TAB_RIGHT, KC_KP_4, KC_KP_5, KC_KP_6,                     XXXXXXX, XXXXXXX,KC_XNEW,KC_XCLOSE, XXXXXXX, KC_XFOCUS, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX,  XXXXXXX, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3,                     AUTHORS,  MINIMAP, KC_XBACK,KC_XFORWD,KC_XNEXT, XXXXXXX, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,   _______,KC_LEAD, TG(_QWERTY), _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
        switch(keycode) {
            case PWD_MACRO:
                SEND_STRING(secret_jmp);
                return false;
        }
    }
    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_Q) {
      // Anything you can do in a macro.
      SEND_STRING(secret_oneP);
    }
    SEQ_ONE_KEY(KC_J) {
      // Anything you can do in a macro.
      SEND_STRING(secret_jmp);
    }
    SEQ_ONE_KEY(KC_P) {
      // Anything you can do in a macro.
      SEND_STRING(secret_pin);
    }

    SEQ_ONE_KEY(KC_ENT) {
      register_code(KC_LGUI);
      register_code(KC_ENT);
      unregister_code(KC_ENTER);
      unregister_code(KC_LGUI);
    }
  }
}

