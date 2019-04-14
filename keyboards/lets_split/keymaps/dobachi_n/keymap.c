#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16
#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET
#define KC_TGA TG(_ADJUST)
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)
#define KC_SFTES SFT_T(KC_ESC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------|  |-----------------------------------------.
     TAB,   Q,     W,     E,     R,     T,        Y,     U,     I,     O,     P,     BSPC,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     LCTL,  A,     S,     D,     F,     G,        H,     J,     K,     L,     SCLN,  QUOT,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     LSFT,  Z,     X,     C,     V,     B,        N,     M,     COMM,  DOT,   SLSH,  ENT,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     ESC,   TGA,   LGUI,  LALT,  LOWER, SPC,      RSFT,  RAISE, LEFT,  DOWN,  UP,    RGHT\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------|  |-----------------------------------------.
     TAB,   1,     2,     3,     4,     5,        6,     7,     8,     9,     0,     BSPC,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     LCTL , F1,    F2,    F3,    F4,    F5,       LEFT,  DOWN,  UP,    RGHT,  XXXXX, XXXXX,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     LSFT,  F6,    F7 ,   F8 ,   F9 ,   F10,      F11  , F12  , XXXXX, XXXXX, XXXXX, ENT,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     ESC,   TGA,   LGUI,  LALT,  LOWER, SPC,      RSFT,  RAISE, LEFT,  DOWN,  UP,    RGHT\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |      |      |      |    INT4     |      |      | Alt  | Ctrl |Shift |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------|  |-----------------------------------------.
     TILD , EXLM,  AT,    HASH,  DLR,   PERC,     CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  BSPC,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     LCTL , XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,    MINS,  EQL,   LCBR,  RCBR,  PIPE,  GRV,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     LSFT,  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,    UNDS,  PLUS,  LBRC,  RBRC,  BSLS,  ENT,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     ESC,   TGA,   LGUI,  LALT,  LOWER, SPC,      RSFT,  RAISE, LEFT,  DOWN,  UP,    RGHT\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |Up    |      |      |Pause |JIS \ | PrSc |ScLk  |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Left  |Down  |Right |AGnorm|      |Ins   | Home |PGUP  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|Del   | End  |PGDN  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------|  |-----------------------------------------.
     RST,   XXXXX, XXXXX, UP,    XXXXX, XXXXX,    XXXXX, INT3 , PSCR , SLCK , XXXXX, XXXXX,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     XXXXX, XXXXX, LEFT,  DOWN,  RGHT,  XXXXX,    XXXXX, INS  , HOME , PGUP , XXXXX, XXXXX,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,    XXXXX, DEL  , END  , PGDN , XXXXX, ENT,\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
     ESC,   TGA,   LGUI,  LALT,  LOWER, SPC,      RSFT,  RAISE, LEFT,  DOWN,  UP,    RGHT\
  //|------+------+------+------+------+------|  |------+------+------+------+------+------|
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
