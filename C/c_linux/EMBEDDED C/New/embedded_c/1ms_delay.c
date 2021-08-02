#include<reg51.h>
void delay_sec(unsigned char);
sbit sel=P0^0;
main()
{
while(1)
{
sel=0;
delay_sec(1);
sel=1;
delay_sec(1);
}
}

void delay_sec(unsigned char dly)
{
unsigned char num,num1,j=2;
unsigned int i=202408;
while(j--) // GENERATES 1 SEC DEALAY
{
while(i--)
{
for(;dly>0;dly--)         //THIS 
for(num1=9;num1>0;num1--) //WILL GIVE 1 MS
for(num=53;num>0;num--);  //DELAY
}
}
}
