#ifndef __MAC_KEYBOARD_MAP_H__
#define __MAC_KEYBOARD_MAP_H__

#include "CONFIG.h"

// HID Keyboard codes for Mac compatibility
// Based on USB HID Usage Table for Keyboard/Keypad Page (0x07)

#define HID_KEYBOARD_ERROR_UNDEFINED    0x01
#define HID_KEYBOARD_POST_FAIL          0x02
#define HID_KEYBOARD_ERROR_UNDEFINED2   0x03
#define HID_KEYBOARD_A                  0x04
#define HID_KEYBOARD_B                  0x05
#define HID_KEYBOARD_C                  0x06
#define HID_KEYBOARD_D                  0x07
#define HID_KEYBOARD_E                  0x08
#define HID_KEYBOARD_F                  0x09
#define HID_KEYBOARD_G                  0x0A
#define HID_KEYBOARD_H                  0x0B
#define HID_KEYBOARD_I                  0x0C
#define HID_KEYBOARD_J                  0x0D
#define HID_KEYBOARD_K                  0x0E
#define HID_KEYBOARD_L                  0x0F
#define HID_KEYBOARD_M                  0x10
#define HID_KEYBOARD_N                  0x11
#define HID_KEYBOARD_O                  0x12
#define HID_KEYBOARD_P                  0x13
#define HID_KEYBOARD_Q                  0x14
#define HID_KEYBOARD_R                  0x15
#define HID_KEYBOARD_S                  0x16
#define HID_KEYBOARD_T                  0x17
#define HID_KEYBOARD_U                  0x18
#define HID_KEYBOARD_V                  0x19
#define HID_KEYBOARD_W                  0x1A
#define HID_KEYBOARD_X                  0x1B
#define HID_KEYBOARD_Y                  0x1C
#define HID_KEYBOARD_Z                  0x1D
#define HID_KEYBOARD_1                  0x1E
#define HID_KEYBOARD_2                  0x1F
#define HID_KEYBOARD_3                  0x20
#define HID_KEYBOARD_4                  0x21
#define HID_KEYBOARD_5                  0x22
#define HID_KEYBOARD_6                  0x23
#define HID_KEYBOARD_7                  0x24
#define HID_KEYBOARD_8                  0x25
#define HID_KEYBOARD_9                  0x26
#define HID_KEYBOARD_0                  0x27
#define HID_KEYBOARD_RETURN             0x28  // Enter/Return
#define HID_KEYBOARD_ESCAPE             0x29  // Escape
#define HID_KEYBOARD_BACKSPACE          0x2A  // Delete/Backspace
#define HID_KEYBOARD_TAB                0x2B  // Tab
#define HID_KEYBOARD_SPACE              0x2C  // Space
#define HID_KEYBOARD_MINUS              0x2D  // -_
#define HID_KEYBOARD_EQUAL              0x2E  // =+
#define HID_KEYBOARD_BRACKET_LEFT       0x2F  // [{
#define HID_KEYBOARD_BRACKET_RIGHT      0x30  // ]}
#define HID_KEYBOARD_BACKSLASH          0x31  // \|
#define HID_KEYBOARD_SEMICOLON          0x33  // ;:
#define HID_KEYBOARD_APOSTROPHE          0x34  // '"
#define HID_KEYBOARD_GRAVE              0x35  // `~
#define HID_KEYBOARD_COMMA              0x36  // ,<
#define HID_KEYBOARD_PERIOD             0x37  // .>
#define HID_KEYBOARD_SLASH              0x38  // /?
#define HID_KEYBOARD_CAPS_LOCK          0x39  // Caps Lock

