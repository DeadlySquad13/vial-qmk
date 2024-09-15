#ifdef OLED_ENABLE
#include "oled/bongocat.c"
#include "definitions.h"
// TODO: Check if we still need it
#include "font_block.h"
// #include "game/game.h"
// #include "oled/luna.c"

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
    oled_write_ln_P(PSTR("DEFLT\n"), false);
    oled_write_ln_P(PSTR("\n"), false);
    switch(get_highest_layer(default_layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
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
            oled_write_P(PSTR("Symb\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _GAME_RIGHT:
            oled_write_P(PSTR("GameR\n"), false);
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
        case _WORKSPACE:
            oled_write_P(PSTR("WSpce\n"), false);
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
