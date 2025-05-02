// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#define KC_ADJ_PSCR LT(_ADJUST, KC_PSCR)
// #define KC_RAISE LT(_RAISE, KC_ENT)
// #define KC_LOWER LT(_LOWER, KC_TAB)
#define KC_RAISE MO(_RAISE)
#define KC_LOWER MO(_LOWER)
#define KC_LCTL LCTL_T(KC_SPC)
#define KC_RCTL RCTL_T(KC_SPC)

const uint16_t PROGMEM esc_combo[] = {KC_A, KC_S, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
};

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_TML, // TML = Tmux leader key Ctrl + a
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,     KC_5,   KC_CAPS,                     KC_MUTE, KC_6,    KC_7,          KC_8,    KC_9,    KC_0,     KC_QUOT,
  QK_GESC,  KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,   KC_PGUP,                     KC_VOLU, KC_Y,    KC_U,          KC_I,    KC_O,    KC_P,     KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,     KC_G,   KC_PGDN,                    KC_VOLD, KC_H,    KC_J,          KC_K,    KC_L,    KC_SCLN,  KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,                                         KC_N,    KC_M,          KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
  KC_UNDS,  KC_EQL, KC_LGUI, KC_LALT,           KC_LOWER, KC_LCTL,               KC_RCTL,  KC_RAISE,                  KC_RALT, KC_RGUI, KC_LBRC,  KC_RBRC,
                                                KC_ADJ_PSCR, KC_F5,                 KC_F6, KC_TML, 
                                                KC_F10, KC_F9,                       KC_F7, KC_F8
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_MPLY,               KC_FIND, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_MCTL,              KC_NXTWD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  KC_TILD, KC_EXLM,   KC_AT,   KC_HASH,  KC_DLR,  KC_PERC, KC_LPAD,              KC_PRVWD, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  KC_LSFT,  KC_EQL,   KC_MINS, KC_PLUS,  KC_LCBR, KC_RCBR,                                 KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_RSFT,
  _______,   _______,  _______, _______,  _______, _______,                                _______, _______, _______, _______, _______, _______,
                                              _______,  _______,                  _______, _______,
                                              _______,  _______,                  _______, _______
),

/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
*/

[_RAISE] = LAYOUT(
  _______,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   CG_TOGG,                KC_CAPS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,     KC_F11,
  KC_GRV,   KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_0,                   KC_0,  KC_6,     KC_7,     KC_8,     KC_9,      KC_0,       KC_F12,
  KC_TILD,  KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,  KC_PERC, KC_0,                   KC_0,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_DEL,     KC_PIPE,
  KC_LSFT,  KC_EQL,  KC_MINS, KC_PLUS,  KC_LCBR, KC_RCBR,                                XXXXXXX,  KC_LSTRT, XXXXXXX,  KC_LEND,   XXXXXXX,    KC_RSFT,
  _______, _______,  _______,   _______, _______, _______,                               _______,  _______,  _______,  _______,   _______,    _______,
                                              _______, _______,                   _______,   _______,
                                              _______, _______,                   _______,   _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

    [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX, KC_0,                 KC_0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
  QK_BOOT,  XXXXXXX, KC_QWERTY, XXXXXXX,  CG_TOGG,  XXXXXXX, KC_0,                 KC_0, XXXXXXX, MS_BTN1, MS_BTN3, MS_BTN2, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, CG_TOGG,   XXXXXXX,  XXXXXXX,  XXXXXXX, KC_0,                 KC_0, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  _______,  _______, _______,   _______,  _______,  _______,                             _______, _______, _______, _______, _______, _______,
                                                _______,  _______,                 _______,   _______,
                                                _______,  _______,                 _______,   _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }

            return false;

        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_MASK_CS));
                    register_code(KC_TAB);
                } else {
                    register_mods(mod_config(MOD_MASK_SA));
                    register_code(KC_TAB);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_MASK_CS));
                    unregister_code(KC_TAB);
                } else {
                    unregister_mods(mod_config(MOD_MASK_SA));
                    unregister_code(KC_TAB);
                }
            }

            break;

        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_MASK_CTRL));
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                } else {
                    register_mods(mod_config(MOD_MASK_ALT));
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_MASK_CTRL));
                } else {
                    unregister_mods(mod_config(MOD_MASK_ALT));
                }
            }

            break;

        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }

            break;

        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;

        case KC_TML:
            SEND_STRING(SS_LCTL("a"));
            break;

    }

    return true;
}
