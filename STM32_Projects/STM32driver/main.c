#include "stm32f4xx.h"
#include "stm32f401xc.h"                  // Device header
#include "stm32f4xx_UART.h"
#include "stm32f4xx_Delay.h"
#include "stm32f4xx_SPI.h"
#include <string.h>
#include "stdbool.h"
#include "stdio.h"
#include "E22_Lora.h"


int main()
{	
	Serial1_Begin(9600);
	Serial2_Begin(9600);
	char a;
	loraMode(2);
	setDataSetting();
	SysTickDelayMs(1000);
	while (1)
	{
		Serial2_println("sending Data...\n");
		SysTickDelayMs(500);         
		loraMode(0);
		Serial2_write(Serial1_read());
		SysTickDelayMs(100);
		Serial1_write(Serial2_read());
	}
	
	

}
