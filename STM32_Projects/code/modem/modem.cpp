// #include <Arduino.h>
// #include "modem.h"
// #include <HardwareSerial.h>
// HardwareSerial Serial2(PA3, PA2);  // RX, TX

// // Your GPRS credentials, if any
// const char apn[]      = "gpinternet";
// const char gprsUser[] = "";
// const char gprsPass[] = "";

// #define simPwr PA6
// #define simEn PB12
// #define dtr PA1
// //#define stat PA6


// String  teleTopic = "v1/devices/me/telemetry";
// String  attTopic = "v1/devices/me/attributes";
// String  resTopic = "v1/devices/me/response/+";
// String  reqTopic = "v1/devices/me/request/1";
// uint32_t lastReconnectAttempt = 0;


// void modemInit() {
//   //GPIO Init
//   //pinMode(PC13, OUTPUT);
//   pinMode(simEn, OUTPUT);
//   pinMode(simPwr, OUTPUT);
//   pinMode(dtr, OUTPUT);
//   //pinMode(stat, OUTPUT);
  
  
//   // !!!!!!!!!!!
//   // Set your reset, enable, power pins here
//   // !!!!!!!!!!!
//   digitalWrite(simEn, HIGH); // make sim module enable

//   //Initialize Serial
  


//   //Enable PWR key
//   digitalWrite(simPwr, HIGH);
//   delay(1000);
//   digitalWrite(simPwr, LOW);
//   delay(2000);

//   Serial2.begin(115200);
//   delay(500);
//   Serial.println("Initializing modem...");
// }

// void gprsInit(){

//       Serial.println("Gprs Init...");
//       if (Serial2.available())
//       Serial.write(Serial2.read());

//       Serial2.println("AT");
//       showSerialdata();
//       delay(500);

//       Serial2.println("AT+CSQ");
//       showSerialdata();
//       delay(500);

//       Serial2.println("AT+CPIN?");
//       delay(500);
//       showSerialdata();

//       Serial2.println("AT+COPS?");
//       delay(500);
//       showSerialdata();

//       Serial2.println("AT+CREG?");
//       delay(500);
//       showSerialdata();

//       Serial2.println("AT+CGMI");
//       delay(500);
//       showSerialdata();

//       Serial2.println("AT+CNMP=2");
//       delay(1000);
//       showSerialdata();


// }

// void mqttConnect(String clientId, String broker, String user, String pass){

//       Serial2.println("AT+CMQTTSTART");
//       showSerialdata();
//       delay(500);

//       Serial2.println("AT+CMQTTACCQ=0,\"" + String(clientId) +  "\"");
//       showSerialdata();
//       delay(500);

//       Serial2.println("AT+CMQTTCONNECT=0,\"tcp://" + String(broker) + "\"" +  ",\"" + String(user) + "\",\"" + String(pass) + "\"");
//       showSerialdata();
//       delay(2000);

// }

// void mqttStop(){

//       Serial2.println("AT+CMQTTSTOP");
//       showSerialdata();
//       delay(500);
// }

// void mqttDisconnect(int timeout){

//       Serial2.println("AT+CMQTTDISC=0," + String(timeout));
//       showSerialdata();
//       delay(500);
// }

// void clientRelease(){

//       Serial2.println("AT+CMQTTREL=0");
//       showSerialdata();
//       delay(500);
// }

// void publishData(String data, String dataType, int qos){
//   if(dataType == "telemetry"){
    
//       Serial2.println("AT+CMQTTTOPIC=0," + String(String(teleTopic).length()));
//       showSerialdata();
//       delay(500);

//       Serial2.println(teleTopic);
//       showSerialdata();
//       delay(2000);

//       Serial2.println("AT+CMQTTPAYLOAD=0," + String(String(data).length()));
//       showSerialdata();
//       delay(500);

//       Serial2.println(data);
//       showSerialdata();
//       delay(500);

//       Serial2.println("AT+CMQTTPUB=0," + String(qos));
//       showSerialdata();
//       delay(500);
//   }
//   else if(dataType == "attribute"){

//       Serial2.println("AT+CMQTTTOPIC=0," + String(String(attTopic).length()));
//       showSerialdata();
//       delay(500);

//       Serial2.println(attTopic);
//       showSerialdata();
//       delay(500);


//       Serial2.println("AT+CMQTTPAYLOAD=0," + String(String(data).length()));
//       showSerialdata();
//       delay(500);

//       Serial2.println(data);
//       showSerialdata();
//       delay(500);

      
//       Serial2.println("AT+CMQTTPUB=0," + String(qos));
//       showSerialdata();
//       delay(500);
//   }
//   else {
//     Serial.println("No valid dataType");
//   }
// }

// void subscribe(int qos){

//       Serial2.println("AT+CMQTTSUBTOPIC=0," + String(String(resTopic).length()) + "," + String(qos));
//       showSerialdata();
//       delay(500);

//       Serial2.println(resTopic);
//       showSerialdata();
//       delay(500);

//       Serial2.println("AT+CMQTTSUB=" + String(qos));
//       showSerialdata();
//       delay(500);
// }

// void reqData(int qos, String data){

//       Serial2.println("AT+CMQTTTOPIC=0," + String(String(reqTopic).length()));
//       showSerialdata();
//       delay(500);

//       Serial2.println(reqTopic);
//       showSerialdata();
//       delay(500);


//       Serial2.println("AT+CMQTTPAYLOAD=0," + String(String(data).length()));
//       showSerialdata();
//       delay(500);

//       Serial2.println(data);
//       showSerialdata();
//       delay(500);

      
//       Serial2.println("AT+CMQTTPUB=0," + String(qos));
//       showSerialdata();
//       delay(500);
      
// }


// void showSerialdata() {

//   while (Serial2.available() != 0)
//   Serial.write(Serial2.read());
//   delay(200);
  
// }