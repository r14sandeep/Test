/** compiler directives **/
#include<string.h>

/** user defined header files **/
#include "i2c.h"

/** global variables accessing which are declared in other file **/
extern unsigned char rec_buff[25];

/** receiving data from eeprom to rec_buff[] **/
void eeprom_data_read(unsigned char val)
{
	//local vartiables declaration
	unsigned char i=0,ch1;

	memset(rec_buff,'\0',25);//clear the buffer
	if(val == 0)
		i = 0;
	else if(val == 1)
		i = 5;
	//receive eeprom memory till null character to rec_buff[]	
	while(1)
	{
		ch1 = device_read(0XA0,i);//starting location is 0
		if(ch1 == '\0')//checking for null character
			break;
		else
		{
			if(val == 0)
				rec_buff[i] = ch1;//saving received data into rec_buff[]
			if(val == 1)
				rec_buff[i-5] = ch1;//saving received data into rec_buff[]
			i++;
		}
	}	
	rec_buff[i] = '\0';
}


/** sending some data into eeprom from rec_buff[] **/
void eeprom_data_write(unsigned char *str,unsigned char val1)
{
	//local variables declaration
	unsigned char i=0;	
	if(val1 == 0)
		i = 0;
	else if(val1 == 1)
		i = 5;
	//sending the rec_buff[] value into eeprom memory till null character
	while(*str)
	{
		device_write(0XA0,i,*str++);
		i++;
		if(val1 == 0)
			if(i==4)
				break;
	}
	device_write(0XA0,i,'\0');
}


