#include "stm32f4xx.h"
#include "clock.h"
#include "systick.h"
#include "led.h"
#include "traffic.h"


int main(void){
	//clock configration
	SystemClock_Config();
	//systick init
	SysTick_Init();
	//link pin , led 
	led_init(0);
	led_init(2);
	led_init(4);
	
	//TURN ALL LEDS OFF
	led_off(0);
	led_off(2);
	led_off(4);
	
	 //Traffic code
	traffic_loop();
	
	return 0;
}






