/*
 * timer.h
 *
 * Created: 13/09/2022 04:43:26 ص
 *  Author: 10
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../DIO Driver/dio.h"
#include "../../Utilities/registers.h"


void TIMER_init(void);
void TIMERDELAY_start(void);
void TIMER_stop(void);
void QuickTogg(void);

//void TIMER_getState(void);


#endif /* TIMER_H_ */