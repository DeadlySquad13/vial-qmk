#include QMK_KEYBOARD_H
#include "tap_dance.c"
#include "combos.c"

void keyboard_post_init_user(void) {
    post_init_tap_dance();
    post_init_combos();
};

