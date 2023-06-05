
//PA2 : USART2 Tx & PA3 : USART2 Rx
void Serial2_Begin(unsigned int Baud_Rate);      //To enable UART2
int Serial2_write( uint16_t data);         //To print a character
uint16_t Serial2_read(void);
void Serial2_println(char *msg, ...);               //To print a line
 //void Serial2_println(char *data);

//PA9 : USART1 TX & PA10 USART1 RX
void Serial1_Begin(unsigned int Baud_Rate);
void Serial1_write( uint16_t data);         //To print a character
uint16_t Serial1_read(void);
void Serial1_println(char *msg, ...);


//APB1 Bit-17 : UART2 Clock Bus (Maximum 50MHz)

void Buffer_read(char buffer);