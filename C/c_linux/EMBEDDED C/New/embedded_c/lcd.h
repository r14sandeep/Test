#ifndef __LCD_H__
#define __LCD_H__
#include"types.h"
extern void delay_ms(u8);
extern void write_lcd(u8);
extern void putc_lcd(u8);
extern void cmd_lcd(u8);
extern void puts_lcd(u8 *);
extern void init_lcd(void);
extern void u16_lcd(u16);
extern void s16_lcd(s16);
extern void build_cgram(u8 *,u8);
extern void float_lcd(float);
#endif


