#include<reg51.h>
#include<string.h>
#include"delay.h"
#include"lcd.h"
#include"keypad1.h"
#include"uart.h"
#include"types.h"
void print_lcd_status(u8*);
extern unsigned char rec_buff[6];
extern bit r_flag;
void status();
void on();
void off();
u8 keyval=0;
u8 flag=0;
void main()
{
				u8 cnt=4,p=0;
				init_lcd();
				str_lcd("enter the password");
				cmd_lcd(0xc0);

				while(1)
				{
					
					do{
					keyval=keyscan();
					}while((keyval>='0')&&(keyval<='9'));
					p=(p*10)+48;
					cmd_lcd(0xc0+cnt);
					putc_lcd('*');
					cnt++;
				//	break;
					if(cnt==4)
					{	
						cnt=0;
						break; 	
					}
				
				if(p==2345)
				{
						u8 keyval=0;
					
						cmd_lcd(0x01);	
						cmd_lcd(0x80);
						str_lcd("1:info");
						cmd_lcd(0x94);
						str_lcd("2:ON");
						cmd_lcd(0xd4);
						str_lcd("3:OFF");
						str_lcd("enter the choice");
						keyval=keyscan();
						switch(keyval)
							{
							case 1:status();
									break;
							case 2:on();
									break;
							case 3:off();
									break;

							default:break;
							}
						
						
					
				}
}
}
void print_lcd_status(u8 *ptr)
{
cmd_lcd(0x01);
cmd_lcd(0x80);
str_lcd("status");
cmd_lcd(0xc0);
if(r_flag)
{
while(!ptr)
{
str_lcd(rec_buff+1);
r_flag=0;
}
}
else
{
str_lcd(ptr);
}
r_flag=0;
while(colscan());
while(keyscan());

}

	
	
void status()
{
	uart_init();
	r_flag=0;
	uart_string("boff");
	print_lcd_status(' ');
	print_lcd_status('0');
	r_flag=0;
	rec_buff[0]=0;
}
void on()
{
	uart_init();
	uart_string("info");
	while(!r_flag)
	{
    	if(strcmp(rec_buff,"on")!=0)
		{
		uart_string("on");
		print_lcd_status(' ');
		}
	else
	{
	print_lcd_status('0');
	}
	r_flag=0;
	status();
	}
}
void off()
{
	uart_init();
	uart_string("info");
	while(!r_flag)
	{
    	if(strcmp(rec_buff,"off")!=0)
		{
		uart_string("off");
		print_lcd_status(' ');
		}
	else
	{
	print_lcd_status('0');
	}
	r_flag=0;
	status();
	}
}
