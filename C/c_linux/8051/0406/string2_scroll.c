#include<reg51.h>
#include"types.h"
#include"delay.h"

//#include"seg.h"

#define SEGS_PORT P0
sbit sel1=P2^0;
sbit sel2=P2^1;
sbit sel3=P2^2;
sbit sel4=P2^3;
int i=0,j;
code u8 seg_lut[]={0x89,0x86,0xc7,0x8c};                                                                                                                                                                                                                                                                                                                                                                                              

u8 dp1=0xff,dp2=0xff,dp3=0xff;




void dispstring_4_mux_segs(u8 *n)
{
		//j=n[i++]-65;
	//	if(i==1)
	//		{
				SEGS_PORT=seg_lut[0]&dp1;
			sel1=0;
			delay_ms(1);
			sel1=1;
		//	}
		//	if(i==2)
		//	{
				SEGS_PORT=seg_lut[1]&dp1;
			sel2=0;
			delay_ms(1);
			sel2=1;
			
		//	}
		//	if(i==3)
		//	{
				SEGS_PORT=seg_lut[2]&dp1;
			sel3=0;
			delay_ms(1);
			sel3=1;
			
		//	}
		//	if(i==4)
		//	{
				SEGS_PORT=seg_lut[3]&dp1;
			sel4=0;
			delay_ms(1);
			sel4=1;


}
