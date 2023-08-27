int IRSensor = 52; // connect IR sensor module to Arduino pin D9
//น้ำตาล +
//น้ำเงิน -
//ดำ data

void setup(){
  Serial.begin(9600); // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working"); // Test to check if serial is working or not
  pinMode(IRSensor, INPUT_PULLUP); // IR Sensor pin INPUT
}

void loop(){
  IR_Value = digitalRead(IRSensor); // Set the GPIO as Input
  Serial.println(sensorStatus); 
  
}
