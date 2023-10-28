/*
 * TIMER_SERVICE.h
 *
 * Created: 10/27/2023 9:40:34 AM
 *  Author: DELL
 */ 


#ifndef TIMER_SERVICE_H_
#define TIMER_SERVICE_H_

#include "STD_TYPES.h"
#include "MEM_MAP.h"
#include "UTILIS.h"





void PWM_Init(void);
void PWM_Freq_KHZ(u16 freq);
void PWM_Freq_HZ(u16 freq);
void PWM_Duty(u16 duty);

void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void));
void Timer1_SetInterruptTime_us (u16 time,void(*LocalFptr)(void));
void Timer1_SetInterruptTime_s (u16 time,void(*LocalFptr)(void));
//void PWM_Measure(u32* Pfreq,u8* Pduty);
void PWM_Measure(u32* Pfreq,u8* Pduty,u32 timeout);
void PWM_Measure2(u32* Pfreq,u8* Pduty);


/********* Timer0 interface ***********/

void PWM_TIMER0_Init(void);
void PWM_timer0_Duty(u16 duty);






#endif /* TIMER_SERVICE_H_ */