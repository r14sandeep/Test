#include"types.h"
void delay_ms(u16 dly)
{
	u16 num;
	for(;dly>0;dly--)
		for(num=122;num>0;num--);
}
