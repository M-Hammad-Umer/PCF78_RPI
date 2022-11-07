
#include <stdio.h>
#include <stdint.h>
#include <pigpio.h>
#include <fcntl.h>
#include <unistd.h>
#include "pcf8574.h"



static uint8_t tempReg = 0x00;

void PCF8574_Pin_Write(uint8_t PinNumber, uint8_t Value)
{
	uint8_t PCFAddr = PCF8574_BASE_ADDRESS + (PinNumber/8);
	PinNumber = PinNumber % 8;

	uint8_t fd = i2cOpen(1, PCFAddr, 0);
		tempReg = 0x00;
		if(Value == HIGH)
		{
			tempReg |= (1 << PinNumber);
			i2cWriteByte(fd , tempReg);
			
		}
		else if(Value == LOW)
		{
			tempReg &= ~(1 << PinNumber);
			i2cWriteByte(fd , tempReg);
		}
}


uint8_t PCF8574_Pin_Read(uint8_t PinNumber)
 {
	uint8_t PCFAddr = PCF8574_BASE_ADDRESS + (PinNumber/8);
	uint8_t fd = i2cOpen(1, PCFAddr, 0);
	PinNumber = PinNumber % 8;
	printf("Addess = %x , pin = %d\n", PCFAddr , PinNumber);
	uint8_t data = i2cReadByte(fd);
	i2cClose(fd);
	return((data >> PinNumber) & 0x01);
}
