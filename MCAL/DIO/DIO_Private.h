/*
 * DIO_Private.h
 *
 * Created: 10/20/2023 10:51:52 AM
 *  Author: DELL
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*

/ * DIO_Registers * /
#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

#define PINA (*(volatile unsigned char*)0x39)
#define PINB (*(volatile unsigned char*)0x36)
#define PINC (*(volatile unsigned char*)0x33)
#define PIND (*(volatile unsigned char*)0x30)

#define PORTA (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*)0x35)
#define PORTD (*(volatile unsigned char*)0x32)
/ ******************************************************************************************************** /*/

extern const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS];

static void DIO_InitPin( DIO_pin_type pin ,DIO_PinStatus_type status);




#endif /* DIO_PRIVATE_H_ */