// Modifier keys
#define HID_KEYBOARD_CTRL               0xE0  // Left Control
#define HID_KEYBOARD_SHIFT              0xE1  // Left Shift
#define HID_KEYBOARD_ALT               0xE2  // Left Alt / Option
#define HID_KEYBOARD_GUI               0xE3  // Left Command / Meta (Mac Cmd key)
#define HID_KEYBOARD_CTRL_RIGHT         0xE4  // Right Control
#define HID_KEYBOARD_SHIFT_RIGHT        0xE5  // Right Shift
#define HID_KEYBOARD_ALT_RIGHT         0xE6  // Right Alt / Option
#define HID_KEYBOARD_GUI_RIGHT         0xE7  // Right Command / Meta

// Function keys
#define HID_KEYBOARD_F1                0x3A
#define HID_KEYBOARD_F2                0x3B
#define HID_KEYBOARD_F3                0x3C
#define HID_KEYBOARD_F4                0x3D
#define HID_KEYBOARD_F5                0x3E
#define HID_KEYBOARD_F6                0x3F
#define HID_KEYBOARD_F7                0x40
#define HID_KEYBOARD_F8                0x41
#define HID_KEYBOARD_F9                0x42
#define HID_KEYBOARD_F10               0x43
#define HID_KEYBOARD_F11               0x44
#define HID_KEYBOARD_F12               0x45

// Keypad
#define HID_KEYBOARD_KEYPAD_NUM_LOCK   0x53
#define HID_KEYBOARD_KEYPAD_SLASH      0x54
#define HID_KEYBOARD_KEYPAD_ASTERISK   0x55
#define HID_KEYBOARD_KEYPAD_MINUS      0x56
#define HID_KEYBOARD_KEYPAD_PLUS       0x57
#define HID_KEYBOARD_KEYPAD_ENTER      0x58
#define HID_KEYBOARD_KEYPAD_1          0x59
#define HID_KEYBOARD_KEYPAD_2          0x5A
#define HID_KEYBOARD_KEYPAD_3          0x5B
#define HID_KEYBOARD_KEYPAD_4          0x5C
#define HID_KEYBOARD_KEYPAD_5          0x5D
#define HID_KEYBOARD_KEYPAD_6          0x5E
#define HID_KEYBOARD_KEYPAD_7          0x5F
#define HID_KEYBOARD_KEYPAD_8          0x60
#define HID_KEYBOARD_KEYPAD_9          0x61
#define HID_KEYBOARD_KEYPAD_0          0x62
#define HID_KEYBOARD_KEYPAD_PERIOD     0x63

// Arrow keys
#define HID_KEYBOARD_UP_ARROW          0x52
#define HID_KEYBOARD_DOWN_ARROW        0x51
#define HID_KEYBOARD_LEFT_ARROW        0x50
#define HID_KEYBOARD_RIGHT_ARROW       0x4F

// Consumer Page codes (for media keys)
#define CONSUMER_PAGE                   0x0C
#define CONSUMER_VOLUME_UP              0xE9
#define CONSUMER_VOLUME_DOWN            0xEA
#define CONSUMER_MUTE                   0xE2
#define CONSUMER_PLAY_PAUSE            0xCD

typedef enum {
    KEY_FUNC_MIC = 0,    // Key 0: Microphone - triggers voice input
    KEY_FUNC_ALLOW,       // Key 1: Allow/Approve - sends Return
    KEY_FUNC_DISALLOW,    // Key 2: Disallow/Reject - sends Escape
    KEY_FUNC_ENTER,       // Key 3: Enter - sends Return
    KEY_FUNC_POWER        // Key 4: Power key (unchanged)
} mac_key_function_t;

typedef struct {
    mac_key_function_t func;
    uint8_t key_code;           // HID key code to send
    uint8_t modifier;            // Modifier keys (Shift, Ctrl, Alt, Cmd)
    const char* description;    // Key description
} mac_key_config_t;

extern const mac_key_config_t mac_key_configs[5];

void mac_key_press(uint8_t key_index);
void mac_key_release(uint8_t key_index);
void mac_key_click(uint8_t key_index);
void trigger_voice_input(void);

#endif
