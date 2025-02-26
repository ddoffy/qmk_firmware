// Copyright 2022 axtlos (@axtloss)
// SPDX-License-Identifier: GPL-2.0-only
#include QMK_KEYBOARD_H

/*
keymap_config.swap_lctl_lgui = true; it means the keyboard is in MAC mode
 */

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// Tap dance declarations
enum {
    TD_SCLN_QUOT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT)
};

enum custom_keycodes {
    KC_COLEMAK = SAFE_RANGE,
    KC_QWERTY,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_GAME,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_UNLOCK,
    KC_CSCOM,
    KC_CREATE,
    KC_SCREENSHOT,
    KC_NEWTAB,
    KC_SW,
    KC_TAB1,
    KC_TAB2,
    KC_TAB3,
    KC_TAB4,
    KC_TAB5,
    KC_TAB6,
    KC_TAB7,
    KC_TAB8,
    KC_TAB9,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|  MUTE |    |ADJUST |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /  Enter/       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
  KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,      KC_CAPS , KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,  KC_LALT, KC_LCTL,KC_LOWER, KC_ENT,      KC_SPC,   KC_RAISE, KC_RCTL, KC_RALT, KC_RGUI
),
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | / Space /       \Space \  |RAISE | RGUI | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_TAB1,   KC_TAB2,    KC_TAB3,    KC_TAB4,    KC_TAB5,                       KC_TAB6,    KC_TAB7,    KC_TAB8,    KC_TAB9,    KC_0, KC_QUOT,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, TD(TD_SCLN_QUOT),  KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_NEWTAB,      KC_SW,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
            KC_LGUI,   KC_LALT,  KC_LCTL, KC_LOWER, KC_SPC,           KC_SPC, KC_RAISE, KC_RCTL, KC_RALT, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|New tab|    |S_wndw|------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   [  |   {  |-------|    |-------|   }  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | Lower | / Space /       \Space\   |Raise | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,    _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                    _______, _______, _______, _______, KC_SPC,        KC_SPC, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |  `   |      |      |      |      |      |                    |           |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------     +------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |SSHOT |      |                    |           | PWrd |      | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------     +------+------+------+------+------|
 * | Tab  |  ae  |  ue  |  oe  |  ss  | euro |-------.    ,-------| Left      | Down |  Up  | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |   |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste| caps |-------|    |-------| KC_CREATE |    ' |  Ins | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | / Space /       \Space \  |RAISE | RGUI | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,KC_INS,  KC_PSCR,KC_MENU,KC_SCREENSHOT, LGUI(KC_5),                        LGUI(KC_6), KC_PGDN,   KC_PGUP, LGUI(KC_9),LGUI(KC_0), KC_BSPC,
  _______,RALT(KC_Q), RALT(KC_Y),  RALT(KC_P), RALT(KC_S) , RALT(KC_5),             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  KC_DEL, KC_BSPC,
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_CAPS,  _______,            _______,KC_CREATE, KC_QUOT, KC_INS, KC_LEND,   XXXXXXX, _______,
                    _______, _______, _______, _______, KC_SPC,                     KC_SPC, _______, _______, _______, _______
),
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RAlt | RCTR | Print|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_LCTL,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,       XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                    KC_LGUI,KC_LALT,KC_SPC, KC_LOWER, KC_ENT,       KC_SPC,  KC_RAISE, KC_RALT, KC_RCTL, KC_PSCR
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|GAMING|      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |UNLOCK|      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------''------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT  , XXXXXXX,KC_QWERTY,KC_COLEMAK,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,CG_TOGG, KC_GAME,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  KC_UNLOCK , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                          _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),
};

#ifdef OLED_ENABLE

static uint32_t start_time = 0; // stores the time when the keyboard was powered
                                // on
static uint8_t joke_index = 0;  // index of the joke to display
static uint32_t last_joke_time = 0; // time when the last joke was displayed

const char *jokes[] = {
    "rm -rf is not a joke...",
    "No color? You're not a real Linux user.",
    "I'm not a computer, I am Doffy.",
    "You've never touched it before, you've never seen it before",
    "OCT 25 == DEC 31, you ain't know? you dumb?",
    "The global variables are like whores",
    "My girl is pissed off. I'm not ignoring her, I'm just debugging.",
    "It works on my machine",
    "I'm not a bug, don't test me",
    "This is the shit you never met before",
    "It works, don't touch",
    "Why it works? don't ask me, ask it" // 12
};

const uint8_t NUM_JOKES = 12;

void keyboard_post_init_user(void) {
    start_time = timer_read32();  // Record the start time when the keyboard is initialized
}

bool show_lock = false; // this is used to display the lock icon and disable keypresses when the keyboard is locked


/* static void render_logo(void) { */

/*     static const char PROGMEM no_qmk[] = { */
/*         // 'doffylogo_L', 128x32px */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, */
/* //        0x18, 0x18, 0x38, 0xf0, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xd8, 0x08, 0x0c, 0x0c, 0x0c, */
/* //        0x0c, 0x00, 0x1c, 0x1c, 0xfc, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0x8c, */
/* //        0x8c, 0x8c, 0x8c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0x9c, 0x0c, */
/* //        0x0c, 0x0c, 0x04, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x3c, 0x60, 0x3c, 0xc0, 0xc0, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x1c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x80, 0x80, 0x80, 0x80, */
/* //        0xc0, 0x60, 0x70, 0x3d, 0x1d, 0x1d, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0xff, 0xc0, 0x80, 0x80, 0x80, */
/* //        0x80, 0x00, 0xc0, 0xc0, 0xff, 0x7f, 0x3f, 0x1f, 0x00, 0x00, 0x00, 0xff, 0x7f, 0xff, 0xff, 0x03, */
/* //        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xdf, 0x07, 0x03, */
/* //        0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xff, 0xff, */
/* //        0xff, 0xfe, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, */
/* //        0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, */
/* //        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 */
/*     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, */
/* 	0xc0, 0xe0, 0x60, 0x70, 0x30, 0x38, 0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x78, */
/* 	0x18, 0x18, 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xf8, 0xf8, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x18, */
/* 	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, */
/* 	0x70, 0x30, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x30, 0x70, 0xe0, 0xc0, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, */
/* 	0x30, 0x30, 0x30, 0x30, 0x30, 0xb0, 0xf0, 0xf8, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, */
/* 	0x07, 0x06, 0x06, 0x0e, 0x0c, 0x0c, 0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x0c, 0x0f, 0x0f, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1b, 0x1f, */
/* 	0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0f, 0x0f, 0x0c, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1b, 0x1f, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, */
/* 	0x0e, 0x0c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x10, 0x18, 0x18, 0x18, 0x18, 0x1c, 0x0c, 0x0f, 0x03, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x1c, 0x18, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, */
/* 	0x30, 0x18, 0x18, 0x1c, 0x0e, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 */
/*        }; */

/*     oled_write_raw_P(no_qmk, sizeof(no_qmk)); */

/* //      static const char PROGMEM no_qmk[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x80, 0x80, 0x80, */
/* //                                            0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0xe0, 0xf0, */
/* //                                            0xf8, 0xf8, 0xe0, 0x00, 0x00, 0x0e, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, */
/* //                                            0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, */
/* //                                            0x08, 0x88, 0x88, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xf0, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0x08, 0x08, 0x88, 0x88, 0x88, 0x48, 0x48, 0x48, 0x28, 0x28, 0x18, 0x18, 0x08, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0xf0, 0xfc, 0xf8, 0x03, 0xf3, 0xe7, 0xdf, 0x9f, 0x3f, 0xfe, 0xfe, 0xfc, 0xf9, */
/* //                                            0xfb, 0xf3, 0xf7, 0xf7, 0xe7, 0xef, 0xcf, 0x90, 0xa1, 0x81, 0x81, 0x81, 0xa0, 0xbd, 0xff, 0xff, */
/* //                                            0xff, 0xff, 0x7f, 0x3f, 0x9c, 0xdc, 0xf8, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, */
/* //                                            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, */
/* //                                            0x60, 0x00, 0x00, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x4c, 0x4f, */
/* //                                            0x47, 0x43, 0x43, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0xc2, 0xc2, 0x41, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0xe3, 0x13, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0xe2, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0x3f, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, */
/* //                                            0xff, 0xff, 0x03, 0x79, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x79, 0x03, 0xff, 0xff, 0xff, 0xff, 0x1f, */
/* //                                            0x03, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, */
/* //                                            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x40, 0x40, */
/* //                                            0x40, 0x40, 0x40, 0x40, 0x44, 0x4a, 0x4a, 0x51, 0x51, 0x60, 0x60, 0x40, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x1f, */
/* //                                            0x3f, 0x3f, 0x7f, 0x7c, 0x78, 0x78, 0x78, 0x78, 0x7c, 0x7e, 0x7f, 0x7f, 0x4f, 0x43, 0x40, 0x60, */
/* //                                            0x60, 0x78, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, */
/* //                                            0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x21, */
/* //                                            0x11, 0x11, 0x09, 0x09, 0x05, 0x05, 0x03, 0x03, 0x05, 0x09, 0x11, 0x21, 0x00, 0x00, 0x00, 0x00, */
/* //                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; */
/* // */
/* //    oled_write_raw_P(no_qmk, sizeof(no_qmk)); */
/* } */

static const char PROGMEM locked_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xce, 0xc6,
                                           0xc6, 0xce, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
                                           0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

/* 32 * 14 os logos */
static const char PROGMEM linux_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x27, 0x27, 0x8f, 0x9f, 0x03,
                                          0x73, 0xff, 0x03, 0xf2, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x19, 0x19, 0x1b, 0x1b, 0x1b,
                                          0x1a, 0x18, 0x18, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       60

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;


/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[current_frame], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[current_frame], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }
    }

#    if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }
#    endif

    /* animation timer  */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* KEYBOARD PET END */
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

/* static void print_logo_narrow(void) { */
/*      render_logo(); */
/* } */

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    if (show_lock == true) {
        oled_write_raw_P(locked_logo, sizeof(locked_logo));
    } else if (keymap_config.swap_lctl_lgui) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(linux_logo, sizeof(linux_logo));
    }

    oled_set_cursor(0, 3);

    switch (get_highest_layer(default_layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR(" CLMK "), false);
            break;
        case _GAME:
            oled_write_P(PSTR(" GAME "), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("QWERT"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
    }

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write_P(PSTR("LAYER"), false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR(" Adj "), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    /* caps lock */
    oled_set_cursor(0, 8);
    oled_write_P(PSTR("CPSLK"), led_usb_state.caps_lock);

    /* KEYBOARD PET RENDER START */

    render_luna(0, 13);

    /* KEYBOARD PET RENDER END */
}

static void print_up_time(void) {
    oled_clear();

    // Calculate elapsed time in miliseconds
    uint32_t elapsed_ms = (timer_read32() - start_time);
    uint32_t elapsed_seconds = elapsed_ms / 1000;
    uint32_t elapsed_minutes = elapsed_seconds / 60;
    uint32_t elapsed_hours = elapsed_minutes / 60;

    // Print the elapsed time on the OLED display
    char time_str[32];

    snprintf(time_str, sizeof(time_str), "Uptime: %02u:%02u:%02u",
             (unsigned int)elapsed_hours,
             (unsigned int)(elapsed_minutes % 60),
             (unsigned int)(elapsed_seconds % 60));
    oled_write_ln(time_str, false);

    // print a quote on the OLED display
    // under the uptime
    // Rotate jokes every 10 seconds
    if (timer_elapsed32(last_joke_time) > 30000) {
        joke_index = (joke_index + 1) % NUM_JOKES;
        last_joke_time = timer_read32();
    }

    // Display current joke
    oled_write_ln(jokes[joke_index], false);
}

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        /* print_logo_narrow(); */
        print_up_time();
    }

    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_GAME:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (show_lock == true) {
                return false;
            }
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
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
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
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
        case KC_DLINE:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                register_mods(mod_config(MOD_RCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                // Swap CTL and GUI on Mac
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_MASK_GUI));
                    register_code(KC_C);
                }
                // Linux/Windows
                else {
                    register_mods(mod_config(MOD_MASK_CS));
                    register_code(KC_C);
                }

            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_MASK_GUI));
                    unregister_code(KC_C);
                } else {
                    unregister_mods(mod_config(MOD_MASK_CS));
                    unregister_code(KC_C);
                }
            }
            break;
        case KC_PASTE:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_MASK_GUI));
                    register_code(KC_V);
                } else {
                    register_mods(mod_config(MOD_MASK_CS));
                    register_code(KC_V);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_MASK_GUI));
                    unregister_code(KC_V);
                } else {
                    unregister_mods(mod_config(MOD_MASK_CS));
                    unregister_code(KC_V);
                }
            }
            break;
        case KC_CUT:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_MASK_GUI));
                    register_code(KC_X);
                } else {
                    register_mods(mod_config(MOD_MASK_CS));
                    register_code(KC_X);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_MASK_GUI));
                    unregister_code(KC_X);
                } else {
                    unregister_mods(mod_config(MOD_MASK_CS));
                    unregister_code(KC_X);
                }
            }
            break;
        case KC_UNDO:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_MASK_GUI));
                    register_code(KC_Z);
                } else {
                    register_mods(mod_config(MOD_MASK_CS));
                    register_code(KC_Z);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_MASK_GUI));
                    unregister_code(KC_Z);
                } else {
                    unregister_mods(mod_config(MOD_MASK_CS));
                    unregister_code(KC_Z);
                }
            }
            break;
        case KC_CREATE:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_N);
                } else {
                    register_mods(MOD_BIT(KC_LALT));
                    register_code(KC_INS);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_code(KC_N);
                    unregister_mods(mod_config(MOD_LCTL));
                } else {
                    unregister_code(KC_INS);
                    unregister_mods(MOD_BIT(KC_LALT));
                }
            }
            break;
        case KC_SCREENSHOT:
            if (show_lock == true) {
                return false;
            }
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_MASK_CSG));
                    register_code(KC_4);
                } else {
                    register_code(KC_PSCR);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    register_code(KC_4);
                    unregister_mods(mod_config(MOD_MASK_CSG));
                } else {
                    unregister_code(KC_PSCR);
                }
            }
            break;
        case KC_NEWTAB:
            if (show_lock == true) {
                return false;
            }

            // combine key for new terminal tab in linux and mac
            // CTRL + SHIFT + T for linux
            // CMD + T for mac
            if (keymap_config.swap_lctl_lgui) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_T);
                } else {
                    unregister_code(KC_T);
                    unregister_mods(mod_config(MOD_LCTL));
                }
            } else {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_MASK_CS));
                    register_code(KC_T);
                } else {
                    unregister_code(KC_T);
                    unregister_mods(mod_config(MOD_MASK_CS));
                }
            }
            break;
        case KC_SW:
            if (show_lock == true) {
                return false;
            }
            // to switch window in linux and mac
            // ALT + TAB for linux
            // CMD + TAB for mac
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_TAB);
                } else {
                    register_mods(mod_config(MOD_MASK_ALT));
                    register_code(KC_TAB);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_code(KC_TAB);
                    unregister_mods(mod_config(MOD_LCTL));
                } else {
                    unregister_code(KC_TAB);
                    unregister_mods(mod_config(MOD_MASK_ALT));
                }
            }
            break;
        case KC_TAB1:
        case KC_TAB2:
        case KC_TAB3:
        case KC_TAB4:
        case KC_TAB5:
        case KC_TAB6:
        case KC_TAB7:
        case KC_TAB8:
        case KC_TAB9:
            if (show_lock == true) {
                return false;
            }

            // to switch to a specific tab in linux and mac
            // ALT + 1 to ALT + 9 for linux
            // CMD + 1 to CMD + 9 for mac
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_1 + (keycode - KC_TAB1));
                } else {
                    register_mods(mod_config(MOD_MASK_ALT));
                    register_code(KC_1 + (keycode - KC_TAB1));
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_code(KC_1 + (keycode - KC_TAB1));
                    unregister_mods(mod_config(MOD_LCTL));
                } else {
                    unregister_code(KC_1 + (keycode - KC_TAB1));
                    unregister_mods(mod_config(MOD_MASK_ALT));
                }
            }
            break;
        case KC_UNLOCK:
            if (record->event.pressed) {
                show_lock = !show_lock;
                print_status_narrow();
            }
            return false;
    }

    /* This stops any keypress to be sent to the computer when the keyboard is locked */
    return !show_lock;
}

//  #ifdef ENCODER_ENABLE
//  bool encoder_update_user(uint8_t index, bool clockwise) {
//      if (index == 0) { /* First encoder */
//          if (clockwise) {
//              tap_code(KC_VOLD);
//          } else {
//              tap_code(KC_VOLU);
//          }
//          return true;
//      }
//      if (index == 1) { /* Second encoder */
//          if (clockwise) {
//              tap_code(KC_PGDN);
//          } else {
//              tap_code(KC_PGUP);
//          }
//      }
//      return true;
//  }
//
//  #endif

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        /* [_QWERTY] = { */
        /*     ENCODER_CCW_CW(KC_VOLU, KC_VOLD), */
        /*     ENCODER_CCW_CW(C(KC_TAB), S(C(KC_TAB)))  // Right encoder: Cycle tabs (Ctrl + Tab, Ctrl + Shift + Tab) */
        /* }, */
            /* ENCODER_CCW_CW(MS_WHLU, MS_WHLD) }, */
        [_QWERTY] = {
            ENCODER_CCW_CW(S(C(KC_TAB)), S(C(KC_TAB))),  // Right encoder: Cycle tabs (Ctrl + Tab, Ctrl + Shift + Tab) */
            ENCODER_CCW_CW(LCMD(KC_TAB), LSFT(LCMD(KC_TAB)))  // Right encoder: Cycle tabs (Cmd+Tab on Mac, Ctrl+Tab on Linux)
        },
        [_COLEMAK] = {
            ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
            ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)
        },
        [_LOWER] = {
            ENCODER_CCW_CW(RGB_HUD, RGB_HUI),
            ENCODER_CCW_CW(KC_BRIU, KC_BRID)
        },
        [_RAISE] = {
            ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT),
            ENCODER_CCW_CW(RGB_SPD, RGB_SPI)
        },
        [_ADJUST] = {
            ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),
            ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)
        },
    };
#endif
