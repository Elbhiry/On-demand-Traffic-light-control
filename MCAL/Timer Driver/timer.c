/*
 * timer.c
 *
 * Created: 13/09/2022 04:43:13 ص
 *  Author: 10
 */ 
#include "timer.h"
//#define NUMBER_OF_OVERFLOWS 19532
#define NUMBER_OF_OVERFLOWS 10000

unsigned int overflowCounter=0;
	

	/* Replace with your application code */
	
void TIMER_init(void)
{
	
	//Choose Timer Mode(Configuration)
	TCCR0 =0x00;   //Normal mode and not start timer
	// Set timer initial value
	TCNT0 =0x00;   //Data register (counter)
	//// Start Timer  -> Set the clock source (prescalar)
	//TCCR0 |=(1<<0);  //NO PRESCALAR
	

}



void TIMERDELAY_start(void)
{
	// Start Timer  -> Set the clock source (prescalar)
	TCCR0 |=(1<<0);  //NO PRESCALAR
	
	while(overflowCounter<NUMBER_OF_OVERFLOWS)
	{
		//repeated 2000 times
		//STOP AFTER 1 OVERFLOW  check timer interrupt flag register
		// wait until the overflow flag is to be set(BUSY WAIT)
		while((TIFR&(1<<0))==0);
		//clear the overflow
		TIFR |=(1<<0);
		overflowCounter++;
	}
	overflowCounter=0;
}


void TIMER_stop(void)
{
	//stop timer
	TCCR0=0x00;
	
}

void QuickTogg(void)
{
	 #define NUMBER_OVERFLOWS 1000

	// Start Timer  -> Set the clock source (prescalar)
	TCCR0 |=(1<<0);  //NO PRESCALAR
	
	while(overflowCounter<NUMBER_OVERFLOWS)
	{

		//repeated 2000 times
		//STOP AFTER 1 OVERFLOW  check timer interrupt flag register
		// wait until the overflow flag is to be set(BUSY WAIT)
		while((TIFR&(1<<0))==0);
		//clear the overflow
		TIFR |=(1<<0);
		overflowCounter++;
	}
	overflowCounter=0;
}
	
	
	
	

		
		
		//LED_toggle(PORT_D,PIN7);
		//LED_on(PORT_B,0);
		
		
		
		
		
	
	
	
	
	
	
	
	
	//LED_init(PORT_D,PIN7);
	//LED_init(PORT_B,0);
	//BUTTON_init(PORT_C,1);
	//LED_init(PORT_D,7);
	// uint8_t buttonState;