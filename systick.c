#include "stm32f4xx.h"
#include "systick.h"

void SysTick_Init(void)
{
	SysTick->LOAD = 84000-1;
	SysTick->VAL = 0;
	SysTick->CTRL = (1U << 2) | (1U << 1) | (1U << 0) ;
}

volatile uint32_t tick_count = 0;

void SysTick_Handler(void)
{
	tick_count++;
}

void Delay_ms(uint32_t ms)
{
	//polling loop
	//for(uint32_t i=0; i < ms; i++){
		//while(!(SysTick->CTRL & (1U << 16)));
	//}
	
	//SysTick Interrupt
	uint32_t start = tick_count;
	while((tick_count - start) < ms);
}

//old delay
//void delay(volatile uint32_t count){
//	while(count--);
//}
