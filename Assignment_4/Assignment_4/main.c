/*
 * Assignment_4.c
 *
 * Created: 7/20/2020 12:30:58 AM
 * Author : mohammed
 */ 

#include "Timer.h"
#include "LED.h"
#include <avr/interrupt.h>


extern uint8 CounterRegister_InitValue ;

int main(void)
{
	
	
	LED0_Init();
	LED0_ON();
	
	
	Timer_Init();
	
	Timer_SetDelay(1000);
	Timer_Start();
	
	
	while (1)
	{
		
		
	}
}


ISR(TIMER2_COMP_vect)
{
	
	static uint32 counter = 0;
	
	counter++;
	
	if(counter == CounterRegister_InitValue)
	{
		TCNT0 = CounterRegister_InitValue;
		
		counter = 0;
		
		LED0_toggle();
		
	}
	
	
}