#include QMK_KEYBOARD_H
#include "macroses.h"

// Custom keycodes.
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        extern uint32_t tap_timer;
        tap_timer = timer_read32();
    }
    switch (keycode) {
        case NEXTSEN:  // Next sentence macro.
          if (record->event.pressed) {
            SEND_STRING(". ");
            add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
          }
          return false;

        case PREDL:  // Next sentence macro.
          if (record->event.pressed) {
            SEND_STRING("/ ");
            add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
          }
          return false;

        case BRACES:
            if (record->event.pressed) {
                uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                    if (shifted) {
                        unregister_code(KC_LSFT);
                        unregister_code(KC_RSFT);
                        SEND_STRING("{}"SS_TAP(X_LEFT));
                    }
                    else {
                        SEND_STRING("[]"SS_TAP(X_LEFT));
                    }
            }
            break;

        case PARENTH:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
            break;

        case TMUX:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LCTL(SS_TAP(X_SPC))
                );
            }
            break;

        case LANG1:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_LSFT(SS_TAP(X_7)))
                );
            }
            break;

        case LANG2:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_LSFT(SS_TAP(X_8)))
                );
            }
            break;

        case LANG3:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_LSFT(SS_TAP(X_9)))
                );
            }
            break;

        case LANG4:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_LSFT(SS_TAP(X_0)))
                );
            }
            break;
    }

    return true;
}
