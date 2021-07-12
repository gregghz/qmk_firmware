#include QMK_KEYBOARD_H
#include "version.h"
#include "stdbool.h"
#include "joystick.h"
#include "print.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols
    WIN, // window management
    GAME, // gaming
    ANALOG_GAME, // analog directional for gaming (fortnite)
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD,

  JOY_UP,
  JOY_DN,
  JOY_LF,
  JOY_RG
};

joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_GRAVE,             KC_1,    KC_2,          KC_3,    KC_4,    KC_5,    TT(SYMB), /**/ TT(WIN),  KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,               KC_Q,    KC_W,          KC_E,    KC_R,    KC_T,    KC_EQL,   /**/ KC_MINUS, KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL,              KC_A,    KC_S,          KC_D,    KC_F,    KC_G,              /**/           KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSPO,              KC_Z,    KC_X,          KC_C,    KC_V,    KC_B,    KC_LBRC,  /**/ KC_RBRC,  KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
  KC_LALT,              KC_QUOT, LALT(KC_LSFT), KC_LEFT, KC_RGHT,                    /**/                     KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, KC_ESC,
                                                                  TT(WIN), KC_DEL,   /**/ KC_LALT,  TG(GAME),
                                                                           KC_HOME,  /**/ KC_PGUP,
                                                         KC_SPC,  KC_LWIN, KC_END,   /**/ KC_PGDN,  KC_LALT,  KC_ENT
),

[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, /**/ KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, /**/ KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,           /**/          KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, /**/ KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   /**/                   KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
                                               KC_TRNS, KC_TRNS, /**/ KC_MPRV, KC_MNXT,
                                                        KC_TRNS, /**/ KC_VOLU,
                                      KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_VOLD, KC_MUTE, KC_MPLY
),

[WIN] = LAYOUT_ergodox_pretty(
  C(A(KC_BSPC)), KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,           KC_TRNS, KC_TRNS,        /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,       C(A(KC_U)),    C(A(KC_UP)),   C(A(KC_I)),       KC_TRNS,           KC_TRNS, C(A(KC_EQL)),   /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,       C(A(KC_LEFT)), C(A(KC_ENT)),  C(A(KC_RIGHT)),   KC_TRNS,           KC_TRNS,                 /**/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,       C(A(KC_J)),    C(A(KC_DOWN)), C(A(KC_K)),       KC_TRNS,           KC_TRNS, C(A(KC_MINUS)), /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,       KC_TRNS,       KC_TRNS,       C(A(G(KC_LEFT))), C(A(G(KC_RIGHT))),                          /**/                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                    KC_TRNS, KC_TRNS,        /**/ KC_TRNS, KC_TRNS,
                                                                                             KC_TRNS,        /**/ KC_TRNS,
                                                                 C(A(KC_C)),        KC_TRNS, KC_TRNS,        /**/ KC_TRNS, KC_TRNS, KC_TRNS
),

[GAME] = LAYOUT_ergodox_pretty(
  // left hand
  KC_1,    KC_1, KC_2, KC_3, KC_4,   KC_5, KC_6,    /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R,   KC_T, KC_EQL,  /**/ KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,
  KC_TRNS, KC_A, KC_S, KC_D, KC_F,   KC_G,          /**/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V,   KC_B, KC_LBRC, /**/ KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,
  KC_Y,    KC_U, KC_I, KC_P, KC_N,                  /**/                   KC_TRNS, KC_TRNS, KC_TRNS, TG(ANALOG_GAME), KC_ESC,
                                     KC_J, KC_K,    /**/ KC_TRNS, KC_TRNS,
                                           KC_L,    /**/ KC_TRNS,
                             KC_SPC, KC_H, KC_M,    /**/ KC_TRNS, KC_TRNS, KC_TRNS
),

[ANALOG_GAME] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, JOY_UP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, JOY_LF,  JOY_DN,  JOY_RG,  KC_TRNS, KC_TRNS,          /**/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   /**/                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS, KC_TRNS,          /**/ KC_TRNS, KC_TRNS,
                                               KC_TRNS,          /**/ KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS,          /**/ KC_TRNS, KC_TRNS, KC_TRNS
)
};

//static uint8_t precision_val = 70;
static uint8_t axesFlags = 0;
enum axes {
  Precision = 1,
  Axis1High = 2,
  Axis1Low = 4,
  Axis2High = 8,
  Axis2Low = 16
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
}
  }

  uprintf("%d pressed\n", keycode);

    switch (keycode) {
      case JOY_UP:
        print("JOY UP????\n");
          if (record->event.pressed) {
            axesFlags |= Axis2Low;
          } else {
            axesFlags &= ~Axis2Low;
          }
          joystick_status.axes[0] |= Axis2Low;
          joystick_status.status |= JS_UPDATED;
        break;
      case JOY_DN:
          if (record->event.pressed) {
            axesFlags |= Axis2High;
          } else {
            axesFlags &= ~Axis2High;
          }
          joystick_status.status |= JS_UPDATED;
        break;
      case JOY_LF:
          if (record->event.pressed) {
            axesFlags |= Axis1Low;
          } else {
            axesFlags &= ~Axis1Low;
          }
          joystick_status.status |= JS_UPDATED;
        break;
      case JOY_RG:
          if (record->event.pressed) {
            axesFlags |= Axis1High;
          } else {
            axesFlags &= ~Axis1High;
          }
          joystick_status.status |= JS_UPDATED;
        break;
    }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif

  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        // set this for joystick on wasd
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      /* case 5: */
      /*   ergodox_right_led_1_on(); */
      /*   ergodox_right_led_3_on(); */
      /*   #ifdef RGBLIGHT_COLOR_LAYER_5 */
      /*     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5); */
      /*   #endif */
      /*   break; */
      /* case 6: */
      /*   ergodox_right_led_2_on(); */
      /*   ergodox_right_led_3_on(); */
      /*   #ifdef RGBLIGHT_COLOR_LAYER_6 */
      /*     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6); */
      /*   #endif */
      /*   break; */
      /* case 7: */
      /*   ergodox_right_led_1_on(); */
      /*   ergodox_right_led_2_on(); */
      /*   ergodox_right_led_3_on(); */
      /*   #ifdef RGBLIGHT_COLOR_LAYER_7 */
      /*     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7); */
      /*   #endif */
      /*   break; */
      default:
        break;
    }

  return state;
};
