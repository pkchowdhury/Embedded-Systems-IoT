
// #include "stm32f4xx.h"
// #include "stm32f401xc.h"                  // Device header
// #include "stm32f4xx_UART.h"
// #include "stm32f4xx_Delay.h"
// #include <string.h>
// #include "stdbool.h"
// #include "stdio.h"
// int data;
// double voltage;
// double celsius;
// //configure ADC Ch1
                      
// int main(void)
// {	
// 	//Serial2 Init
// 	Serial2_Begin(9600);
	

// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

// 	//TIM2 
// 	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //TIM2 Enable
// 	TIM2->PSC = 1600 -1;
// 	TIM2->ARR = 10000 -1;
// 	TIM2->CNT = TIM_CNT_CNT_Pos;
// 	TIM2->CCMR1 = TIM_CCMR1_OC2PE | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
// 	TIM2->CCER = TIM_CCER_CC2E_Msk;
// 	TIM2->CCR2 = 50-1;
// 	TIM2->CR1 = TIM_CR1_CEN;

// 	//ADC
// 	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //ADC1 Enable clock
// 	ADC->CCR |= 0x00800000; //ADC_CCR_TSVREFE; // Temp sensor and Vref init enable 
// 	ADC->CCR &=~ 0x00400000; //ADC_CCR_VBATE; // VBATE is disabled for Temp sensor
	
// 	ADC1->SMPR1 = 0x04000000; //ADC_SMPR1_SMP18_2; //sampling time minimum 10us
// 	ADC1->SQR3 = 18; //ADC_SQR3_SQ4_3; //ch 18 is active for temp sensor conversion
// 	ADC1->CR2 = 0x13000000; //ADC_CR2_EXTSEL_0 | ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_3; //disable adc
// 	ADC1->CR2 |= ADC_CR2_ADON_Msk; //enable ADC


	
// 	while (1){
// 		while(!(ADC1->SR)){}
// 		data = ADC1->DR;
// 		voltage = (double)data/4095*3.3;
// 		celsius = (voltage - 0.76)/ 0.0025+25;
// 		Serial2_println("Stm32f4xx_Temp: ");
// 		Serial2_println("%.2f\260C\r\n", celsius);
// 	}
	
// }



