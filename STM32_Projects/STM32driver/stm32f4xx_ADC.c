// #include "stm32f4xx.h"
// #include "stm32f401xc.h"                  // Device header
// #include "stm32f4xx_UART.h"
// #include "stm32f4xx_Delay.h"
// #include <string.h>
// #include "stdbool.h"
// #include "stdio.h"
// int analogValue;

// //configure ADC Ch1
                      
// int main(void)
// {	
// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
// 	GPIOA->MODER |= GPIO_MODER_MODE1_Msk; //set PA1 to output mode

// 	//ADC
// 	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //ADC1 Enable
// 	ADC1->CR2 = ADC_CR2_ADON_Pos; //disable adc
// 	ADC1->SQR3 = ADC_SQR3_SQ1;
// 	ADC1->CR2 |= ADC_CR2_ADON_Msk; //enable ADC


// 	while (1){
// 		ADC1->CR2 |= ADC_CR2_SWSTART;
// 		while(!(ADC1->SR & ADC_SR_EOC)){}
// 		analogValue = ADC1->DR;
// 	}
	
// }
