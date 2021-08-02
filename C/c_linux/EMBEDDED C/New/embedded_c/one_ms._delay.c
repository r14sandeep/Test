#include<intrins.h>
void one_ms_delay(unsigned char dly);
void one_sec_delay(unsigned char delay);
main()
{
one_sec_delay(1);
while(1);
}
void one_ms_delay(unsigned char dly)
{
unsigned int i;
for(;dly>0;dly--)
for(i=1;i<=122;i++); 
}
void one_sec_delay(unsigned char delay)
{
unsigned char i,j;
for(;delay>0;delay--)
for(i=10;i>0;i--)
for(j=100;j>0;j--)
one_ms_delay(1);
for(i=1;i<=102;i++)
for(j=1;j<=5;j++);
for(i=0;i<2;i++);
_nop_();
_nop_();
//NOP;
//NOP;
}
