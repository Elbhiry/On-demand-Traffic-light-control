/*
 * interrupt.h
 *
 * Created: 13/09/2022 04:42:55 ص
 *  Author: 10
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

//#include "../../Utilities/registers.h"
#include "avr/interrupt.h"



/************************************************************************/
/*      Interrupt vectors                                                                     */
/***********************************************************************
//  External Interrupt Vectors

// External Interrupt Request 0
#define EXT_INT_0 __vector1

//External Interrupt Request 1
#define EXT_INT_1 __vector_2

// External Interrupt Request 2
#define EXT_INT_2 __vector_3


//Set Global Interrupts , Set the I-bit in status register to 1
//#define sei() __asm__ __volatile__ ("sei" ::: "memory")
#define sei() __asm volatile( "sei" ::: "memory" )


//clear Global Interrupts ,Set the I-bit in status register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

// ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

*/


#endif /* INTERRUPT_H_ */