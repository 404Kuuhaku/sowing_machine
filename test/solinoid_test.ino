int solenoidValvePin = 2;

void setup() {
  pinMode(solenoidValvePin,OUTPUT);
  

}

void loop() {
  digitalWrite(solenoidValvePin,HIGH);
  delay(1000);
  digitalWrite(solenoidValvePin,LOW);
  delay(1000);
}
