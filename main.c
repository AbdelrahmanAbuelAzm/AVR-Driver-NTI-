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

volatile u8 ADC_Flag=0;

int main(void)
{
	
	
	u8 key='T';
	DIO_Init();
	LCD_Init();
	//KEKPAD_Init();
	
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	ADC_Auto_Triggered_Init(ADC_EXTERNAL_INTERRUPT0,CH_0);
	
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	EXI_Enable(EX_INT0);
	GLOBAL_ENABLE();
	
	LCD_GoTo(0,0);
	LCD_WriteString("ADC Interrupt");
	LCD_GoTo(1,0);
	
    u16 num=0,disp_num=0;;
	//ADC_StartConversion(CH_1);
	
	
    while (1) 
    {
		
		if(ADC_Flag==1)
		{
			LCD_WriteNumber(ADC_Read(CH_0));
			LCD_WriteString("in");
			ADC_Flag=0;
		}
		
		
		//delay(20);
		
		
				/*key=KEYPAD_GetKey();
				
				if(key!='T')
				{
					if(key=='1')
					{
						LCD_GoTo(0,0);
						LCD_WriteString("Abdelrahman");
					}
					else if(key=='2')
					{
						LCD_GoTo(1,0);
						LCD_WriteString("Ibrahim");
					}
					else if(key=='3')
					{
						LCD_GoTo(2,0);
						LCD_WriteString("Abdullah");
					}
					else if(key=='4')
					{
						LCD_GoTo(3,0);
						LCD_WriteString("Abo EL Azm");
					}*/
					/*if(key>='0' && key<='9')
					{
						num=(num*10)+(key-'0');
					}
					else if(key== '=')
					{
						//equal_flag=1;
						num=0;
						//num=0;
					}*/
					
				}
				
				
			
    }


ISR(ADC_vect)
{
	
		ADC_Flag=1;
		
}
ISR(INT0_vect)
{
	
	DIO_TogglePin(PINB7);
	
}