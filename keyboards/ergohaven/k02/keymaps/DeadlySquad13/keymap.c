#include QMK_KEYBOARD_H
#include "oled/bongocat.c"
/* #include "oled/luna.c" */
#include "font_block.h"
#include "game/game.h"
#include "layers.c"

#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _FOUR 4
#define _FIVE 5
#define _SIX 6
#define _SEVEN 7
#define _EIGHT 8
#define _NINE 9
#define _TEN 10
#define _ELEVEN 11
#define _TWELVE 12
#define _THIRTEEN 13
#define _FOURTEEN 14
#define _FIFTEEN 15

#define BASE      DF(_BASE)
#define RAISE     MO(_RAISE)
#define LOWER     MO(_LOWER)
#define ADJUST    MO(_ADJUST)
#define PREVWRD   LCTL(KC_LEFT)
#define NEXTWRD   LCTL(KC_RIGHT)

#define _BASE 0
#define _NAV 1
#define _SYMB 2
#define _MEDIA 3
#define _GAME 4
#define _NUM  5
#define _FUNC 6
#define _SETS 7

enum custom_keycodes {
    NEXTSEN = QK_KB,
    PREDL,
    BRACES,
    PARENTH,
    GM_INV,
};

#define MT_LGUI_S MT(MOD_LGUI, KC_S)
#define MT_LALT_D MT(MOD_LALT, KC_D)
#define MT_LTCL_F MT(MOD_LCTL, KC_F)

#define MT_RTCL_J MT(MOD_RCTL, KC_J)
#define MT_RALT_K MT(MOD_RALT, KC_K)
#define MT_RGUI_L MT(MOD_RGUI, KC_L)

const uint16_t PROGMEM combo_a_s[] = {KC_A, MT_LGUI_S, COMBO_END};
const uint16_t PROGMEM combo_d_f[] = {MT_LALT_D, MT_LTCL_F, COMBO_END};

const uint16_t PROGMEM combo_j_k[] = {MT_RTCL_J, MT_RALT_K, COMBO_END};
const uint16_t PROGMEM combo_l_scln[] = {MT_RGUI_L, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_a_s, KC_ENTER),
    COMBO(combo_d_f, KC_ESC),

    COMBO(combo_j_k, KC_ESC),
    COMBO(combo_l_scln, KC_ENTER),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT( \
          KC_GRV,   KC_1,    KC_2,    KC_3,     KC_4,     KC_5,                         KC_6,  KC_7,     KC_8,     KC_9,   KC_0,    KC_BSPC, \
          KC_ESC,   KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,                         KC_Y,  KC_U,     KC_I,     KC_O,   KC_P,    KC_LBRC, \
          KC_TAB,   KC_A,    MT_LGUI_S,    MT_LALT_D,     MT_LTCL_F,     KC_G,                         KC_H,  MT_RTCL_J,     MT_RALT_K,     MT_RGUI_L,   KC_SCLN, KC_QUOT, \
          KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,                         KC_N,  KC_M,     KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, \
                                   QK_BOOT,   LT(_NUM, KC_DEL), OSM(MOD_LSFT), LT(_NAV, KC_SPACE), OSL(_SYMB), OSL(_SYMB), LT(_NAV, KC_SPACE), OSM(MOD_RSFT), KC_BSPC,       KC_BSPC \
        ),

        [_NAV] = LAYOUT( \
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                           KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,  _______,
            QK_BOOT, _______, KC_HOME, KC_UP,   KC_END,   _______,                          _______, KC_HOME,  _______, KC_END,   KC_ESC,  _______,
            _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,                          KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_CAPS, _______,
            _______, _______, PREVWRD, NEXTSEN, NEXTWRD,  _______,                          KC_PSCR, KC_ENTER, _______, _______,  _______, _______,
                              _______, _______, _______,  _______, _______,        _______, _______, _______,  _______, _______\
        ),

        [_RAISE] = LAYOUT( \
         _______, _______, KC_AT,   KC_DLR,  KC_HASH, _______,                          _______, _______, KC_CIRC, _______, _______,  QK_BOOT,
         _______, _______, KC_LT,   KC_EQL,  KC_GT,   KC_GRV,                           _______, KC_LBRC, KC_UNDS, KC_RBRC, _______,  _______,
         _______, KC_BSLS, KC_LPRN, KC_MINS, KC_RPRN, KC_PLUS,                          KC_PERC, KC_LCBR, KC_SCLN, KC_RCBR, KC_EXLM,  _______,
         _______, _______, KC_ASTR, KC_COLN, KC_SLSH, _______,                          _______, KC_PIPE, KC_TILD, KC_AMPR, _______,  QK_RBT,
                           _______, _______, _______, ADJUST, _______,         _______, _______, _______, _______, _______ \
        ),

      [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, GM_INV,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, DM_PLY1, DM_REC1,
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                           _______, KC_VOLD, KC_MUTE, KC_VOLU, DM_PLY2, DM_REC2,
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, CG_TOGG,                           _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, DM_RSTP,
                          _______, _______, _______, _______, _______,         _______, _______,  _______, _______, _______

       ),
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // bongocat
    /* return OLED_ROTATION_270;  // luna */
  }
    else {
    set_rotation(1);
    return OLED_ROTATION_270;
    }
  return rotation;
}

void render_layer_state(void) {
    // Print current mode
    oled_write_ln_P(PSTR("K:02\n"), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("v2.9\n"), false);
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
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjst"), false);
            break;
        case _FOUR:
            oled_write_P(PSTR("Four\n"), false);
            break;
        case _FIVE:
            oled_write_P(PSTR("Five\n"), false);
            break;
        case _SIX:
            oled_write_P(PSTR("Six\n"), false);
            break;
        case _SEVEN:
            oled_write_P(PSTR("Seven"), false);
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
            oled_write_P(PSTR("Frtn\n"), false);
            break;
         case _FIFTEEN:
            oled_write_P(PSTR("Fiftn"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}


// Used to draw on to the oled screen
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        /* render_layer_state(); */
         if (!isGamingMode()) {
             render_layer_state();
         }
    } else {
    render_bongocat();  // bongocat
    /* render_luna_status();  // luna */
}
    return false;
}

void matrix_scan_user(void) {
    if (isGamingMode()) {
        if (countMainTimer() > 0) {
            game_main();
        }
    }
}

#endif



// custom keycodes
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
        case GM_INV:
            // Toggle gaming mode & clear OLED display
            if (!record->event.pressed) {
                toggleGamingMode();
                if (isGamingMode()) {
                    readMainTimer();
                    initGame();
                    startGame();
                }
                oled_clear();
            }
            break;
        case KC_S:
            if (record->event.pressed) {
                if (isGamingMode()) {
                    movePlayer(1); // 1 = isLeft
                    return false;
                }
            }
            break;
        case KC_F:
            if (record->event.pressed) {
                if (isGamingMode()) {
                    movePlayer(0); // 0 = isRight
                    return false;
                }
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                if (isGamingMode()) {
                    firePlayerBeam();
                    return false;
                }
            }
            break;
        case KC_ENT:
        case KC_LGUI:
            if (record->event.pressed) {
                if (isGamingMode()) {
                    return false;
                }
            }
            break;
    }
 return true;
}

