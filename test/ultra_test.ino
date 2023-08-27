#include <Arduino.h>

const int trig = 7; //ประกาศขา trig
const int echo = 6; //ประกาศขา echo
long duration, distance; //ประกาศตัวแปรเก็บค่าระยะ

void setup() {
  Serial.begin(9600);
  pinMode(echo, INPUT); //สั่งให้ขา echo ใช้งานเป็น input
  pinMode(trig, OUTPUT); //สั่งให้ขา trig ใช้งานเป็น output
}
void loop() {
 digitalWrite(trig, LOW); 
 delayMicroseconds(5); 
 digitalWrite(trig, HIGH); 
 delayMicroseconds(5); 
 digitalWrite(trig, LOW); //ใช้งานขา trig
 
 duration = pulseIn(echo, HIGH); //อ่านค่าของ echo
 distance = (duration/2) / 29.1; //คำนวณเป็น centimeters
 Serial.print(distance); 
 Serial.print(" cm\n");
}