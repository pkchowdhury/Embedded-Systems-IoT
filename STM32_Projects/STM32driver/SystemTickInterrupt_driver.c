
// #include "stm32f4xx.h"
// #include "stm32f401xc.h"                  // Device header
// #include "stm32f4xx_UART.h"
// #include "stm32f4xx_Delay.h"
// #include <string.h>
// #include "stdbool.h"
// #include "stdio.h"


// //configure sysTick interrupt to toggle LED
// //at 1 Hz, system clock at 16 Mhz
// int main(void)
// {	
// 	__disable_irq(); //disable global interrupt

// 	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
// 	GPIOA->MODER |= GPIO_MODER_MODE5_0; //set PA5 to output mode

// 	SysTick->LOAD = 16000000 -1; //system clock 16 MHz
// 	SysTick->VAL = 0;
// 	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;

// 	__enable_irq(); //enable global interrupt

// 	while (1){

// 	}
	
// }

// void SysTick_Handler(void){
// 	GPIOA->ODR ^= 1 << 5;
// }


