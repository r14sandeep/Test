#include<reg51.h>
#include<string.h>
#include "lcd.h"
#include "delay.h"
#include "uart.h"
#include"types.h"
#include"keypad.h"

void status(void);
void on(void);
void off(void);
u8 check_pwd(void);
void print_lcd_status(u8 *);

u8 pwd[5]="1234";
u8 ch_pwd[5];

extern unsigned char rec_buff[6];
extern bit r_flag;

sbit led=P3^7;

void process()
{
	u8 n=0;
	u8 flag=0;
//	uart_init();
	while(1)
	{
		led=0;
		while(!check_pwd())
		{
			cmd_lcd(0x94);
			str_lcd("Incorrect Password");
			delay_ms(500);
		}//while check pwd
		led=1;
		while(1)
		{
			cmd_lcd(0x01);	
			cmd_lcd(0x80);
			str_lcd("******* MENU *******");
			cmd_lcd(0xc0);
			str_lcd("1. INFO ");
			cmd_lcd(0x94);
			str_lcd("2. BON - ON");
			cmd_lcd(0xd4);
			str_lcd("3. BOFF - OFF");  
			
			do
			{
				n=keyscan();
			}while((n!=1) && (n!=2) && (n!=3) && (n!=4));

				
			switch(n)
			{
				case 1: status(); break;
				case 2:	on(); break;
				case 3:	off(); break;
				case 4: flag=1;
						goto abc;
//				default: break;
			}	
			abc:
 		    	if(flag==1)
				{
					flag=0;
					break;
				}
		}//while1 inner
	}//while1 outer
	
}

/*

u8 check_pwd()
{
	
	u16 num=0;
	u8 i;
	u8 j=0;

	cmd_lcd(0x01);
	cmd_lcd(0x80);
	str_lcd("Enter Password:");
//	cmd_lcd(0xc0);
	
	while(1)
	{
		num=0;
		do		
		{
			//init_rows();
		//	init_cols();
			i=keyscan();
		//	while(!colscan());
			cmd_lcd(0xc0+j++);
			putc_lcd('*');
			num=(num*10)+i;
		}while(num<1000);

		if(num==pwd)
			return 1;
		else
			return 0;
	}		
}
*/

u8 check_pwd()
{
	u8 i,j;
	cmd_lcd(0x01);
	cmd_lcd(0x80);
	str_lcd("Enter Password:");
	ch_pwd[0]=0;
	i=0;
	while(1)
	{
		j=keyscan();
		if(j!=16)
		{
			ch_pwd[i]=(j+'0');
			cmd_lcd(0xc0+i);
			putc_lcd('*');
			i++;
			if(i==4)
				break;
		}
		else
		{
			if(i!=0)
			{
				i--;
				ch_pwd[i]=0;
				cmd_lcd(0xc0+i);
				putc_lcd(' ');
			}
		}
	}//while1

	if(strcmp(pwd,ch_pwd)==0)
		return 1;
	else
		return 0;

}


void print_lcd_status(u8 *ptr)
{
	cmd_lcd(0x01);
	cmd_lcd(0x80);
	str_lcd("Status:");
	cmd_lcd(0xc0);
//	if(r_flag)
	while(!r_flag);
	if(!ptr)
	{
		str_lcd(rec_buff+1);
	//	r_flag=0;
	}
	else
		str_lcd(ptr);
	
	cmd_lcd(0xd4);
	str_lcd("pres any key to exit");
//	while(colscan());
	while(keyscan());	
}


void status()
{
//	uart_init();
	r_flag=0;
	uart_string("INFO$");
//	print_lcd_status();
	print_lcd_status(0);
//	r_flag=0;
//	rec_buff[0]=0;
}

void on()
{
//	uart_init();
//	uart_string("INFO$");
//	while(!r_flag);
	if(strcmp(rec_buff,"BON")!=0)
	{
		uart_string("BON$");
		print_lcd_status("ON");
		
	}
	else
	{
		print_lcd_status(0);
	}
//	r_flag=0;
//	status();
}

void off()
{
//	uart_init();
//	uart_string("INFO$");
//	while(!r_flag);
	if(strcmp(rec_buff,"BOFF")!=0)
	{
		uart_string("BOFF$");
		print_lcd_status("OFF");
	}
	else
	{
		print_lcd_status(0);
	}
//	r_flag=0;
//	status();
}
