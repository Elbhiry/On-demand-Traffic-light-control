/*
 * dio.h
 *
 * Created: 13/09/2022 04:42:24 ص
 *  Author: 10
 */ 


#ifndef DIO_H_
#define DIO_H_


//inlude register.h
#include "../../Utilities/registers.h"

//all internal driver typedefs
// all driver macros

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// Direction defines
#define IN  0
#define OUT  1

// Value defines
#define LOW  0
#define HIGH  1

//enum  PINS
//{PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7};
	
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7


// all driver functions prototypes

void DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction);  // initialize dio direction (Configuaration)

void DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value); // write data to dio

void DIO_toggle(uint8_t portNumber,uint8_t pinNumber);  // toggle dio

void  DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value);  //// read dio



#endif /* DIO_H_ */