#ifndef shift_h
#define shift_h

extern void _74hc164_tx1(unsigned char d);	//used for shift register1
extern void _74hc164_tx2(unsigned char d);	//used for shift register2
extern void _74hc164_tx3(unsigned char d);	//used for shift register3
extern void _74hc164_tx4(unsigned char d);	//used for shift register4
extern void tx(unsigned char d,int sel);

#endif
