#include <stdio.h>
#include <stdint.h>
#include "pcf8574.h"
#include <fcntl.h>
#include <unistd.h>
#include <pigpio.h>


/*
 *  This Library is designed fo multiple PCF8574, pin o. 0 is the 0th bit of 1st(000) PCF8574, 
 *	8 being 0th bit of 2nd(001) 
 *  16 being 0th bit of 2nd(010)
 *	upto 63.
 *  
*/ 
 
int main()
{
if(gpioInitialise() < 0)
{
	printf("i2c not initialized\n");
}
	while(1)
	{

		uint8_t r = PCF8574_Pin_Read(24);
		printf("result =  %x\n" ,r);
		gpioDelay(10000);

	}
	
}