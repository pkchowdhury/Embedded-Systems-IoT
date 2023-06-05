////The Start Bit is always zero (always single bit)
////The stop bit is always 1 (Either single or double bit)

//#include "stm32f4xx.h"
//#include "stm32f401xc.h"                  // Device header
//#include "stm32f4xx_UART.h"
//#include "stm32f4xx_Delay.h"
//#include <string.h>
//#include "stdbool.h"
//#include "stdio.h"
////Led: PA5
////push button: PC13
//int counter = 0;
//void EXTI15_10_IRQHandler(void);
//int main(void)
//{
//	__disable_irq();
//	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //port A enable
//	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; //port C enable
//	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; //enable syscfg clock

//	GPIOA->MODER |= GPIO_MODER_MODE5_0;
//	SYSCFG->EXTICR[3] = SYSCFG_EXTICR4_EXTI13_PC; //select Port C for EXTI13
//	EXTI->IMR |= EXTI_IMR_MR13; //unmask EXTI13
//	EXTI->FTSR |= EXTI_FTSR_TR13; //select falling edge trigger
//	
//	NVIC_EnableIRQ(EXTI15_10_IRQn);

//	__enable_irq();	

//	while (1)
//	{
//	}
//	
//}

//void EXTI15_10_IRQHandler(void){
//	GPIOA->BSRR =  GPIO_BSRR_BS5;
//	SysTickDelayMs(400);
//	GPIOA->BSRR =  GPIO_BSRR_BR5;
//	SysTickDelayMs(400);
//	GPIOA->BSRR =  GPIO_BSRR_BS5;
//	SysTickDelayMs(400);
//	GPIOA->BSRR =  GPIO_BSRR_BR5;
//	SysTickDelayMs(400);
//	counter++;

//	EXTI->PR = EXTI_PR_PR13;
//}

