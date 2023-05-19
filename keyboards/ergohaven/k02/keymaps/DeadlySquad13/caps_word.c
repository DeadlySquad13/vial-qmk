#include "definitions.h"
#include "tap_dance.h"

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        // Home row mods.
        case TD_S_LGUI:
        case TD_D_LALT:
        case TD_F_LCTL:
        // Bottom row mods.
        case TD_M_RCTL:
        case TD_COMM_RALT:
        case TD_DOT_RGUI:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        // Some layers should preserve it too.
        case NUM:
        case SYMB:
        case TD_DEL_NUM:
        case TD_TMUX_SYMB:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
