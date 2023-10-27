/*
 * G9_Round6.c
 *
 * Created: 10/20/2023 10:39:46 AM
 * Author : DELL
 */ 

//#include <avr/io.h>
#include "STD_TYPES.h"
#include "UTILIS.h"
#include "MEM_MAP.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
//#include "SEGMENT_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "LCD_CONFIG.h"
#include "KEYBAD_INTERFACE.h"
#include "KEYBAD_CONFIG.h"
#include "EX_INTRUUPT_INTERFACE.h"
#include "ADC_INTERFACE.h"
#include "TIMER_INTERFAC.h"
#include "TIMER_SERVICE.h"

volatile u8 ADC_Flag=0,EXT_INT_flag=0,shared_flag=0,OV_Flag=0;



int main(void)
{
	
	
	u8 key='T';
	DIO_Init();
	LCD_Init();
	//KEKPAD_Init();
	
	//ADC_Init(VREF_AVCC,ADC_SCALER_64);
	//ADC_Auto_Triggered_Init(ADC_TIMER0_OVERFLOW,CH_0);
	
	TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_64);
	TIMER0_OV_InterruptEnable();
	
	//EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	//EXI_Enable(EX_INT0);
	
	GLOBAL_ENABLE();
	
	LCD_GoTo(0,0);
	LCD_WriteString("Timer mode");
	
	
    u16 num=0,disp_num=0;
	
	TCNT0=6;
	//OCR0=150;
	
	
    while (1) 
    {
		
		
		
		if(OV_Flag%1==0)
		{
			DIO_TogglePin(PINB7);
		}
		if(OV_Flag%2==0)
		{
			DIO_TogglePin(PINA4);
		}
		if(OV_Flag%5==0)
		{
			DIO_TogglePin(PINA5);
		}
		if(OV_Flag%10==0)
		{
			DIO_TogglePin(PINA6);
		}
		
	/*	if(ADC_Flag==1)
		{
			LCD_GoTo(1,0);
			LCD_WriteString("chanel 0=");
			LCD_WriteString("    ");
			LCD_GoTo(1,0);
			LCD_WriteNumber(ADC_GetRead(CH_0));
			
			ADC_Channel_Selection(CH_1);
			//ADC_Flag=0;
			//delay(100);
		}
		else if(ADC_Flag==2)
		{
			LCD_GoTo(2,0);
			LCD_WriteString("chanel 1=");
			LCD_WriteNumber(ADC_GetRead(CH_1));
			ADC_Channel_Selection(CH_0);
			
			//ADC_Flag=0;
			
		}*/
		
					
				}
				
    }


ISR(TIMER0_OV_vect)
{
	static u16 c=0;
	TCNT0=6;
	c++;
	if(c==1000)
	{
		//DIO_TogglePin(PINB7);
		OV_Flag++;
		c=0;
		if(OV_Flag==11)
		{
			OV_Flag=1;
		}
		
	}
	
}

/*
ISR(TIMER0_OC_vect)
{
	DIO_TogglePin(PINB7);
	
	
}
*/
ISR(ADC_vect)
{
	
	
	if(shared_flag==1)
	{
		DIO_TogglePin(PINB5);
		shared_flag=0;
		ADC_Flag++;
		if(ADC_Flag==3)
		{
			ADC_Flag=0;
		}
		
	}
	
	
}
/*
ISR(INT0_vect)
{
	EXT_INT_flag++;
	DIO_TogglePin(PINB6);
	if(EXT_INT_flag==2)
	{
		EXT_INT_flag=0;
	}
	
	
	
}
*/