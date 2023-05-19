#include "definitions.h"
#include "tap_dance.h"
#include "combos.h"

void post_init_tap_dance(void) {
    // Tap, Hold, Double tap, Tap + hold.
    vial_tap_dance_entry_t td_SPACE_LSFT = {
        KC_SPACE,
        KC_LSFT,
        KC_NO,
        KC_SPACE,
        MEDIUM_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_ENTER_NAV = {
        KC_ENTER,
        NAV,
        KC_NO,
        KC_ENTER,
        MEDIUM_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_TMUX_SYMB = {
        TMUX,
        SYMB,
        KC_NO,
        KC_NO,
        MEDIUM_TAPPING_TERM
    };

    // Home row mods.
    vial_tap_dance_entry_t td_S_LGUI = {
        KC_S,
        KC_LGUI,
        KC_NO,
        KC_S,
        SLOW_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_D_LALT = {
        KC_D,
        KC_LALT,
        KC_NO,
        KC_D,
        MEDIUM_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_F_LCTL = {
        KC_F,
        KC_LCTL,
        KC_NO,
        KC_F,
        FAST_TAPPING_TERM
    };

    // Bottom row mods.
    vial_tap_dance_entry_t td_M_RCTL = {
        KC_M,
        KC_RCTL,
        KC_NO,
        KC_M,
        FAST_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_COMM_RALT = {
        KC_COMM,
        KC_RALT,
        KC_NO,
        KC_COMM,
        MEDIUM_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_DOT_RGUI = {
        KC_DOT,
        KC_RGUI,
        KC_NO,
        KC_DOT,
        SLOW_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_CAPS_GAME= {
        CAPS_WORD,
        GAME,
        KC_NO,
        KC_NO,
        SLOW_TAPPING_TERM
    };


    vial_tap_dance_entry_t td_DEL_NUM = {
        KC_DEL,
        NUM,
        KC_NO,
        KC_DEL,
        MEDIUM_TAPPING_TERM
    };

    // vial_tap_dance_entry_t td_VIRTUALDESKTOP___GAME = {
    //     C(G(KC)),
    //     KC_NO,
    //     GAME,
    //     KC_NO,
    //     MEDIUM_TAPPING_TERM
    // };

    // The first parameter corresponds to the TD(i) slot.
    dynamic_keymap_set_tap_dance(0, &td_SPACE_LSFT);
    dynamic_keymap_set_tap_dance(2, &td_ENTER_NAV);
    dynamic_keymap_set_tap_dance(3, &td_TMUX_SYMB);
    dynamic_keymap_set_tap_dance(4, &td_DEL_NUM);
    dynamic_keymap_set_tap_dance(5, &td_CAPS_GAME);

    // Home row mods.
    dynamic_keymap_set_tap_dance(25, &td_S_LGUI);
    dynamic_keymap_set_tap_dance(26, &td_D_LALT);
    dynamic_keymap_set_tap_dance(27, &td_F_LCTL);
    // Bottom row mods.
    dynamic_keymap_set_tap_dance(28, &td_M_RCTL);
    dynamic_keymap_set_tap_dance(29, &td_COMM_RALT);
    dynamic_keymap_set_tap_dance(30, &td_DOT_RGUI);
}
