/* Copyright 2021 Dane Evans
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

#include QMK_KEYBOARD_H

#include "czech.h"

#define INDICATOR_BRIGHTNESS 30

enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _CHARS,
    _VIM,
    _NUMPAD,
    _CZ_LOW,
    _CZ_UP,
};

#define KC_QWERTY PDF(_QWERTY)

// kanata-mirrored tap-holds
#define ESC_CHR LT(_CHARS, KC_ESC)      // tap ESC, hold chars layer
#define BSP_NAV LT(_VIM, KC_BSPC)       // tap BSPC, hold vim/nav layer
#define MOD_SPC MT(MOD_LGUI, KC_SPC)    // tap SPC, hold GUI
#define CTL_RET MT(MOD_LCTL, KC_ENT)    // tap ENT, hold CTRL
#define DOT_NUM LT(_NUMPAD, KC_DOT)     // tap ., hold numpad layer

// czech layer holds
#define CZ_LOW  MO(_CZ_LOW)             // hold lowercase czech layer
#define CZ_UP   MO(_CZ_UP)              // hold uppercase czech (from cz_low)

// one-shot left shift: tap once -> next key is shifted, then auto-releases
#define OSM_SFT OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY  (mirrors kanata: ESC/chars on caps-pos, BSPC/nav on ]-pos, ;/CTRL+ENT on home-row)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Caps |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |                    |  Y   |  U   |  I   |  O   |  P   |Bsp/Nv|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc/ |  A   |  S   |  D   |  F   |  G   |                    |  H   |  J   |  K   |  L   | Ent/ |  ;   |
 * | Char |      |      |      |      |      |-------.    ,-------|      |      |      |      | Ctl  |      |
 * |------+------+------+------+------+------| MUTE  |    | PrtSc |------+------+------+------+------+------|
 * |LShift|  Z   |  X   |  C   |  V   |  B   |-------|    |-------|  N   |  M   |  ,   |./Num |  /   |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *           |OSft | LCtl | LAlt |Spc/Gui|Bspc /     \Bsp/Nv\|Spc/Gui| CZ | Esc/  | Del |
 *           |     |      |      |       |    /       \      \      | Tog | Char |     |
 *           `------------------------------------'           '----------------------'
 */
  [_QWERTY] = LAYOUT(
  KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    BSP_NAV,
  ESC_CHR, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    CTL_RET, KC_SCLN,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,    KC_PSCR,  KC_N,    KC_M,    KC_COMM, DOT_NUM, KC_SLSH, KC_RSFT,
                    OSM_SFT, KC_LCTL, KC_LALT, MOD_SPC, KC_BSPC,    BSP_NAV,  MOD_SPC, CZ_LOW, ESC_CHR,  KC_DEL
),

/* CHARS  (synced cell-by-cell with kanata characters layer)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  ~   |  #   |  {   |  }   |  &   |                    |  |   |  _   |  "   |  '   |  `   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  %   |  ;   |  (   |  )   |  ?   |-------.    ,-------|  !   |  =   |  -   |  +   |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  ^   |  $   |  [   |  ]   |  @   |-------|    |-------|  :   |  *   |  <   |  >   |  \   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */
[_CHARS] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, KC_TILD, KC_HASH, KC_LCBR, KC_RCBR, KC_AMPR,                       KC_PIPE, KC_UNDS, KC_DQT,  KC_QUOT, KC_GRV,  _______,
  _______, KC_PERC, KC_SCLN, KC_LPRN, KC_RPRN, KC_QUES,                       KC_EXLM, KC_EQL,  KC_MINS, KC_PLUS, _______, _______,
  _______, KC_CIRC, KC_DLR,  KC_LBRC, KC_RBRC, KC_AT,   _______,    _______,  KC_COLN, KC_ASTR, KC_LT,   KC_GT,   KC_BSLS, _______,
                    _______, _______, _______, _______, _______,    _______,  _______, _______, _______, _______
),

/* VIM/NAV  (synced with kanata navigation layer; vim-style word motions)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |C-Rgt |      |      |                    |      | PgUp |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |PgDown|      |      |-------.    ,-------| Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Home | End  |      |      |C-Lft |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |     |      |      | Enter |     /        \     |      |      |      |      |
 */
[_VIM] = LAYOUT(
  _______, _______, _______, _______,     _______, _______,                       _______, _______, _______, _______,  _______, _______,
  _______, _______, _______, C(KC_RIGHT), _______, _______,                       _______, KC_PGUP, _______, _______,  _______, _______,
  _______, _______, _______, KC_PGDN,     _______, _______,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  _______, KC_HOME, KC_END,  _______,     _______, C(KC_LEFT), _______,  _______, _______, _______, _______, _______,  _______, _______,
                    _______, _______,     _______, KC_ENT,  _______,    _______, _______, _______, _______, _______
),

/* NUMPAD  (mirrors kanata numbers layer; left-handed numpad)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  7   |  8   |  9   |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  4   |  5   |  6   |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  0   |  1   |  2   |  3   |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */
[_NUMPAD] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, KC_7,    KC_8,    KC_9,    _______,                        _______, _______, _______, _______, _______, _______,
  _______, _______, KC_4,    KC_5,    KC_6,    _______,                        _______, _______, _______, _______, _______, _______,
  _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______,    _______,   _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,    _______,   _______, _______, _______, _______
),

/* CZ_LOW  (kanata-equivalent czechLow; unicode via UNICODE_MODE_LINUX = Ctrl+Shift+U + hex + Enter)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  ä   |  é   |  ě   |  ř   |  ť   |                    |  ý   |  ů   |  í   |  ó   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  á   |  š   |  ď   |      |      |-------.    ,-------|      |  ú   |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | CZUP |  ž   |      |  č   |      |      |-------|    |-------|      |  ň   |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */
[_CZ_LOW] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
  _______, CZ_ad,   CZ_e,    CZ_eh,   CZ_r,    CZ_t,                           CZ_y,    CZ_uk,   CZ_i,    CZ_o,    _______, _______,
  _______, CZ_a,    CZ_s,    CZ_d,    _______, _______,                        _______, CZ_u,    _______, _______, _______, _______,
  CZ_UP,   CZ_z,    _______, CZ_c,    _______, _______, _______,    _______,   _______, CZ_n,    _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,    _______,   _______, _______, _______, _______
),

/* CZ_UP  (kanata-equivalent czechUp; reached by holding LSft slot while CZ_LOW is held)
 */
[_CZ_UP] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
  _______, _______, CZ_E,    CZ_Eh,   CZ_R,    CZ_T,                           CZ_Y,    CZ_Uk,   CZ_I,    CZ_O,    _______, _______,
  _______, CZ_A,    CZ_S,    CZ_D,    _______, _______,                        _______, CZ_U,    _______, _______, _______, _______,
  _______, CZ_Z,    _______, CZ_C,    _______, _______, _______,    _______,   _______, CZ_N,    _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,    _______,   _______, _______, _______, _______
)

};


#ifdef OLED_ENABLE
    #include "oled.c"
#endif

#ifdef ENCODER_ENABLE
    #include "encoder.c"
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
