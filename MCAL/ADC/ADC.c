/*
 * ADC.c
 *
 * Created: 10/24/2023 9:23:52 AM
 *  Author: DELL
 */ 
#include "STD_TYPES.h"
#include "MEM_MAP.h"
#include "UTILIS.h"
#include "ADC_INTERFACE.h"






static u8 ADC_BusyFlag;// for ADC separted functions
// workining on single conversion mode only we have diffrential mode 
void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler)
{
	//vref
	/*
	AREF, Internal Vref turned off                        ******************* Important note while select the mode******************
	AVCC with external capacitor at AREF pin
	*/
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	//prescaler
	ADCSRA&=0xF8;    //clear first 3 bit in the reg 
	scaler&=0x07;    // take first 3 num in number only 
	ADCSRA=ADCSRA|scaler;  // put the input prescaler in first 3 bit in regester
	 
	
	//Enable ADC
	SET_BIT(ADCSRA,ADEN); // mmokin a3ml7a function low el app bta3y 3ayez y3ml power consumption
	
}

void ADC_Auto_Triggered_Init(ADC_AutoTriggered_type Selected_Mode,ADC_Channel_type CH)
{
	
	ADMUX&=0xE0; // clear 5 bits of mul input
	CH&=0x1F; //take first 5 bits of ch number
	ADMUX=ADMUX|CH;  //put the value of ch in the 5 bits
	
	
	SET_BIT(ADCSRA,ADEN); // ADC ENABLE
	SET_BIT(ADCSRA,ADPS2);  
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS0);
	
	
	
	SET_BIT(ADCSRA,ADATE);//enable auto triggered
	SET_BIT(ADCSRA,ADIE);//enable ADC INTURRENPT ENAPLE
	
	
	switch(Selected_Mode)
	{
		case ADC_Free_Running:
		CLR_BIT(SFIOR,ADTS0);
		CLR_BIT(SFIOR,ADTS1);
		CLR_BIT(SFIOR,ADTS2);
		SET_BIT(ADCSRA,ADSC);    // Start conversion at first time only 
		break;
		
		case ADC_Analog_Comparator:
		SET_BIT(SFIOR,ADTS0);
		CLR_BIT(SFIOR,ADTS1);
		CLR_BIT(SFIOR,ADTS2);
		break;
		
		case ADC_EXTERNAL_INTERRUPT0:
		CLR_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		CLR_BIT(SFIOR,ADTS2);
		break;
		
		case ADC_TIMER0_COMPARE_MATCH:
		SET_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		CLR_BIT(SFIOR,ADTS2);
		break;
		
		case ADC_TIMER0_OVERFLOW:
		CLR_BIT(SFIOR,ADTS0);
		CLR_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
		case ADC_TIMER_COMPARE_MATCH_B:
		SET_BIT(SFIOR,ADTS0);
		CLR_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
		case ADC_TIMER1_OVERFLOW:
		CLR_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
		case ADC_TIMER1_CAPUTRE_EVENT:
		SET_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
	}
	
	//SET_BIT(ADCSRA,ADSC);
	
}

void ADC_Channel_Selection(ADC_Channel_type CH)
{
	// set channel mux
	ADMUX&=0xE0; // clear 5 bits of mul input
	CH&=0x1F; //take first 5 bits of ch number
	ADMUX=ADMUX|CH;  //put the value of ch in the 5 bits
}

u16 ADC_Read(ADC_Channel_type CH)
{
	// set channel mux
	ADMUX&=0xE0; // clear 5 bits of mul input
	CH&=0x1F; //take first 5 bits of ch number
	ADMUX=ADMUX|CH;  //put the value of ch in the 5 bits
	
	//ADC start conversion
	SET_BIT(ADCSRA,ADSC); //start conversion ,after conversion finished the bit return to 0 automatically
	
	//wait for ADC finish
	while(READ_BIT(ADCSRA,ADSC)==1);  //stop here until conversion done
	
	//Get read
	/*
	u16 adc=ADCL;
	adc=adc|(ADCH<<8);
	return adc;
	*/
	
	/*
	if ADLE=1
	u16 adc=ADCL>>6;
	adc=adc|ADCH<<2;*/
	
	return ADC; // read the u16 (2 registers) of stored  data ;
}

u16 ADC_StartConversion(ADC_Channel_type CH)
{
	
	if(ADC_BusyFlag==0)
	{
		ADMUX&=0xE0; // clear 5 bits of mul input
		CH&=0x1F; //take first 5 bits of ch number
		ADMUX=ADMUX|CH;  //put the value of ch in the 5 bits
		
		//ADC start conversion
		SET_BIT(ADCSRA,ADSC); //start conversion ,after conversion finished the bit return to 0 automatically
		ADC_BusyFlag=1;
	}
	return 0; //check the return value
}

u16 ADC_GetRead(ADC_Channel_type CH)
{
	//Get read
	/*
	u16 adc=ADCL;
	adc=adc|(ADCH<<8);
	return adc;
	*/
	
	/*
	if ADLE=1
	u16 adc=ADCL>>6;
	adc=adc|ADCH<<2;*/
	//while(READ_BIT(ADCSRA,ADSC)==1);  //stop here until conversion done (blocking methode)
	return ADC; // read the u16 (2
}

u8 ADC_GetReadPeriodic(u16*pdata)
{
	//periodic check (polling methode)  5las conversion wla la2 badl el busy wait
	if(!READ_BIT(ADCSRA,ADSC))
	{
		*pdata=ADC;
		ADC_BusyFlag=0;
		return 1;
	}
	return 0;
}

 u16 ADC_GetReadNoblock(void)
 {
	 return ADC;
 }

u16 ADC_VoltRead(ADC_Channel_type CH)// return volt in MV
{
	u16 volt;
	u16 adc;
	adc=ADC_Read(CH);
	volt=(((u32)adc*5000))/1024;  //eqn for measure volt in mile volt
	
	
	return volt;
}

u16 InterPolation(u16 y1,u16 y2,u16 x,u16 x1,u16 x2)
{
	u16 y=((((y2-(s32)y1)*(s32)(x-x1))/(x2-x1))+y1);
	//u16 y=(((((y2-y1)*(u32)(x-x1))+((x2-x1)/2))/(x2-x1))+y1); // bygeb resolution a3la lec 51 min 20 check if forget
	return y;
}