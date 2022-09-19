/*
 * button.h
 *
 * Created: 13/09/2022 04:31:59 ص
 *  Author: 10
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_



#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Library/interrupt.h"
#include "../../MCAL/Timer Driver/timer.h"


#define BUTTON_1_PORT PORT_C
#define BUTTON_1_PIN PIN1

#define ButtonNotPressed  0
#define ButtonPressed     1


#define BUTTON_2_PORT PORT_D

//Initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);

//button read
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);



#endif /* BUTTON_H_ */