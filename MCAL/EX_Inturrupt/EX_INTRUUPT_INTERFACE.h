/*
 * EX_INTRUUPT_INTERFACE.h
 *
 * Created: 10/23/2023 9:34:59 AM
 *  Author: DELL
 */ 


#ifndef EX_INTRUUPT_INTERFACE_H_
#define EX_INTRUUPT_INTERFACE_H_

#include "EX_INTURRUPT_CONFIG.h"




typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}TriggerEdge_type;

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;


void EXI_Init(void);

#define   GLOBAL_ENABLE    sei
#define   Global_Disable   cli

void EXI_Enable(ExInterruptSource_type Interrupt);
void EXI_Disable(ExInterruptSource_type Interrupt);
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void));






#endif /* EX_INTRUUPT_INTERFACE_H_ */