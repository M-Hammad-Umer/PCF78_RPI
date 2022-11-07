#include <stdio.h>
#include <stdint.h>
#include <stdint.h>


//Address
#define PCF8574_BASE_ADDRESS 0x20


// Pin Macros of PCF8574
#define P0 0
#define P1 1
#define P2 2
#define P3 3
#define P4 4
#define P5 5
#define P6 6
#define P7 7



// General Macros
#define HIGH 1
#define LOW 0
#define SET HIGH
#define RESET LOW


void PCF8574_Pin_Write(uint8_t PinNumber, uint8_t Value);
uint8_t PCF8574_Pin_Read(uint8_t PinNumber);