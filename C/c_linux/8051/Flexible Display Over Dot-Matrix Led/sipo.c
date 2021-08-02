/** compiler directive **/
#include<reg52.h>

/** shift register1 connections**/
sbit dat1=P2^0;
sbit clk1=P2^1;
/** shift register2 connections**/
sbit dat2=P2^2;
sbit clk2=P2^3;
/** shift register3 connections**/
sbit dat3=P2^4;
sbit clk3=P2^5;
/** shift register4 connections**/
sbit dat4=P2^6;
sbit clk4=P2^7;

/** shift register1 function defination **/
/** giving the 8bit data **/
void _74hc164_tx1(unsigned char d)
{
	char i=7;
	while(i>=0)
	{
		dat1=((d>>i)&1)?1:0;	//passing bit by bit to the shift register
		clk1=0;	
		i--;	//decrement i valur for next bit	
		clk1=1;//for every clock pulse 1bit is shifted
	}
}

/** shift register2 function defination **/
/** giving the 8bit data **/
void _74hc164_tx2(unsigned char d)
{
	char i=7;
	while(i>=0)
	{
		dat2=((d>>i)&1)?1:0;//passing bit by bit to the shift register
		clk2=0;
		i--;	//decrement i valur for next bit	
		clk2=1;//for every clock pulse 1bit is shifted
	}
}

/** shift register3 function defination **/
/** giving the 8bit data **/
void _74hc164_tx3(unsigned char d)
{
	char i=7;
	while(i>=0)
	{
		dat3=((d>>i)&1)?1:0;//passing bit by bit to the shift register
		clk3=0;
		i--;	//decrement i valur for next bit	
		clk3=1;//for every clock pulse 1bit is shifted
	}
}

/** shift register4 function defination **/
/** giving the 8bit data **/
void _74hc164_tx4(unsigned char d)
{
	char i=7;
	while(i>=0)
	{
		dat4=((d>>i)&1)?1:0;//passing bit by bit to the shift register
		clk4=0;
		i--;	//decrement i valur for next bit	
		clk4=1;//for every clock pulse 1bit is shifted
	}
}

/** dot matrix display selection function **/	
void tx(unsigned char d,int sel)
{
	if(sel==1)	//1st dot matrix display selection
		_74hc164_tx1(d);	//sending data to dot matrix 1
	else if(sel==2)	//2nd dot matrix display selection
		_74hc164_tx2(d);	//sending data to dot matrix 2
	else if(sel==3)	//3rd dot matrix display selection
		_74hc164_tx3(d);	//sending data to dot matrix 3
	else if(sel==4)	//4th dot matrix display selection
		_74hc164_tx4(d);	//sending data to dot matrix 4
}

