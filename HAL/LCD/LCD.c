/*
 * LCD.c
 *
 * Created: 10/21/2023 10:19:28 AM
 *  Author: DELL
 */ 

#include "STD_TYPES.h"
#include "UTILIS.h"
#include "MEM_MAP.h"
#include "LCD_CONFIG.h"
#include "LCD_INTERFACE.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"

// for 8 or 4 bit mode

#if LCD_MODE ==  _8_BIT


static void WriteInst(u8 inst)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCDPORT,inst);// [ 8 bit or 16 bit ]0x38 from data sheet configuration (function set )
	DIO_WritePin(EN,HIGH);
	delay(1);
	DIO_WritePin(EN,LOW);
	delay(1);
}
void LCD_Init(void)
{
	delay(50);
	
	WriteInst(0x38);
	WriteInst(0x0c);//0e for blank or  0f for bold cursor or 0b  check in the second inst  (DIsplay on off)
	WriteInst(0x01);  //clears screen
	delay(1); //from data sheet
	WriteInst(0x06); // entry mood
	
	
}
void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCDPORT,data);// [ 8 bit or 16 bit ]0x38 from data sheet configuration (function set )
	DIO_WritePin(EN,HIGH);
	delay(1);
	DIO_WritePin(EN,LOW);
	delay(1);
}

#else


static void WriteInst(u8 inst)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(inst,7));
	DIO_WritePin(D6,READ_BIT(inst,6));
	DIO_WritePin(D5,READ_BIT(inst,5));
	DIO_WritePin(D4,READ_BIT(inst,4));
	
	
	DIO_WritePin(EN,HIGH);
	delay(1);
	DIO_WritePin(EN,LOW);
	delay(1);
	
	DIO_WritePin(D7,READ_BIT(inst,3));
	DIO_WritePin(D6,READ_BIT(inst,2));
	DIO_WritePin(D5,READ_BIT(inst,1));
	DIO_WritePin(D4,READ_BIT(inst,0));
	
	DIO_WritePin(EN,HIGH);
	delay(1);
	DIO_WritePin(EN,LOW);
	delay(1);
}
void LCD_Init(void)
{
	delay(50);
	
	
	WriteInst(0x02);
	WriteInst(0x28);
	
	WriteInst(0x0c);//0e for blank or  0f for bold cursor or 0c to off cursor  check in the second inst  (DIsplay on off)
	WriteInst(0x01);  //clears screen
	delay(1); //from data sheet
	WriteInst(0x06); // entry mood
	
	
}
void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	
	
	DIO_WritePin(EN,HIGH);
	delay(1);
	DIO_WritePin(EN,LOW);
	delay(1);
	
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	
	DIO_WritePin(EN,HIGH);
	delay(1);
	DIO_WritePin(EN,LOW);
	delay(1);
}

#endif






