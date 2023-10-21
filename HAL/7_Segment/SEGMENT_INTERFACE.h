/*
 * _7SEGMENT_INTERFACE.h
 *
 * Created: 10/21/2023 12:41:52 AM
 *  Author: DELL
 */ 


#ifndef SEGMENT_INTERFACE_H_
#define SEGMENT_INTERFACE_H_

void Segment_Display(u16 num);


typedef union{

	unsigned char Seg;
	struct reg {

		unsigned char Val:4;
		unsigned char :4;
		

	}BITS_t;

}BYTE_t;

#endif /* SEGMENT_INTERFACE_H_ */