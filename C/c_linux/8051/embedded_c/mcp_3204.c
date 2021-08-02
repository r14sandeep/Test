#include<reg51.h>
#include"types.h"
sbit clk=P2^4;
sbit din=P2^5;
sbit dout=P2^6;
sbit _cs=P2^7;
float read_adc_mcp3204(u8 channelNo)
{
u16 adcval=0;
u8 i;
bit d1,d0;
clk=din=dout=_cs=1;
d1=(channelNo>>1)&1;
d0=(channelNo&1);
_cs=0;//begin communication session
clk=0;clk=1;//send start bit
clk=0;clk=1;//send single ended mode bit
clk=0;clk=1;//send d2(dont care bit)
din=d1;
clk=0;clk=1;//send d1 bit
din=d0;
clk=0;clk=1;//send d0 bit & start sampling
clk=0;clk=1;//continue & end sampling
clk=0;clk=1;//slave outputs null bit
for(i=0;i<12;i++)
{
clk=0;
if(dout)
adcval|=0x0800>>i;
clk=1;
}
_cs=1;//end communication session
return (adcval*(5.0/4096));
}


