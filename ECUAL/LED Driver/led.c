/*
 * led.c
 *
 * Created: 13/09/2022 04:32:34 ص
 *  Author: 10
 */ 

#include "led.h"


void LED_init(uint8_t ledPort,uint8_t ledPin)  //output DEvice
{
	DIO_init(ledPort,ledPin,OUT);
	
}
void LED_on(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,HIGH);
	
}

void LED_off(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,LOW);
}

void LED_toggle(uint8_t ledPort,uint8_t ledPin)
{
	DIO_toggle(ledPort,ledPin);
}