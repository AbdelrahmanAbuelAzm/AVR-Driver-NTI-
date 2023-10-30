
#include "STD_TYPES.h"
#include "MEM_MAP.h"
#include "UTILIS.h"
#include "SPI.h"


void SPI_Init(void )
{
	// SLAVE OR MASTER
	#if SPI_MODE
   SET_BIT(SPCR,MSTR);
   //clock 2mhz
  switch(Clock)
  {
	  case 4:
	   CLR_BIT(SPCR,SPR0);
	   CLR_BIT(SPCR,SPR1);
	   break;
	   
	   case 16:
	   SET_BIT(SPCR,SPR0);
	   CLR_BIT(SPCR,SPR1);
	   break;
	   
	   case 64:
	   CLR_BIT(SPCR,SPR0);
	   SET_BIT(SPCR,SPR1);
	   break;
	   
	   case 128:
	   SET_BIT(SPCR,SPR0);
	   SET_BIT(SPCR,SPR1);
	   break;
	   
	   default:
	   CLR_BIT(SPCR,SPR0);
	   CLR_BIT(SPCR,SPR1);
	   break;
	   
  }
  
   #else
   CLR_BIT(SPCR,MSTR);
   #endif
	
	
	//enable
	
	SET_BIT(SPCR,SPE);
}


u8 SPI_SendReceive(u8 data)
{
	// write puffer
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	//READ PUFFER
	return SPDR;
	
}