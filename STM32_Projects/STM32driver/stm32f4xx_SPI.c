//SPI1 Pins
//MOSI PA7
//SCK PA5
//SS PA4

//SPI2 Pins
//RES: PB5
//DC: PB4
//CS: PB3
#include "stm32f4xx.h"
#include "stm32f401xc.h"                  // Device header
#include "stm32f4xx_SPI.h"

void SPI1_Init(void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //Enable Clock on GPIOA
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

	GPIOA->MODER |= GPIO_MODER_MODE7_1 | GPIO_MODER_MODE5_1;
	GPIOA->AFR[0] |= GPIO_AFRL_AFRL5_0 | GPIO_AFRL_AFRL5_2; // AF5 for PA4, PA5, PA7
	GPIOA->MODER |= GPIO_MODER_MODE4_0; // set PA4 to output mode

	//SPI Confg
	SPI1->CR1 = SPI_CR1_BR_1; // set baud rate for 8 bit data frame
	SPI1->CR2 = SPI_CR2_RXDMAEN; 
	SPI1->CR1 |= SPI_CR1_SPE; //SPI Enable

}
void SPI1_write_data(unsigned char data){
	while(!(SPI1->SR & SPI_SR_TXE)){} //wait until transmit buffer is empty
	GPIOA->BSRR = GPIO_BSRR_BR4; //reset PA4
	SPI1->DR = data; // write data on SPI
	while(SPI1->DR & SPI_DR_DR){} //wait for transmission completion
	GPIOA->BSRR = GPIO_BSRR_BS4; //set PA4
}

