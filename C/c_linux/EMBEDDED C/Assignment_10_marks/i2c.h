#ifndef __I2C_H__
#define __I2C_H__

#include"types.h"

extern void i2c_start(void);
extern void i2c_write(u8);
extern void i2c_slaveack(void);
extern void i2c_stop(void);
extern void i2c_noack(void);
extern u8 i2c_read(void);
extern void i2c_device_write(u8,u8,u8);
extern u8 i2c_device_read(u8,u8);

#endif
