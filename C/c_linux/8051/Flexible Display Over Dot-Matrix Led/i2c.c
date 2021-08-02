/** compiler directives **/
#include<reg52.h>

/** user defined header file **/
#include "delay.h"

/** I2C signals connection **/
sbit SCL = P3^7;
sbit SDA = P3^6;

/** start condition**/
void start()
{
//SDA high to low whenever SCL is high
	SCL=0;	//SCL is low
	SDA=1;	//SDA is high
	SCL=1;	//SCL is high
	SDA=0;	//SDA is low
}

/** stop condition **/
void stop()
{
//SDA low to high whenever SCL is high
	SCL=0;	//SCL is low
	SDA=0;	//SDA is low
	SCL=1;	//SCL is high
	SDA=1;	//SDA is high
}

/** waiting for ack from the slave**/
void ack()
{
	SCL=0;	//SCL is low
	SDA=1;	//SDA is high
	SCL=1;	//SCL is high
	while(SDA==1);//waiting for slave ack
}

/** no acknowledge while master is receiving the last byte **/
void noack()
{
	SCL=0;	//SCL is low
	SDA=1;	//SDA is high
	SCL=1;	//SCL is high
}

/** sending one byte process **/
void send_byte(unsigned char dat)
{
	//local variables declaration	
	unsigned char i;

	for(i=0;i<8;i++)	//loop for sending 8 bits (bit by bit through SDA)
	{
		SCL=0;	//SCL is low
		SDA = (dat&(0x80>>i))?1:0; //assign bit status to SDA line
		SCL=1;	//SCL is high 
	}	

}
/** receive one byte process **/
unsigned char receive_byte()
{
	//local variables declaration	
	unsigned char i,buff=0;

	for(i=0;i<8;i++)//loop for receiving 8 bits (bit by bit through SDA)
	{
		SCL=0;	//SCL is low
		SCL=1;	//SCL is high
		if(SDA)//if SDA is high
			buff |= (0x80>>i);//update bit status to buff variable
	}
	return buff;	//return the one byte which is received from slave memory

}

/** reading one byet from i2c device **/
unsigned char device_read(unsigned char sa,unsigned char addr)
{
	//local variables declaration	
	unsigned char buff;
	start();	//start condition
	send_byte(sa);//sending slave address on bus
	ack();	//waiting for acknowlegde from slave
	send_byte(addr);	//sending memory address
	ack();	//waiting for acknowlegde from slave
	start();	//restart condition
	send_byte(sa|1);	//sending slave address for read
	ack();	//waiting for acknowlegde from slave
	buff = receive_byte();	//reading one byte info from slave
	noack();	//sending no acknowledge
	stop();	//stop condition
	return buff;	//return received byte info from memory
}

/** write one byte into one memory location **/
void device_write(unsigned char sa,unsigned char addr,unsigned char dat)
{
	start();	//start condition
	send_byte(sa);	//sending slave address on bus
	ack();	//waiting for acknowlegde from slave
	send_byte(addr);
	ack();	//waiting for acknowlegde from slave
	send_byte(dat);
	ack();	//waiting for acknowlegde from slave
	stop();	//stop condition
	delay_ms(10);
}
