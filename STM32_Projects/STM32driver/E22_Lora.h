void setDataSetting(void);
void loraMode(int modeType);

unsigned char CRC8(const unsigned char *input, int count);
void loraInit(void);
char sendData(char data);