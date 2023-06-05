// //The Start Bit is always zero (always single bit)
// //The stop bit is always 1 (Either single or double bit)

// #include "stm32f4xx.h"
// #include "stm32f401xc.h"                  // Device header
// #include "stm32f4xx_UART.h"
// #include "stm32f4xx_Delay.h"
// #include <string.h>
// #include "stdbool.h"
// #include "stdio.h"
// //Led: PA5
// //push button: PC14, PB10
// volatile int pc14_counter = 0;
// volatile int pb10_counter =0;
// int main(void)
// {
// 	__disable_irq();
// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //port A enable
// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; //port C enable
// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; //port B enable
// 	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; //enable syscfg clock

// 	GPIOA->MODER |= GPIO_MODER_MODE5_0; 

// 	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR14_0; //pull-up internal resistor
// 	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI14_PC; //select Port C for EXTI14
// 	EXTI->IMR |= EXTI_IMR_MR14; //unmask EXTI14
// 	EXTI->FTSR |= EXTI_FTSR_TR14; //select falling edge trigger
	
// 	GPIOB->PUPDR |= GPIO_PUPDR_PUPDR10_0; //pull-up internal resistor

// 	SYSCFG-> EXTICR[2] = SYSCFG_EXTICR3_EXTI10_PB;

// 	EXTI->IMR |= EXTI_IMR_MR10;
// 	EXTI->FTSR |= EXTI_FTSR_TR10;

// 	NVIC_EnableIRQ(EXTI15_10_IRQn);

// 	__enable_irq();	

// 	while (1)
// 	{
// 	}
	
// }

// void EXTI15_10_IRQHandler(void){

// 	//pc14
// 	if(EXTI->PR == EXTI_PR_PR14){
// 		GPIOA->BSRR =  GPIO_BSRR_BS5;
// 		SysTickDelayMs(100);
// 		GPIOA->BSRR =  GPIO_BSRR_BR5;
// 		SysTickDelayMs(100);
// 		pc14_counter++;
// 		EXTI->PR = EXTI_PR_PR14; //clear interrupt pending flag
// 	}
// 	//pb10
// 	else if(EXTI->PR == EXTI_PR_PR10){
// 		GPIOA->BSRR =  GPIO_BSRR_BS5;
// 		SysTickDelayMs(100);
// 		GPIOA->BSRR =  GPIO_BSRR_BR5;
// 		SysTickDelayMs(100);
// 		GPIOA->BSRR =  GPIO_BSRR_BS5;
// 		SysTickDelayMs(100);
// 		GPIOA->BSRR =  GPIO_BSRR_BR5;
// 		SysTickDelayMs(100);
// 		pb10_counter++;
// 		EXTI->PR = EXTI_PR_PR10; //clear interrupt pending flag
// 	}
// }

