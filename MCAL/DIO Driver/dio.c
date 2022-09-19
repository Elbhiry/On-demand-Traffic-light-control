/*
 * dio.c
 *
 * Created: 13/09/2022 04:42:36 ص
 *  Author: 10
 */ 


 

//include  .h
#include "dio.h"
//global variables  static or extern'
//function definition

void DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction)
{
	switch(portNumber)
  {
	case PORT_A:
	
	if(direction == IN)
	{
		 DDRA &=~(1<<pinNumber);   //INPUT
	}
	else if (direction == OUT)
	{
		DDRA |=(1<<pinNumber);     //OUTPUT
	}
	else 
	{
	//Error Handling
	}
	break;
  
  
  
  case PORT_B:
       if(direction == IN)
        {
	      DDRB &=~(1<<pinNumber);   //INPUT
        }
       else if (direction == OUT)
         {
	      DDRB |=(1<<pinNumber);     //OUTPUT
         }
       else
        {
	      //Error Handling
        }
    break;
  
   case PORT_C:
    if(direction == IN)
    {
	    DDRC &=~(1<<pinNumber);   //INPUT
    }
    else if (direction == OUT)
    {
	    DDRC |=(1<<pinNumber);     //OUTPUT
    }
    else
    {
	    //Error Handling
    }
    break;
   
   case PORT_D:
   if(direction == IN)
   {
	   DDRD &=~(1<<pinNumber);   //INPUT
   }
   else if (direction == OUT)
   {
	   DDRD |=(1<<pinNumber);     //OUTPUT
   }
   else
   {
	   //Error Handling
   }
   break;
  
  }
  
}
void DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
		
		if(value == LOW)
		{
			PORTA &=~(1<<pinNumber);   //Write 0
		}
		else if (value == HIGH)
		{
			PORTA |=(1<<pinNumber);    //Write 1
		}
		else
		{
			//Error Handling
		}
		break;
		
		
		
		case PORT_B:
		if(value == LOW)
		{
			PORTB &=~(1<<pinNumber);   //Write 0
		}
		else if (value == HIGH)
		{
			PORTB |=(1<<pinNumber);     //Write 1
		}
		else
		{
			//Error Handling
		}
		break;
		
		case PORT_C:
		if(value == LOW)
		{
			PORTC &=~(1<<pinNumber);   //Write 0
		}
		else if (value == HIGH)
		{
			PORTC |=(1<<pinNumber);      //Write 1
		}
		else
		{
			//Error Handling
		}
		break;
		
		case PORT_D:
		if(value == LOW)
		{
			PORTD &=~(1<<pinNumber);   //Write 0
		}
		else if (value == HIGH)
		{
			PORTD |=(1<<pinNumber);     //Write 1
		}
		else
		{
			//Error Handling
		}
		break;
		
	}
	
}

void DIO_toggle(uint8_t portNumber,uint8_t pinNumber){
	switch(portNumber)
	{
		case PORT_A:
			PORTA ^=(1<<pinNumber);   
		break;
		
		case PORT_B:
			PORTB ^=(1<<pinNumber);   
		break;
		
		case PORT_C:
			PORTC ^=(1<<pinNumber);   
		break;
		
		case PORT_D:
			PORTD ^=(1<<pinNumber);   
		break;
		
	}
}

void  DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value)
{
	switch(portNumber)
	{
		case PORT_A :
		  *value= (PINA & (1<<pinNumber))>>pinNumber;    //get state ->READ bit
		  break;
		  
		case PORT_B :
		*value= (PINB & (1<<pinNumber))>>pinNumber;    //get state ->READ bit
		 break;
		
		case PORT_C :
		*value= (PINC & (1<<pinNumber))>>pinNumber;    //get state ->READ bit
		 break;
		
		case PORT_D :
		*value= (PIND & (1<<pinNumber))>>pinNumber;    //get state ->READ bit
		 break;
		 
		 default:  
		 //ERROR HANDLING 
		 break;
	}
}