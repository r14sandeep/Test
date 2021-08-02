#include<reg52.h>
#include"mcp3204.h"

sbit clk =P1^0;
sbit dout=P1^1;
sbit din =P1^2;
sbit cs  =P1^3;

float read_mcp3204(unsigned char chno)
{
	unsigned int val=0;
	char i;
	bit d0,d1;
	
	if(chno==0)
		d1=d0=0;	
	else if(chno==1)
	{
		d1=0;
		d0=1;	
	}
	else if(chno==2)
	{
		d1=1;
		d0=0;	
	}
	else if(chno==3)
	{
		d1=1;
		d0=1;	
	}

	clk=din=dout=cs=1;
	
	cs=0;

	clk=0;clk=1;
	clk=0;clk=1;
	clk=0;clk=1;

	clk=0;din=d1;clk=1;	
	clk=0;din=d0;clk=1;
	
	clk=0;clk=1;
	clk=0;clk=1;
	
	for(i=11;i>=0;i--)
	{
		clk=0;
		clk=1;
		if(dout)
			val|=(1<<i);
	}
	cs=1;
	
	return ((val*5.0)/4095);	
}
