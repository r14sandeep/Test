#include<reg51.h>
#include"i2c.h"
#include"keypad.h"
#include"delay.h"
#include"lcd.h"

code u8 cgram_lut[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

typedef struct ds1307
{
	u8 secs,mins,hrs;
}rtc;

void update_clock(u8 hrs,u8 mins,u8 secs)
{     
	i2c_device_write(0xd0,0x02,hrs);
	i2c_device_write(0xd0,0x01,mins);
	i2c_device_write(0xd0,0x00,secs);
}

u8 make_bcd(u8 p,u8 q)
{
	u8 temp;
	temp=(p*16)+q;
	return temp;
}

void edit_clock(rtc time)
{
	u8 a[6];
	s8 i=0;
	u8 temp;
	cmd_lcd(0x80);
	puts_lcd("set clock:       ");
	a[0]=time.hrs/16;
	a[1]=time.hrs%16;
	a[2]=time.mins/16;
	a[3]=time.mins%16;
	a[4]=time.secs/16;
	a[5]=time.secs%16;
	while(1)
	{
		init_rows();
		while(colscan())
		{
			cmd_lcd(0xc0);
			putc_lcd(a[0]+'0');
			putc_lcd(a[1]+'0');
			putc_lcd(':');
			putc_lcd(a[2]+'0');
			putc_lcd(a[3]+'0');
			putc_lcd(':');
			putc_lcd(a[4]+'0');
			putc_lcd(a[5]+'0');
			delay_ms(100);
			if(i==0 || i==1)
				cmd_lcd(0xc0+i);
			else if(i==2 || i==3)
				cmd_lcd(0xc0+i+1);
			else if(i==4 || i==5)
				cmd_lcd(0xc0+i+2);
			putc_lcd(0);
			delay_ms(100);
		}//while colscan
		
		init_rows();
		if(i==0)
		{
			do{
				temp=keyscan();
				while(!colscan());
				if(temp==11 || temp==12 || temp==10 ||temp==17) goto S1;
			}while(temp>=3);
		}
		else if(i==1)
		{
			if(a[0]==2)
			{	
				do{
					temp=keyscan();
					while(!colscan());
					if(temp==11 || temp==12 || temp==10 ||temp==17) goto S1;
				}while(temp>=4);
			}//a[0]==2
			else
			{
				do{
					temp=keyscan();
					while(!colscan());
					if(temp==11 || temp==12 || temp==10 ||temp==17) goto S1;
				}while(temp>=10);
			}
		}
		else if(i==2 || i==4)
		{
			do{
				temp=keyscan();
				while(!colscan());
				if(temp==11 || temp==12 || temp==10 ||temp==17) goto S1;
			}while(temp>=6);
		}
		else
		{
			do{
				temp=keyscan();
				while(!colscan());
				if(temp==11 || temp==12 || temp==10 ||temp==17) goto S1;
			}while(temp>=10);
		}

		a[i]=temp;

	S1:	if(temp==11)
		{
			if(i==5)
				i=-1;
			i++;
		}
		else if(temp==12)
		{
			if(i==0)
				i=6;
			i--;
		}
		else if(temp==10)
		{
			update_clock(make_bcd(a[0],a[1]),make_bcd(a[2],a[3]),make_bcd(a[4],a[5]));
			return;
		}
		else if(temp==17)
			return;
	}//while 1
}

main()
{
	u8 i;
	rtc time;
	init_lcd();
	build_cgram(cgram_lut,8);
	update_clock(0x23,0x59,0x00);
	while(1)
	{
		cmd_lcd(0x80);
		puts_lcd("Clock Time:      ");
		init_rows();
		while(colscan())
		{
			time.hrs=i2c_device_read(0xd0,0x02);
			time.mins=i2c_device_read(0xd0,0x01);
			time.secs=i2c_device_read(0xd0,0x00);
			cmd_lcd(0xc0);
			putc_lcd((time.hrs/16)+'0');
			putc_lcd((time.hrs%16)+'0');
			putc_lcd(':');
			putc_lcd((time.mins/16)+'0');
			putc_lcd((time.mins%16)+'0');
			putc_lcd(':');
			putc_lcd((time.secs/16)+'0');
			putc_lcd((time.secs%16)+'0');
		}
		i=keyscan();
		while(!colscan());
		if(i==17)
		{
			edit_clock(time);
		}
	}
}

