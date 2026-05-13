#ifndef __AI_STATE_MACHINE_H__
#define __AI_STATE_MACHINE_H__

#include "CONFIG.h"

typedef enum {
    AI_STATE_IDLE = 0,           // No task, LEDs off
    AI_STATE_WORKING,            // AI is coding, rainbow bounce animation
    AI_STATE_WAITING_ALLOW,      // Waiting for user approval, animation paused
    AI_STATE_WAITING_DISALLOW,   // Waiting for user rejection (optional state)
    AI_STATE_ALLOWED,            // User allowed, resume animation
    AI_STATE_DISALLOWED          // User disallowed, resume animation
} ai_work_state_t;

extern ai_work_state_t g_ai_work_state;

void ai_state_init(void);
void ai_state_set(ai_work_state_t new_state);
ai_work_state_t ai_state_get(void);
uint8_t ai_state_is_waiting(void);
void ai_state_handle_allow(void);
void ai_state_handle_disallow(void);
void ai_state_handle_work_start(void);
void ai_state_handle_work_end(void);

#endif
