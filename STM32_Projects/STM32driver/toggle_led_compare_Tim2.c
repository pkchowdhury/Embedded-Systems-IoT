// //The Start Bit is always zero (always single bit)
// //The stop bit is always 1 (Either single or double bit)

// #include "stm32f4xx.h"
// #include "stm32f401xc.h"                  // Device header
// #include "stm32f4xx_UART.h"
// #include "stm32f4xx_Delay.h"
// #include <string.h>
// #include "stdbool.h"
// #include "stdio.h"

// int main(void)
// {
	
// 	Serial2_Begin(9600);

// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
//     //GPIOA->MODER |= 1 << 10; // PA5 to Output Mode
// 	GPIOA->MODER |= GPIO_MODER_MODE5_1; //Set PA5 to ALternative function
// 	GPIOA->AFR[0] |= GPIO_AFRL_AFRL5_0; //Set AF1 for PA5 (TIM1/TIM2)
	 
// 	//Timer Config
// 	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //TIM2 Enable
// 	TIM2->PSC = 1600 -1; // 16000000 div by 1600 = 10000
// 	TIM2->ARR = 1000 - 1; // 10000 div by 10000 = 1 Hz
// 	TIM2->CCMR1 = 0x30; //TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_1; //set output to toggle on match
// 	TIM2->CCR1 = 0; //set the match value
// 	TIM2->CCER |= 1; //Enable ch1 compare mode
// 	TIM2->CNT = 0; //Clear the timer Counter
// 	TIM2->CR1 = 1; //Enable TIM2

//     while(1){

// 		// while(!(TIM2->SR &1)){}
// 		// TIM2->SR &=~1;
// 		// GPIOA->ODR ^= 1 << 5;

//     }	
// }

