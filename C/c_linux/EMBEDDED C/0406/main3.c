#include"seg.h"
#include"types.h"
//int i;
main()
{
	//u8 mins,secs;
		u8 i,j;
	while(1)
	{
		for(i=0;i<11;i++)
			for(j=250;j>0;j--)
				dispi_4_mux_segs(i);
		//dispstring_4_mux_segs("ACEF");
	

		//for(i=0;i<100;i++)
	//	dispi_4_mux_segs(1234);
		/*for(mins=0;mins<60;mins++)
			for(secs=0;secs<60;secs++)
				for(i=250;i>0;i--)
				{
					dispi_2_mux_segs(mins,0);
					dispi_2_mux_segs(secs,1);
				}	
		*/
	}


}
