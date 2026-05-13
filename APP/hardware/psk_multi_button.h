#ifndef _PSK_MULTI_BUTTON_H
#define _PSK_MULTI_BUTTON_H

#include "main.h"

#define TOTAL_KEY 5

void my_button_init(void);
void key_scan(void);
uint8_t num_of_keys(void);
void set_mode(uint8_t mode);
void user_defined_mode(uint8_t key_index, uint8_t if_press, uint8_t mode);

#endif
