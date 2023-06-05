// //The Start Bit is always zero (always single bit)
// //The stop bit is always 1 (Either single or double bit)

// #include "stm32f4xx.h"
// #include "stm32f401xc.h"                  // Device header
// #include "stm32f4xx_UART.h"
// #include "stm32f4xx_Delay.h"
// #include <string.h>
// #include "stdbool.h"
// #include "stdio.h"
// int period;
// float freq;
// int main(void)
// {
	
// 	Serial2_Begin(9600);
// 	int last_value = 0;
// 	int current_value = 0;
// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
// 	GPIOA->MODER |= GPIO_MODER_MODE5_1; //Set PA5 to ALternate function
// 	GPIOA->AFR[0] |= GPIO_AFRL_AFRL5_0; //Set AF1 for PA5 (TIM1/TIM2) Ch1
	 
// 	//Timer Config for compare mode
// 	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //TIM2 Enable
// 	TIM2->PSC = 1600 -1; // 16000000 div by 1600 = 10000
// 	TIM2->ARR = 10000 - 1; // 10000 div by 10000 = 1 Hz
// 	TIM2->CCMR1 = 0x30; //TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_1; //set output to toggle on match
// 	TIM2->CCR1 = 0; //set the match value
// 	TIM2->CCER |= TIM_CCER_CC1E; //Enable ch1 compare mode
// 	TIM2->CNT = 0; //Clear the timer Counter
// 	TIM2->CR1 = TIM_CR1_CEN; //Enable TIM2

// 	//Configure PA6 as input of TIM3 Ch1

// 	GPIOA->MODER |= GPIO_MODER_MODE6_1; //set PA6 to alternate function
// 	GPIOA->AFR[0] |= GPIO_AFRL_AFRL6_1; // set AF2 for PA6 (TIM3) ch1

// 	//Timer Config for capture mode
// 	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; //TIM3 Enable
// 	TIM3->PSC = 16000 -1; // 16000000 div by 16000 = 1000
// 	TIM3->CCMR1 = 0x41;  //set ch1 to capture at every edge
// 	TIM3->CCER |= TIM_CCER_CC1E; //Enable ch1 compare mode
// 	TIM3->CR1 = TIM_CR1_CEN; //Enable TIM3 for ch1

//     while(1){
// 		// Wait until the edge is captured
// 		while(!(TIM3->SR & 2)){} //until input edge is captured
// 		current_value = TIM3->CCR1;
// 		period = current_value - last_value;
// 		last_value = current_value;
// 		freq = 1000.0f/period;
// 		last_value = current_value;
//     }	
// }

