/** compiler directives **/
#include<reg52.h>

/** user defined header files **/
#include"delay.h"
#include"dml.h"
#include"sipo.h"
#include"eeprom.h"
#include"rtc.h"


/** main function **/
int main()
{
	while(1)
	{
		//display_char("HELP",40);	//display 'B' character on sinngle dot matrix display
		//display_char('A',10);
		//scroll_string("   INDIA   ",30);
		//rtc_time();
		eeprom();
	}
	
}//main end



