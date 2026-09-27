#include "led.h"
#include "systick.h"
#include "traffic.h"

void traffic_loop()
{
while(1){
		//Green led on
		led_on(0);
		led_off(2);
		led_off(4);
		// delay(1000000);
		Delay_ms(1000);
		
		//yellow led on
		led_off(0);
		led_on(2);
		led_off(4);
	// delay(1000000);
		Delay_ms(1000);
		
		//Red led on
		led_off(0);
		led_off(2);
		led_on(4);
	// delay(1000000);
		Delay_ms(1000);
		
	}
}