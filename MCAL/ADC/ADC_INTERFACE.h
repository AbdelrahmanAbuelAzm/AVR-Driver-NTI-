/*
 * ADC_INTERFACE.h
 *
 * Created: 10/24/2023 9:24:10 AM
 *  Author: DELL
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


typedef enum{
	ADC_Free_Running=0,
	ADC_Analog_Comparator,
	ADC_EXTERNAL_INTERRUPT0,
	ADC_TIMER0_COMPARE_MATCH,
	ADC_TIMER0_OVERFLOW,
	ADC_TIMER_COMPARE_MATCH_B,
	ADC_TIMER1_OVERFLOW,
	ADC_TIMER1_CAPUTRE_EVENT
	}ADC_AutoTriggered_type;
	
	
typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256V
}ADC_VoltRef_type;
typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128  // da byde rakam 7 a7to 3la tol fe el reg mn 8er set w clear
}ADC_Prescaler_type;

typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_type;



void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler);
void ADC_Auto_Triggered_Init(ADC_AutoTriggered_type Selected_Mode,ADC_Channel_type CH);
u16 ADC_StartConversion(ADC_Channel_type CH);
void ADC_Channel_Selection(ADC_Channel_type CH);
u16 ADC_GetRead(ADC_Channel_type CH);
u16 ADC_Read(ADC_Channel_type CH);
u8 ADC_GetReadPeriodic(u16*pdata);
u16 ADC_GetReadNoblock(void);
u16 ADC_VoltRead(ADC_Channel_type CH); //return in mile volt
u16 InterPolation(u16 y1,u16 y2,u16 x,u16 x1,u16 x2);




#endif /* ADC_INTERFACE_H_ */