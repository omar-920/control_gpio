#include "stm32f4xx.h"
#include "led.h"

void led_init(uint8_t pin)
{
	RCC->AHB1ENR |= (1U << 0);
	 //PIN 0 MODE
	GPIOA->MODER &= ~(3U << (pin*2));
	GPIOA->MODER |= (1U << (pin*2));
}

void led_on(uint8_t pin)
{
    GPIOA->BSRR = (1U << pin);
}

void led_off(uint8_t pin)
{
    GPIOA->BSRR = (1U << (pin + 16));
}