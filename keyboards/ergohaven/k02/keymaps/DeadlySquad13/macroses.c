#include QMK_KEYBOARD_H
#include "definitions.h"
#include "macroses.h"
#include "tap_dance.h"
#include "os_detection.h"
#include "caps_word.h"

// Custom keycodes.
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        extern uint32_t tap_timer;
        tap_timer = timer_read32();
    } else {
        if (is_oneshot_layer_active()) {
            // Imitating osl because set_oneshot_layer in tap_dance isn't reset
            // automatically...
            if (IS_LAYER_ON(_WORKSPACE)) {
                layer_off(_WORKSPACE);
            }
        }
        // if (is_oneshot_layer_active() && IS_LAYER_ON(_WORKSPACE)) {
        //     clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        //     reset_oneshot_layer();
        //     SEND_STRING(". ");
        //     layer_off(_WORKSPACE);

        //     return true;
        // }
    }

    // TODO: Add strict type to keycode so that switch corrects when we assign
    // unexisting keycode.
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
            if (detected_host_os() != OS_WINDOWS) {
                del_oneshot_mods(MOD_BIT(KC_LGUI));
            } else {
                del_oneshot_mods(MOD_BIT(KC_LALT));
            }
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LCTL(SS_TAP(X_SPC))
                );
            }
            break;

        case WEZTERM:
            if (detected_host_os() != OS_WINDOWS) {
                del_oneshot_mods(MOD_BIT(KC_LGUI));
            } else {
                del_oneshot_mods(MOD_BIT(KC_LALT));
            }
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_TAP(X_SPC))
                );
            }
            break;

        case VIM_WIN:
            if (detected_host_os() != OS_WINDOWS) {
                del_oneshot_mods(MOD_BIT(KC_LGUI));
            } else {
                del_oneshot_mods(MOD_BIT(KC_LALT));
            }
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LCTL(SS_TAP(X_Q)) // Ctrl-W for vim's windows.
                );
            }
            break;

        case LANG0:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_LSFT(SS_TAP(X_6)))
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

        case COPY:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LCTL(SS_TAP(X_X))
                );
            }
            return false;

        case PASTE:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LCTL(SS_TAP(X_T))
                );
            }
            return false;

        case CUT:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LCTL(SS_TAP(X_Z))
                );
            }
            return false;

        case CAPS_WORD:
            if (record->event.pressed) {
                toggle_caps_word_mode(CAPS_WORD_MODE_DEFAULT);
            }
            return false;
    }

    return true;
}
