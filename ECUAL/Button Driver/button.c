/*
 * button.c
 *
 * Created: 13/09/2022 04:32:08 ص
 *  Author: 10
 */ 




#include "button.h"

//Initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin){
	DIO_init(buttonPort,buttonPin,IN);
}

//button read
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value){
	DIO_read(buttonPort,buttonPin,value);
}