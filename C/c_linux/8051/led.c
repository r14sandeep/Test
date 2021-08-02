#include<reg51.h>
#define leds P0
void delay_ms(unsigned int dly);
void disp_binary_leds(unsigned int);
main()
{
	unsigned int i;
	while(1)
	{
		for(i=0;i<256;i++)
		{
			disp_binary_leds(i);
			delay_ms(500);
		}
	
	}
}
void disp_binary_leds(unsigned int num)
{
	leds=num^0x0f;
}


void delay_ms(unsigned int dly)
{
	unsigned int num;
	for(;dly>0;dly--)
		for(num=122;num>0;num--);

}
