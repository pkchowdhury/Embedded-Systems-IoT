
#include "stm32f4xx.h"
#include "stm32f401xc.h" 
#include "stm32f4xx_UART.h"
#include "stm32f4xx_Delay.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

#define DEBUG_UART1 USART1
#define DEBUG_UART2 USART2

void Serial2_Begin(unsigned int Baud_Rate)
{
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	
	//Alternate Funtion 7 is USART2 (Section 8.3.2 figure 17)
	//Activate Alternate Functions for GPIO and AHB bus for PORTA
	//PA2 : USART2 Tx & PA3 : USART2 Rx 
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODE2_1|GPIO_MODER_MODE3_1;
	GPIOA->AFR[0] |= GPIO_AFRL_AFRL2_2|GPIO_AFRL_AFRL2_1|GPIO_AFRL_AFRL2_0; //Alternate Function 7 is set for PA2
	GPIOA->AFR[0] |= GPIO_AFRL_AFRL3_2|GPIO_AFRL_AFRL3_1|GPIO_AFRL_AFRL3_0; //Alternate Function 7 is set for PA3

	USART2->BRR |= 16000000/Baud_Rate; //9600 at 8MHz
	//USART2->BRR |= 16000000/115200;
	USART2->CR1 |= USART_CR1_TE|USART_CR1_RE;  //Transmission and reception Enabled
	USART2->CR1 |= USART_CR1_UE;               //USART Enabled 
	
}

int Serial2_write( uint16_t data){
	
	while(!(USART2->SR & USART_SR_TXE)){}
	USART2->DR = (data &(uint16_t)0x01FF);
	return USART2->DR;
}

uint16_t Serial2_read(void){
	while(!(USART2->SR & USART_SR_RXNE)){} //wait until char arrives
	return (USART2->DR & (uint16_t)0x01FF);
}

// void Serial2_println(char *data)
// {
// 	unsigned int temp;
// 	for(temp=0;temp<=strlen(data)-1;temp++)
// 	{
// 		Serial2_write(data[temp]);
// 	}
// 	Serial2_write(13); //CR
// 	Serial2_write(10); //LF
// }


///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

void Serial1_Begin(unsigned int Baud_Rate)
{
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	GPIOA->MODER |= GPIO_MODER_MODE9_1|GPIO_MODER_MODE10_1;
	GPIOA->AFR[1] |= GPIO_AFRH_AFRH1_2|GPIO_AFRH_AFRH1_1|GPIO_AFRH_AFRH1_0; //Alternate Function 7 is set for PA9
	GPIOA->AFR[1] |= GPIO_AFRH_AFRH2_2|GPIO_AFRH_AFRH2_1|GPIO_AFRH_AFRH2_0; //Alternate Function 7 is set for PA3
	
	USART1->BRR |= 16000000/Baud_Rate;         //9600 at 8MHz 
	USART1->CR1 |= USART_CR1_TE|USART_CR1_RE;  //Transmission and reception Enabled
	USART1->CR1 |= USART_CR1_UE;               //USART Enabled 
	//_delay_ms(100);
}

void Serial1_write( uint16_t data){
	
	while(!(USART1->SR & USART_SR_TXE)){}
	USART1->DR = (data &(uint16_t)0x01FF);
}

uint16_t Serial1_read(void){
	while(!(USART1->SR & USART_SR_RXNE)){} //wait until char arrives
	return (USART1->DR & (uint16_t)0x01FF);
}

// void Serial1_println(char *data)
// {
// 	unsigned int temp;
// 	for(temp=0;temp<=strlen(data)-1;temp++)
// 	{
// 		Serial1_write(data[temp]);
// 	}
// 	Serial1_write(13); //CR
// 	Serial1_write(10); //LF
// }

void Serial2_println(char *msg, ...)
{
	char buff[80];
	
	#ifdef DEBUG_UART2
	va_list args;
	va_start(args, msg);
	vsprintf(buff, msg, args);
	
	for(unsigned int i =0; i < strlen(buff); i++){
		USART2-> DR = buff[i];
		while(!(USART2->SR & USART_SR_TXE));
	}
	#endif
	
}

void Serial1_println(char *msg, ...)
{
	char buff[80];
	
	#ifdef DEBUG_UART1
	va_list args;
	va_start(args, msg);
	vsprintf(buff, msg, args);
	
	for(unsigned int i =0; i < strlen(buff); i++){
		USART1-> DR = buff[i];
		while(!(USART1->SR & USART_SR_TXE));
	}
	
	#endif
	
}
