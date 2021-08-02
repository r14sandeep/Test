#include"types.h"
void delay_ms(u8 dly)
{
	u16 i;
	for(;dly;dly--)
	for(i=122;i>0;i--);
}