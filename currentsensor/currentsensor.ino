const int analog_IN = A0;
int mv_per_amp = 100; // use 100 for 20A Module and 66 for 30A Module
int raw_value= 0;
int acs_offset = 2500;
double voltage = 0;
double amps = 0;

void setup(){
     Serial.begin(9600);
}

void loop(){
    raw_value = analogRead(analog_IN);

    voltage = (raw_value / 1024.0) * 5000; // Gets you mV
    amps = ((voltage - acs_offset) / mv_per_amp);
    Serial.print("\n Voltage = ");
    Serial.print(voltage, 3);
    Serial.print(" mV"); // shows the voltage measured
    Serial.print("\t Amps = "); // shows the current
    Serial.println(amps,3);
    Serial.print(" Amp"); // shows the voltage measured
    delay(2500);

}
