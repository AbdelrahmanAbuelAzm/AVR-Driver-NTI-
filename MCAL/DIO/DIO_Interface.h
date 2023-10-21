/*
 * DIO_Interface.h
 *
 * Created: 10/20/2023 10:53:17 AM
 *  Author: DELL
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
}DIO_PinStatus_type;

typedef enum{
	PA=0,
	PB,
	PC,
	PD
}DIO_Port_type;

typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_pin_type;
typedef enum{
	LOW=0,
	HIGH
}DIO_PinVoltage_type;



void DIO_Init(void);

void DIO_WritePin(DIO_pin_type pin , DIO_PinVoltage_type volt);
void DIO_InitPin2(DIO_Port_type port,u8 pin_num,  DIO_PinStatus_type status);

DIO_PinVoltage_type DIO_ReadPin(DIO_pin_type pin);
void DIO_TogglePin(DIO_pin_type pin);
void DIO_WritePort(DIO_Port_type port,u8 data);
u8 DIO_ReadPort(DIO_Port_type port);


//new driver


void DIO_Set_u8PortDirection(u8 copy_u8Port_ID,u8 copy_u8Port_Direc);
void DIO_Set_u8PortValue(u8 copy_u8Port_ID,u8 copy_u8Port_Value);
void DIO_Set_PinDirection(u8 copy_u8Port_ID,u8 copy_u8Pin_ID,u8 copy_u8pin_Direc);
void DIO_Set_PinValue(u8 copy_u8Port_ID,u8 copy_u8Pin_ID,u8 copy_u8pin_Value);
u8   DIO_Get_PinValue(u8 copy_u8Port_ID,u8 copy_u8Pin_ID,u8 copy_u8pin_Value);
void DIO_TogglePin2(u8 copy_u8Port_ID,u8 copy_u8Pin_ID);





#endif /* DIO_INTERFACE_H_ */