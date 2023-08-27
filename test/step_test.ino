#include <Arduino.h>

const int stepPin = 9;
const int dirPin = 8;
const int enPin = 10;

int cmWant = 5;
int stepPerCM = 1600;
int stepSetup = 800;
int controlStep = cmWant * stepPerCM;
int stepSpeed = 500;

void setup()
{
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
}

void loop()
{

  digitalWrite(dirPin, HIGH); // หมุนตามเข็ม
  for (int x = 0; x < controlStep; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepSpeed);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepSpeed);
  }

  delay(1000);

  digitalWrite(dirPin, LOW); // หมุนทวนเข็ม
  for (int x = 0; x < controlStep; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepSpeed);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepSpeed);
  }

  delay(1000);
}
