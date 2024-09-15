#include QMK_KEYBOARD_H
#include "layers.c"
#include "definitions.h"
#include "tap_dance.h"
#include "macroses.h"
#include "combos.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT( \
          KC_GRV, KC_1, KC_2,      KC_3,      KC_4,      KC_5,                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    SETS, \
          GAME,   KC_Q, KC_W,      KC_E,      KC_R,      KC_T,                             KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,    KC_LBRC, \
          KC_TAB, KC_A, MT_LGUI_S, MT_LALT_D, MT_LCTL_F, KC_G,                             KC_H,      MT_RCTL_J, MT_RALT_K, MT_RGUI_L, KC_SCLN, KC_QUOT, \
          MEDIA,  KC_Z, KC_X,      KC_C,      KC_V,      KC_B,                             KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH, CAPS_WORD, \
                        FUNC,      DEL_NUM,   OSM_LSFT,  TD(WORKSPACE_NAV), SYMB,    SYMB, SPACE_NAV, OSM_RSFT,  KC_BSPC,   FUNC      \
        ),

        [_NAV] = LAYOUT( \
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,  _______,
            QK_BOOT, _______, KC_HOME, KC_UP,   KC_END,   _______,                          _______, KC_HOME,  _______, KC_END,   KC_ESC,  _______,
            _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,                          KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_CAPS, _______,
            _______, _______, PREVWRD, NEXTSEN, NEXTWRD,  _______,                          KC_PSCR, KC_ENTER, _______, _______,  _______, _______,
                              _______, _______, _______,  _______, _______,        _______, _______, _______,  _______, _______\
        ),

        [_SYMB] = LAYOUT( \
            _______, _______,  KC_AT,    _______,  KC_DLR,   _______,                       _______,  _______,  _______,  _______,  _______,  QK_BOOT,
            _______, KC_TILD,  _KC_LT,   _KC_EXLM, _KC_EQL,  _KC_GT,                        _KC_CIRC,  _KC_LBRC, KC_UNDS,  _KC_RBRC, _______,  _______,
            _______, _KC_PLUS, _KC_RPRN, _KC_MINS, _KC_RCBR, _KC_BSLS,                      KC_PERC,  _KC_LCBR, _KC_QUOT, _KC_LPRN, _KC_EXLM, _______,
            KC_LSFT, _KC_SCLN, _KC_SLSH, _KC_DQUO, _KC_ASTR, KC_HASH,                       _KC_AMPR, _KC_QUES, _KC_COLN, _KC_PIPE,  _______, QK_RBT,
                               _______,  _______,  _______,  _______,  _______,    _______, _______,  _______,  _______,  _______ \
        ),

        // [_WORKSPACE] = LAYOUT( \
        //   LGUI(KC_GRV), LGUI(KC_1), LGUI(KC_2),   LGUI(KC_3),      LGUI(KC_4),      LGUI(KC_5),                         LGUI(KC_6),      LGUI(KC_7),      LGUI(KC_8),      LGUI(KC_9),      LGUI(KC_0),    LGUI(KC_ESC), \
        //   KC_ESC, LGUI(KC_Q), LGUI(KC_W),   LGUI(KC_E),      LGUI(KC_R),      LGUI(KC_T),                         LGUI(KC_Y),      LGUI(KC_U),      LGUI(KC_I),      LGUI(KC_O),      LGUI(KC_P),    LGUI(KC_LBRC), \
        //   LGUI(KC_TAB), LGUI(KC_A), LGUI(KC_S),   LGUI(KC_D),      LGUI(KC_F),      LGUI(KC_G),                         LGUI(KC_H),      LGUI(KC_J),      LGUI(KC_K),      LGUI(KC_L),      LGUI(KC_SCLN), LGUI(KC_QUOT), \
        //   MEDIA,        LGUI(KC_Z), LGUI(KC_X),   LGUI(KC_C),      LGUI(KC_V),      LGUI(KC_B),                         LGUI(KC_N),      LGUI(KC_M),      LGUI(KC_COMM),   LGUI(KC_DOT),    LGUI(KC_SLSH), LGUI(KC_RSFT), \
        //                 FUNC,   DEL_NUM,   OSM_LSFT,  TD(WORKSPACE_NAV), SYMB,    SYMB, SPACE_NAV, OSM_RSFT,  KC_BSPC,   FUNC      \
        // ),

        [_WORKSPACE] = LAYOUT( \
          KC_GRV, KC_1, KC_2,   KC_3,      KC_4,      KC_5,                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    KC_ESC, \
          KC_ESC, KC_Q, KC_W,   KC_E,      KC_R,      KC_T,                             KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,    KC_LBRC, \
          KC_TAB, KC_A, KC_S,   KC_D,      KC_F,      KC_G,                             KC_H,      TMUX,      WEZTERM,   VIM_WIN,   KC_SCLN, KC_QUOT, \
          MEDIA,  KC_Z, KC_X,   KC_C,      KC_V,      KC_B,                             KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH, KC_RSFT, \
                        FUNC,   DEL_NUM,   OSM_LSFT,  TD(WORKSPACE_NAV), SYMB,    SYMB, SPACE_NAV, OSM_RSFT,  KC_BSPC,   FUNC      \
        ),

        [_MEDIA] = LAYOUT(
            _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, DM_PLY1, DM_REC1,
            RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                           _______, KC_VOLD, KC_MUTE, KC_VOLU, DM_PLY2, DM_REC2,
            RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, CG_TOGG,                           _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, DM_RSTP,
                              _______, _______, _______, _______, _______,         _______, _______,  _______, _______, _______
        ),

        [_GAME] = LAYOUT( \
            _______, _______, _______, _______, _______, _______,                           _______, _______,  _______, _______, _______, GAME_RIGHT,
            KC_ESC,  _______, KC_W,    _______, _______, _______,                           _______, _______,  _______, _______, _______, _______,
            KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    _______,                           _______, _______,  _______, _______, _______, _______,
            KC_LSFT, _______, _______, _______, _______, _______,                           _______, _______,  _______, _______, _______, KC_INS,
                              BASE,    _______, KC_LALT, KC_SPACE, KC_LCTL,        _______, _______, KC_ENTER, KC_BSPC, BASE \
        ),

        // May just change left hand to passthrough keys.
        [_GAME_RIGHT] = LAYOUT( \
            _______, _______, _______, _______, _______, _______,                           _______, _______,  _______, _______, _______, _______,
            KC_ESC,  _______, KC_W,    _______, _______, _______,                           _______, _______,  _______, _______, _______, _______,
            KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    _______,                           _______, KC_J,     KC_K,    KC_L,    KC_SCLN, _______,
            KC_LSFT, _______, _______, _______, _______, _______,                           _______, _______,  _______, _______, _______, KC_INS,
                              BASE,    _______, KC_LALT, KC_SPACE, KC_LCTL,        _______, _______, KC_ENTER, KC_BSPC, GAME \
        ),

        [_NUM] = LAYOUT( \
            _______, _______, _______, _______, _______, _______,                            _______,  KC_PSLS, KC_PAST,  _______, _______,  _______,
            _______, _______, _______, _______, _______, _______,                            _______,  KC_P7,   KC_P8,    KC_P9,   KC_PPLS,  _______,
            _______, _______, _______, _______, _______, KC_NUM,                             _______,  KC_P4,   KC_P5,    KC_P6,   KC_PPLS,  _______,
            _______, _______, _______, _______, _______, _______,                            _______,  KC_P1,   KC_P2,    KC_P3,   KC_PMNS,  _______,
                              _______, _______, _______, _______, _______,         KC_ENTER, KC_0,     KC_PDOT, _______,  _______ \
        ),

        [_FUNC] = LAYOUT( \
            _______, _______, _______, _______, _______, _______,                           _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______,                           _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______,                           _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______,                           _______,  _______,  _______, _______,  _______,  _______,
                              _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______ \
        ),

        [_SETS] = LAYOUT( \
            _______, LANG4,   LANG3,   LANG2,   LANG1,   LANG0,                            LANG0,   LANG1,   LANG2,   LANG3,    LANG4,    _______,
            // _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
            _______, _______, _______, _______, CG_SWAP, _______,                          _______, _______, _______, _______,  _______,  _______,
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
                              _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______ \
        ),
};
