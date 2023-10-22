/*
 * KEYBAD.c
 *
 * Created: 10/22/2023 10:26:49 AM
 *  Author: DELL
 */ 
#define KEYPAD_PRG 1



#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "KEYBAD_INTERFACE.h"
#include "UTILIS.h"
#include "KEYBAD_CONFIG.h"



void KEKPAD_Init(void)
{
	
	for(u8 r=0;r<ROWS;r++)
	{
		DIO_WritePin(LAST_OUTPUT-r,HIGH);
	}
	
}

u8 KEYPAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;
	for(r=0;r<ROWS;r++)
	{
		DIO_WritePin(LAST_OUTPUT-r,LOW);
		for(c=0;c<COLS+1;c++)
		{
			if(DIO_ReadPin(LAST_INPUT-c)==LOW)
			{
				if(c<3)
				{
					key=KeysArr[r][c];
					delay(10);
					while(DIO_ReadPin(LAST_INPUT-c)==LOW);
				}
				else if(c==3)
				{
					continue;
				}
				else if(c>3)
				{
					key=KeysArr[r][c-1];
					delay(10);
					while(DIO_ReadPin(LAST_INPUT-c)==LOW);
				}
				
			}
		}
		DIO_WritePin(LAST_OUTPUT-r,HIGH);
	}
	return key;
	
}


