#include QMK_KEYBOARD_H
#include "definitions.h"
#include "macroses.h"

const uint16_t PROGMEM combo_a_s[] = {KC_A, MT_LGUI_S, COMBO_END};
const uint16_t PROGMEM combo_d_f[] = {MT_LALT_D, MT_LTCL_F, COMBO_END};

const uint16_t PROGMEM combo_j_k[] = {MT_RTCL_J, MT_RALT_K, COMBO_END};
const uint16_t PROGMEM combo_l_scln[] = {MT_RGUI_L, KC_SCLN, COMBO_END};

const uint16_t PROGMEM combo_x_v[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM combo_c_v[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_z_v[] = {KC_Z, KC_V, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_a_s, KC_ENTER),
    COMBO(combo_d_f, KC_ESC),

    COMBO(combo_j_k, KC_ESC),
    COMBO(combo_l_scln, KC_ENTER),

    COMBO(combo_x_v, COPY),
    COMBO(combo_c_v, PASTE),
    COMBO(combo_z_v, CUT),
};

