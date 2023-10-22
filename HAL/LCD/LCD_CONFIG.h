/*
 * LCD_CONFIG.h
 *
 * Created: 10/21/2023 10:20:18 AM
 *  Author: DELL
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_



#define _8_BIT 1
#define _4_BIT 0
// LCD mode
#define LCD_MODE  _4_BIT

#define RS PINA3
#define EN PINA2
// 4 bit mode only

#define  D4 PINB0
#define  D5 PINB1  // check in Proteus
#define  D6 PINB2
#define  D7 PINB4

// 8 bit mode only
#define LCDPORT PA






#endif /* LCD_CONFIG_H_ */