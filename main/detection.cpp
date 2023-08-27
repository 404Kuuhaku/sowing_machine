#include "Arduino.h"

int IRSensor = 52;
int IR_Value;


void detectionSetup(){
    pinMode(IRSensor, INPUT_PULLUP); // IR Sensor pin INPUT
}
void detectionTray()
{
    IR_Value = digitalRead(IRSensor); // Set the GPIO as Input
}
