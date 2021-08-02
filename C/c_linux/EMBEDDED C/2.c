#include<reg51.h>
#define leds P0
#define check 0
#if check>0
void disp_binary_leds(unsigned int sum)
{
leds=num^0x0f;
}
#else
sbit led1=leds^0;
sbit led2=leds^1;
sbit led3=leds^2;
sbit led4=leds^3;
sbit led5=leds^4;
sbit led6=leds^5;
sbit led7=leds^6;
sbit led8=leds^7;
void disp_binary_leds(unsigned int num)
{
led1=((num>>0)&0x01)?0:1;
led2=((num>>1)&0x01)?0:1;
led3=((num>>2)&0x01)?0:1;
led4=((num>>3)&0x01)?0:1;
led5=((num>>4)&0x01)?1:0;
led6=((num>>5)&0x01)?1:0;
led7=((num>>6)&0x01)?1:0;
led8=((num>>7)&0x01)?1:0;
}
#endif
