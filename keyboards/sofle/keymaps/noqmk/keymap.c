// Copyright 2022 axtlos (@axtloss)
// SPDX-License-Identifier: GPL-2.0-only
#include QMK_KEYBOARD_H

/*
keymap_config.swap_lctl_lgui = true; it means the keyboard is in MAC mode
 */

const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
};

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUN,
    _NAV,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_ADJUST,
    KC_CREATE,
    KC_SCREENSHOT,
    KC_NEWTAB,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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
  _______,   _______,    _______,      _______,     _______,      _______,                        _______,     _______,  _______,  _______,  _______, _______,
  QK_GESC,  KC_Q,        KC_W,         KC_E,        KC_R,         KC_T,                           KC_Y,        KC_U,         KC_I,  KC_O, KC_P, KC_UNDS,
  KC_BSPC,  LGUI_T(KC_A), LALT_T(KC_S), CTL_T(KC_D), LSFT_T(KC_F), KC_G,                           KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
  KC_PIPE,  KC_Z,        KC_X,         KC_C,        KC_V,         KC_B, KC_MUTE,       _______, KC_N,  KC_M,       KC_COMM,    KC_DOT,     KC_SLSH, KC_MINUS,
            _______,     _______, LT(_ADJUST, KC_EQL),   LT(_LOWER, KC_TAB),  LT(_NAV, KC_SPC),                 LT(_FUN, KC_SPC), LT(_RAISE, KC_ENT), KC_DEL, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|New_tab|    |S_wndw|------+------+------+------+------+------|
 * |  _   |  =   |  -   |  +   |   [  |   {  |-------|    |-------|   }  |   ]  |   '  |   "  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | Lower | / Space /       \Space\   |Raise | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,   _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_PLUS,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,   KC_PIPE,
  KC_UNDS,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,    _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS,   KC_UNDS,
                    _______, _______, _______, _______, KC_SPC,        KC_SPC, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |  `   |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |  F1  |   F2 |   F3 |   F4 |  F5  |                    |      | PWrd |      | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F6  |  F7  |  F8  |  F9  |  F10 |-------.    ,-------| Left | Down |  Up  | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |   |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | F11  |  F12 |-------|    |-------| KC_CREATE | Print|  Ins | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | / Space /       \Space \  |RAISE | RGUI | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______,_______, _______, _______,_______, _______,                          _______,   _______, _______, _______, _______, _______,
  _______,KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______,KC_1, KC_2,  KC_3, KC_4,   KC_5,                           KC_LEFT,   KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_F12,
  _______,KC_6, KC_7,  KC_8, KC_9 ,  KC_0,  _______,        _______,KC_CREATE, KC_PSCR, KC_INS,  _______, XXXXXXX, _______,
                    _______, _______, _______, KC_0, KC_SPC,             KC_SPC, _______, _______, _______, _______
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
/*
    QK_MOUSE_CURSOR_LEFT	MS_LEFT	Mouse cursor left
    QK_MOUSE_CURSOR_DOWN	MS_DOWN	Mouse cursor down
    QK_MOUSE_CURSOR_UP	MS_UP	Mouse cursor up
    QK_MOUSE_CURSOR_RIGHT	MS_RGHT	Mouse cursor right
    QK_MOUSE_BUTTON_1	MS_BTN1	Mouse button 1
    QK_MOUSE_BUTTON_2	MS_BTN2	Mouse button 2
    QK_MOUSE_BUTTON_3	MS_BTN3	Mouse button 3
 */
[_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT  , XXXXXXX,KC_QWERTY,XXXXXXX,CG_TOGG,XXXXXXX,                     XXXXXXX, MS_BTN1, MS_BTN3, MS_BTN2, XXXXXXX, KC_SLEP,
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_MPRV, KC_MUTE,
                          _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),
[_FUN] = LAYOUT(
    // ,-----------------------------------------.                    ,-----------------------------------------.
    //  |  TERM |  F1  |  F2  |  F3  |  F4  |  F5  |                  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
    //  |------+------+------+------+------+------|                  |------+------+------+------+------+------|
    //  |  GO  | RUST | .NET |  JS  |  PY  | TEST |                  |SEARCH|  ==  |  !=  |  <=  |  >=  |  =>  |
    //  |------+------+------+------+------+------|                  |------+------+------+------+------+------|
    //  |  CUT | COPY | SEL  | FIND | FRMT | REFAC|                  | FUNC |  IF  | FOR  |WHILE |ASYNC |RETURN|
    //  |------+------+------+------+------+------|                  |------+------+------+------+------+------|
    //  | UNDO | REDO |CLOSE |INDENT|PASTE |BUILD |                  |  +=  |  -=  |  *=  |  /=  |  ++  |  --  |
    //  `-----------------------------------------/                  \-----------------------------------------'
    //               | GUI  | SAVE | ALT  | CODE |SPACE|        | GIT |CLASS | TRY  |CONST | NULL |CTRL |
    //               |      |      |      |(act) |     |        |     |      |      |      |      |     |
    //               `----------------------------------'        `----------------------------------'

    _______, _______,  _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, KC_F11, KC_F12, KC_PSCR, KC_CAPS,  _______,                                _______, _______, _______, _______, _______, _______,
    _______, KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,                                _______, _______, _______, _______, _______, _______,
    _______, KC_F6, KC_F7, KC_F8, KC_F9,  KC_F10, _______,              _______, _______, _______, _______, _______, _______, _______,
              _______, _______, _______, KC_0, _______,                                _______, _______, _______, _______, _______
),
[_NAV] = LAYOUT(
    // ,-----------------------------------------.                    ,-----------------------------------------.
    //  |  TERM |  F1  |  F2  |  F3  |  F4  |  F5  |                  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
    //  |------+------+------+------+------+------|                  |------+------+------+------+------+------|
    //  |  GO  | RUST | .NET |  JS  |  PY  | TEST |                  |SEARCH|  ==  |  !=  |  <=  |  >=  |  =>  |
    //  |------+------+------+------+------+------|                  |------+------+------+------+------+------|
    //  |  CUT | COPY | SEL  | FIND | FRMT | REFAC|                  | FUNC |  IF  | FOR  |WHILE |ASYNC |RETURN|
    //  |------+------+------+------+------+------|                  |------+------+------+------+------+------|
    //  | UNDO | REDO |CLOSE |INDENT|PASTE |BUILD |                  |  +=  |  -=  |  *=  |  /=  |  ++  |  --  |
    //  `-----------------------------------------/                  \-----------------------------------------'
    //               | GUI  | SAVE | ALT  | CODE |SPACE|        | GIT |CLASS | TRY  |CONST | NULL |CTRL |
    //               |      |      |      |(act) |     |        |     |      |      |      |      |     |
    //               `----------------------------------'        `----------------------------------'

    _______,  _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______,                                KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_CAPS,  _______,
    _______,  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
              _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______
),
};


