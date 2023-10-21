/*
 * UTILIS.h
 *
 * Created: 10/20/2023 11:04:08 AM
 *  Author: DELL
 */ 


#ifndef UTILIS_H_
#define UTILIS_H_

#define F_CPU 16000000
#include <util/delay.h>

//abdelbasit driver
#define READ_BIT(reg,bit)  ((reg>>bit)&1)   // macro like function // de lazem trga3 1 aw o bas
#define READ_BIT2(reg,bit)  (reg &(1<<bit))  // de momkin trga3 rakm 8er 1 w 0
#define SET_BIT(reg,bit) (reg=reg|(1<<bit))
#define CLR_BIT(reg,bit)  (reg=reg&(~(1<<bit)) )
#define TOG_BIT(reg,bit)  (reg=reg ^( 1<<bit))

#define delay(d)  _delay_ms(d)

// new driver

// #define SET_BIT(REG,BIT) REG|= (1<<BIT)
// #define CLEAR_BIT(REG,BIT) REG&= ~(1<<BIT)
// #define TOGGLE_BIT(REG,BIT) REG^= (1<<BIT)
// #define GET_BIT(REG,BIT) ((REG>>bit)&(1))
#define CONC_BYTE(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif /* UTILIS_H_ */