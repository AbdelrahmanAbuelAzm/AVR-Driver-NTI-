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
#include "ADC_INTERFACE.h"
#include "TIMER_INTERFAC.h"
#include "TIMER_SERVICE.h"
#include "UART_INTERFACE.h"
#include "UART_Services.h"
#include "SPI.h"

volatile u8 ADC_Flag=0,Uart_TX_flag=0,Uart_RX_flag=0;



void Servo_SetAngle(u8 angle)
{
	//cross multiplication (angle/180 =  OCR/1000)    1000 is the range betwen 1ms and 2ms
	if(angle>180)
	{
		angle=180;
	
	}
	OCR1B=((angle*(u32)1000)/(u32)180)+999;   //+999 ashan bbtdy mn 1ms 
}




void trans_func(void)
{
	
	Uart_TX_flag=1;
}

void Reciv_func(void)
{
	
	Uart_RX_flag=1;
}

int main(void)
{
	
	
	u8 key='T';
	DIO_Init();
	LCD_Init();
	//UART_Init();
	//KEKPAD_Init();
	SPI_Init();
	
	//ADC_Init(VREF_AVCC,ADC_SCALER_64);
	
	//ADC_Auto_Triggered_Init(ADC_EXTERNAL_INTERRUPT0,CH_0);
	
	//TIMER0_Init(tim,TIMER0_SCALER_64);
	//PWM_TIMER0_Init();
	
	//TIMER0_OV_InterruptEnable();
	
	//EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	//EXI_Enable(EX_INT0);
	
	//Timer1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8);
	//OCR1A=19999;
	//Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	
	
	UART_TX_InterruptEnable();
	UART_RX_InterruptEnable();
	GLOBAL_ENABLE();
	
	LCD_GoTo(0,0);
	LCD_WriteString("SPI TRANSMITTER");
	
	//OCR1B=999;
   // u16 num=0,disp_num=0,ADC_Num=0,Duty=0;
	//Timer1_ICU_SetCallBack("Servo");
	//TCNT0=6;
	//OCR0=150;
	
// 	u8 angle=0;
// 	u16 adc=0;
// 	u8 uart=0;
	
	//UART_TX_SetCallBack(trans_func);
	//UART_RX_SetCallBack(Reciv_func);
	
	
	//UART_SendNoBlock('9');
	//uart=UART_ReceiveNoBlock();
	u8 SPI_data=0;
    while (1) 
    {
		
		SPI_data=0;
		SPI_data= SPI_SendReceive('T');
		if(SPI_data==0)
		{
			DIO_TogglePin(PINA4); //green
		}
		if(SPI_data=='R')
		{
			DIO_TogglePin(PINA5); //blue
		}
		if(SPI_data!='R'&& SPI_data!=0)
		{
			DIO_TogglePin(PINA6);  //yellow
		}
		if(SPI_data=='T')
		{
			DIO_TogglePin(PINB7); //blue
		}
		
		delay(20);
		SPI_data=0;
		
		
/*
		
		if(Uart_TX_flag==1)
		{
			LCD_GoTo(1,0);
			LCD_WriteString("tx done");
			Uart_TX_flag=0;
		}
		if(Uart_RX_flag==1)
		{
			LCD_GoTo(2,0);
			LCD_WriteChar(uart+'0');
			Uart_RX_flag=0;
		}
		
*/
		
				
	}
				
 }




/*
ISR(TIMER0_OC_vect)
{
	DIO_TogglePin(PINB7);
	
	
}
*/
ISR(ADC_vect)
{
	
	ADC_Flag=1;
	
}

ISR(INT0_vect)
{
	/*EXT_INT_flag++;
	DIO_TogglePin(PINB6);
	if(EXT_INT_flag==2)
	{
		EXT_INT_flag=0;
	}*/
	
	
	
}
