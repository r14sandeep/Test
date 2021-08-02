#include<reg51.h>
#include"delay.h"
#include"i2c.h"
#include"lcd.h"
#include"keypad.h"
#include"types.h"
#include"rtc.h"
u8 count=0,key;
time rtc;
main()
{
	u8 keyval;
	init_lcd();
	while(1)
	{
		read_rtc();
		while(!colscan());
			while(1)
			{
				loop:keyval=keyscan();
				{
					while(colscan());
					{
						if(keyval==10)
						{
							if(count<=4)
							{
								count=0;
								goto loop;
							}
								count++;
									switch(count)
									{
									case 1:set_hours();
									case 2:set_mins();
									case 3:set_secs();
									}
									i2c_device_write(0xd0,0x02,rtc.hrs);
									i2c_device_write(0xd0,0x01,rtc.mins);
									i2c_device_write(0xd0,0x00,rtc.secs);
					    }
					}
				}
			}
		}
}

void read_rtc(void)
{
rtc.hrs=i2c_device_read(0xd0,0x02);
rtc.mins=i2c_device_read(0xd0,0x01);
rtc.secs=i2c_device_read(0xd0,0x00);
cmd_lcd(0xc0);
putc_lcd((rtc.hrs/16)+48);
putc_lcd((rtc.hrs%16)+48);
putc_lcd('.');
cmd_lcd(0xc3);
putc_lcd((rtc.mins/16)+48);
putc_lcd((rtc.mins%16)+48);
putc_lcd('.');
cmd_lcd(0xc6);
putc_lcd((rtc.hrs/16)+48);
putc_lcd((rtc.hrs/16)+48);
}
void set_hours()
{
loop:cmd_lcd(0x01);
puts_lcd("enter thr HRS");
cmd_lcd(0xc0);
key=keyscan();
if(key>=3)
goto loop;
delay_ms(100);
key=(key*10)+keyscan();
if(key>23)
goto loop;
rtc.hrs=key;
count=0;
}
void set_mins()
{
loop:cmd_lcd(0x01);
puts_lcd("enter thr MINS");
cmd_lcd(0xc0);
key=keyscan();
if(key>=5)
goto loop;
delay_ms(100);
key=(key*10)+keyscan();
if(key>59)
goto loop;
rtc.mins=key;
count=0;
}
void set_secs()
{
loop:cmd_lcd(0x01);
puts_lcd("enter thr SECS");
cmd_lcd(0xc0);
key=keyscan();
if(key>=5)
goto loop;
delay_ms(100);
key=(key*10)+keyscan();
if(key>59)
goto loop;
rtc.secs=key;
count=0;
}
