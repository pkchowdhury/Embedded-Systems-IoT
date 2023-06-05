#include "stm32f4xx.h"
#include "stm32f401xc.h"                  // Device header
#include "stm32f4xx_UART.h"
#include "stm32f4xx_Delay.h"
#include "stm32f4xx_SPI.h"
#include <string.h>
#include "stdbool.h"
#include "stdio.h"
#include "E22_Lora.h"
//Lora pins
// M0_230 PB6
// M1_230 PB5
// RX_230 PA9
// TX_230 PA10
// AUX_230 PB4


void loraInit(void)
{	
    Serial1_Begin(9600);
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; //Enable Clock

    //Set PB4, PB5, PB6 as output
    GPIOB->MODER |= GPIO_MODER_MODE5_0;
    GPIOB->MODER |= GPIO_MODER_MODE4_0; 
    GPIOB->MODER |= GPIO_MODER_MODE6_0;
    // loraMode(3); //Deep Sleep Mode
    // SysTickDelayMs(100);

    // loraMode(0); // Normal Mode
    SysTickDelayMs(100);
}

void setDataSetting(void){
   
    loraMode(2);// Configuration Mode

    Serial1_write(11000000); //Write Mode
    Serial1_write(00); // starting address
    Serial1_write(0111); //7 parameter
    Serial1_write(1011); //ADDH
    Serial1_write(10110); //ADDL
    Serial1_write(00); //NETID
    Serial1_write(01100010); // 011 00 000 (9600 8N1 0.3K)
    Serial1_write(00); //00 for 30dbm, 01 for 27dbm
    Serial1_write(1); //OT channel
    Serial1_write(01000011);  

    SysTickDelayMs(500);
}
char sendData(char data){

    loraMode(0); //Normal Mode

    SysTickDelayMs(500);

    Serial1_write(00001011); //ADDH
    Serial1_write(00010110); //ADDL
    Serial1_write(00000001); //OT channel
    Serial1_write(data); //data

    SysTickDelayMs(100);

    return data;
    
}


void loraMode(int modeType){
    if(modeType == 0){ 
    //Initiate Normal Mode on LoRa
    GPIOB->ODR = 0 << 5; //set M0 low
    GPIOB->ODR = 0 << 6; //set M1 low
    }
    else if(modeType == 1){
        
    //Initiate WOR Mode on LoRa
    GPIOB->ODR = 1 << 5; //set M0 low
    GPIOB->ODR = 0 << 6; //set M1 low
    }
    else if(modeType == 2){
        
    //Initiate Configure Mode on LoRa
    GPIOB->ODR = 0 << 5; //set M0 low
    GPIOB->ODR = 1 << 6; //set M1 low
    }
    else if(modeType == 3){
        
    //Initiate Deep Sleep Mode on LoRa
    GPIOB->ODR = 1 << 5; //set M0 low
    GPIOB->ODR = 1 << 6; //set M1 low
    }

}

const unsigned char r_crctable[256] = { //reversed, 8-bit, poly=0x07
  0x00, 0x91, 0xE3, 0x72, 0x07, 0x96, 0xE4, 0x75,
  0x0E, 0x9F, 0xED, 0x7C, 0x09, 0x98, 0xEA, 0x7B,
  0x1C, 0x8D, 0xFF, 0x6E, 0x1B, 0x8A, 0xF8, 0x69,
  0x12, 0x83, 0xF1, 0x60, 0x15, 0x84, 0xF6, 0x67,
  0x38, 0xA9, 0xDB, 0x4A, 0x3F, 0xAE, 0xDC, 0x4D,
  0x36, 0xA7, 0xD5, 0x44, 0x31, 0xA0, 0xD2, 0x43,
  0x24, 0xB5, 0xC7, 0x56, 0x23, 0xB2, 0xC0, 0x51,
  0x2A, 0xBB, 0xC9, 0x58, 0x2D, 0xBC, 0xCE, 0x5F,
  0x70, 0xE1, 0x93, 0x02, 0x77, 0xE6, 0x94, 0x05,
  0x7E, 0xEF, 0x9D, 0x0C, 0x79, 0xE8, 0x9A, 0x0B,
  0x6C, 0xFD, 0x8F, 0x1E, 0x6B, 0xFA, 0x88, 0x19,
  0x62, 0xF3, 0x81, 0x10, 0x65, 0xF4, 0x86, 0x17,
  0x48, 0xD9, 0xAB, 0x3A, 0x4F, 0xDE, 0xAC, 0x3D,
  0x46, 0xD7, 0xA5, 0x34, 0x41, 0xD0, 0xA2, 0x33,
  0x54, 0xC5, 0xB7, 0x26, 0x53, 0xC2, 0xB0, 0x21,
  0x5A, 0xCB, 0xB9, 0x28, 0x5D, 0xCC, 0xBE, 0x2F,
  0xE0, 0x71, 0x03, 0x92, 0xE7, 0x76, 0x04, 0x95,
  0xEE, 0x7F, 0x0D, 0x9C, 0xE9, 0x78, 0x0A, 0x9B,
  0xFC, 0x6D, 0x1F, 0x8E, 0xFB, 0x6A, 0x18, 0x89,
  0xF2, 0x63, 0x11, 0x80, 0xF5, 0x64, 0x16, 0x87,
  0xD8, 0x49, 0x3B, 0xAA, 0xDF, 0x4E, 0x3C, 0xAD,
  0xD6, 0x47, 0x35, 0xA4, 0xD1, 0x40, 0x32, 0xA3,
  0xC4, 0x55, 0x27, 0xB6, 0xC3, 0x52, 0x20, 0xB1,
  0xCA, 0x5B, 0x29, 0xB8, 0xCD, 0x5C, 0x2E, 0xBF,
  0x90, 0x01, 0x73, 0xE2, 0x97, 0x06, 0x74, 0xE5,
  0x9E, 0x0F, 0x7D, 0xEC, 0x99, 0x08, 0x7A, 0xEB,
  0x8C, 0x1D, 0x6F, 0xFE, 0x8B, 0x1A, 0x68, 0xF9,
  0x82, 0x13, 0x61, 0xF0, 0x85, 0x14, 0x66, 0xF7,
  0xA8, 0x39, 0x4B, 0xDA, 0xAF, 0x3E, 0x4C, 0xDD,
  0xA6, 0x37, 0x45, 0xD4, 0xA1, 0x30, 0x42, 0xD3,
  0xB4, 0x25, 0x57, 0xC6, 0xB3, 0x22, 0x50, 0xC1,
  0xBA, 0x2B, 0x59, 0xC8, 0xBD, 0x2C, 0x5E, 0xCF
};

unsigned char CRC8(const unsigned char *input, int count) {
  unsigned char fcs = 0xFF;
  int i;
  for (i = 0; i < count; i++) {
    fcs = r_crctable[fcs ^ input[i]];
  }
  return (0xFF - fcs);
}
