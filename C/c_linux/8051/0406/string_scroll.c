#include<reg51.h>
#include"types.h"
#include"delay.h"
//#include"seg.h"

#define SEGS_PORT P0
sbit sel1=P2^7;
sbit sel2=P2^6;
sbit sel3=P2^5;
sbit sel4=P2^4;
int i=0,j;
code u8 seg_lut[]={0x88,0x80,0xc6,0xc0,0x86,0x8e,0x82};                                                                                                                                                                                                                                                                                                                                                                                             

u8 dp1=0xff,dp2=0xff,dp3=0xff;




void dispstring_4_mux_segs(u8 *n)
{
//		k=strlen(n);
		//while(1)
		//{
		while(n[i])
		{
//			cnt++;
			j=n[i++]-65;
			
		
		
			if(i==1)
			{
				SEGS_PORT=seg_lut[j]&dp1;
			sel1=0;
			delay_ms(1);
			sel1=1;
			}
			if(i==2)
			{
				SEGS_PORT=seg_lut[j]&dp2;
			sel2=0;
			delay_ms(1);
			sel2=1;
			
			}
			if(i==3)
			{
				SEGS_PORT=seg_lut[j]&dp3;
			sel3=0;
			delay_ms(1);
			sel3=1;
			
			}
			if(i==4)
			{
				SEGS_PORT=seg_lut[j]&dp1;
			sel4=0;
			delay_ms(1);
			sel4=1;
			i=0;
			}
		 //}
		}
}
















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































