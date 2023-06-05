
// #include "stm32f4xx.h"
// #include "stm32f401xc.h"                  // Device header
// #include "stm32f4xx_UART.h"
// #include "stm32f4xx_Delay.h"
// #include <string.h>
// #include "stdbool.h"
// #include "stdio.h"
// void ledplay(int value);
// int count = 0;
// int main(void)
// {	
// 	__disable_irq(); //disable global interrupt

// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
// 	GPIOA->MODER |= GPIO_MODER_MODE5_0; //set PA5 to output mode
// 	Serial2_Begin(9600);
// 	USART2->CR1 |= USART_CR1_RXNEIE; //enable Rx interrupt

// 	NVIC_EnableIRQ(USART2_IRQn); //enable interrupt request

// 	__enable_irq(); //enable global interrupt
// 	while (1)
// 	{
// 	}
	
// }

// void USART2_IRQHandler(void){
// 	char c;
// 	if(USART2->SR & USART_SR_RXNE_Msk){
// 		c =USART2->DR;
// 		ledplay(c);
// 		count++;
// 	}
// }
// void ledplay(int value){
// 	value %= 16;
// 	for(; value>0; value--){
// 		GPIOA->BSRR = 0x20; //turn on led
// 		SysTickDelayMs(100);
// 		GPIOA->BSRR = 0x00200000; // turn off led
// 		SysTickDelayMs(100);
// 	}
// 	SysTickDelayMs(400);
// }