#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char doffy_logo[] PROGMEM  = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8,
	0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc,
	0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00,
	0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x00, 0x00,
	0x00, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0xe0,
	0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0xe0,
	0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 0xe7, 0xe7, 0xe7, 0xe3, 0xf3, 0x73, 0xe1, 0x81,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x09, 0x83, 0xc3, 0xe3,
	0x73, 0x73, 0xc3, 0x81, 0x81, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x08, 0x00, 0x00,
	0xc1, 0xf1, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff,
	0xff, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x05, 0x0e, 0x0e, 0xee, 0xef, 0xe7,
	0xe7, 0xc6, 0x06, 0x06, 0x06, 0xa6, 0xae, 0x3e, 0x3e, 0xbe, 0xbe, 0xbf, 0x3f, 0x3b, 0xb9, 0xb8,
	0xb8, 0x38, 0xb8, 0xb8, 0xb9, 0x3f, 0x3f, 0xae, 0xa6, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00,
	0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0xff,
	0xff, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03,
	0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x07,
	0x0f, 0x0f, 0x0e, 0x1e, 0x1c, 0x1c, 0x3e, 0x3e, 0x3c, 0x3d, 0x7d, 0x7d, 0x7c, 0x7c, 0x7d, 0x7d,
	0x7c, 0x7c, 0x7d, 0x7d, 0x3d, 0x3c, 0x3e, 0x3e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x00, 0x00,
	0x03, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x01, 0x00,
	0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
	0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(doffy_logo, sizeof(doffy_logo));
}

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
#    define ANIM_FRAME_DURATION 100  // how long each frame lasts in ms
#    define ANIM_SIZE           144   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

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
    // else {
    //     return OLED_ROTATION_270;
    // }

    return rotation;
}

static void print_logo_narrow(void) {
     render_logo();
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(linux_logo, sizeof(linux_logo));
    }

    oled_set_cursor(0, 3);

    switch (get_highest_layer(default_layer_state)) {
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
        case _FUN:
            oled_write_P(PSTR("FUN "), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV "), false);
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


bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }

    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_CREATE:
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
        default:
            return true;
    }

    /* This stops any keypress to be sent to the computer when the keyboard is locked */
    return true;
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
        [_QWERTY] = {
            ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
            ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
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
        [_FUN] = {
            ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),
            ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)
        },
        [_NAV] = {
            ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),
            ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)
        },
    };
#endif
