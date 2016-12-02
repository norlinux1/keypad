#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

#include "lcd_lib.h"
#include "teclado.h"
#include "user_interface.h"

uint16_t InputNumber(char *msg)
{
	uint8_t keyCode,x,pos;
	uint8_t prev_key=255;
	
		
	while(1)
	{
		x=0;
		pos=0;
		LCDclr();
		LCDStringXY(msg,0,0);
		LCDGotoXY(6,1);
	
		uint8_t key[]="****";
 
		
		uint8_t system_reset=0;

    	while(!system_reset)
    	{
			
			keyCode=GetKeyPressed(); //Get the keycode of pressed key
			
			if(keyCode==prev_key)
			continue;
			else if(keyCode==255)
			{
				prev_key=255;
				continue;
			}
			else
			{
				prev_key=keyCode;
			}
			
			if(pos==4)
			{
				//Wait for enter key or reset key
				while(1)
				{
					keyCode=GetKeyPressed();
					if(keyCode==4)
					{
						//Enter key
						break;
					}
				
				}
				
				//Convert pass to a single integer
				return(((1000*key[0])+(100*key[1])+(10*key[2])+key[3]));		//save the password in 16 bit integer
				LCDclr();
			}

			switch (keyCode) 									//generating key character to display on LCD
		 	{
				case (11): 
					LCDStringXY("1",pos+6,1);
					key[x]=1;
					++x;
		 			pos++;
					break;
			
			
				case (10): 
					LCDStringXY("2",pos+6,1);
					key[x]=2;
		     		++x;
					pos++;
				break;
			
				case (9): 
					LCDStringXY("3",pos+6,1);
					key[x]=3;
		           	++x;
				 	pos++;
				break;
			
				case (7): 
				LCDStringXY("4",pos+6,1);
		           	key[x]=4;
		           	++x;
				 	pos++;
				break;
			
				case (6): 
					LCDStringXY("5",pos+6,1);
		           	key[x]=5;
		           	++x;
				 	pos++;
				break;
			
				case (5): 
					LCDStringXY("6",pos+6,1);
		           	key[x]=6;
		           	++x;
					pos++;
				break;
			
				case (3): 
					LCDStringXY("7",pos+6,1);
		          	key[x]=7;
		           	++x;
					pos++;
				break;

				case (2): 
					LCDStringXY("8",pos+6,1);
		           	key[x]=8;
		           	++x;
				 	pos++;
				break;
			
				case (1): 
					LCDStringXY("9",pos+6,1);
		           	key[x]=9;
		           	++x;
				 	pos++;
				break;

				case (14): 
					LCDStringXY("0",pos+6,1);
		           	key[x]=0;
		           	++x;
				 	pos++;
				break;
				case (8): 
					system_reset=1;
					
					break;
					
				default: ;
			}
			_delay_loop_2(1000);
		}	
	}		
}
