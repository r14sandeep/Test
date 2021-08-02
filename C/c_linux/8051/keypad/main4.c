#include"keypad.h"
#include<reg51.h>
#include"seg.h"
#include"delay.h"
sbit led=P2^7;
extern s8 khcount;
main()
{
	u16 i,j,k,key=0;
	init_rows();
	while(1)
	{
		led=~led;
		while(colscan());
		khcount=-1;
		for(j=300;j>0;j++)
			for(i=122;i>0;i--)
			{
				init_rows();
				if(!colscan())
					khcount=-1;
				khcount++;
				key=keyscan2();
				while(!colscan());
				i=122;j=300;
			}
	
	}
	delay_ms(1000);
	for(k=500;k>0;k--)
	dispi_2_mux_segs(key,0);

}
