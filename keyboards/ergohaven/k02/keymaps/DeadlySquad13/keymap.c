#include QMK_KEYBOARD_H
#include "oled/bongocat.c"
// #include "oled/luna.c"

#define _BASE 0
#define _NAV 1
#define _SYMB 2
#define _MEDIA 3
#define _GAME 4
#define _NUM  5
#define _FUNC 6
#define _SETS 7

#define _EIGHT 8
#define _NINE 9
#define _TEN 10
#define _ELEVEN 11
#define _TWELVE 12
#define _THIRTEEN 13
#define _FOURTEEN 14
#define _FIFTEEN 15
#define _SIXTEEN 16

#define BASE    DF(_BASE)
#define NAV     MO(_NAV)
#define SYMB    MO(_SYMB)
#define MEDIA   MO(_MEDIA)
#define GAME    DF(_GAME)
#define NUM     MO(_NUM)
#define FUNC    MO(_FUNC)
#define SETS    OSL(_SETS)

#define PREVWRD   LCTL(KC_LEFT)
#define NEXTWRD   LCTL(KC_RIGHT)

enum custom_keycodes {
    NEXTSEN = USER00,
    PREDL,
    BRACES,
    PARENTH,
    TMUX,
    LANG1,
    LANG2,
    LANG3,
    LANG4,
};

// --- Tap Dance. ---
#define TD_SPACE_LSFT TD(0)
#define TD_ENTER_NAV TD(2)
#define TD_TMUX_SYMB TD(3)
#define TD_DEL_NUM TD(4)
#define TD_CAPS_GAME TD(5)
// #define TD_BSPC_FUN TD(30)

// Home row mods.
#define TD_S_LGUI TD(25)
#define TD_D_LALT TD(26)
#define TD_F_LCTL TD(27)
// Bottom row mods.
#define TD_M_RCTL TD(28)
#define TD_COMM_RALT TD(29)
#define TD_DOT_RGUI TD(30)


#define FAST_TAPPING_TERM 130
#define MEDIUM_TAPPING_TERM 140
#define SLOW_TAPPING_TERM 160

// --- Combos. ---
enum combo_keycodes {
    CM_JK_ESCAPE,
    CM_LSCLN_ENTER,
};


