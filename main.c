/*
 * G9_Round6.c
 *
 * Created: 10/20/2023 10:39:46 AM
 * Author : DELL
 */ 

//#include <avr/io.h>
#include "STD_TYPES.h"
#include "UTILIS.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
//#include "SEGMENT_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "LCD_CONFIG.h"
#include "KEYBAD_INTERFACE.h"
#include "KEYBAD_CONFIG.h"



int main(void)
{
	
	
	u8 key='T';
	DIO_Init();
	LCD_Init();
	KEKPAD_Init();
	LCD_GoTo(0,0);
	LCD_WriteString("KeyBad");
	LCD_WriteChar('A');
	LCD_WriteChar('Z');
	LCD_GoTo(1,0);
	
    u16 num=0,disp_num=0;;
	
    while (1) 
    {
		
				key=KEYPAD_GetKey();
				
				if(key!='T')
				{
					LCD_WriteChar(key);
					
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
}

