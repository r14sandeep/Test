#include<reg51.h>
#include"types.h"
#include"delay.h"
//#include"seg.h"

#define SEGS_PORT P0
sbit sel1=P2^0;
sbit sel2=P2^1;
sbit sel3=P2^2;
sbit sel4=P2^3;
int i,j,k,l;

code u8 seg_lut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};

//code u8 seg_lut[]={0x89,0x86,0xc7,0x8c};


u8 dp1=0xff,dp2=0xff,dp3=0xff;
	
	void dispi_4_mux_segs(u16 n)
	{
			while(1)
			{

				for(i=0;i<200;i++)
				{
					//if(i==0)
				//	{
						SEGS_PORT=seg_lut[n/1000]&dp1;
						sel1=0;
						delay_ms(1);
						sel1=1;
	
						SEGS_PORT=seg_lut[(n/100)%10]&dp2;
						sel2=0;
						delay_ms(1);
						sel2=1;
		
						SEGS_PORT=seg_lut[(n/10)%10]&dp3;
						sel3=0;
						delay_ms(1);
						sel3=1;
		
						SEGS_PORT=seg_lut[n%10];
		    			sel4=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           	sel4=0;				//////seg4 on
		 				delay_ms(1);
						sel4=1;				//////seg4 off						
				}
					//delay_ms(100);
				 	//}
		
				//	if(i==1)
				//	{	
					
						for(i=0;i<200;i++)
				{						
						SEGS_PORT=seg_lut[(n/100)%10]&dp2;
						sel1=0;
						delay_ms(1);
						sel1=1;
		
						
						SEGS_PORT=seg_lut[(n/10)%10]&dp3;
						sel2=0;
						delay_ms(1);
						sel2=1;
		
						
						SEGS_PORT=seg_lut[n%10];
						sel3=0;
						delay_ms(1);
						sel3=1;
		
						
		    			/*SEGS_PORT=seg_lut[n/1000]&dp1;
						sel4=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           	sel4=0;				//////seg4 on
		 				delay_ms(1);
						sel4=1;	*/			//////seg4 off
					}
					//delay_ms(300);
					//}
				//	if(i==2)
				//	{
			
			for(i=0;i<200;i++)
				{
				
						SEGS_PORT=seg_lut[(n/10)%10]&dp3;				
						sel1=0;
						delay_ms(1);
						sel1=1;
		
						
						
						SEGS_PORT=seg_lut[n%10];
						sel2=0;
						delay_ms(1);
						sel2=1;
		
						
						
						/*SEGS_PORT=seg_lut[n/1000]&dp1;
						sel3=0;
						delay_ms(1);
						sel3=1;
		
						
		    			
						SEGS_PORT=seg_lut[(n/100)%10]&dp2;
						sel4=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           	sel4=0;				//////seg4 on
		 				delay_ms(1);
						sel4=1;	*/			//////seg4 off
				}	
					//delay_ms(300);
				//	}
				//	if(i==3)
					//{
		
				for(i=0;i<200;i++)
				{
				
						SEGS_PORT=seg_lut[n%10];								
						sel1=0;
						delay_ms(1);
						sel1=1;
		
						
						
						
					/*	SEGS_PORT=seg_lut[n/1000]&dp1;
						sel2=0;
						delay_ms(1);
						sel2=1;
		
						
						
						
						SEGS_PORT=seg_lut[(n/100)%10]&dp2;
						sel3=0;
						delay_ms(1);
						sel3=1;
		
						
		    			
						
						SEGS_PORT=seg_lut[(n/10)%10]&dp3;
						sel4=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           	sel4=0;				//////seg4 on
		 				delay_ms(1);
						sel4=1;				//////seg4 off
						//i=-1;*/
					}
						for(i=0;i<200;i++)
				{
						SEGS_PORT=seg_lut[n/1000]&dp1;
						sel4=0;
						delay_ms(1);
						sel4=1;
					  }
					for(i=0;i<150;i++)
					{
						SEGS_PORT=seg_lut[n/1000]&dp1;
						sel3=0;
						delay_ms(1);
						sel3=1;
	
						SEGS_PORT=seg_lut[(n/100)%10]&dp2;
						sel4=0;
						delay_ms(1);
						sel4=1;
					}
					for(i=0;i<200;i++)
					{
						SEGS_PORT=seg_lut[n/1000]&dp1;
						sel2=0;
						delay_ms(1);
						sel2=1;
	
						SEGS_PORT=seg_lut[(n/100)%10]&dp2;
						sel3=0;
						delay_ms(1);
						sel3=1;

						SEGS_PORT=seg_lut[(n/10)%10]&dp3;
						sel4=0;
						delay_ms(1);
						sel4=1;
					}
					//	delay_ms(300);
					
					
			}		
//	}
}			
			
/*			void dispf_4_mux_segs(float f)
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


void dispi_2_mux_segs(u8 n,bit flag)
{
	if(flag==0)
	{
		SEGS_PORT=seg_lut[n/10]&dp1;
		sel1=0;
		delay_ms(1);
		sel1=1;
		SEGS_PORT=seg_lut[n%10]&dp2;
		sel2=0;
		delay_ms(1);
		sel2=1;

	}
	else
	{
		SEGS_PORT=seg_lut[n/10]&dp3;
		sel3=0;
		delay_ms(1);
		sel3=1;
		SEGS_PORT=seg_lut[n%10];
		sel4=0;
		delay_ms(1);
		sel4=1;

	}


}
*/	
