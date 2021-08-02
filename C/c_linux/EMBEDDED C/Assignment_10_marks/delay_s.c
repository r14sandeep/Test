#include"delay.h"
void delay_s(unsigned int dly)
{
	unsigned int temp;
	for(;dly>0;dly--)
	{
		for(temp=65535;temp>0;temp--);
		for(temp=59401;temp>0;temp--);
	}


/*	for(;dly>0;dly--)
	{
		delay_ms(1000);
	}*/
}
