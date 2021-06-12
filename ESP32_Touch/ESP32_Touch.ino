/*T1: GPIO 0
T2: GPIO 2
T3: GPIO 15
T4: GPIO 13
T5: GPIO 12
T6: GPIO 14
T7: GPIO 27
T8: GPIO 33
T9: GPIO 32*/

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 delay(1000);
 Serial.println("ESP32 Touch Test");
 pinMode(2, OUTPUT);
 digitalWrite(2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = touchRead(4);
  Serial.println(value);
  delay(1000);
  if(value <= 50)
  {
    digitalWrite(2, HIGH);
    Serial.println("LED ON");
    delay(1000);
  }else if(value > 50)
  {digitalWrite(2, LOW);
  Serial.println("LED OFF");
  delay(1000);
  }
}
