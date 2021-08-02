
#include<reg51.h>
#include"seg.h"
#include"types.h"
//#include"delay.h"
#include"keypad.h"
main()
{
	u8 keyval;
	while(1)
	{
	keyval=keyscan();
	while(!keyscan())
	dispi_2_mux_segs(keyval,0);
	}
}
