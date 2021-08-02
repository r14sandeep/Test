#include"delay.h"
#include"i2c.h"
#include"lcd.h"

main()
{
	u8 i,buff;
	init_lcd();
	puts_lcd("writing..");
	for(i=0;i<128;i++)
		i2c_device_write(0xa0,i,'A'+i);
	cmd_lcd(0x01);
	puts_lcd("written");
	delay_ms(2000);
	cmd_lcd(0x01);
	puts_lcd("reading.");
	for(i=0;i<128;i++)
	{
		buff=i2c_device_read(0xa0,i);
		cmd_lcd(0xc0);
		putc_lcd(buff);
		delay_ms(100);
	}
	cmd_lcd(0xc0+8);
	puts_lcd("read");
	while(1);
}
