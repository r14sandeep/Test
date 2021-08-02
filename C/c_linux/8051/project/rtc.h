#ifndef __RTC_H__
#define __RTC_H__
//#include"types.h"
typedef struct ds1307
{
unsigned char secs,mins,hrs;
}time;
extern unsigned char set_hours(void);
extern unsigned char set_mins(void);
extern unsigned char set_secs(void);
//extern void read_rtc(void);
extern void rtc_time(void);
#endif
