#include<reg51.h>
#include"delay.h"
#include"mcp_3204.h"
main()
{
while(1)
{
u8 i;
for(i=250;i>0;i--)
dispf_4_mux_segs(read_adc_mcp3204(0));
for(i=250;i>0;i--)
dispf_4_mux_segs(read_adc_mcp3204(1));
}
}
