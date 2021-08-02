#include"types.h"
void delay_ms(u8 n)
{
	u16 i;
	for(;n;n--);
	for(i=0;i<1000;i++);
}
