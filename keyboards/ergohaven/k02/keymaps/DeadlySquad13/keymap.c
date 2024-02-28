#include QMK_KEYBOARD_H
#include "layers.c"
#include "definitions.h"
#include "macroses.h"

const uint16_t PROGMEM combo_a_s[] = {KC_A, MT_LGUI_S, COMBO_END};
const uint16_t PROGMEM combo_d_f[] = {MT_LALT_D, MT_LTCL_F, COMBO_END};

const uint16_t PROGMEM combo_j_k[] = {MT_RTCL_J, MT_RALT_K, COMBO_END};
const uint16_t PROGMEM combo_l_scln[] = {MT_RGUI_L, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_a_s, KC_ENTER),
    COMBO(combo_d_f, KC_ESC),

    COMBO(combo_j_k, KC_ESC),
    COMBO(combo_l_scln, KC_ENTER),
};

// Tap Dance keycodes
enum td_keycodes {
    WORKSPACE_NAV // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    // TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void workspace_nav_finished(tap_dance_state_t *state, void *user_data);
void workspace_nav_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT( \
          KC_GRV, KC_1, KC_2,      KC_3,      KC_4,      KC_5,                         KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    SETS, \
          GAME,   KC_Q, KC_W,      KC_E,      KC_R,      KC_T,                         KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,    KC_LBRC, \
          KC_TAB, KC_A, MT_LGUI_S, MT_LALT_D, MT_LTCL_F, KC_G,                         KC_H,      MT_RTCL_J, MT_RALT_K, MT_RGUI_L, KC_SCLN, KC_QUOT, \
          MEDIA,  KC_Z, KC_X,      KC_C,      KC_V,      KC_B,                         KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH, KC_RSFT, \
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
        //     _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        //     _______, _______, _______, LGUI(KC_E), _______, _______,                           _______, _______, _______, _______, _______, _______,
        //     _______, _______, LGUI(KC_S), LGUI(KC_D), LGUI(KC_F), _______,                 _______, _______, _______, _______, _______, _______,
        //     _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        //                        _______,  _______,  _______,  _______,  _______,    _______, _______,  _______,  _______,  _______ \
        // ),

        [_MEDIA] = LAYOUT(
            _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, DM_PLY1, DM_REC1,
            RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                           _______, KC_VOLD, KC_MUTE, KC_VOLU, DM_PLY2, DM_REC2,
            RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, CG_TOGG,                           _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, DM_RSTP,
                              _______, _______, _______, _______, _______,         _______, _______,  _______, _______, _______
        ),

        [_GAME] = LAYOUT( \
            _______, _______, _______, _______, _______, _______,                           _______, _______,  _______, _______, _______, _______,
            KC_ESC,  _______, KC_W,    _______, _______, _______,                           _______, _______,  _______, _______, _______, _______,
            KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    _______,                           _______, _______,  _______, _______, _______, _______,
            KC_LSFT, _______, _______, _______, _______, _______,                           _______, _______,  _______, _______, _______, KC_INS,
                              BASE,    _______, KC_LALT, KC_SPACE, KC_LCTL,        _______, _______, KC_ENTER, KC_BSPC, BASE \
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
// https://docs.qmk.fm/#/feature_tap_dance?id=example-5
// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    // if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define.
void workspace_nav_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            add_oneshot_mods(MOD_BIT(KC_LGUI));
            break;
        case TD_SINGLE_HOLD:
            layer_on(_NAV);
            break;
        // case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
        //     tap_code16(KC_LPRN);
        //     register_code16(KC_LPRN);
        //     break;
        default:
            break;
    }
}

void workspace_nav_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            // del_oneshot_mods(MOD_BIT(KC_LGUI));
            break;
        case TD_SINGLE_HOLD:
            layer_off(_NAV);
            break;
        // case TD_DOUBLE_SINGLE_TAP:
        //     unregister_code16(KC_LPRN);
        //     break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [WORKSPACE_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, workspace_nav_finished, workspace_nav_reset)
};


#define ULTRA_FAST_TAPPING_TERM 110
#define FAST_TAPPING_TERM 130
#define MEDIUM_TAPPING_TERM 140
#define SLOW_TAPPING_TERM 160

// Set tapping term for tap-dance keys.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WORKSPACE_NAV:
            return ULTRA_FAST_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}
