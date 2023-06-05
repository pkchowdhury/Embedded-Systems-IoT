// prescaler TIM2->1600 - 1
// Auto Reload  Resister TIM2->ARR = 10000
// COntrol Res TIM2->CR1 = 1  enable/desable timer
// Status Res TIM2->SR & 1 check update interrupt flag
// capture compare res CCR1, CCR2, CCR4, CCR4  || timestamp = TIM2->CCR1
// Capture compare Mode res CCMR1/ CCMR2 TIM2-> CCMR1 = 0x41
// Capture/ Compare Enable Res TIM2->CCER = 1
// Control Res 2 Enable/Desable  ADC  ADC1->CR2 = 1

#include "stm32f4xx_Delay.h"
#include "stm32f4xx.h"
#include "stm32f401xc.h"                  // Device header

void _delay_ms(volatile int expected_delay)
{
	expected_delay = (F_CPU/15000)*expected_delay;
	volatile int delay_creation_loop;
	for(delay_creation_loop = 0; delay_creation_loop <= expected_delay; delay_creation_loop ++){}
}

void SysTickDelayMs(int n){

    //configure systick
    SysTick->LOAD = 16000; // Reload Number clock cycles/ms
    SysTick->VAL = 0; //clear current value register
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    for(int i=0; i<n; i++){
        //check if count flag is set
        while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0){}
    }
    SysTick->CTRL = 0;
}