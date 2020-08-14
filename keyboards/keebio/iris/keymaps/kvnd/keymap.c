#include "iris.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum custom_keycodes {
    SHOT_MACRO = SAFE_RANGE,
};

enum {
  TD_RSE = 0,
  TD_PLS,
  TD_BLSH,
  TD_BRCK
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_RASE MO(1)
#define KC_LWR MO(2)
#define KC_OTR MO(3)


#define KC_ZALT MT(MOD_LALT, KC_Z)
#define KC_TCTL MT(MOD_LCTL, KC_GRAVE)

#define KC_TD TD

#define KC_WLFT LALT(KC_LEFT) // WORD LEFT
#define KC_WRHT LALT(KC_RIGHT) // WORD RIGHT

#define KC_XEDT LCTL(LGUI(KC_T)) // XCode - New Editor
#define KC_XEDB LALT(LCTL(LGUI(KC_T))) // XCode - New Editor Below
#define KC_XECL LALT(LCTL(LGUI(KC_W))) // XCode - Close Editor
#define KC_XECO LSFT(LALT(LCTL(LGUI(KC_W)))) // XCode - Close Other Editor
#define KC_XEDF LSFT(LCTL(LGUI(KC_ENT))) // XCode - Focus Editor
#define KC_XMIN LSFT(LCTL(LGUI(KC_M))) // XCode - Toggle Minimap

#define KC_CCRL LCTL(KC_GRAVE) // XCode - Change Editor
#define KC_CLAE HYPR(KC_GRAVE) // XCode - Close Editor
#define KC_XBCK LCTL(LGUI(KC_LEFT)) // XCode - History Back
#define KC_XFWD LCTL(LGUI(KC_RIGHT)) // XCode - History Forward

#define KC_SWAP LCTL(KC_T)
#define KC_ALRD LGUI(KC_SPACE) // Toggle Alfred

#define KC_LOCK HYPR(KC_L) // Lock the screen via Alfred
#define KC_SCST SHOT_MACRO // Screenshot Macro
#define KC_FCS HYPR(KC_F) // Trigger Focus

//Tap Dance Definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//   //Tap once for quote, twice for RAISE
//   [TD_RSE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, TO(1)),
//   [TD_PLS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL),
//   [TD_BLSH] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_BSLASH),
//   [TD_BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  ,  0 ,MINUS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,LBRACKET,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RASE, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN, QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,ZALT, X  , C  , V  , B  ,BSPC,          , N  , M  ,COMM,DOT ,SLSH,LWR,
  //`i----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       TCTL,LGUI,ENT,          SPC ,ALRD,OTR
  //                  `----+----+----'        `----+----+----'
  ),

  KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     LOCK,MUTE,MRWD,MFFD,MPLY,    ,                   ,    ,   ,    ,BSLASH,EQUAL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8 , 9  ,  0 ,RBRACKET,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,VOLD,VOLU,    ,SCST,    ,               LEFT,DOWN,UP,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,   ,     ,SCST,         ,    ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,     ,LCBR,         LBRC, DOT,EQUAL
  //                  `----+----+----'        `----+----+----'
  ),

  KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH, DLR,PERC,              ,CIRC,AMPR,ASTR,LPRN,RPRN,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,CIRC,AMPR,ASTR,LPRN,RPRN,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,BSLS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,SLSH,RCBR,         RBRC, DOT,EQUAL
  //                  `----+----+----'        `----+----+----'
  ),

  KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     LOCK,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,XEDT,XEDB,XECL,XEDF,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,   ,     ,    ,         ,    ,    ,   ,XBCK,XFWD,CCRL,XECO,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),
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
