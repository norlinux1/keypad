/*
 * teclado.c
 *
 * Created: 02-12-2016 13:52:29
 *  Author: User
 */ 
#include <avr/io.h>
#include <inttypes.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "teclado.h"
#define KEYPAD_PORT PORTB
#define KEYPAD_DDR   DDRB
#define KEYPAD_PIN   PINB

uint8_t GetKeyPressed()
{
	
	KEYPAD_PORT|= 0X0F;
	
	for(uint8_t i=0;i<4;i++)
	{
		KEYPAD_DDR&=~(0XFF);
		KEYPAD_DDR|=(0X80>>i);
		_delay_us(5);  		  	 		  //delay for port o/p settling
		for(uint8_t j=0;j<4;j++)
		{
			if(!(KEYPAD_PIN & (0X08>>j)))
			{
				return (j*4+i);
			}
		}
	}
	return 255; //Nenhum botão foi pressionado
}

