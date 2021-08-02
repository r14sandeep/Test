#include<reg51.h>
sbit led=P1^0;
void delay_ms(unsigned int dly);
main()
{
while(1)
{
led=~led;
delay_ms(10);
}
}
void delay_ms(unsigned int dly)
{
unsigned int num;
for(;dly>0;dly--)
for(num=122;num>0;num--);
}
