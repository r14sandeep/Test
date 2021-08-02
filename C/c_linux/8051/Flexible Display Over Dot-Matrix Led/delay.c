/** millisecond delay function defination **/
void delay_ms(unsigned int dly)
{
	unsigned char i;
	for(;dly>0;dly--)
	{
		for(i=0;i<250;i++);
		for(i=0;i<135;i++);
	}
}

/** microsecond delay function defination **/
void delay_us(int us)
{
	int i;
	for (i=0;i<us;i++);
}
