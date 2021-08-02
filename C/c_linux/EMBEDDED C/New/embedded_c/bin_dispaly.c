#include<reg51.h>
#define led P0
void delay(unsigned char dly)
{
	unsigned int num;
	for(;dly;dly--)
	for(num=0;num<65000;num++);
}
void disp_binary(unsigned char num)
{
	led=num;
}
main()
{
	unsigned char i;
	while(1)
	{                                                            
	for(i=0;i<256;i++)
		disp_binary(i);
		delay(5);
	}
}
