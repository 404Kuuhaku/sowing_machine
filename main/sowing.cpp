#include "Arduino.h"

// seeding function
int solenoidValvePin = 22;

const int seed_stepPin = 24;
const int seed_dirPin = 26;
const int seed_enPin = 28;

int seed_angleWant;                // ต้องการให้เคลื่อนที่กี่ องศา
int seed_stepPerAngle = 800 / 360; // หมุนกี่สเต็ปถึงเคลื่อนที่ได้ 1 องศา
int seed_stepSetup = 800;
int seed_controlStep ;
int seed_stepSpeed = 500;

void sowingSetup()
{
    // seeding function
    pinMode(solenoidValvePin, OUTPUT);

    pinMode(seed_stepPin, OUTPUT);
    pinMode(seed_dirPin, OUTPUT);
    pinMode(seed_enPin, OUTPUT);
    digitalWrite(seed_enPin, LOW);
}


void cal_seed_controlStep(){
    seed_controlStep = seed_angleWant * seed_stepPerAngle;
}


void pullSeedingFunction()
{
    digitalWrite(solenoidValvePin, LOW); // ดูดเมล็ด

    // หมุนจาก B->A (ทวนเข็ม)
    Serial.println("Starting B --> A");

    Serial.println(seed_stepPerAngle);
    seed_angleWant = 90; // สมมุติว่า 90 องศา ถึงจุด A
    cal_seed_controlStep();
    Serial.println(seed_angleWant);
    Serial.println(seed_controlStep);

    digitalWrite(seed_dirPin, LOW); // หมุนทวนเข็ม
    for (int x = 0; x < seed_controlStep; x++)
    {
        digitalWrite(seed_stepPin, HIGH);
        delayMicroseconds(seed_stepSpeed);
        digitalWrite(seed_stepPin, LOW);
        delayMicroseconds(seed_stepSpeed);
    }

    delay(2000); // waiting for 2 sec

    // หมุนจาก A->B (ตามเข็ม)
    Serial.println("Starting A --> B");

    Serial.println(seed_stepPerAngle);
    seed_angleWant = 90; // สมมุติว่า 90 องศา ถึงจุด B
    cal_seed_controlStep();
    Serial.println(seed_angleWant);
    Serial.println(seed_controlStep);

    digitalWrite(seed_dirPin, HIGH); // หมุนตามเข็ม
    for (int x = 0; x < seed_controlStep; x++)
    {
        digitalWrite(seed_stepPin, HIGH);
        delayMicroseconds(seed_stepSpeed);
        digitalWrite(seed_stepPin, LOW);
        delayMicroseconds(seed_stepSpeed);
    }
}

void releaseSeedingFunction()
{
    digitalWrite(solenoidValvePin, HIGH); // ปล่อยเมล็ด
}
