#include<reg51.h>
#include"types.h"
#include"delay.h"
#include"seg.h"
#define SEGS_PORT P0
//void delay_ms(u8);
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