void LCD_GoTo(u8 line,u8 cell)
{
	if(line==0)
	{
		WriteInst(0x80+cell);
	}
	else if(line ==1)
	{
		WriteInst(0xc0+cell);// 80 for first line +40 for second line + cell no
		
	}
	else if(line ==2)
	{
		WriteInst(0x94+cell);// 80 for first line +40 for second line + cell no
		
	}
	else if(line ==3)
	{
		WriteInst(0xd4+cell);// 80 for first line +40 for second line + cell no
		
	}
	
	
}
void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
}
void LCD_WriteString(c8*str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}
void LCD_WriteNumber(s32 num) //125
{
	c8 str[20];
	u8 i=0;
	s8 j;
	//LCD_Clear();
	if (num==0)
	{
		LCD_Clear();
		LCD_WriteChar('0');
		return ;
	}
	if (num<0)
	{
		LCD_WriteChar('-');
		num=num*(-1);
	}
	
	while(num)
	{
		str[i]=num%10 +'0';
		i++;
		num=num/10;
	}
	for (j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
	
}


void LCD_WriteNumber2(s32 num)
{
	u8 flag=0;
	if(num==0)
	{
		LCD_Clear();
		LCD_WriteChar('0');
	}
	else if(num>MIN_S32 && num<MAX_S32 )
	{
		if(num<0)
		{
			num=num*-1;
			flag=1;
		}
		s32 x=num;
		u8 NUM_ARR[12]={0},i;
		u8 j=0;
		for(i=0;  (i<12) && (x!=0);i++)
		{
			NUM_ARR[i]=x%10 +'0';
			x=x/10;
			j++;
		}
		if(flag==1)
		{
			NUM_ARR[i]='-';
			j++;
		}
		
		for(j;j>0;j--)
		{
			LCD_WriteChar(NUM_ARR[j-1]);
		}
	}
	else
	{
		LCD_Clear();
		LCD_WriteString((c8*)"OVER FLOW");
	}
	
}

void LCD_WriteHex(u8 num)
{
	u8 HN=num>>4;
	u8 LN=num & 0x0f;
	if(HN<10)
	{
		LCD_WriteChar(HN+'0');
	}
	else
	{
		LCD_WriteChar(HN-10+'A');
	}
	if(LN<10)
	{
		LCD_WriteChar(LN+'0');
	}
	else
	{
		LCD_WriteChar(LN-10+'A');
	}
}
void LCD_Clear(void)
{
	WriteInst(0x01);
	delay(1);
}
void LCD_Write_4D(u16 num)
{
	LCD_WriteChar( ((num%10000)/1000 )+'0' );
	LCD_WriteChar( ((num%1000)/100 )+'0' );
	LCD_WriteChar( ((num%100)/10 )+'0' );
	LCD_WriteChar( ((num%10)/1 )+'0' );
}
void LCD_WriteBinary(u8 num)
{
	u8 i;
	for(i=8;i>0;i--)
	{
		//LCD_WriteChar(READ_BIT(num,(i-1))?'1':'0');
		LCD_WriteChar(READ_BIT(num,(i-1))+ '0');
	}
}
void LCD_WriteStringGoTo(u8 line,u8 cell,c8 * str)
{
	LCD_GoTo(line,cell);
	LCD_WriteString(str);
}
void LCD_ClearPosition(u8 line ,u8 cell ,u8 NoCells)
{
	LCD_GoTo(line,cell);
	for(u8 i=0;i<NoCells;i++)
	{
		LCD_WriteChar(' ');
	}
}


void New_Shape_Init(void)
{
	unsigned char new_shape[] = {
		0x04,
		0x0A,
		0x04,
		0x04,
		0x0E,
		0x15,
		0x04,
		0x0A
	};

	// Define the starting address of the new character in CG Ram
	unsigned char new_char_addr = 0x01; // assuming CG Ram starts at address 0x00

	// Load the new shape into CG Ram
	for (int i = 0; i < 8; i++) {
		WriteInst(0x47+ new_char_addr + i); // set CG Ram address to new_char_addr + i
		WriteData(new_shape[i]); // load the bit pattern into CG Ram
	}
}
void LCD_CustomChar(u8 address,u8* pattern)
{
	
	WriteInst(0x40+address*8);
	for(u8 i =0;i<8;i++)
	{
		// set CG Ram address to new_char_addr + i
		WriteData(pattern[i]);
	}
	WriteInst(0x80);
}
void LCD_NameDispRotary(u8* Name,u8 size)
{
	u8 i,j;
	
	for(i=0;i<=(15+size);i++)
	{
		for(j=0;j<=i;j++)
		{
			
			if(i>=0+j && i<=15+j)
			{
				LCD_GoTo(0,i-j);
				LCD_WriteChar( (size-2-j)<0 ? (' ') : (Name[(size-2-j)])  );
			}
			
		}
		delay(150);
	}
	
	for(i=0;i<=(15+size);i++)
	{
		for(j=0;j<=i;j++)
		{
			
			if(i>=0+j && i<=15+j)
			{
				LCD_GoTo(1,i-j);
				LCD_WriteChar( (size-2-j)<0 ? (' ') : (Name[(size-2-j)])  );
			}
			
		}
		delay(150);
	}
	
}

void LCD_WriteNumber3(s32 num) //125
{
	u8 str[20];
	u8 i=0;
	s8 j;
	if (num==0)
	{
		LCD_WriteChar('0');
		return ;
	}
	if (num<0)
	{
		LCD_WriteChar('-');
		num=num*(-1);
	}
	
	while(num)
	{
		str[i]=num%10 +'0';
		i++;
		num=num/10;
	}
	for (j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	//LCD_WriteString(str);
	
}

