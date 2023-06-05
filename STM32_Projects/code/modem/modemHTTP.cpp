// #include <modem.h>

// // MQTT details
// String broker = "thinkiot.com.bd";
// String clientId = "SN002";
// String userName = "SN002";
// String pass = "SN002";


// String data = "{\"id\":69}";
// String rData = "{\"clientKeys\":\"id\"}";
// void setup(){

//     Serial.begin(115200);
//     modemInit();
//     delay(30000);

//     gprsInit();
//     delay(2000);
//     mqttConnect(clientId, broker, userName, pass);
//     delay(1000);
//     subscribe(0);
//     delay(2000);
// }

// void loop(){
  
//     publishData(data, "attribute", 0);
//     delay(5000);

//     reqData(0,rData);
//     delay(5000);
// }