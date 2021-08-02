/** compiler directive **/
#include<string.h>

/** user defined header files **/
#include "uart.h"
#include "function.h"
#include "i2c.h"
#include "eeprom.h"
#include "dml.h"
#include "rtc.h"
#include "delay.h"

/** global variables accessing which are declared in other file **/
extern unsigned char k,ch,mode,mode1,rec_buff[25];
extern bit e_flag,r_flag,reentry;
bit str_flag;

/** global variable declaration **/
unsigned char mode;


/** display menu on hyper terminal **/
void menu(void)
{
	uart_string("\r\n****** MENU ******\r\n");
	uart_string("1) FIXED STRING \r\n");
	uart_string("2) FIXED STRING WITH BLINKING\r\n");
	uart_string("3) STRING WITH SCROLLING\r\n");
	uart_string("4) TIME DISPLAY \r\n");
	uart_string("5) RTC DISPLAY WITH SCROLLING\r\n");
	uart_string("6) TEXT EDIT MODE \r\n");
	uart_string("7) TIME EDIT MODE \r\n");
	uart_string("8) EXIT \r\n");
}

/** menu selection & saving status in eeprom **/
void menu_selection()
{
	/** display string on hyper terminal **/
	uart_string("Waiting for i/p \r\n");

	while(1)
	{
		e_flag=1;
		ch = 0;
		while(ch == 0);

		if(ch == '1')
		{
			mode=1;	//for fixed string
			device_write(0xA0,0X30,mode);//saving mode status in eeprom
		}
		else if(ch == '2')
		{
			mode=2;	//for string blinking				
			device_write(0xA0,0X30,mode);//saving mode status in eeprom
		}
		else if(ch == '3')
		{
			mode=3;	//string with scrolling
			device_write(0xA0,0X30,mode);//saving mode status in eeprom
		}
		else if(ch == '4')
		{
			mode=4;		//display only time
			device_write(0xA0,0X30,mode);//saving mode status in eeprom
		}
		else if(ch == '5')
		{
			mode = 5;	//display rtv info with scrolling			
			device_write(0xA0,0X30,mode);//saving mode status in eeprom
		}
		else if(ch == '6')
		{
			string_edit();
			eeprom_data_write(rec_buff,str_flag);//saving mode status in eeprom
		}
		else if(ch == '7')	//time editing mode
		{
			serial_time_edit();
		}
		else if(ch == '8')	//exit from menu
			break;
		else
			uart_string("Wrong selection\r\n");//display string on hyper terminal
		break;
	}
}

/** change string **/
void string_edit(void)
{
	
	r_flag=0;//making flag 0 to identify the string termination
	e_flag=0;
	
	//display string on hyper terminal 
	uart_string("\r\n1.FIXED TEXT (only 4 characters + $)\r\n");
	uart_string("2.TEXT WITH SCROLLING (only 20 characters + $)\r\n");
	uart_string("Waiting for i/p \r\n");
	ch = 0;
	while((ch != '1') & (ch != '2'));
	if(ch == '1')
		str_flag = 0;
	else if(ch == '2')
		str_flag = 1;
	k=0;
	memset(rec_buff,'\0',25);	//clear the buffer
	uart_string("\r\nEnter new string (terminate with $):\r\n");
	while(r_flag==0);//waiting for string entry termination
}

