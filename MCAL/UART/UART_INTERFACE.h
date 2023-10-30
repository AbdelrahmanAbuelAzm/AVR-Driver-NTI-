/*
 * UART_INTERFACE.h
 *
 * Created: 10/29/2023 2:42:25 AM
 *  Author: DELL
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Init(void);

void UART_Send(u8 data);

u8 UART_Receive(void);

u8 UART_ReceivePerodic(u8*pdata);



void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);

void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);

void UART_RX_SetCallBack(void (*LocalFptr)(void));
void UART_TX_SetCallBack(void (*LocalFptr)(void));

void UART_SendNoBlock(u8 data);
u8 UART_ReceiveNoBlock(void);


#endif /* UART_INTERFACE_H_ */