#include<reg51.h>
#include"types.h"
#include"delay.h"
//#include"seg.h"

#define SEGS_PORT P0
sbit sel1=P2^0;
sbit sel2=P2^1;
sbit sel3=P2^2;
sbit sel4=P2^3;
//int i=0,j,cnt=0,k;
code u8 seg_lut[]={0xff,0xff,0xff,0x88,0x80,0xc6,0xc0,0x86,0x8e,0x82,0xff,0xff,0xff};//,0x89,0x00,0xe1};                                                                                                                                                                                                                                                                                                                                                                                              

//code u8 seg_lut[]={0x88,0x80,0xc6,0xc0,0x86,0x8e,0x82};//,0x89,0x00,0xe1};                                                                                                                                                                                                                                                                                                                                                                                              

u8 dp1=0xff,dp2=0xff,dp3=0xff;


void dispi_4_mux_segs(u8 n)
{
	SEGS_PORT=seg_lut[n]&dp1;
	sel1=0;
	delay_ms(1);
	sel1=1;

	SEGS_PORT=seg_lut[n+1]&dp2;
	sel2=0;
	delay_ms(1);
	sel2=1;

	SEGS_PORT=seg_lut[n+2]&dp3;
	sel3=0;
	delay_ms(1);
	sel3=1;

	SEGS_PORT=seg_lut[n+3];
    sel4=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           	sel4=0;				//////seg4 on
 	delay_ms(1);
	sel4=1;				//////seg4 off

}






/*
void dispstring_4_mux_segs(u8 *n)
{

		for(k=0;k<150;k++)
		{
				i=0;
				while(n[i])
				{
					
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
						SEGS_PORT=seg_lut[j]&dp1;
					sel2=0;
					delay_ms(1);
					sel2=1;
					
					}
					if(i==3)
					{
						SEGS_PORT=seg_lut[j]&dp1;
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
					//break;
					//i=0;
					}
				
					
				}
						
		}
		//i=0;
		for(k=0;k<150;k++)
		{
				i=1;
				while(n[i])
				{
					
					j=n[i++]-65;
				
				
					if(i==2)
					{
						SEGS_PORT=seg_lut[j]&dp1;
					sel1=0;
					delay_ms(1);
					sel1=1;
					}
					if(i==3)
					{
						SEGS_PORT=seg_lut[j]&dp1;
					sel2=0;
					delay_ms(1);
					sel2=1;
					
					}
					if(i==4)
					{
						SEGS_PORT=seg_lut[j]&dp1;
					sel3=0;
					delay_ms(1);
					sel3=1;
					
					}
					if(i==5)
					{
						SEGS_PORT=seg_lut[j]&dp1;
					sel4=0;
					delay_ms(1);
					sel4=1;
					break;
					
					}
				
					
				}
		   }
		   for(k=0;k<120;k++)
			{
				i=2;
				while(n[i])
				{
					
					j=n[i++]-65;
				
				
					if(i==3)
					{
						SEGS_PORT=seg_lut[j]&dp1;
					sel1=0;
					delay_ms(1);
					sel1=1;
					}
					if(i==4)
					{
						SEGS_PORT=seg_lut[j]&dp1;
					sel2=0;
					delay_ms(1);
					sel2=1;
					
					}
					if(i==5)
					{
						SEGS_PORT=seg_lut[j]&dp1;
					sel3=0;
					delay_ms(1);
					sel3=1;
					
					}
					if(i==6)
					{
						SEGS_PORT=seg_lut[j]&dp1;
					sel4=0;
					delay_ms(1);
					sel4=1;
					
					}
				
				}
			  }
			for(k=0;k<120;k++)
			{
				i=3;
				while(n[i])
				{
					
					j=n[i++]-65;
				
				
				//	if(i==4)
				//	{
						SEGS_PORT=seg_lut[j]&dp1;
					sel1=0;
					delay_ms(1);
					sel1=1;
				//	}
					
				 }
			}
		
	//	}
	//}
}

*/
