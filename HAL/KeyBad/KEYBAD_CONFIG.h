/*
 * KEYBAD_CONFIG.h
 *
 * Created: 10/22/2023 10:30:52 AM
 *  Author: DELL
 */ 


#ifndef KEYBAD_CONFIG_H_
#define KEYBAD_CONFIG_H_





#define ROWS 4
#define COLS 4

#define LAST_OUTPUT PINC5
#define LAST_INPUT PIND7
#define  NO_KEY 'T'

#if KEYPAD_PRG

const u8 KeysArr[ROWS] [COLS]={   { '7','8','9','-'}
                                 ,{ '4','5','6','*'}
                                 ,{ '1','2','3','/'}
                                 ,{ 'C','0','=','+'}
} ;

#endif



#endif /* KEYBAD_CONFIG_H_ */