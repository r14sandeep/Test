#include<reg51.h>
#include"types.h"

sbit r0=P3^4; sbit c0=P3^0;
sbit r1=P3^5; sbit c1=P3^1;
sbit r2=P3^6; sbit c2=P3^2;
sbit r3=P3^7 ; sbit c3=P3^3;
code u8 keypad_lut[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
void init_rows(void)
{r0=r1=r2=r3=0;}
void init_cols(void)
{c0=c1=c2=c3=1;}
bit colscan(void)
{return (c0&c1&c2&c3);}
u8 keyscan(void)
{
	u8 row,col;
	init_cols();
	init_rows();
	while(colscan());///detect anykey pressed,once keypressed proceed for identifying row in which key is pressed
	r0=0;r1=r2=r3=1;
	if(!colscan())
	{row=0;goto colcheck;}
	r1=0;r0=r2=r3=1;
	if(!colscan())
	{row=1;goto colcheck;}
	r2=0;r0=r1=r3=1;
	if(!colscan())
	{row=2;goto colcheck;}
	r3=0;r1=r2=r0=1;
	if(!colscan())
	{row=3;goto colcheck;}
	
colcheck:
	if(c0==0)col=0;
	else if(c1==0) col=1;
	else if(c2==0) col=2;
	else if(c3==0) col=3;
	return keypad_lut[row][col];
}
