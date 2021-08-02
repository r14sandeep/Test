#include<reg51.h>
#include"delay.h"
#include"i2c.h"
#include"lcd.h"
#include"keypad1.h"
#include"types.h"
#include"rtc.h"
//u8 key;
u8 set_secs();
u8 set_mins();
u8 set_hours();
u8 i=0;

main()
{
u8 count=0;
time rtc;
u8 keyval;
rtc.hrs=0x00;
rtc.mins=0x00;
rtc.secs=0x00;
i2c_device_write(0xd0,0x02,rtc.hrs);
i2c_device_write(0xd0,0x01,rtc.mins);
i2c_device_write(0xd0,0x00,rtc.secs);

init_lcd();
//putc_lcd('A');
while(1){
while(colscan())
{
//	putc_lcd('2');
	read_rtc();
}
//	while(colscan());
	while(1)
	{
	loop:keyval=keyscan();
		while(!colscan());
		cmd_lcd(0x80);
		putc_lcd(keyval+48);
		if(keyval==10)
		{
//			putc_lcd('C');
			count++;
			if(count>=5)
			{
				count=0;
				goto loop;
			}
			
			//		count++;
			cmd_lcd(0x85);
			putc_lcd(keyval+48);
			cmd_lcd(0xc0);
			switch(count)
			{
				case 1:putc_lcd('A'); rtc.hrs=set_hours();  break;
				case 2:rtc.mins=set_mins();	break;
				case 3:rtc.secs=set_secs();	break;
				default: goto abc;
			}
			i2c_device_write(0xd0,0x02,rtc.hrs);
			i2c_device_write(0xd0,0x01,rtc.mins);
			i2c_device_write(0xd0,0x00,rtc.secs);

			abc: break;
		}
	}

}
			
}		


void read_rtc(void)
{

time rtc1;

cmd_lcd(0x80);
putc_lcd('a'+ i);
rtc1.hrs=i2c_device_read(0xd0,0x02);
rtc1.mins=i2c_device_read(0xd0,0x01);
rtc1.secs=i2c_device_read(0xd0,0x00);
cmd_lcd(0xc0);
putc_lcd((rtc1.hrs/16)+48);
putc_lcd((rtc1.hrs%16)+48);
putc_lcd('.');
//cmd_lcd(0xc3);
putc_lcd((rtc1.mins/16)+48);
putc_lcd((rtc1.mins%16)+48);
putc_lcd('.');
//cmd_lcd(0xc6);
putc_lcd((rtc1.hrs/16)+48);
putc_lcd((rtc1.hrs%16)+48);
putc_lcd('A' +i);
i++;
delay_ms(500);
}

u8 set_mins(void)
{
	u8 key,num=0;
	loop:cmd_lcd(0x80);
		puts_lcd("enter thr HRS");
		cmd_lcd(0xc0);
		puts_lcd("             ");
		while(colscan());
		key=keyscan();
		while(!colscan());
		putc_lcd(key);
		if(key>=3)
			goto loop;
//delay_ms(100);
		num=key*10;
		while(colscan());
		key=keyscan();
		while(!colscan());
		num+=key;

	if(num>=24)
		goto loop;
	
//	rtc.hrs=key;
//count=0;
	return num;
}


u8 set_hours(void)
{
	u8 key=0,num=0,key2=0;
	loop:cmd_lcd(0x80);
		puts_lcd("enter thr Mins");
		cmd_lcd(0xc0);
		puts_lcd("             ");
		while(colscan())
		{ 
			putc_lcd(key+48);
			putc_lcd(key2+48);
			key=keyscan();
			while(!colscan());
			putc_lcd(key);
			if(key>=6)
				goto loop;
			else
				break;
		}
//delay_ms(100);
		num=key*10;
loop1:	while(colscan())
		{
			cmd_lcd(0xc0);
			putc_lcd(key+48);
			putc_lcd(key2+48);
			key2=keyscan();
			while(!colscan());
			if(key>=10)
				goto loop1;
			else 
				break;
		}
			num+=key;

/*	if(num>=60)
		goto loop;
*/	
//	rtc.hrs=key;
//count=0;
	return num;
}

u8 set_secs(void)
{
	u8 key,num=0;
	loop:cmd_lcd(0x80);
		puts_lcd("enter thr Secs");
		cmd_lcd(0xc0);
		puts_lcd("             ");
		while(colscan());
		key=keyscan();
		while(!colscan());
		putc_lcd(key);
		if(key>=3)
			goto loop;
//delay_ms(100);
		num=key*10;
		while(colscan());
		key=keyscan();
		while(!colscan());
		num+=key;

	if(num>=60)
		goto loop;
	
//	rtc.hrs=key;
//count=0;
	return num;
}