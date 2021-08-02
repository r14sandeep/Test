#include"delay.h"
//#include"types.h"
#include"rtc.h"
#include"i2c.h"
#include"dml.h"
#include"sipo.h"
#include<string.h>
//#include"i2c.h"
typedef struct ds
{
unsigned char secs,mins,hrs,day,date,month,year;
}ti;



void rtc_time(void)
{
ti rtc;
unsigned char buf[20];
//init_lcd();
//puts_lcd("initialize rtc");
rtc.hrs=0x17;
rtc.mins=0x59;
rtc.secs=0x50;
rtc.day=0x07;
rtc.month=0x12;
rtc.year=0x16;
rtc.date=0x30;
i2c_device_write(0xd0,0x02,rtc.hrs);
i2c_device_write(0xd0,0x01,rtc.mins);
i2c_device_write(0xd0,0x00,rtc.secs);
i2c_device_write(0xd0,0x03,rtc.day);
i2c_device_write(0xd0,0x05,rtc.month);
i2c_device_write(0xd0,0x06,rtc.year);
i2c_device_write(0xd0,0x04,rtc.date);
while(1)
{

rtc.hrs=i2c_device_read(0xd0,0x02);
rtc.mins=i2c_device_read(0xd0,0x01);
rtc.secs=i2c_device_read(0xd0,0x00);
rtc.day=i2c_device_read(0xd0,0x03);
rtc.month=i2c_device_read(0xd0,0x05);
rtc.year=i2c_device_read(0xd0,0x06);
rtc.date=i2c_device_read(0xd0,0x04);

buf[0]=(rtc.hrs/16)+48;
buf[1]=(rtc.hrs%16)+48;
buf[2]=':';
buf[3]=(rtc.mins/16)+48;
buf[4]=(rtc.mins%16)+48;
buf[5]=':';
buf[6]=(rtc.secs/16)+48;
buf[7]=(rtc.secs%16)+48;
scroll_string("   TIME:",40);
scroll_string(buf,40);//(rtc.hrs/16)+48


if(rtc.day==1)
strcpy(buf,"SUNDAY");

if(rtc.day==2)
strcpy(buf,"MONDAY");

if(rtc.day==3)
strcpy(buf,"TUESDAY");

if(rtc.day==4)
strcpy(buf,"WEDNESDAY");


if(rtc.day==5)
strcpy(buf,"THURSDAY");


if(rtc.day==6)
strcpy(buf,"FRIDAY");

if(rtc.day==7)
strcpy(buf,"SATURDAY");

scroll_string("DAY:",40);
scroll_string(buf,40);










/*scroll_string(&buf,40);//(rtc.hrs%16)+48
scroll_string('.',40);
//cmd_lcd(0xc3);
scroll_string(&buf,40);//(rtc.mins/16)+48
scroll_string(&buf,40);//(rtc.mins%16)+48
scroll_string('.',40);
//cmd_lcd(0xc6);
scroll_string(&buf,40);//&(rtc.hrs/16)+48
scroll_string(&buf,40);//&(rtc.hrs/16)+48*/
}
}
