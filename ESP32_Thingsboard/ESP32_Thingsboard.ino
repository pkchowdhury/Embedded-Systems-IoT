#include "ThingsBoard.h"
#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
//#include <ESP8266WiFi.h>
#include<DHT.h>

#define WIFI_AP             "WORKSTATION101"
#define WIFI_PASSWORD       "WS@101-04"

// See https://thingsboard.io/docs/getting-started-guides/helloworld/
// to understand how to obtain an access token
#define TOKEN               "thinkbroom_102"
#define THINGSBOARD_SERVER  "178.128.50.197"

#define DHTPIN 13  //be careful the pin no. on the nodeMcu and arduino ide differ 
#define DHTTYPE DHT11 //specifying the type of sensor

  DHT dht(DHTPIN,DHTTYPE);
  
// Baud rate for debug serial
#define SERIAL_DEBUG_BAUD   115200
float h, t;
char datas[100];
char sen_datas[100];
// Initialize ThingsBoard client
WiFiClient espClient;
// Initialize ThingsBoard instance
ThingsBoard tb(espClient);
// the Wifi radio's status
int status = WL_IDLE_STATUS;
String payloads;
void setup() {
  // initialize serial for debugging
  Serial.begin(SERIAL_DEBUG_BAUD);
  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  InitWiFi();
  dht.begin();
 
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);
}
 void readDatas(){
 h=dht.readHumidity(); 
 t=dht.readTemperature();  
}
void loop() {
  delay(1000);

  if (WiFi.status() != WL_CONNECTED) {
    reconnect();
  }

  if (!tb.connected()) {
    // Connect to the ThingsBoard
    Serial.print("Connecting to: ");
    Serial.print(THINGSBOARD_SERVER);
    Serial.print(" with token ");
    Serial.println(TOKEN);
    if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect");
      return;
    }
  }

  

  // Uploads new telemetry to ThingsBoard using MQTT.
  // See https://thingsboard.io/docs/reference/mqtt-api/#telemetry-upload-api
  // for more details
  readDatas();
  //Serial.println(t); 
  //Serial.println(h);

  String sensor_data;
  sensor_data += "{";
  sensor_data += "\"Temperature\":";
  sensor_data += String(26);
  sensor_data += ",";
  sensor_data += "\"Humidity\":";
  sensor_data += String(65);
  sensor_data += "}";

  //Serial.println(sensor_data);
  int sen_len = sensor_data.length();
  sensor_data.toCharArray(sen_datas, sen_len+1);
  
  tb.sendTelemetryJson(sen_datas);
  
  String payloads;
  payloads += "{";
  payloads += "\"Latitude\":";
  payloads += String(23.8608370,6);
  payloads += ",";
  payloads += "\"Longitude\":";
  payloads += String(90.3993350,6);
  payloads += "}";

  //Serial.println(payloads);
  int len = payloads.length();
  payloads.toCharArray(datas, len+1);
  
  tb.sendAttributeJSON(datas);
  
  Serial.println(sen_datas);
  Serial.println(datas);
  
  Serial.println("Sending Data...");
  
}

void InitWiFi()
{
  Serial.println("Connecting to AP ...");
  // attempt to connect to WiFi network

  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to AP");
}

void reconnect() {
  // Loop until we're reconnected
  status = WiFi.status();
  if ( status != WL_CONNECTED) {
    WiFi.begin(WIFI_AP, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("Connected to AP");
  }
}
