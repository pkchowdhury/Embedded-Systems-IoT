#include <Arduino.h>
#define TINY_GSM_MODEM_SIM800
#include <TinyGsmClient.h>
#include <SoftwareSerial.h>
#include "ThingsBoard.h"
#include <Wire.h>
#include<DHT.h>
#define TOKEN               "DHT11_DEMO_TOKEN"
#define THINGSBOARD_SERVER  "178.128.50.197"

SoftwareSerial serialGsm(PB12, PB13);
 
TinyGsm modem(serialGsm);
TinyGsmClient client(modem);
ThingsBoard tb(client);

bool modemConnected = false;
const char apn[]  = "gpinternet";
#define DHTPIN PB4  //be careful the pin no. on the nodeMcu and arduino ide differ 
#define DHTTYPE DHT11 //specifying the type of sensor

DHT dht(DHTPIN,DHTTYPE);

float h, t;
char datas[100];
String payloads;

 void readDatas(){

  h = dht.readHumidity(); 
  t = dht.readTemperature(); 
 }
 
void setup()
{     
  Serial.begin(9600);
  Serial.println("Initializing...");
  //serialGsm.begin(9600);
  //delay(3000);
  //modem.restart();
  //String modemInfo = modem.getModemInfo();
  //Serial.println(modemInfo);
  //serialGsm.end();
  dht.begin();
 
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);
  
  delay(1000);
}

void loop(){

  readDatas();
  /*serialGsm.listen();
  if (!modemConnected) {
    if (!modem.waitForNetwork()) {
        delay(10000);
        return;
    }
    //Serial.print(apn);
    if (!modem.gprsConnect(apn)) {
        
        delay(10000);
        return;
    }
    modemConnected = true;
  }
    if (!tb.connected()) {
    Serial.print(THINGSBOARD_SERVER);
    Serial.println(TOKEN);
    if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect, retrying ...");
      return;
    }
 }
 
  payloads += "{";
  payloads += "\"Temperature\":"; 
  payloads += String(t); 
  payloads += ",";
  payloads += "\"Humidity\":"; 
  payloads += String(h);
  payloads += "}";

  int len = 0;
  len = payloads.length();
  payloads.toCharArray(datas, len+1);
  tb.sendTelemetryJson(datas);*/
  Serial.println(t);
  Serial.println(h);
  delay(1000);
  Serial.println("Sending telemetry data...");
  
}