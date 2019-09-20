#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2
#define _OTHER 3

#define MRAISE MO(_RAISE)
#define MLOWER MO(_LOWER)
#define MOTHER MO(_OTHER)

#define KC_ZALT MT(MOD_LALT, KC_Z)
#define KC_TCTL MT(MOD_LCTL, KC_GRAVE)

#define KC_TD TD

#define WRDLEFT LALT(KC_LEFT) // WORD LEFT
#define WRDRIGHT LALT(KC_RIGHT) // WORD RIGHT

#define XEDITOR LCTL(LGUI(KC_T)) // XCode - New Editor
#define XBEDITOR LALT(LCTL(LGUI(KC_T))) // XCode - New Editor Below
#define XCEDTR LALT(LCTL(LGUI(KC_W))) // XCode - Close Editor
#define XCOEDTR LSFT(LALT(LCTL(LGUI(KC_W)))) // XCode - Close Other Editor
#define XFOCUS LSFT(LCTL(LGUI(KC_ENT))) // XCode - Focus Editor

// #define KC_XMIN LSFT(LCTL(LGUI(KC_M))) // XCode - Toggle Minimap
#define XCAUTHOR LSFT(LCTL(LGUI(KC_A))) // XCode - Toggle Author

#define XRUNB LCTL(LGUI(KC_B)) // XCode - Run without Building
// #define ALWR LT(_LOWER, KC_ALRD)


#define XCHANGE LCTL(KC_GRAVE) // XCode - Change Editor
#define KC_CLAE HYPR(KC_GRAVE) // XCode - Close Editor
#define XBACK LCTL(LGUI(KC_LEFT)) // XCode - History Back
#define XFRWD LCTL(LGUI(KC_RIGHT)) // XCode - History Forward

#define KC_SWAP LCTL(KC_T)
#define KC_ALRD LGUI(KC_SPACE) // Toggle Alfred

#define KC_LOCK HYPR(KC_L) // Lock the screen via Alfred
#define KC_SCST SHOT_MACRO // Screenshot Macro
#define KC_FCS HYPR(KC_F) // Trigger Focus
#define KC_EMBG HYPR(KC_O) // Trigger 'Xcode Embiggen'
#define KC_SML HYPR(KC_I) // Trigger 'Xcode Smallen'

enum custom_keycodes {
    SHOT_MACRO = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      MRAISE, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSPO, KC_ZALT, KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,          _______,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TCTL, KC_LGUI,   KC_ENT,                    KC_SPC, KC_ALRD   ,MOTHER
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_LOCK, _______, _______, _______, _______, _______,                            _______, _______, _______, _______,_______ , KC_EQUAL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______,   KC_UP , _______, _______, _______,                            _______, _______, KC_UP, _______, KC_LBRACKET, KC_RBRACKET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,                            WRDLEFT, KC_LEFT, KC_DOWN,KC_RIGHT,WRDRIGHT, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LPRN, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, KC_RPRN,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_OTHER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TG(_QWERTY), _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_EMBG, KC_SML, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XCAUTHOR, _______, _______, _______, _______,                            _______, _______, XEDITOR ,XBEDITOR, XCEDTR, XFOCUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, XRUNB   , _______,          _______, _______, _______,  XBACK,  XFRWD, XCHANGE, XCOEDTR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, XFOCUS,                   _______, _______, _______
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