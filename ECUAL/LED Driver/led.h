/*
 * led.h
 *
 * Created: 13/09/2022 04:32:45 ص
 *  Author: 10
 */ 


#ifndef LED_H_
#define LED_H_


#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Library/interrupt.h"
#include "../../MCAL/Timer Driver/timer.h"

void LED_init(uint8_t ledPort,uint8_t ledPin);
void LED_on(uint8_t ledPort,uint8_t ledPin);
void LED_off(uint8_t ledPort,uint8_t ledPin);
void LED_toggle(uint8_t ledPort,uint8_t ledPin);




#endif /* LED_H_ */