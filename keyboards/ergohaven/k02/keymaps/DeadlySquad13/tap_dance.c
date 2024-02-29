#include QMK_KEYBOARD_H
#include "tap_dance.h"
#include "definitions.h"

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
            // add_oneshot_mods(MOD_BIT(KC_LGUI));
            set_oneshot_layer(_WORKSPACE, ONESHOT_START);
            // layer_on(_WORKSPACE);
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
            // layer_off(_WORKSPACE);
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


// Set tapping term for tap-dance keys.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WORKSPACE_NAV:
            return ULTRA_FAST_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}
