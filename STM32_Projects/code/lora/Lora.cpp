// #include "Arduino.h"
// #include "Lora.h"
// #include <HardwareSerial.h>
// //SoftwareSerial serialLora(PA12, PA11); //Rx, Tx
// HardwareSerial Serial2(PA3, PA2); //Rx, Tx

// #define M0 PB3 //PA15
// #define M1 PB4 //PA14
// #define AUX PA6 //PA13
// #define loraEn PB5

// void CharToByte(char* chars, byte* bytes, int count);

// void loraInit() {
//     Serial2.begin(9600);
    
//     pinMode(loraEn, OUTPUT);
//     digitalWrite(loraEn, HIGH);
    
//     pinMode(M0, OUTPUT); // M0
//     pinMode(M1, OUTPUT); // M1
//     pinMode(AUX, INPUT);// AUX
    
// }
 
// void multiSerial() {
//   if (Serial2.available()) {
//     Serial.write(Serial2.read());
//   }
//   if (Serial.available()) {
//     Serial2.write(Serial.read());
//   }
// }

// void loraMode(int mode){

//     if(mode == 0){
//         //Normal Mode
//         digitalWrite(M0, LOW); //M0
//         delay(1000);
//         digitalWrite(M1, LOW); //M1
//         delay(5000);
//     }

//     else if( mode == 1){
//         //WOR Mode
//         digitalWrite(M0, HIGH); //M0
//         delay(1000);
//         digitalWrite(M1, LOW); //M1
//         delay(5000);

//     }
//         else if( mode == 2){
//         //Configuration Mode
//         digitalWrite(M0, LOW); //M0
//         delay(1000);
//         digitalWrite(M1, HIGH); //M1
//         delay(5000);

//     }
//         else if( mode == 1){
//         //Deep Sleep Mode
//         digitalWrite(M0, HIGH); //M1
//         delay(1000);
//         digitalWrite(M1, HIGH); //M0
//         delay(5000);

//     }
// }

// void setConf(int addh, int addl, int ch, int netId){
//     loraMode(2);
//     delay(500);

//     Serial2.write((byte) 192);
//     Serial2.write((byte) 00);
//     Serial2.write((byte) 07);
//     Serial2.write(addh);
//     Serial2.write(addl);
//     Serial2.write((byte) netId);
//     Serial2.write((byte) 103); //2.4kbps
//     Serial2.write((byte) 00);//0 for 30dbm, 01 for 27dbm
//     Serial2.write((byte) ch);
//     Serial2.write((byte) 67); //Fixed Transmission
//     delay(100);

// }

// void sendData(int addh, int addl, int ch, char* buf){
//     loraMode(0);
//     int cnt = strlen(buf);
//     byte* buffer;
//     Serial2.write((byte) addh);
//     Serial2.write((byte) addl);
//     Serial2.write((byte) ch);
//     CharToByte(buf, buffer, cnt);
    
// }

// void CharToByte(char* chars, byte* bytes, int count){
    
//     for(unsigned int i = 0; i < count; i++){
//         bytes[i] = (byte)chars[i];
//         Serial2.write(bytes[i]);
//     }
// }