#include"seg.h"
#include"types.h"
#include"delay.h"
main()
{
	u8 i;
	while(1)
	{
		for(i=250;i>0;i--)
				dispi_4_mux_segs(8749);
		//delay_ms(1000);
		for(i=250;i>0;i--)
			dispf_4_mux_segs(8.749);
		for(i=250;i>0;i--)
		//delay_ms(1000);	
		dispf_4_mux_segs(87.49);
		for(i=250;i>0;i--)
		//delay_ms(1000);
		dispf_4_mux_segs(874.9);
	
	}


}
