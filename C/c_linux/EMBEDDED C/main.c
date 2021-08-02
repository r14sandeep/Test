#include"led.h"
#include"delay1.h"
void delay_ms(unsigned int dly);
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
