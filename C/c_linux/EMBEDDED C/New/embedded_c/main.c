#include"led.h"
#include"delay.h"
main()
{
unsigned char i;
while(1)
{
for(i=0;i<256;i++)
	{
disp_binary_leds(i);
delay_ms(500);
	}
}
}
