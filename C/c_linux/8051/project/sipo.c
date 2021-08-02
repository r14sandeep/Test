/** compiler directive **/
#include<reg52.h>

#include "delay.h"

/** shift register1 connections**/
sbit dat1=P2^0;
sbit clk1=P2^1;
sbit dat2=P2^2;
sbit clk2=P2^3;
sbit dat3=P2^4;
sbit clk3=P2^5;
sbit dat4=P2^6;
sbit clk4=P2^7;

/** shift register1 function defination **/
/** giving the 8bit data **/
/*void _74hc164_tx1(unsigned char d,unsigned int n)
{
	char i;
	if(n==0)
	for(i=7;i>=0;i--)
	{
		dat1=((d>>i)&1)?1:0;	//passing bit by bit to the shift register
		clk1=0;	
		clk1=1;//for every clock pulse 1bit is shifted
	}
	if(n==1)
	for(i=7;i>=0;i--)
	{
		dat2=((d>>i)&1)?1:0;	//passing bit by bit to the shift register
		clk2=0;	
		clk2=1;//for every clock pulse 1bit is shifted
	}
	if(n==2)
	for(i=7;i>=0;i--)
	{
		dat3=((d>>i)&1)?1:0;	//passing bit by bit to the shift register
		clk3=0;	
		clk3=1;//for every clock pulse 1bit is shifted
	}
	if(n==3)
	for(i=7;i>=0;i--)
	{
		dat4=((d>>i)&1)?1:0;	//passing bit by bit to the shift register
		clk4=0;	
		clk4=1;//for every clock pulse 1bit is shifted
	}
}*/

void _74hc164_tx1(unsigned char d)
{
	char i;
		for(i=7;i>=0;i--)
		{

			dat1=((d>>i)&1)?1:0;
			clk1=0;	
			clk1=1;
		}
}

void _74hc164_tx2(unsigned char d)
{
	char i;
		for(i=7;i>=0;i--)
		{

			dat2=((d>>i)&1)?1:0;
			clk2=0;	
			clk2=1;
		}
}
void _74hc164_tx3(unsigned char d)
{

	char i;
	for(i=7;i>=0;i--)
	{

		dat3=((d>>i)&1)?1:0;
		clk3=0;	
		clk3=1;
	  }
}
		
void _74hc164_tx4(unsigned char d)
{
	char i;
	for(i=7;i>=0;i--)
	{


		dat4=((d>>i)&1)?1:0;
		clk4=0;	
		clk4=1;
		
		
	}
}



