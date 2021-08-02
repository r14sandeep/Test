#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include"types.h"

extern void init_rows(void);
extern void init_cols(void);
extern bit colscan(void);
extern u8 keyscan(void);
extern u8 keyscan2(void);
extern u8 get_row(void);
extern u8 get_col(void);

#endif
