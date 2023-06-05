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
	
// 	//Serial2_Begin(9600);
// 	int last_value = 0;
// 	int current_value = 0;
// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
// 	GPIOA->MODER |= GPIO_MODER_MODE5_1; //Set PA5 to ALternate function
// 	GPIOA->AFR[0] |= GPIO_AFRL_AFRL5_0; //Set AF1 for PA5 (TIM1/TIM2) Ch1
	 
// 	//Timer Config for compare mode
// 	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //TIM2 Enable
// 	TIM2->PSC = 10 -1; // 16000000 div by 10 = 1600000
// 	TIM2->ARR = 26667 - 1; // 1600000 div by 26667 = 59.999 Hz
// 	TIM2->CNT = 0; //Clear the timer Counter
// 	TIM2->CCMR1 = 0x60; //Enable PWM Mode
// 	TIM2->CCER |= TIM_CCER_CC1E; //Enable ch1 compare mode
// 	TIM2->CCR1 = 8889 - 1; //pulse width 1/3 rd the period
// 	TIM2->CR1 = TIM_CR1_CEN; //Enable TIM2

//     while(1){

//     }	
// }

