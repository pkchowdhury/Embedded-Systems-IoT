#include "Arduino.h"
#include<SPIFlash.h>
#include<flash.h>

#define BAUD_RATE 115200

#define arrayLen(x) sizeof(x)/sizeof(x[0])
uint32_t strAddr[3], floatAddr[2], byteAddr[4];
String testStr[] = {
  "Test String 0",
  "Test String 1",
  "Test String 2"
};
float testFloat[] = {
  3.1415, 6.283
};
byte testByte[] = {
  3, 245, 84, 100
};

//SPIFlash flash(SS1, &SPI1);       //Use this constructor if using an SPI bus other than the default SPI. Only works with chips with more than one hardware SPI bus
SPIFlash flash(PA4);



void flashInit() {
  Serial.begin(BAUD_RATE);

  delay(50); //Time to terminal get connected
  Serial.print(F("Initialising Flash memory"));
  for (int i = 0; i < 10; ++i)
  {
    Serial.print(F("."));
  }
  Serial.println();
  flash.begin();
  Serial.println();
  Serial.println();

  getAddresses();
  dataIO();
  flash.eraseChip();      // Uncomment this if you would like to erase chip
}

// Function to get addresses for various variables
void getAddresses() {
  for (uint8_t i = 0; i < arrayLen(byteAddr); i++) {
    byteAddr[i] = flash.getAddress(sizeof(byte));
    Serial.print("Byte Address ");
    Serial.print(i);
    Serial.print(" : 0x");
    Serial.println(byteAddr[i], HEX);
  }

  for (uint8_t i = 0; i < arrayLen(floatAddr); i++) {
    floatAddr[i] = flash.getAddress(sizeof(float));
    Serial.print("Float Address ");
    Serial.print(i);
    Serial.print(" : 0x");
    Serial.println(floatAddr[i], HEX);
  }

  for (uint8_t i = 0; i < arrayLen(strAddr); i++) {
    strAddr[i] = flash.getAddress(flash.sizeofStr(testStr[i]));
    Serial.print("String Address ");
    Serial.print(i);
    Serial.print(" : 0x");
    Serial.println(strAddr[i], HEX);
  }
}

// Function to write data
void dataIO() {
  uint8_t _byte;
  float _float;
  String _string;
  for (uint8_t i = 0; i < arrayLen(byteAddr); i++) {
    if (flash.writeByte(byteAddr[i], testByte[i])) {
      Serial.print(testByte[i]);
      Serial.print(" written to 0x");
      Serial.println(byteAddr[i], HEX);
    }
    _byte = flash.readByte(byteAddr[i]);
    Serial.print(_byte);
    Serial.print(" read from 0x");
    Serial.println(byteAddr[i], HEX);
  }

  for (uint8_t i = 0; i < arrayLen(floatAddr); i++) {
    if (flash.writeFloat(floatAddr[i], testFloat[i])) {
      Serial.print(testFloat[i]);
      Serial.print(" written to 0x");
      Serial.println(floatAddr[i], HEX);
    }
    _float = flash.readFloat(floatAddr[i]);
    Serial.print(_float);
    Serial.print(" read from 0x");
    Serial.println(floatAddr[i], HEX);
  }

  for (uint8_t i = 0; i < arrayLen(strAddr); i++) {
    if (flash.writeStr(strAddr[i], testStr[i])) {
      Serial.print("'");
      Serial.print(testStr[i]);
      Serial.print("' written to 0x");
      Serial.println(strAddr[i], HEX);
    }
    flash.readStr(strAddr[i], _string);
    Serial.print("'");
    Serial.print(_string);
    Serial.print("' read from 0x");
    Serial.println(strAddr[i], HEX);
    _string = "";
  }
}