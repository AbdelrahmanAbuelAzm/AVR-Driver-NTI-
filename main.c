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
#include "SEGMENT_INTERFACE.h"

int main(void)
{
	u16 x=0;
	DIO_Init();
	
    
    while (1) 
    {
		
		
		
		for(u8 i=0;i<5;i++)
		{
			
			Segment_Display(x);
			delay(5);
		}
		
		/*Segment_Display(x);
		delay(40);*/
		
		
		x++;
		if(x==10000)
		{
			x=0;
		}
		

		
		
    }
}