/** time editing through hyper terminal **/
void serial_time_edit()
{
	unsigned char sec,min,hr,day,date,mon,year;
	reentry = 0;
	e_flag = 0;
/** display instructions for the user **/
	uart_string("\r\nenter for editing time&date as per the formate given below\r\n");
	uart_string("    SS:MM:HH DAY DD/MM/YY$\r\n");
	uart_string("ex: 22:10:09 01 27/02/15$\r\n");
	uart_string("Note: DAY: 01-SUN,02-MON,03-TUE,04-WED,05-THU,06-FRI,07-SAT\r\n");
	uart_string("Entry limits is as follows\r\n");
	uart_string("(sec - 00-59) (min - 00 - 59) (hour - 00 - 23)\r\n");
	uart_string("(day - 01-07) (date - 01 - 31) (month - 01 - 12) (year - 00 - 99)\r\n");
	k=0; //for accessing the data from 0th element to the buffer 
	memset(rec_buff,'\0',25);
	r_flag = 0;		
	while(r_flag==0);//waiting for the string termination
	uart_string("\r\n");
	
	ch = rec_buff[0]-48;
	ch = (ch*10) + (rec_buff[1]-48);
	if((ch >=0) && (ch <=59))//sec value limit checking
	{
		sec = (((ch/10) * 0x10) + (ch%10));//convert to bcd 
		device_write(0xd0,0x00,sec);//write to rtc
	}


	//collecting the min info
	ch = rec_buff[3]-48;
	ch = (ch*10) + (rec_buff[4]-48);
	if((ch >=0) && (ch <=59))//min value limit checking
	{
		min = (((ch/10) * 0x10) + (ch%10));//convert to bcd 
		device_write(0xd0,0x01,min);//write to rtc
	}

	//collecting the hour info
	ch = rec_buff[6]-48;
	ch = (ch*10) + (rec_buff[7]-48);
	if((ch >=0) && (ch <=23))//hour value limit checking
	{
		hr = (((ch/10) * 0x10) + (ch%10));//convert to bcd 
		device_write(0xd0,0x02,hr);//write to rtc
	}

	//collecting the day info
	ch = rec_buff[9]-48;
	ch = (ch*10) + (rec_buff[10]-48);
	if((ch >=1) && (ch <=7))//day value limit checking
	{
		day = (((ch/10) * 0x10) + (ch%10));//convert to bcd 
		device_write(0xd0,0x03,day);//write to rtc
	}

	//collecting the date info
	ch = rec_buff[12]-48;
	ch = (ch*10) + (rec_buff[13]-48);
	if((ch >=1) && (ch <=31))//date value limit checking
	{
		date = (((ch/10) * 0x10) + (ch%10));//convert to bcd 
		device_write(0xd0,0x04,date);//write to rtc
	}

	//collecting the mon info
	ch = rec_buff[15]-48;
	ch = (ch*10) + (rec_buff[16]-48);
	if((ch >=1) && (ch <=12))//mon value limit checking
	{
		mon = (((ch/10) * 0x10) + (ch%10));//convert to bcd  
		device_write(0xd0,0x05,mon);//write to rtc
	}

	//collecting the year info
	ch = rec_buff[18]-48;
	ch = (ch*10) + (rec_buff[19]-48);
	if((ch >=0) && (ch <=99))//year value limit checking	
	{
		year = (((ch/10) * 0x10) + (ch%10));//convert to bcd 
		device_write(0xd0,0x06,year);//write to rtc
	}
}


/** overall system process **/
void process()
{

//display_string('N',50);
//while(1)
		//display_string("ABCD",50);
	uart_init();	//initialise the uart
	//device_write(0xd0,0x00,0x00);	//initialise the seconds memory location with 0
//device_write(0xa0,0x30,0x01);	

	while(1)
	{
		e_flag=0;
		//display string on hyper terminal	
		uart_string("\r\n*** RUN MODE ***\r\n");
		uart_string("*** PRESS ! TO EXIT RUN & ENTER EDIT MODE ***\r\n");
	
		mode = device_read(0xA0,0x30);	//read mode status from eeprom

		if((mode == 1) | (mode == 2))
			eeprom_data_read(0);	//reading string from eeprom 	
		else if(mode == 3)
			eeprom_data_read(1);	//reading string from eeprom 


		while(1)
		{	
			if(mode == 1)			
				display_string(rec_buff,50);//display string on dot matrix
			else if(mode == 2)
			{
				display_string(rec_buff,50);//display string on dot matrix	
				display_string("    ",50);//display string on dot matrix					
			}
			else if(mode == 3)	
			{
				display_string(rec_buff,50);//display string on dot matrix		
				rotate(rec_buff);	//calling rotate string
			}
			else if(mode == 4)	//
			{
				disp_onlytime();//display only time	
			}
			else if(mode == 5)
			{
				scroll_time_date_day();//display rtc with scrolling	
			}
			if(reentry)	//checking edit mode selection
			{
				reentry = 0;//making 0 for next loop identification
				break;
			}
		}
		menu();		//calling menu function	
		menu_selection();	//calling menu selection
	}
}
