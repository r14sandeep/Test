#include<reg51.h>
#include"types.h"
//sbit r0

code u8 keypad_lut[4][4][4]={{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},
{{17,18,19,20},{21,22,23,24},{25,26,27,28},{29,30,31,32}},
{{33,34,35,36},{37,38,39,40},{41,42,43,44},{45,46,47,48}},
{{49,50,51,52},{53,54,55,56},{57,58,59,60},{61,62,63,64}}};
void init_rows(void){r0=r1=r2=r3=0;}
void init_cols(void){c0=c1=c2=c3=1;}
bit colscan(void){return (c0&c1&c2&c3);}

u8 get_row(void)
{
	r0=0;r1=r2=r3=1;
	if(!colscan())return 0;
	r1=0;r2=r0=r3=1;
	if(!colscan()) return 1;
	r2=0;r0=r1=r3=1;
	if(!colscan()) return 2;
	r3=0;r0=r1=r2=1;
	if(!colscan()) return 3;
}
u8 get_get(void)
{
	if(c0==0) return 0;
	else if(c1==0) return 1;
	else if(c2==0) return 2;
	else if(c3==0) return 3;
} 
s8 khcount=-1;
u8 keyscan2(void)
{
	u8 row=0,col=0;
	static u8 prow,pcol;
	init_cols();
	init_rows();
	while(colscan());
	row=get_row();
	col=get_col();
	if(row!=prow)
	{
		khcount=0;prow=row;
	}
	if(col!=pcol)
	{
		khcount=0;pcol=col;
	}
	return keypad_lut[khcount][row][col];

}
