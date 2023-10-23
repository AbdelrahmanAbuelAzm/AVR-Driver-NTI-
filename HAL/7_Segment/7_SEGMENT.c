/*
 * _7_SEGMENT.c
 *
 * Created: 10/21/2023 12:11:12 AM
 *  Author: DELL
 */ 

#include "STD_TYPES.h"
#include "UTILIS.h"
#include "MEM_MAP.h"
#include "SEGMENT_INTERFACE.h"
#include "DIO_Interface.h"



void Segment_Display(u16 num)
{
	
	u8 x1,x2,x3,x4;
	char SegmentArr[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x10,0x11}; //note that digit NO4 in 7SEG connected to PB4 not PB3
	x1=num%10;
	x2=(num/10)%10;
	x3=(num/100)%10;
	x4=(num/1000)%10;
	
	//turn off all Digit
	DIO_WritePin(PINA3,HIGH);
	DIO_WritePin(PINA2,HIGH);
	DIO_WritePin(PINB5,HIGH);
	DIO_WritePin(PINB6,HIGH);
	
	//First Digit
	DIO_WritePin(PINA3,LOW);
	DIO_WritePort(PB,( ( DIO_ReadPort(PB) & (0xE8) )| SegmentArr[x1] ) );
	_delay_us(500);
	DIO_WritePin(PINA3,HIGH);
	
	
	//second Digit
	DIO_WritePin(PINA2,LOW);
	DIO_WritePort(PB,( ( DIO_ReadPort(PB) & (0xE8) )| SegmentArr[x2] ) );
	_delay_us(500);
	DIO_WritePin(PINA2,HIGH);
	
	
	//third Digit
	DIO_WritePin(PINB5,LOW);
	DIO_WritePort(PB,( ( DIO_ReadPort(PB) & (0xE8) )| SegmentArr[x3] ) );
	_delay_us(500);
	DIO_WritePin(PINB5,HIGH);
	
	
	//fourth Digit
	DIO_WritePin(PINB6,LOW);
	DIO_WritePort(PB,( ( DIO_ReadPort(PB) & (0xE8) )| SegmentArr[x4] ) );
	_delay_us(500);
	DIO_WritePin(PINB6,HIGH);
	
	
}



void Segment_Display_2digit_Right(u16 num)
{
	
	u8 x1,x2;
	char SegmentArr[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x10,0x11}; //note that digit NO4 in 7SEG connected to PB4 not PB3
	x1=num%10;
	x2=(num/10)%10;

	
	//turn off all Digit
	DIO_WritePin(PINA3,HIGH);
	DIO_WritePin(PINA2,HIGH);
	
	
	//First Digit
	DIO_WritePin(PINA3,LOW);
	DIO_WritePort(PB,( ( DIO_ReadPort(PB) & (0xE8) )| SegmentArr[x1] ) );
	_delay_us(500);
	DIO_WritePin(PINA3,HIGH);
	
	
	//second Digit
	DIO_WritePin(PINA2,LOW);
	DIO_WritePort(PB,( ( DIO_ReadPort(PB) & (0xE8) )| SegmentArr[x2] ) );
	_delay_us(500);
	DIO_WritePin(PINA2,HIGH);
	
	
}



void Segment_Display_2digit_Left(u16 num)
{
	
	u8 x1,x2;
	char SegmentArr[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x10,0x11}; //note that digit NO4 in 7SEG connected to PB4 not PB3
	x1=num%10;
	x2=(num/10)%10;
	
	
	//turn off all Digit
	
	DIO_WritePin(PINB5,HIGH);
	DIO_WritePin(PINB6,HIGH);
	
	
	//third Digit
	DIO_WritePin(PINB5,LOW);
	DIO_WritePort(PB,( ( DIO_ReadPort(PB) & (0xE8) )| SegmentArr[x1] ) );
	_delay_us(500);
	DIO_WritePin(PINB5,HIGH);
	
	
	//fourth Digit
	DIO_WritePin(PINB6,LOW);
	DIO_WritePort(PB,( ( DIO_ReadPort(PB) & (0xE8) )| SegmentArr[x2] ) );
	_delay_us(500);
	DIO_WritePin(PINB6,HIGH);
	
	
}