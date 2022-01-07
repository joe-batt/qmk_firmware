#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */
#define _BASE 0
#define _GAME 1
#define _FLIP 2
#define _FAUDIO 3
#define _RGBMOUSE 4

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    TD_CAPS_ENT,
    TD_CAPS_DEL,
    TD_MEDIA
};

td_state_t cur_dance(qk_tap_dance_state_t *state);
void custom_mod_tap(qk_tap_dance_state_t *state, uint16_t keycode);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);
void y_finished(qk_tap_dance_state_t *state, void *user_data);
void y_reset(qk_tap_dance_state_t *state, void *user_data);


/*#define L4_HOME LT(4, KC_HOME)*/
/*#define L4_PGDN LT(4, KC_PGDN)*/
#define L3_RBRC LT(3, KC_RBRC)
#define L2_ENT LT(2, KC_ENT)
#define SF_GUI LSFT(KC_LGUI)
#define SFT_SPC RSFT_T(KC_SPC)
#define SFT_BSP LSFT_T(KC_BSPC)
#define L4_COMM LT(4, KC_COMM)
#define CTL_TAB LCTL_T(KC_TAB)
#define CPS_DEL TD(TD_CAPS_DEL)
#define CPS_ENT TD(TD_CAPS_ENT)
#define TD_MD TD(TD_MEDIA) 

const uint16_t PROGMEM f12_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM sft_ins_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM alt_f4_combo[] = {KC_E, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM ctrl_c_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sctl_c_combo[] = {KC_S, KC_D, KC_F, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(f12_combo, KC_F12),
    COMBO(sft_ins_combo, LSFT(KC_INS)),
    COMBO(alt_f4_combo, LSG(KC_Q)),
    COMBO(ctrl_c_combo, LCTL(KC_R)),
    COMBO(sctl_c_combo, LCTL(LSFT(KC_R))),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case KC_DEL:
        if ( ((get_mods() & MOD_MASK_SHIFT) || (get_mods() & MOD_MASK_CTRL)) && !(get_mods() & MOD_MASK_ALT)) {
            if (record->event.pressed) {
                register_code(KC_INS);
            } else {
                unregister_code(KC_INS);
            }
        }
        return false;

    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_ESC  ,                          KC_VOLU ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,TD_MD   ,                          KC_VOLD ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_NUHS ,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,MO(4)   ,KC_NO   ,        KC_PSCR ,MO(4)   ,KC_N    ,KC_M    ,KC_LBRC ,KC_QUOT ,KC_SLSH ,KC_RSFT ,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
           MO(3)   ,KC_NUBS ,KC_LALT ,KC_LGUI ,     CTL_TAB ,    SFT_BSP ,CPS_DEL ,        CPS_ENT  ,SFT_SPC,    TT(1)   ,     KC_COMM ,KC_DOT  ,KC_RALT ,L3_RBRC
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
           ),
    [_GAME] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,                                            KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,                          KC_TRNS ,KC_NO   ,KC_PGUP ,KC_UP   ,KC_PGDN ,KC_NO   ,KC_NO   ,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_F5   ,                          KC_TRNS ,KC_HOME ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_END  ,KC_NO   ,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_TRNS ,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
           KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,     KC_LCTL ,    KC_SPC  ,L2_ENT  ,        KC_TRNS ,KC_TRNS ,    KC_TRNS ,     KC_NO   ,KC_NO   ,KC_NO   ,KC_TRNS
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
           ),
	[_FLIP] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           KC_NO   ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,                                            KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   , 
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_NO   ,KC_P    ,KC_O    ,KC_I    ,KC_U    ,KC_Y    ,KC_NO   ,                          KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_NO   ,KC_SCLN ,KC_L    ,KC_K    ,KC_J    ,KC_H    ,KC_F9   ,                          KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   , 
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_LSFT ,KC_SLSH ,KC_QUOT ,KC_LBRC ,KC_M    ,KC_N    ,KC_TRNS ,KC_NO   ,        KC_NO   ,KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   , 
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
           KC_TRNS ,KC_TRNS ,KC_DOT  ,KC_COMM ,     KC_NO   ,    KC_BSPC ,KC_TRNS ,        KC_NO   ,KC_NO   ,    KC_NO   ,     KC_TRNS ,KC_NO   ,KC_NO   , KC_TRNS
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
            ),
	/*[_FLIP] = LAYOUT(*/
        /*//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐*/
           /*KC_NO   ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,                                            KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   , */
        /*//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤*/
           /*KC_NO   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_NO   ,                          KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,*/
        /*//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤*/
           /*KC_NO   ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_F9   ,                          KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   , */
        /*//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤*/
           /*KC_LSFT ,KC_N    ,KC_M    ,KC_LBRC ,KC_QUOT ,KC_SLSH ,KC_TRNS ,KC_NO   ,        KC_NO   ,KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   , */
        /*//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤*/
           /*KC_TRNS ,KC_TRNS ,KC_COMM ,KC_DOT  ,     KC_NO   ,    KC_TRNS ,KC_TRNS ,        KC_NO   ,KC_NO   ,    KC_NO   ,     KC_TRNS ,KC_NO   ,KC_NO   , KC_TRNS*/
        /*//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘*/
            /*),*/
	[_FAUDIO] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           RESET   ,KC_NO   ,KC_F10  ,KC_F11  ,KC_F12  ,KC_NO   ,                                            KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,RESET   , 
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_NO   ,KC_NO   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_NO   ,NK_ON   ,                          KC_TRNS ,KC_NO   ,KC_MRWD ,KC_MFFD ,KC_NO   ,KC_NO   ,KC_NO   , 
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           SF_GUI  ,KC_NO   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_NO   ,NK_OFF  ,                          KC_TRNS ,KC_NO   ,KC_MPLY ,KC_MSTP ,KC_MUTE ,KC_NO   ,KC_NO   , 
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_TRNS ,KC_NO   ,KC_F1   ,KC_F2   ,KC_F3   ,KC_NO   ,KC_TRNS ,KC_NO   ,        KC_NO   ,KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   , 
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
           KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_RGUI ,     KC_RCTL ,    KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,    KC_NO   ,     KC_NO   ,KC_NO   ,KC_NO   ,KC_TRNS
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
           ),
    [_RGBMOUSE] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           RGB_SAI ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,                                            KC_NO   ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,KC_NO   ,KC_NO   ,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           RGB_SAD ,RGB_M_X ,RGB_M_K ,RGB_M_R ,RGB_M_SW,RGB_TOG ,RGB_VAI ,                          KC_NO   ,KC_NO   ,KC_WH_L ,KC_MS_U ,KC_WH_R ,KC_NO   ,KC_NO   ,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           RGB_HUI ,RGB_M_B ,RGB_M_G ,RGB_M_P ,RGB_SPD ,RGB_SPI ,RGB_VAD ,                          KC_NO   ,KC_NO   ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_NO   ,KC_NO   ,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           RGB_HUD ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_TRNS ,KC_NO   ,        KC_BTN3 ,KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
           KC_TRNS ,KC_NO   ,KC_NO   ,KC_TRNS ,     KC_NO   ,    KC_NO   ,KC_NO   ,        KC_BTN2 ,KC_BTN1 ,    KC_NO   ,     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
           )
};

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_RED}
);

