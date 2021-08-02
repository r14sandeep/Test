#include<reg51.h>
#include"types.h"
#include"delay.h"
#include"lcd.h"
sbit rs=P0^0;
sbit rw=P0^1;
sbit en=P0^2;
sbit d4=P0^4;
sbit d5=P0^5;
sbit d6=P0^6;
sbit d7=P0^7;

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
	en=1;
	delay_ms(2);
}



void init_lcd(void)
{
	delay_ms(15);
	cmd_lcd(0x03);
	delay_ms(3);
	cmd_lcd(0x03);
	cmd_lcd(0x03);
	cmd_lcd(0x02);
	cmd_lcd(0x02);
	cmd_lcd(0x08);
	cmd_lcd(0x00);
	cmd_lcd(0x01);
	cmd_lcd(0x06);
	cmd_lcd(0x0f);
	cmd_lcd(0x80);
}

void cmd_lcd(u8 cmd)
{
	rs=0;/////select cmd reg
	write_lcd(cmd);  //wr to cmd reg,wr to instr decoder via cmd reg

}
void putc_lcd(u8 ch)
{
	rs=1;
	write_lcd(ch);
}



void puts_lcd(u8 *s)
{
	while(*s)
		putc_lcd(*s++);

}


void u16_lcd(u16 n)
{
	u8 a[5]={0};
	s8 i=0;
	if(n==0)
	{	putc_lcd('0');return;}
	else
	{
		while(n)
		{
			a[                                                  i++]=(n%10)+48;
			n/=10;
		}
		for(--i;i>=0;i--)
			putc_lcd(a[i]);
	}
}


void float_lcd(float f)
{
	u16 i;u8 j;
	i=f;
	u16_lcd(i);
	putc_lcd('.');
	for(j=0;j<3;j++)
	{
		f=(f-i)*10;
		i=f;
		u16_lcd(i);
	}

}

void build_cgram(u8 *a,u8 size)
{
	u8 i;
	cmd_lcd(0x40);  ////pos cursor to cgram
	for(i=0;i<size;i++)
		putc_lcd(a[i]);   ///wr to cgram via data reg
	cmd_lcd(0x80);   ////pos cursor back to ddram 

}
