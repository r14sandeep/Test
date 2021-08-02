#include"delay.h"
#include"types.h"
#include"lcd.h"
#include"i2c.h"
typedef struct ds1307
{
u8 secs,mins,hrs,day,date,month,year;
}time;
main()
{
time rtc;
init_lcd();
puts_lcd("initialize rtc");
rtc.hrs=0x23;
rtc.mins=0x59;
rtc.secs=0x50;
while(1)
{
i2c_device_write(0xd0,0x02,rtc.hrs);
i2c_device_write(0xd0,0x01,rtc.mins);
i2c_device_write(0xd0,0x00,rtc.secs);
cmd_lcd(0xc0);
putc_lcd((rtc.hrs/16)+48);
putc_lcd((rtc.hrs%16)+48);
putc_lcd('.');
cmd_lcd(0xc3);
putc_lcd((rtc.mins/16)+48);
putc_lcd((rtc.mins%16)+48);
putc_lcd('.');
cmd_lcd(0xc6);
putc_lcd((rtc.hrs/16)+48);
putc_lcd((rtc.hrs/16)+48);
}
}
