#include QMK_KEYBOARD_H

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

// #define KC_XECO LSFT(LALT(LCTL(LGUI(KC_W)))) // XCode - Close Other Editor
// #define KC_XEDB LALT(LCTL(LGUI(KC_T))) // XCode - New Editor Below

#define KC_SWAP LCTL(KC_T)
#define KC_ALRD LGUI(KC_SPACE) // Toggle Alfred

#define KC_LOCK HYPR(KC_L) // Lock the screen via Alfred
#define KC_SCST SHOT_MACRO // Screenshot Macro
#define KC_FCS HYPR(KC_F) // Trigger Focus

#define SHIFT SFT_T(KC_LCBR)

#define HOME TO(_QWERTY)
#define KC_XCODE TT(_XCODE)

// #define SPACE LT(_ARROW, KC_SPC)
// #define ENTER LT(_LOWER, KC_ENT)
#define ARROW MO(_ARROW)

#define _QWERTY 0
#define _ARROW 1
#define _LOWER 2
#define _XCODE 3

enum {
  TD_ESC_TAB = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_TAB)
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  SHOT_MACRO,
  PWD_MACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      ___NO__, ___NO__, ___NO__, ___NO__, ___NO__, ___NO__,                           ___NO__, ___NO__, ___NO__, ___NO__, ___NO__, ___NO__,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT , KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,          ___NO__, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_GRV, KC_LGUI, KC_ENT,                    KC_SPC,   ARROW, KC_XCODE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  

  [_ARROW] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     ___NO__,  ___NO__, ___NO__, ___NO__, ___NO__, ___NO__,                            ___NO__, ___NO__, ___NO__, ___NO__, ___NO__, ___NO__,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, TAB_LEFT,KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,                            KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT,TAB_RIGHT, ___NO__,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, _______,         ___NO__, ___NO__, ___NO__, ___NO__, ___NO__, ___NO__,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                 _______, _______, ___NO__
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     ___NO__, ___NO__, ___NO__, ___NO__, ___NO__, ___NO__,                            ___NO__, ___NO__, ___NO__, ___NO__, ___NO__, ___NO__,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, TAB_LEFT,KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,                            KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT,TAB_RIGHT, ___NO__,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, _______,         ___NO__, ___NO__, ___NO__, ___NO__, ___NO__, ___NO__,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   ___NO__, ___NO__, ___NO__
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_XCODE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     HOME   , ___NO__, ___NO__, ___NO__, ___NO__, ___NO__,                            ___NO__, ___NO__, ___NO__, ___NO__, ___NO__, ___NO__,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     ___NO__, TAB_LEFT, ___NO__, ___NO__, ___NO__, ___NO__,                            ___NO__, ___NO__, ___NO__, ___NO__, TAB_RIGHT, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     ___NO__, AUTHORS, ___NO__, ___NO__, ___NO__, ___NO__,                            ___NO__, ___NO__, KC_XNEW, KC_XCLOSE, ___NO__, KC_XFOCUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, ___NO__, ___NO__, ___NO__, ___NO__, _______,          ___NO__, ___NO__, MINIMAP, KC_XBACK,KC_XFORWD,KC_XNEXT, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
        switch(keycode) {
            case SHOT_MACRO:
                SEND_STRING(SS_LSFT(SS_LGUI("4")));
                SEND_STRING(" ");
                return false;
        }
    }
    return true;
}