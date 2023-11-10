#include QMK_KEYBOARD_H

#define _BASE 0
#define _NAV 1
#define _SYMB 2
#define _MEDIA 3
#define _GAME 4
#define _NUM  5
#define _FUNC 6
#define _SETS 7

#define _EIGHT 8
#define _NINE 9
#define _TEN 10
#define _ELEVEN 11
#define _TWELVE 12
#define _THIRTEEN 13
#define _FOURTEEN 14
#define _FIFTEEN 15
#define _SIXTEEN 16

// Layers.
#define BASE    DF(_BASE)
#define NAV     MO(_NAV)
#define SYMB    OSL(_SYMB)
#define MEDIA   MO(_MEDIA)
#define GAME    DF(_GAME)
// #define NUM     MO(_NUM)
#define FUNC    MO(_FUNC)
#define SETS    OSL(_SETS)

// Tap-dance layers.
#define NUM_DEL LT(_NUM, KC_DEL)
#define NAV_SPACE LT(_NAV, KC_SPACE)

// Mods.
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)

// Home-mods (home-row tap dance modifiers).
#define MT_LGUI_S MT(MOD_LGUI, KC_S)
#define MT_LALT_D MT(MOD_LALT, KC_D)
#define MT_LTCL_F MT(MOD_LCTL, KC_F)

#define MT_RTCL_J MT(MOD_RCTL, KC_J)
#define MT_RALT_K MT(MOD_RALT, KC_K)
#define MT_RGUI_L MT(MOD_RGUI, KC_L)

// Mappings for universal layout symbol layer. Should be synchronized with ahk.
#define _KC_EXLM LCAG(KC_1)

#define _KC_QUOT LCAG(KC_2)
#define _KC_DQUO HYPR(KC_2)

#define _KC_SCLN LCAG(KC_4)

#define _KC_COLN LCAG(KC_6)

#define _KC_QUES LCAG(KC_7)
#define _KC_AMPR HYPR(KC_7)

#define _KC_ASTR LCAG(KC_8)

#define _KC_LPRN LCAG(KC_9)

#define _KC_RPRN LCAG(KC_0)

#define _KC_MINS LCAG(KC_F13)

#define _KC_EQL LCAG(KC_F14)
#define _KC_PLUS HYPR(KC_F14)

#define _KC_LBRC LCAG(KC_F15)
#define _KC_LCBR HYPR(KC_F15)

#define _KC_RBRC LCAG(KC_F16)
#define _KC_RCBR HYPR(KC_F16)

#define _KC_LT LCAG(KC_F17)

#define _KC_GT LCAG(KC_F18)

#define _KC_BSLS LCAG(KC_F19)
#define _KC_PIPE HYPR(KC_F19)

#define _KC_SLSH LCAG(KC_F20)

#define PREVWRD   LCTL(KC_LEFT)
#define NEXTWRD   LCTL(KC_RIGHT)
