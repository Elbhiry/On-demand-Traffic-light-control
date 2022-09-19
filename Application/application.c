/*
 * application.c
 *
 * Created: 13/09/2022 04:29:54 ص
 *  Author: 10
 */ 
#include "application.h" 
uint8_t led_number=0;
uint8_t ButtonTrig=0;  // Button Trigger
uint8_t CurrLedColour ;


void App_init(void)
{
	/*1.Set direction for button pin to Input*/
	//DDRD |=(1<<PIND2);  //pin 2 port D
	BUTTON_init(PORT_D,PIN2);
	
	/*2.set all LED pins to output */
	
	/************************************************************************/
	/*                	CARS LEDS  Definition   PORTA                      */
	/************************************************************************/
	//DDRA |=(1<<PINA0);
    LED_init(PORT_A,PIN0);   //GREEN

	//DDRA |=(1<<PINA1);
	LED_init(PORT_A,PIN1);  //YELLOW

	//DDRA |=(1<<PINA2);
    LED_init(PORT_A,PIN2);  //RED

	/************************************************************************/
	/*                PEDESTRIANS LEDS  Definition  PORTB                 */
	/************************************************************************/
	 
	//DDRA |=(1<<PINA0);
	LED_init(PORT_B,PIN0);   //GREEN

	//DDRA |=(1<<PINA1);
	LED_init(PORT_B,PIN1);  //YELLOW

	//DDRA |=(1<<PINA2);
	LED_init(PORT_B,PIN2);  //RED
	
	
	
	
	/*3. Enable global interrupts - setting bit 7 in the status register to 1*/
	sei();
	
	/*4.Choose External interrupt Sense control  - sense on rising edge   */
	MCUCR |=(0<<ISC00) | (1<<ISC01);
	//MCUCR |=(0<<1) | (1<<0);

	
	/*5. Enable External interrupt 0 INT0*/
	//GICR |=(1<<INT0);
	GICR |=(1<<6);

//TIMER_init();
    CurrLedColour=0;
}



  void App_start(void)
  {
	  while(1)
	  {
		 while(ButtonTrig==0)
		 {    //Button OFF
			    
				/************************************************************************/
				/*                    Normal Mode  GREEN ON                                                  */
				/************************************************************************/		
				
				//test
				


				
						
			    LED_on(PORT_A,PIN0);   //Green
				LED_off(PORT_A,PIN2);   //red

				CurrLedColour=0;
				TIMERDELAY_start(); // 5sec

				LED_off(PORT_A,PIN0);
				
				if(ButtonTrig==1) break;  //Check BUTTON
				/************************************************************************/
				/*                    Normal Mode  YELLOW ON                                                      */
				/************************************************************************/
				 LED_on(PORT_A,PIN1);   //Yellow
				 TIMERDELAY_start(); // 5sec
				 LED_off(PORT_A,PIN1);
				 CurrLedColour=0;

				 
				 if(ButtonTrig==1) break;   //Check BUTTON
				/************************************************************************/
				/*                    Normal Mode  RED ON                                                      */
				/************************************************************************/
				 LED_off(PORT_A,PIN0);
				 LED_off(PORT_A,PIN1);
				 LED_on(PORT_A,PIN2);   //RED
				 CurrLedColour=1;
				 TIMERDELAY_start(); // 5sec
				 LED_off(PORT_A,PIN2);
				
				if(ButtonTrig==1) break;   //Check BUTTON
				
		 }
				 

				 
			 if(ButtonTrig==1)    //Button ON
			  {
			     
				 switch(CurrLedColour)
				 {
					case  0 :   // G or Y traffic for CARS
					  				

					  LED_on(PORT_B,PIN2);   //red مشاه
					  TIMERDELAY_start(); // 5sec
					  

					  
					  LED_on(PORT_B,PIN1);  // yellow مشاه
					  LED_on(PORT_A,PIN1);  //yellow cars
					  TIMERDELAY_start(); // 5sec
					  
					  LED_off(PORT_B,PIN1);  // yellow مشاه
					  LED_off(PORT_A,PIN1);  //yellow cars
					  LED_off(PORT_B,PIN2);   //red مشاه


					  
					  
					  
					  LED_on(PORT_B,PIN0);  //GREEN OF PEDESTRIANS ON FOR 5 SEC 
					 
					  LED_on(PORT_A,PIN2);   //RED OF CARS ON FOR 5 SEC
					  
					  TIMERDELAY_start(); // 5sec
					  
					  LED_off(PORT_B,PIN0);   //GREEN off مشاه
					  LED_off(PORT_A,PIN2);		//RED off  car			
					  ButtonTrig=0;

					
					 break;
					 
					case  1 :    // RED traffic for CARS
					  //GREEN OF PEDESTRIANS ON FOR 5 SEC //RED OF CARS ON FOR 5 SEC
					  LED_on(PORT_B,PIN0);   //GREEN
					  LED_on(PORT_A,PIN2);   //RED
 					  TIMERDELAY_start(); // 5sec
					  LED_off(PORT_B,PIN0);   //GREEN
					  LED_off(PORT_A,PIN2);	
					  
					  				 
					  
					  
					  
					  
					  
   
                      ButtonTrig=0; 
					  break;
					   
					  default: //ERRORS  
					  break;
 					 
				 }
				  
		 } 
	
      }
  }
  
  
    //controlling the button

  
   ISR(INT0_vect)
 { 
	  ButtonTrig=1;
	 
  }
  
  
  
  
 
 
 

 
 
 
