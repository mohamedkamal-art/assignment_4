/*
 * Timer.c
 *
 * Created: 17/07/2020 12:28:31 م
 *  Author: Ali
 */ 


#include "Timer.h"
#include "BIT_Math.h"


 uint8 CounterRegister_InitValue = 0;
 //uint32 Number_OverFlows = 0;


void Timer_Init(void)
{
	/*Initialize Timer 0  as CTC */
	SET_BIT(TCCR0 , 3);
	CLR_BIT(TCCR0 , 6);
	
	TIMSK |= 0x01;
	
	SREG |= 0x80;
	
}

void Timer_Start(void)
{
	
	/* start timer with prescaler   1024 */
	TCCR0 |= 0x05;
	
}

void Timer_Stop(void)
{
	
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	
}


void Timer_SetDelay(uint32 Delay_Ms)
{
	/* tick time in micro second */
	uint8 Tick_Time_us = (1024 / 16);
	
	uint32 Total_Ticks = (Delay_Ms * 1000) / Tick_Time_us;
	
	CounterRegister_InitValue = Total_Ticks - 1;
	
	OCR0 = CounterRegister_InitValue;
	
    /*Number_OverFlows = Total_Ticks / 256 ;
	
	CounterRegister_InitValue = 256 - (Total_Ticks % 256) ; //256 - ((  ((float) Total_Ticks / 256 ) - Number_OverFlows ) * 256 );
	
	
	TCNT0 = CounterRegister_InitValue ;
	
	Number_OverFlows ++;
	*/
}

