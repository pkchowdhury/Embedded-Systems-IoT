//The Start Bit is always zero (always single bit)
//The stop bit is always 1 (Either single or double bit)

#include "stm32f4xx.h"
#include "stm32f401xc.h"                   // Device header
#include "stm32f4xx_UART.h"
#include "stm32f4xx_Delay.h"
#include <string.h>
#include "modem.h"

void modem(void)
{
	Serial1_Begin(115200);
	//Serial2_Begin(115200);
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= 1 << 12;
	
	GPIOA->ODR	= (1 << 6); 
	_delay_ms(1000);
	
	GPIOA->ODR = (0 << 6);
	_delay_ms(5000);
	
	
	char* str = "{\"id\":69}";
	unsigned int m = 0;
	m = strlen(str);
	while(1)
	{ 		

		Serial1_println("AT\r\n");		
		_delay_ms(10);
					
		Serial1_println("AT+CSQ\r\n");
		_delay_ms(500);
		
		Serial1_println("AT+CPIN?\r\n");
		_delay_ms(500);

		Serial1_println("AT+COPS?\r\n");
		_delay_ms(500);
			
		Serial1_println("AT+CREG=1\r\n");
		_delay_ms(500);

		Serial1_println("AT+CREG?\r\n");
		_delay_ms(500);

		Serial1_println("AT+CGMI\r\n");
		_delay_ms(10);

		Serial1_println("AT+CNMP=2\r\n");
		_delay_ms(10);

		Serial1_println("AT+HTTPINIT\r\n");
		_delay_ms(10000);
			
		//API Address
		Serial1_println("AT+HTTPPARA=\"URL\",\"https://thinkiot.com.bd/api/v1/O5l4owYcOT8cbLa7QXMe/telemetry\"\r\n"); //Server address
		_delay_ms(10);
			
		Serial1_println("AT+HTTPPARA=\"CONTENT\",\"application/json\"\r\n");
		_delay_ms(10);

		//String length 
		Serial1_println("AT+HTTPDATA=%d,10000\r\n", m);
		_delay_ms(10000);

		//Send the data	
		Serial1_println(str);
		_delay_ms(1000);
		
		Serial1_println("AT+HTTPACTION=1\r\n");
		_delay_ms(1000);
		
		Serial1_println("AT+HTTPTERM\r\n");
		_delay_ms(500);
	
	}	
}

