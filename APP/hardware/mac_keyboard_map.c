#include "mac_keyboard_map.h"
#include "keyboard.h"
#include "custom_control.h"

const mac_key_config_t mac_key_configs[5] = {
    {KEY_FUNC_MIC,     0x00, 0x00, "Microphone"},
    {KEY_FUNC_ALLOW,    HID_KEYBOARD_RETURN, 0x00, "Allow"},
    {KEY_FUNC_DISALLOW, HID_KEYBOARD_ESCAPE, 0x00, "Disallow"},
    {KEY_FUNC_ENTER,    HID_KEYBOARD_RETURN, 0x00, "Enter"},
    {KEY_FUNC_POWER,    0x00, 0x00, "Power"}
};

void mac_key_press(uint8_t key_index)
{
    if (key_index >= 5) return;

    const mac_key_config_t* cfg = &mac_key_configs[key_index];

    switch (cfg->func) {
    case KEY_FUNC_MIC:
        trigger_voice_input();
        break;

    case KEY_FUNC_ALLOW:
    case KEY_FUNC_DISALLOW:
    case KEY_FUNC_ENTER:
        if (cfg->modifier) {
            keyboard_press_sp_key_1(LEFT_GUI, 1);
        }
        keyboard_press_key_code_1(cfg->key_code, 1);
        break;

    case KEY_FUNC_POWER:
        break;
    }
}

void mac_key_release(uint8_t key_index)
{
    if (key_index >= 5) return;

    const mac_key_config_t* cfg = &mac_key_configs[key_index];

    switch (cfg->func) {
    case KEY_FUNC_MIC:
        break;

    case KEY_FUNC_ALLOW:
    case KEY_FUNC_DISALLOW:
    case KEY_FUNC_ENTER:
        keyboard_press_key_code_1(cfg->key_code, 0);
        if (cfg->modifier) {
            keyboard_press_sp_key_1(LEFT_GUI, 0);
        }
        break;

    case KEY_FUNC_POWER:
        break;
    }
}

void mac_key_click(uint8_t key_index)
{
    if (key_index >= 5) return;

    const mac_key_config_t* cfg = &mac_key_configs[key_index];

    switch (cfg->func) {
    case KEY_FUNC_MIC:
        trigger_voice_input();
        break;

    case KEY_FUNC_ALLOW:
    case KEY_FUNC_DISALLOW:
    case KEY_FUNC_ENTER:
        keyboard_press_key_code(cfg->key_code, 1);
        break;

    case KEY_FUNC_POWER:
        break;
    }
}

void trigger_voice_input(void)
{
}
