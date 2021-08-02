#ifndef __RTC_H__
#define __RTC_H__
#include"types.h"
typedef struct ds1307
{
u8 secs,mins,hrs;
}time;
extern u8 set_hours(void);
extern u8 set_mins(void);
extern u8 set_secs(void);
extern void read_rtc(void);
#endif
