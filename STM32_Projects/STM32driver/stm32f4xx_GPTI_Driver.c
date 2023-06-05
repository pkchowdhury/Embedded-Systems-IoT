
// #include "stm32f4xx.h"
// #include "stm32f401xc.h"                  // Device header
// #include "stm32f4xx_UART.h"
// #include "stm32f4xx_Delay.h"
// #include <string.h>
// #include "stdbool.h"
// #include "stdio.h"


// //configure TIM2 to toggle LED
// //at 1 Hz, system clock at 16 Mhz
// int main(void)
// {	
// 	__disable_irq(); //disable global interrupt

// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
// 	GPIOA->MODER |= GPIO_MODER_MODE5_0; //set PA5 to output mode

// 	//TIM2
// 	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //TIM2 Enable
// 	TIM2->PSC = 16000 -1;
// 	TIM2->ARR = 1000 -1;
// 	TIM2->CR1 = TIM_CR1_CEN; //Counter Register 1 Enable
// 	TIM2->DIER |= TIM_DIER_UIE; //update Interrupt Enable

// 	NVIC_EnableIRQ(TIM2_IRQn);

// 	__enable_irq(); //enable global interrupt

// 	while (1){

// 	}
	
// }

// void TIM2_IRQHandler(void){
// 	TIM2->SR = 0;
// 	GPIOA->ODR ^= 1 << 5;
// }


