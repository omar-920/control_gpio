#include "stm32f4xx.h"
#include "clock.h"

void SystemClock_Config(void)
{

	RCC->CR |= RCC_CR_HSEON;
	
	//make sure HSE ready
	//while (!(RCC->CR & RCC_CR_HSERDY));
	
	uint32_t timeout = 0xFFFFF;
		while (!(RCC->CR & RCC_CR_HSERDY)) {
			if (--timeout == 0) {
        break;
			}
		}
	
		
	FLASH->ACR &= ~FLASH_ACR_LATENCY; // MAKE FLASH MEMORY 0 
	
	//TWO WAIT STATUS
	FLASH->ACR |= FLASH_ACR_LATENCY_2WS;
		
	// (Prefetch & Caches)
    FLASH->ACR |= FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN;
	
	// PLL CONFIGRATION
	
	RCC->PLLCFGR =	(25U << 0)	|	
									(336U << 6)	|
									(1U << 16)	|
									(RCC_PLLCFGR_PLLSRC_HSE)	|
									(7U << 24);
	RCC->CR |= RCC_CR_PLLON;
	
	while(!(RCC->CR & RCC_CR_PLLRDY));
	
	//make sure APB1 , APB2 , AHB  = 0
	RCC->CFGR &= ~(RCC_CFGR_HPRE | RCC_CFGR_PPRE1 | RCC_CFGR_PPRE2);
	
	// division of APB1 by 2 to make sure 42 MHZ instead of 84 MHZ
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
	
	//make PLL speed default for microcontroller
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	
	// wait until finishing every thing
	while((RCC->CFGR & RCC_CFGR_SWS_PLL) != RCC_CFGR_SWS_PLL);
	
}