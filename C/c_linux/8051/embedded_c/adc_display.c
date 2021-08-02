#include<reg51.h>
#include"types.h"

void delay_ms(u8);

#define SEGS_PORT P0

sbit sel1=P2^0;
sbit sel2=P2^1;
sbit sel3=P2^2;
sbit sel4=P2^3;

code u8 seg_lut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};

u8 dp1=0xff,dp2=0xff,dp3=0xff;

void dispi_4_mux_segs(u16 n)
{
	
	SEGS_PORT=seg_lut[(n/1000)]&dp1;
	sel1=0;//switch seg1 on
	delay_ms(1);//switching time
	sel1=1;
	SEGS_PORT=seg_lut[((n/100)%10)]&dp2;
	sel2=0;
	delay_ms(1);
	sel2=1;
	SEGS_PORT=seg_lut[((n%100)/10)]&dp3;
	sel3=0;
	delay_ms(1);
	sel3=1;
	SEGS_PORT=seg_lut[n%10];
	sel4=0;
	delay_ms(1);
	sel4=1;
}

void dispf_4_mux_segs(float f)
{
	u16 i;
	if((f>=0.0)&&(f<10.0))
	{
		i=f*1000;
		dp1=0x7f;
	}
	else if((f>=10.0)&&(f<100.0))
	{
		i=f*100;
		dp2=0x7f;
	}
	else if((f>=100.0)&&(f<1000.0))
	{
		i=f*10;
		dp3=0x7f;
}
dispi_4_mux_segs(i);
dp1=dp2=dp3=0xff;
}
