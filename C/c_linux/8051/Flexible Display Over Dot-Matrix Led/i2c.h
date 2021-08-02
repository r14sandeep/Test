#ifndef i2c_h
#define i2c_h

extern void start();
extern void stop();
extern void ack();
extern void noack();
extern void send_byte(unsigned char);
extern unsigned char receive_byte();
extern unsigned char device_read(unsigned char,unsigned char);
extern void device_write(unsigned char,unsigned char,unsigned char);

#endif
