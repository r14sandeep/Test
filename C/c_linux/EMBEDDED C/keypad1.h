#ifndef __KEYPAD_H__
#define __KEYPAD_H__
#include"types.h"
//extern s16 count;
extern void init_rows(void);
extern void init_cols(void);
extern bit colscan(void);
extern u8 keyscan(void);
extern void delay_ms(u16);
extern void dispi_4_mux_segs(u16);
#endif