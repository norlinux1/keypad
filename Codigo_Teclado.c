/*
 * Codigo_Teclado.c
 *
 * Created: 02-12-2016 13:49:07
 *  Author: User
 */ 
#include <inttypes.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include "lcd_lib.h"
#include "user_interface.h"
#include "teclado.h"
#define F_CPU 8000000UL
#include <util/delay.h>
uint8_t BemVindo[] = "Bem Vindo!";



int main(void)
{	
	LCDinit();//init LCD bit, dual line, cursor right
	LCDclr();
	LCDGotoXY(3,0);
	LCDstring(BemVindo,10);
	uint16_t password;
    while(1)
    {
        password=InputNumber("Enter Password");

        //Match Password
        if(password==1234)
        {
	        LCDclr();
	        LCDstring("Access OK",9);
	        _delay_ms(200);
	        //Now wait for any key
	        while(GetKeyPressed()==255)
	        {
		        _delay_loop_2(10);
	        }
        }
    }
}