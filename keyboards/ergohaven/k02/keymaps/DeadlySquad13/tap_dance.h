#ifndef TAP_DANCE_H
#define TAP_DANCE_H

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


#define ULTRA_FAST_TAPPING_TERM 110
#define FAST_TAPPING_TERM 130
#define MEDIUM_TAPPING_TERM 140
#define SLOW_TAPPING_TERM 160

#endif
