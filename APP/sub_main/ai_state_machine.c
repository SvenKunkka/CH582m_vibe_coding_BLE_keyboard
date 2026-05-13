#include "ai_state_machine.h"
#include "psk_ws2812.h"
#include "psk_led.h"

ai_work_state_t g_ai_work_state = AI_STATE_IDLE;

void ai_state_init(void)
{
    g_ai_work_state = AI_STATE_IDLE;
    ws2812_display(WS2812_OFF, 0);
}

void ai_state_set(ai_work_state_t new_state)
{
    ai_work_state_t old_state = g_ai_work_state;
    g_ai_work_state = new_state;

    switch (new_state) {
    case AI_STATE_IDLE:
        ws2812_display(WS2812_OFF, 0);
        ws2812_set_bounce_paused(0);
        break;

    case AI_STATE_WORKING:
        ws2812_display(WS2812_RAINBOW_BOUNCE, 0);
        ws2812_set_bounce_paused(0);
        break;

    case AI_STATE_WAITING_ALLOW:
        ws2812_set_bounce_paused(1);
        break;

    case AI_STATE_WAITING_DISALLOW:
        ws2812_set_bounce_paused(1);
        break;

    case AI_STATE_ALLOWED:
        ws2812_set_bounce_paused(0);
        break;

    case AI_STATE_DISALLOWED:
        ws2812_set_bounce_paused(0);
        break;
    }
}

ai_work_state_t ai_state_get(void)
{
    return g_ai_work_state;
}

uint8_t ai_state_is_waiting(void)
{
    return (g_ai_work_state == AI_STATE_WAITING_ALLOW ||
            g_ai_work_state == AI_STATE_WAITING_DISALLOW);
}

void ai_state_handle_allow(void)
{
    if (g_ai_work_state == AI_STATE_WAITING_ALLOW) {
        ai_state_set(AI_STATE_ALLOWED);
        ai_state_set(AI_STATE_WORKING);
    }
}

void ai_state_handle_disallow(void)
{
    if (g_ai_work_state == AI_STATE_WAITING_DISALLOW) {
        ai_state_set(AI_STATE_DISALLOWED);
        ai_state_set(AI_STATE_IDLE);
    }
}

void ai_state_handle_work_start(void)
{
    if (g_ai_work_state == AI_STATE_IDLE) {
        ai_state_set(AI_STATE_WORKING);
    }
}

void ai_state_handle_work_end(void)
{
    if (g_ai_work_state != AI_STATE_IDLE) {
        ai_state_set(AI_STATE_IDLE);
    }
}
