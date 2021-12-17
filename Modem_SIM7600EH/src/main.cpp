#include <Arduino.h>
//#include <SoftwareSerial.h>
//SoftwareSerial Serial1(PA2, PA3);

void ShowSerialData()
{
  while (Serial1.available() != 0)
    Serial.write(Serial1.read());
  delay(200);
 
}

void setup() {
  pinMode(PIN_A6, OUTPUT);

  // initialize both serial ports:
  Serial.begin(115200);
  Serial1.begin(115200);

  delay(2000);
  digitalWrite(PIN_A6, HIGH);
  delay(1000);
  digitalWrite(PIN_A6, LOW);  
  delay(30000);
}

void loop() {


  if (Serial1.available())
  Serial.write(Serial1.read());
 
  Serial1.println("AT");
  delay(500);

  Serial1.println("AT+CSQ");
  delay(1000);
  ShowSerialData();

  Serial1.println("AT+CPIN?");
  delay(500);
  ShowSerialData();

  Serial1.println("AT+COPS?");
  delay(500);
  ShowSerialData();

  Serial1.println("AT+CREG?");
  delay(500);
  ShowSerialData();

  Serial1.println("AT+CGPS=1, 1");
  delay(500);
  ShowSerialData();

  Serial1.println("AT+CGPSINFO");
  delay(500);
  ShowSerialData();

  Serial1.println("AT+CGMI");
  delay(500);
  ShowSerialData();

  Serial1.println("AT+CNMP=2");
  delay(1000);
  ShowSerialData();

  Serial1.println("AT+HTTPINIT");
  delay(10000);
  ShowSerialData();
 

 //JSON format data stream
  String sendtoserver;
  sendtoserver+= "{\"imei_number\":";
  sendtoserver+= "\"001\"";
  sendtoserver+=",\r\n";
  sendtoserver+= "\"dynamic_ip\":";
  sendtoserver+= "\"11319\"";
  sendtoserver+=",\r\n";
  sendtoserver+= "\"lat\":";
  sendtoserver+= "\"23.86205672265129\"";
  sendtoserver+=",\r\n";
  sendtoserver+= "\"lon\":";
  sendtoserver+= "\"90.3986622726246\"";
  sendtoserver+=",\r\n";
  sendtoserver+= "\"battery_health\":";
  sendtoserver+= "\"75\"";
  sendtoserver+=",\r\n";
  sendtoserver+= "\"temperature\":";
  sendtoserver+= "\"24\"";
  sendtoserver+=",\r\n";
  sendtoserver+= "\"added_time\":";
  sendtoserver+= "\"1638338256\"";
  sendtoserver+=",\r\n";
  sendtoserver+= "\"outpost_id\":";
  sendtoserver+= "\"3\"";
  sendtoserver+=",\r\n";
  sendtoserver+= "\"is_emergency\":";
  sendtoserver+= "\"1\"";
  sendtoserver+= "}";
  
  delay(1000);
  
  //API Address
  Serial1.println("AT+HTTPPARA=\"URL\",\"https://ebs.premiumcloudhost.com/api/user-data-update\""); //Server address
  delay(1000);
  ShowSerialData();
 
  Serial1.println("AT+HTTPPARA=\"CONTENT\",\"application/json\"");
  delay(1000);
  ShowSerialData();

  // Serial1.println("AT+HTTPPARA=\"ACCEPT\",\"application/json\"");
  // delay(1000);
  // ShowSerialData();
 
 //String length 
  Serial1.println("AT+HTTPDATA=" + String(sendtoserver.length()+1) + ",10000");
  Serial.println(sendtoserver);
  delay(2000);
  ShowSerialData();

 //sending data to server
  Serial1.println(sendtoserver);
  delay(1000);
  ShowSerialData();
 
  Serial1.println("AT+HTTPACTION=1");
  delay(1000);
  ShowSerialData();
 
  Serial1.println("AT+HTTPREAD");
  delay(1000);
  ShowSerialData();
 
  Serial1.println("AT+HTTPTERM");
  delay(500);
  ShowSerialData();
  
 
  /********************GPRS Communication Stops********************/
  /********************GSM Communication********************/
}

