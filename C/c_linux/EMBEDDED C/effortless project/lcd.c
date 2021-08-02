#include<reg52.h>

#include"delay.h"
#include"lcd.h"

#define lcd_data P0

sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

void write_lcd(unsigned char dat)
{
  lcd_data=dat;
  rw=0; 
  en=1;
  en=0;
  delay_ms(2);
}
void cmd_lcd(unsigned char cmd)
{
  rs=0; //sel cmd reg
  write_lcd(cmd);

}

void putc_lcd(unsigned char val)
{
   rs=1;  // sel data register
   write_lcd(val);

}
void init_lcd()
{
	cmd_lcd(0x02);//return home
	cmd_lcd(0x38);//8_bit mode
 	cmd_lcd(0x06);//increment cursor to right
 	cmd_lcd(0x0c);//display on cursor off
 	cmd_lcd(0x01);//clear screen
 	cmd_lcd(0x80);//first line first position
}


void str_lcd(unsigned char *p)
{
	while(*p)
   		putc_lcd(*p++);
}



/*void int_lcd(unsigned int n)
{
	char a[5]={0},i=0;
	   
	if(n==0)
	{
		putc_lcd('0');
		return ;
	}
	else
	{
		while(n>0)
		{
			a[i++]=((n%10)+48);
			n/=10;
		}
		for(--i;i>=0;i--)
		{
			putc_lcd(a[i]);
		}
	}
}

void float_lcd(float f)
{
	unsigned int i;
	i = f;
	int_lcd(i);
	putc_lcd('.');
	i = (f-i)*1000;
	int_lcd(i);
}*/
