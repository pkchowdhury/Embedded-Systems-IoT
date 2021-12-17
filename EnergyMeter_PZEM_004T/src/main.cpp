#include <Arduino.h>
#include <PZEM004Tv30.h>


PZEM004Tv30 pzem(Serial1);  // RX,TX


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  
}

void loop() {
  float v = pzem.voltage();
  //if (v < 0.0) v = 0.0;
  Serial.print(v);Serial.print("V; ");

  float i = pzem.current();
  if(i >= 0.0){ Serial.print(i);Serial.print("A; "); }

Serial.print(i);Serial.print("A; ");
  
  float p = pzem.power();
  if(p >= 0.0){ Serial.print(p);Serial.print("W; "); }
  
Serial.print(p);Serial.print("W; ");  
 
  float e = pzem.energy();
  if(e >= 0.0){ Serial.print(e);Serial.print("Wh; "); }
  
Serial.print(e);Serial.print("Wh; ");

  Serial.println();

  delay(1000);
}

