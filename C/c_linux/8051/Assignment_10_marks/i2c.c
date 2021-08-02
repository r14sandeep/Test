#include<reg51.h>
#include"types.h"
#include"delay.h"
#include"i2c.h"

sbit scl=P2^4;
sbit sda=P2^5;

void i2c_start(void)
{
	scl=0;
	sda=1;
	scl=1;
	sda=0;
}

void i2c_stop(void)
{
	scl=0;
	sda=0;
	scl=1;
	sda=1;
}

void i2c_write(u8 dat)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		scl=0;
		sda=(dat>>(7-i))&1;
		scl=1;
	}
}

u8 i2c_read(void)
{
	u8 i;
	u8 buff=0;
	for(i=0;i<8;i++)
	{
		scl=0;
		scl=1;
		if(sda)
			buff|=0x80>>i;
	}
	return buff;
}

void i2c_ack(void)
{
	scl=0;
	sda=1;
	scl=1;
	while(sda);	
}

void i2c_noack(void)
{
	scl=0;
	sda=1;
	scl=1;
}

void i2c_device_write(u8 slaveaddr,u8 buffaddr,u8 dat)
{
	i2c_start();
	i2c_write(slaveaddr);
	i2c_ack();
	i2c_write(buffaddr);
	i2c_ack();
	i2c_write(dat);
	i2c_ack();
	i2c_stop();
	delay_ms(10);
}

u8 i2c_device_read(u8 slaveaddr,u8 buffaddr)
{
	u8 buff;
	i2c_start();
	i2c_write(slaveaddr);
	i2c_ack();
	i2c_write(buffaddr);
	i2c_ack();
	i2c_start();
	i2c_write(slaveaddr|1);
	i2c_ack();
	buff=i2c_read();
	i2c_noack();
	i2c_stop();
	return buff;
}
