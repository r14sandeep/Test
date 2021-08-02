#include<reg51.h>
#include"keypad.h"
#include"delay.h"
#include"seg.h"
extern u16 count;
u16 keyvalue=0,outvalue=0;
main()
{
	
	while(1)	
	{

		if(count<4)
		{
		keyvalue=keyscan();
		if(keyvalue<=9)
		outvalue=(outvalue*10)+keyvalue;
		else
		count=4;
		}
		dispi_4_mux_segs(outvalue);
	}
}