const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {12, 2, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM my_gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_BLUE},
    {7, 7, HSV_BLACK}
);

const rgblight_segment_t PROGMEM my_flip_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_PURPLE}
);


const rgblight_segment_t PROGMEM my_faudio_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_SPRINGGREEN}
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_gaming_layer,
    my_capslock_layer,
    my_numlock_layer,
    my_faudio_layer,
    my_flip_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock); 
    rgblight_set_layer_state(2, led_state.num_lock); 
    return true;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _GAME));    
    rgblight_set_layer_state(3, layer_state_cmp(state, _FAUDIO));    
    rgblight_set_layer_state(4, layer_state_cmp(state, _FLIP));    
    return state;
};

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
void custom_mod_tap(qk_tap_dance_state_t *state, uint16_t keycode){ 
    if (state->count >= 2){
            tap_code(keycode);
    }
}

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count >= 2) {
        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    return TD_UNKNOWN;
}


// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t deltap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

static td_tap_t enttap_state = {
    .is_press_action = true,
    .state = TD_NONE
};


void del_each(qk_tap_dance_state_t *state, void *user_data) {
    custom_mod_tap(state, KC_DEL);
}

void ent_each(qk_tap_dance_state_t *state, void *user_data) {
    custom_mod_tap(state, KC_ENT);
}

void custom_mod_finished(td_tap_t tap_state, uint16_t modcode, uint16_t keycode){
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(keycode); break;
        case TD_SINGLE_HOLD: register_code(modcode); break;
        case TD_DOUBLE_TAP: register_code(keycode); break;
        case TD_DOUBLE_HOLD: register_code(keycode); break;
        default: break;
    }
}

void del_finished(qk_tap_dance_state_t *state, void *user_data) {
    deltap_state.state = cur_dance(state);
    custom_mod_finished(deltap_state, KC_CAPS, KC_DEL);
}

void custom_mod_reset(td_tap_t tap_state, uint16_t modcode, uint16_t keycode){
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(keycode); break;
        case TD_SINGLE_HOLD: unregister_code(modcode); break;
        case TD_DOUBLE_TAP: unregister_code(keycode); break;
        case TD_DOUBLE_HOLD: unregister_code(keycode);
        default: break;
    }
    tap_state.state = TD_NONE;
}

void del_reset(qk_tap_dance_state_t *state, void *user_data) {
    custom_mod_reset(deltap_state, KC_CAPS, KC_DEL);
}

void ent_finished(qk_tap_dance_state_t *state, void *user_data) {
    enttap_state.state = cur_dance(state);
    custom_mod_finished(enttap_state, KC_CAPS, KC_ENT);
}

void ent_reset(qk_tap_dance_state_t *state, void *user_data) {
    custom_mod_reset(enttap_state, KC_CAPS, KC_ENT);
}

void media_finished(qk_tap_dance_state_t *state, void *user_data){
    switch (state->count){
        case 1: register_code(KC_MPLY); break;
        case 2: register_code(KC_MSTP); break;
        default: register_code(KC_MUTE); break;
    }
}

void media_reset(qk_tap_dance_state_t *state, void *user_data){
    switch (state->count){
        case 1: unregister_code(KC_MPLY); break;
        case 2: unregister_code(KC_MSTP); break;
        default: unregister_code(KC_MUTE); break;
    }
}



qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPS_DEL] = ACTION_TAP_DANCE_FN_ADVANCED(del_each, del_finished, del_reset),
    [TD_CAPS_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(ent_each, ent_finished, ent_reset),
    [TD_MEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, media_finished, media_reset)
};

/*bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {*/
    /*switch (keycode) {*/
        /*case CTL_TAB:*/
            /*return false;*/
        /*default:*/
            /*return true;*/
    /*}*/
/*}*/
