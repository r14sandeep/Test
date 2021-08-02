#include<reg51.h>
#include"types.h"
#include"seg.h"
void delay_ms(u8 n)
{
	u16 i;
	for(;n>0;n--);
	for(i=0;i<1000;i++);
}
