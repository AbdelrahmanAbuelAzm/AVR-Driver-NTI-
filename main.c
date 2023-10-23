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

volatile u8 EXInt_Flag=0,LCD_flag=0;

int main(void)
{
	
	
	u8 key='T';
	DIO_Init();
	LCD_Init();
	KEKPAD_Init();
	//EXI_Init();
	
	EXI_TriggerEdge(EX_INT1,RISING_EDGE);
	EXI_Enable(EX_INT1);
	GLOBAL_ENABLE();
	
	LCD_GoTo(0,0);
	LCD_WriteString("EX Interrupt");
	LCD_GoTo(1,0);
	
    u16 num=0,disp_num=0;;
	
    while (1) 
    {
		
		if(LCD_flag==1)
		{
			if(EXInt_Flag == 1 )
			{
				LCD_WriteNumber3(EXInt_Flag);
				LCD_flag=0;
			}
			else if(EXInt_Flag == 2  )
			{
				LCD_WriteNumber3(EXInt_Flag);
				LCD_flag=0;
			}
			else if(EXInt_Flag == 3  )
			{
				LCD_WriteNumber3(EXInt_Flag);
				LCD_flag=0;
			}
			else if(EXInt_Flag == 4)
			{
				LCD_WriteNumber3(EXInt_Flag);
				LCD_flag=0;
			}
			else if(EXInt_Flag == 5)
			{
				LCD_WriteNumber3(EXInt_Flag);
				LCD_flag=0;
			}
			else if(EXInt_Flag == 6)
			{
				LCD_WriteNumber3(EXInt_Flag);
				LCD_flag=0;
			}
			else if(EXInt_Flag == 7)
			{
				LCD_WriteNumber3(EXInt_Flag);
				LCD_flag=0;
			}
			else if(EXInt_Flag == 8)
			{
				LCD_WriteNumber3(EXInt_Flag);
				LCD_flag=0;
			}
			else if(EXInt_Flag == 9)
			{
				LCD_WriteNumber3(EXInt_Flag);
				LCD_flag=0;
			}
			else if(EXInt_Flag == 10)
			{
				LCD_WriteNumber3(EXInt_Flag);
				LCD_flag=0;
			}
		}
		
		
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


ISR(INT1_vect)
{
	if(LCD_flag==0)
	{
		EXInt_Flag++;
	}
	
	
	if(EXInt_Flag==11)
	{
		EXInt_Flag=1;
	}
	delay(50);
	LCD_flag=1;
	
}