void keyboard_post_init_user(void) {
    vial_tap_dance_entry_t td_SPACE_LSFT = {
        KC_SPACE,
        KC_LSFT,
        KC_NO,
        KC_NO,
        MEDIUM_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_ENTER_NAV = {
        KC_ENTER,
        NAV,
        KC_NO,
        KC_NO,
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
        KC_NO,
        SLOW_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_D_LALT = {
        KC_D,
        KC_LALT,
        KC_NO,
        KC_NO,
        MEDIUM_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_F_LCTL = {
        KC_F,
        KC_LCTL,
        KC_NO,
        KC_NO,
        FAST_TAPPING_TERM
    };

    // Bottom row mods.
    vial_tap_dance_entry_t td_M_RCTL = {
        KC_M,
        KC_RCTL,
        KC_NO,
        KC_NO,
        FAST_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_COMM_RALT = {
        KC_COMM,
        KC_RALT,
        KC_NO,
        KC_NO,
        MEDIUM_TAPPING_TERM
    };

    vial_tap_dance_entry_t td_DOT_RGUI = {
        KC_DOT,
        KC_RGUI,
        KC_NO,
        KC_NO,
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
        KC_NO,
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

    // --- Combos. ---
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
};

// --- Layers. ---
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT_all( \
            KC_GRV,       KC_1,    KC_2,      KC_3,       KC_4,         KC_5,                                        KC_6,          KC_7,         KC_8,          KC_9,        KC_0,    SETS, \
            TD_CAPS_GAME, KC_Q,    KC_W,      KC_E,       KC_R,         KC_T,                                        KC_Y,          KC_U,         KC_I,          KC_O,        KC_P,    KC_BSLS, \
            KC_TAB,       KC_A,    TD_S_LGUI, TD_D_LALT,  TD_F_LCTL,    KC_G,                                        KC_H,          KC_J,         KC_K,          KC_L,        KC_SCLN, KC_QUOT, \
            MEDIA,        KC_Z,    KC_X,      KC_C,       KC_V,         KC_B,                                        KC_N,          TD_M_RCTL,    TD_COMM_RALT,  TD_DOT_RGUI, KC_SLSH, MEDIA, \
                                   QK_BOOT,   TD_DEL_NUM, TD_ENTER_NAV, TD_SPACE_LSFT, TD_TMUX_SYMB,   TD_TMUX_SYMB, TD_SPACE_LSFT, TD_ENTER_NAV, KC_BSPC,       FUNC \
        ),

        [_NAV] = LAYOUT_all( \
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                           KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,  _______,
            QK_BOOT, _______, KC_HOME, KC_UP,   KC_END,   _______,                          _______, KC_HOME,  _______, KC_END,   KC_ESC,  _______,
            _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,                          KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_CAPS, _______,
            _______, _______, PREVWRD, NEXTSEN, NEXTWRD,  _______,                          KC_PSCR, KC_ENTER, _______, _______,  _______, _______,
                              _______, _______, _______,  _______, _______,        _______, _______, _______,  _______, _______\
        ),

        [_SYMB] = LAYOUT_all( \
            _______, _______, KC_AT,   KC_HASH, KC_DLR, _______,                         _______, _______, KC_CIRC, _______, _______,  QK_BOOT,
            _______, KC_TILD, KC_LT,   KC_MINS, KC_GT,   KC_GRV,                         _______, KC_LBRC, KC_UNDS, KC_RBRC, _______,  _______,
            _______, KC_PLUS, KC_LPRN, KC_EQL,  KC_RPRN, KC_BSLS,                        KC_PERC, KC_LCBR, KC_QUOT, KC_RCBR, KC_EXLM,  _______,
            KC_LSFT, KC_DQUO, KC_ASTR, KC_SCLN, KC_SLSH, _______,                        KC_AMPR, KC_QUES, KC_COLN, KC_PIPE, _______,  QK_RBT,
                              _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______ \
        ),

        [_MEDIA] = LAYOUT_all(
            _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, DM_PLY1, DM_REC1,
            RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                           _______, KC_VOLD, KC_MUTE, KC_VOLU, DM_PLY2, DM_REC2,
            RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, CG_TOGG,                           _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, DM_RSTP,
                              _______, _______, _______, _______, _______,         _______, _______,  _______, _______, _______
        ),

        [_GAME] = LAYOUT_all(
            _______, _______, _______, _______, _______, _______,                            _______, _______,  _______, _______, _______, _______,
            KC_ESC,  _______, KC_W,    _______, _______, _______,                            _______, _______,  _______, _______, _______, _______,
            KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    _______,                            _______, _______,  _______, _______, _______, _______,
            KC_LSFT, _______, _______, _______, _______, _______,                            _______, _______,  _______, _______, _______, KC_INS,
                              BASE,    _______, KC_LALT, KC_SPACE, KC_LCTL,         _______, _______, KC_ENTER, KC_BSPC, BASE \
        ),

        [_NUM] = LAYOUT_all( \
            _______, _______, _______, _______, _______, _______,                           _______,  _______,  _______, _______,  _______,  _______,
            _______, _______, _______, _______, _______, _______,                           _______,  KC_7,     KC_8,    KC_9,     _______,  _______,
            _______, _______, _______, _______, _______, _______,                           _______,  KC_4,     KC_5,    KC_6,     _______,  _______,
            _______, _______, _______, _______, _______, _______,                           _______,  KC_1,     KC_2,    KC_3,     _______,  _______,
                              _______, _______, _______, _______, _______,         _______, KC_0,     _______, _______,  _______ \
        ),

        [_FUNC] = LAYOUT_all( \
            _______, _______, _______, _______, _______, _______,                         _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______,                         _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______,                         _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F10,  KC_1,    KC_F2,   KC_F3,   _______,                         _______,  _______,  _______, _______,  _______,  _______,
                              _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______ \
        ),

        [_SETS] = LAYOUT_all( \
            _______, _______, _______, _______, _______, _______,                          _______, LANG1,   LANG2,   LANG3,    LANG4,    _______,
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
                              _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______ \
        ),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case CM_JK_ESCAPE:
            if (get_highest_layer(default_layer_state) == _GAME) {
                return false;
            }
    }

    return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     if (get_highest_layer(default_layer_state) == _GAME) {
//         combo_disable();
//     }
//     else {
//         combo_enable();
//     }

//     return state;
// }

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_0;  // Bongocat.
        // return OLED_ROTATION_270;  // Luna.
    }
    else {
        return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

void render_layer_state(void) {
    oled_write_ln_P(PSTR("BASE\n"), false);
    oled_write_ln_P(PSTR("\n"), false);
    switch(get_highest_layer(default_layer_state)) {
        case _BASE:
            oled_write_P(PSTR("QWERT"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
    }

    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE\n"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("Mac"), false);
    } else {
        oled_write_ln_P(PSTR("Win"), false);
    }

    oled_write_P(PSTR("\n\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);

    switch (get_highest_layer(layer_state)) {
        case _SYMB:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Symb\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Fun\n"), false);
            break;
        case _SETS:
            oled_write_P(PSTR("Sets\n"), false);
            break;
        case _EIGHT:
            oled_write_P(PSTR("Eight"), false);
            break;
        case _NINE:
            oled_write_P(PSTR("Nine\n"), false);
            break;
         case _TEN:
            oled_write_P(PSTR("Ten\n"), false);
            break;
         case _ELEVEN:
            oled_write_P(PSTR("Elevn"), false);
            break;
         case _TWELVE:
            oled_write_P(PSTR("Twlve"), false);
            break;
         case _THIRTEEN:
            oled_write_P(PSTR("Thrtn"), false);
            break;
         case _FOURTEEN:
            oled_write_P(PSTR("Frtn"), false);
            break;
         case _FIFTEEN:
            oled_write_P(PSTR("Fiftn"), false);
            break;
         case _SIXTEEN:
            oled_write_P(PSTR("Sixtn"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Base"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}


// Used to draw on to the oled screen
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_state();
    } else {
        render_bongocat();  // bongocat
        // render_luna_status();  // luna
    }

    return false;
}

#endif


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
