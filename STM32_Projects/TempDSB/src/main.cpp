#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>

// Baud rate for debug serial
#define SERIAL_DEBUG_BAUD   9600


// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS PB15 //tenp sensor pin

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);




void setup() {
  // Set console baud rate
  Serial.begin(SERIAL_DEBUG_BAUD);
  sensors.begin();
}

void loop() {

  sensors.requestTemperatures(); 

  float cel= sensors.getTempCByIndex(0); 
  delay(1000);

  Serial.println(cel);

}

