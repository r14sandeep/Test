#include<reg51.h>
#include"types.h"
#include"delay.h"
#include"lcd.h"
sbit d4=P0^4;
sbit d5=P0^5;
sbit d6=P0^6;
sbit d7=P0^7;
sbit rs=P0^1;
sbit rw=P0^2;
sbit en=P0^3;

void write_lcd(u8 dat)
{
	rw=0;
	d7=(dat>>7)&1;
	d6=(dat>>6)&1;
   	d5=(dat>>5)&1;
	d4=(dat>>4)&1;
	en=1;
	en=0;
	
	d7=(dat>>3)&1;
	d6=(dat>>2)&1;
	d5=(dat>>1)&1;
	d4=(dat>>0)&1;
	
	en=1;
	en=0;
	delay_one_ms(2);
}

void init_lcd(void)
{
	delay_one_ms(15);
	cmd_lcd(0x03);
	delay_one_ms(3);
	cmd_lcd(0x03);
	cmd_lcd(0x03);
	cmd_lcd(0x02);
	cmd_lcd(0x02);
	cmd_lcd(0x08);
	cmd_lcd(0x00);
	cmd_lcd(0x08);
	cmd_lcd(0x00);
	cmd_lcd(0x01);
	cmd_lcd(0x00);
	cmd_lcd(0x06);
	cmd_lcd(0x0f);
	cmd_lcd(0x80);
}
