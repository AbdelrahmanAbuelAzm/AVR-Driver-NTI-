

#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_


/*
* synch function 
* blocking
*/

void UART_SendString(u8*str);

void UART_ReceiveString(u8*str);
void UART_SendNumber(u32 num);

u8 endian_check(void);

u32 endian_convert_u32(u32 num);


void UART_SendStringCheckSum(u8*str);

u8 UART_ReceiveStringCheckSum(u8*str);

void UART_SendStringAsynch(u8*str);



#endif /* UART_SERVICES_H_ */