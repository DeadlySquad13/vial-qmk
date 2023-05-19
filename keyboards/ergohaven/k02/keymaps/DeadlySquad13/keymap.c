#include QMK_KEYBOARD_H
#include "definitions.h"
#include "tap_dance.h"
#include "macroses.h"

// --- Layers. ---
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT_all( \
            KC_GRV,       KC_1,    KC_2,      KC_3,       KC_4,         KC_5,                                        KC_6,          KC_7,         KC_8,          KC_9,        KC_0,    SETS, \
            TD_CAPS_GAME, KC_Q,    KC_W,      KC_E,       KC_R,         KC_T,                                        KC_Y,          KC_U,         KC_I,          KC_O,        KC_P,    KC_BSLS, \
            KC_TAB,       KC_A,    TD_S_LGUI, TD_D_LALT,  TD_F_LCTL,    KC_G,                                        KC_H,          KC_J,         KC_K,          KC_L,        KC_SCLN, KC_QUOT, \
            MEDIA,        KC_Z,    KC_X,      KC_C,       KC_V,         KC_B,                                        KC_N,          TD_M_RCTL,    TD_COMM_RALT,  TD_DOT_RGUI, KC_SLSH, MEDIA, \
                                   QK_BOOT,   TD_DEL_NUM, TD_ENTER_NAV, TD_SPACE_LSFT, TD_TMUX_SYMB,   TD_TMUX_SYMB, TD_SPACE_LSFT, TD_ENTER_NAV, KC_BSPC,       FUNC \
        ),

        [_NAV] = LAYOUT_all( \
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                           KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,  _______,
            QK_BOOT, _______, KC_HOME, KC_UP,   KC_END,   _______,                          _______, KC_HOME,  _______, KC_END,   KC_ESC,  _______,
            _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,                          KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_CAPS, _______,
            _______, _______, PREVWRD, NEXTSEN, NEXTWRD,  _______,                          KC_PSCR, KC_ENTER, _______, _______,  _______, _______,
                              _______, _______, _______,  _______, _______,        _______, _______, _______,  _______, _______\
        ),

        [_SYMB] = LAYOUT_all( \
            _______, _______,  KC_AT,   KC_HASH,  KC_DLR,  _______,                        _______,  _______,  KC_CIRC,  _______, _______, QK_BOOT,
            _______, KC_TILD,  _KC_LT,  KC_MINS,  _KC_GT,   KC_GRV,                         _______,  KC_LBRC,  KC_UNDS,  KC_RBRC, _______, _______,
            _______, KC_PLUS,  KC_LPRN, KC_EQL,   KC_RPRN, KC_BSLS,                        KC_PERC,  KC_LCBR,  _KC_QUOT, KC_RCBR, KC_EXLM, _______,
            KC_LSFT, _KC_DQUO, KC_ASTR, _KC_SCLN, KC_SLSH, _______,                        _KC_AMPR, _KC_QUES, _KC_COLN, KC_PIPE, _______, QK_RBT,
                                _______, _______, _______, _______, _______,       _______, _______, _______,  _______,  _______ \
        ),

        [_MEDIA] = LAYOUT_all(
            _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, DM_PLY1, DM_REC1,
            RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                           _______, KC_VOLD, KC_MUTE, KC_VOLU, DM_PLY2, DM_REC2,
            RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, CG_TOGG,                           _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, DM_RSTP,
                              _______, _______, _______, _______, _______,         _______, _______,  _______, _______, _______
        ),

        [_GAME] = LAYOUT_all(
            _______, _______, _______, _______, _______, _______,                            _______, _______,  _______, _______, _______, _______,
            KC_ESC,  _______, KC_W,    _______, _______, _______,                            _______, _______,  _______, _______, _______, _______,
            KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    _______,                            _______, _______,  _______, _______, _______, _______,
            KC_LSFT, _______, _______, _______, _______, _______,                            _______, _______,  _______, _______, _______, KC_INS,
                              BASE,    _______, KC_LALT, KC_SPACE, KC_LCTL,         _______, _______, KC_ENTER, KC_BSPC, BASE \
        ),

        [_NUM] = LAYOUT_all( \
            _______, _______, _______, _______, _______, _______,                           _______,  _______,  _______, _______,  _______,  _______,
            _______, _______, _______, _______, _______, _______,                           _______,  KC_7,     KC_8,    KC_9,     _______,  _______,
            _______, _______, _______, _______, _______, _______,                           _______,  KC_4,     KC_5,    KC_6,     _______,  _______,
            _______, _______, _______, _______, _______, _______,                           _______,  KC_1,     KC_2,    KC_3,     _______,  _______,
                              _______, _______, _______, _______, _______,         _______, KC_0,     _______, _______,  _______ \
        ),

        [_FUNC] = LAYOUT_all( \
            _______, _______, _______, _______, _______, _______,                         _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______,                         _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______,                         _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F10,  KC_1,    KC_F2,   KC_F3,   _______,                         _______,  _______,  _______, _______,  _______,  _______,
                              _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______ \
        ),

        [_SETS] = LAYOUT_all( \
            _______, _______, _______, _______, _______, _______,                          _______, LANG1,   LANG2,   LANG3,    LANG4,    _______,
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
                              _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______ \
        ),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     if (get_highest_layer(default_layer_state) == _GAME) {
//         combo_disable();
//     }
//     else {
//         combo_enable();
//     }

//     return state;
// }

