#include <avr/io.h>

#include "spi.h"

void SPI_send(uint8_t cData) 
{
	SPDR = cData; 
	while(!(SPSR & (1<<SPIF)));
}

void SPI_init() 
{
    // set mosi/sck out
	DDRB |= (1<<DDB5)|(1<<DDB3)|(1<<DDB2);
	
	//activate spi
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

