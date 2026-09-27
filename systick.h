#ifndef SYSTICK_H
#define SYSTICK_H
#include <stdint.h>

extern volatile uint32_t tick_count;

void SysTick_Init();
void Delay_ms(uint32_t ms);


#endif