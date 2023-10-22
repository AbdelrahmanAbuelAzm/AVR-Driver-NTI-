/*
 * LCD_INTERFACE.h
 *
 * Created: 10/21/2023 10:19:50 AM
 *  Author: DELL
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



#define MAX_S32  2147483647
#define MIN_S32 -2147483648



void LCD_Init(void);




void LCD_Clear(void);
//void LCD_MOVE

void LCD_GoTo(u8 line,u8 cell);  //line from 0 or 1 cell from 0:15


void LCD_WriteString(c8*str);
void LCD_WriteNumber(s32 num);//task
void LCD_WriteNumber2(s32 num);
void LCD_WriteNumber3(s32 num);
void LCD_WriteBinary(u8 num);// task
void LCD_WriteHex(u8 num); // task
void LCD_WriteChar(u8 ch);
void WriteData(u8 data);
void LCD_Write_4D(u16 num);

void LCD_CustomChar(u8 address,u8* pattern);
void LCD_WriteStringGoTo(u8 line,u8 cell,c8 * str);
void LCD_ClearPosition(u8 line ,u8 cell ,u8 NoCells);
void New_Shape_Init(void);
void LCD_NameDispRotary(u8* Name,u8 size);



#endif /* LCD_INTERFACE_H_ */