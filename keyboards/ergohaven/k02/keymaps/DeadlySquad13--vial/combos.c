#include "definitions.h"
#include "combos.h"
#include "tap_dance.h"

void post_init_combos(void) {
    vial_combo_entry_t cm_JK_ESCAPE = {
        KC_J,
        KC_K,
        KC_NO,
        KC_NO,
        KC_ESC
    };

    vial_combo_entry_t cm_LSCLN_ENTER = {
        KC_L,
        KC_SCLN,
        KC_NO,
        KC_NO,
        KC_ENTER
    };

    vial_combo_entry_t cm_DF_ESCAPE = {
        TD_D_LALT,
        TD_F_LCTL,
        KC_NO,
        KC_NO,
        KC_ESC
    };

    vial_combo_entry_t cm_AS_ENTER = {
        KC_A,
        TD_S_LGUI,
        KC_NO,
        KC_NO,
        KC_ENTER
    };


    dynamic_keymap_set_combo(0, &cm_JK_ESCAPE);
    dynamic_keymap_set_combo(1, &cm_LSCLN_ENTER);

    dynamic_keymap_set_combo(2, &cm_DF_ESCAPE);
    dynamic_keymap_set_combo(3, &cm_AS_ENTER);
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case CM_JK_ESCAPE:
            if (get_highest_layer(default_layer_state) == _GAME) {
                return false;
            }
    }

    return true;
}
