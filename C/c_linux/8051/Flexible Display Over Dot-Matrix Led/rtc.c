/** compiler directives **/
#include "i2c.h"
#include "dml.h"

/** global variables declaration **/
unsigned char time[20]=" ";
code unsigned char *week[] = {" ","SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};

/** global variables accessing which are declared in other file **/
extern bit reentry;

/** accessing current time from rtc into array  **/
void disp_time()
{
	//local variables declaration	
	unsigned char data1,i=0;

	time[i++] = ' ';//adding spaces for proper scrolling visibility
	time[i++] = ' ';
	time[i++] = ' ';

	time[i++] = 'T';
	time[i++] = 'I';
	time[i++] = 'M';
	time[i++] = 'E';
	time[i++] = ' ';
	//accessing the BCD information from RTC
	data1=((device_read(0xD0,0x02)/0x10) + 0x30);//reading hours
	time[i++] = data1;//saving 10th position
	
	data1=((device_read(0xD0,0x02) % 0x10) + 0x30);	//reading hours
	time[i++] = data1;//saving 1's position
	
	time[i++] = ':';//separation between hour and min
	
	data1=((device_read(0xD0,0x01)/0x10) + 0x30);	   //reading minutes
	time[i++] = data1;//saving 10th position
	
	data1=((device_read(0xD0,0x01) % 0x10) + 0x30);   //reading minutes
	time[i++] = data1;//saving 1's position
	
	time[i++] = ':';//separation between min and sec
	
	data1=((device_read(0xD0,0x00)/0x10) + 0x30);	   //reading seconds
	time[i++] = data1;//saving 10th position

	data1=((device_read(0xD0,0x00) % 0x10) + 0x30);   //reading seconds
	time[i++] = data1;//saving 1's position

	time[i++] = ' ';//adding spaces for proper scrolling visibility
	time[i++] = ' ';
	time[i++] = ' ';

	time[i] = '\0';


}

/** accessing current date info from rtc into array  **/
void disp_date()
{
	//local variables declaration	
	unsigned char data1,i=0;

	time[i++] = ' ';//adding spaces for proper scrolling visibility
	time[i++] = ' ';
	time[i++] = ' ';
	time[i++] = 'D';
	time[i++] = 'A';
	time[i++] = 'T';
	time[i++] = 'E';
	time[i++] = ' ';
	//accessing the BCD information from RTC
	data1=((device_read(0xD0,0x04)/0x10) + 0x30);	   //reading date
	time[i++] = data1;//saving 10th position
	
	data1=((device_read(0xD0,0x04) % 0x10) + 0x30);   //reading date
	time[i++] = data1;//saving 1's position
	
	time[i++] = '/';//separation between date and month
	
	data1=((device_read(0xD0,0x05)/0x10) + 0x30);	   //reading month
	time[i++] = data1;//saving 10th position
	
	data1=((device_read(0xD0,0x05) % 0x10) + 0x30);   //reading month
	time[i++] = data1;//saving 1's position
	
	time[i++] = '/';//separation between month and year

	data1=((device_read(0xD0,0x06)/0x10) + 0x30);	   //reading year
	time[i++] = data1;//saving 10th position

	data1=((device_read(0xD0,0x06) % 0x10) + 0x30);   //reading year
	time[i++] = data1;//saving 1's position

	time[i++] = ' ';//adding spaces for proper scrolling visibility
	time[i++] = ' ';
	time[i++] = ' ';

	time[i] = '\0';
}

/** accessing current day from rtc into array  **/
void disp_day()
{
	//local variables declaration	
	unsigned char *s,i=0; 

	time[i++] = ' ';//adding spaces for proper scrolling visibility
	time[i++] = ' ';
	time[i++] = ' ';
	time[i++] = 'D';
	time[i++] = 'A';
	time[i++] = 'Y';
	time[i++] = ' ';
	//accessing the BCD information from RTC
	s = week[device_read(0xD0,0x03)];//reading day 

	while(*s)
	{
		time[i++] = *s++;//saving day info string into array
	}
	time[i++] = ' ';//adding spaces for proper scrolling visibility	
	time[i++] = ' ';
	time[i++] = ' ';
	time[i] = '\0';

}

void scroll_time_date_day()
{
	//local variables declaration	
	unsigned char count;

	while(1)
	{
		if(count==0)	//for time info in to time array 
			disp_time();
		else if(count == 15)
			disp_date();	//for date info in to time array 
		else if(count == 30)//for day info in to time array 	
			disp_day();
	
		display_string(time,20);//display time array info on dot matrix
		rotate_time();//shifting the array values position by one left
		count++;
		if(count>43)	//checking for one loop rotation
		{
			count=0;
			break;
		}
		else if(reentry)//checking for edit mode
			break;
	}
}

/** display min sec on dot matrix **/
void disp_onlytime()
{
	//local variables declaration	
	unsigned char data1,i=0;

	//accessing the BCD information from RTC
	data1=((device_read(0xD0,0x01)/0x10) + 0x30);//reading hours
	time[i++] = data1;//saving 10th position
	
	data1=((device_read(0xD0,0x01) % 0x10) + 0x30);//reading hours
	time[i++] = data1;//saving 1's position
	

	data1=((device_read(0xD0,0x00)/0x10) + 0x30);//reading minutes
	time[i++] = data1;//saving 10th position
	
	data1=((device_read(0xD0,0x00) % 0x10) + 0x30);//reading minutes
	time[i++] = data1;//saving 1's position
	
	time[i] = '\0';
	
	display_string(time,20);//display time on dot matrix
}

