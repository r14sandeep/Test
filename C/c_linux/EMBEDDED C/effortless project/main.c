#include<reg52.h>
#include<string.h>

#include "mcp3204.h"
#include "lcd.h"
#include "delay.h"
#include "uart.h"

sbit device=P1^4;


extern unsigned char k,rec_buff[25];
extern bit r_flag;

float val;

void device_status(void);
void send_devicestatus(void);

main()
{
	init_lcd();
	uart_init();

	cmd_lcd(0x80);
	str_lcd("EFFORTLESS  CONTROL");
	cmd_lcd(0xc0);
	str_lcd("ADC Result:       ");
	cmd_lcd(0xd4);
	str_lcd("Device Status:     ");
	k=0;
	while(1)
	{
		device_status();

		if(r_flag)
		{
			cmd_lcd(0x94);
			str_lcd(rec_buff);
			delay_ms(300);
			cmd_lcd(0x94);
			str_lcd("                    ");
			r_flag = 0;
			k=0;
			if(strcmp(rec_buff,"INFO") == 0)	
			{
				device_status();
				send_devicestatus();
			}
			else if(strcmp(rec_buff,"BON") == 0)	
			{
				device = 0;
				device_status();
				send_devicestatus();
			}
			else if(strcmp(rec_buff,"BOFF") == 0)	
			{
				device = 1;
				device_status();
				send_devicestatus();
			}
			else
			{
				cmd_lcd(0x94);
				str_lcd("Invalid Message");
				delay_ms(300);
				cmd_lcd(0x94);
				str_lcd("                    ");
			}
		}
	}

}

void device_status()
{
	val = read_mcp3204(2);
	cmd_lcd(0xCC);
	float_lcd(val);
	str_lcd(" V ");	
	cmd_lcd(0xE3);
	if(val>1.0 && val <=5.0)	
		str_lcd("OFF");
	else
		str_lcd(" ON");	
	delay_ms(300);
}

void send_devicestatus()
{
	cmd_lcd(0x94);
	str_lcd("sending.............");
	delay_ms(300);
	if(val>1.0 && val <=5.0)
		uart_string("BOFF$");
	else
		uart_string("BON$");
	cmd_lcd(0x94);
	str_lcd("                    ");
}
