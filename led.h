#ifndef LED_H
#define LED_H
#include <stdint.h>
void led_init(uint8_t pin);
void led_on(uint8_t pin);
void led_off(uint8_t pin);

#endif