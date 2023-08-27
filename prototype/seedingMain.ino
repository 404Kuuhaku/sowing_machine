#include <Arduino.h>

int ultrasonicValue;
int roundSeeding;

int stepMotor = 0;

//seeding function
int solenoidValve = 0;
int seedStepMotor = 0;

//vibration seed function
int vibrateMotor = 0;

void setup()
{
    pinMode(stepMotor, OUTPUT);

    //seeding function
    pinMode(solenoidValve, OUTPUT);
    pinMode(seedStepMotor, OUTPUT);

    //vibration seed function
    pinMode(vibrateMotor, OUTPUT);
    
}

void loop()
{
    digitalWrite(vibrateMotor, HIGH);


    if (ultrasonicValue >= 20 && roundSeeding == 0)
    {
        digitalWrite(stepMotor, HIGH);
    }
    else if (ultrasonicValue <= 5 && roundSeeding == 0)
    {
        digitalWrite(stepMotor, LOW);
        // waiting for 3 sec
        pullSeedingFunction();
        analogWrite(stepMotor, หมุนจนถึงจุดกึ่งกลางแถวแรก);
        releaseSeedingFunction();
        roundSeeding++;
    }
    else if (ultrasonicValue <= 5 && roundSeeding >= 1)
    {
        digitalWrite(stepMotor, LOW);
        // waiting for 3 sec
        pullSeedingFunction();
        analogWrite(stepMotor, หมุนจนถึงจุดกึ่งกลางแถวถัดไป);
        releaseSeedingFunction();
        roundSeeding++;
    }
    else if (ultrasonicValue <= 5 && roundSeeding == 10)
    {
        digitalWrite(stepMotor, LOW);
        // waiting for 3 sec
        pullSeedingFunction();
        analogWrite(stepMotor, หมุนจนถึงจุดกึ่งกลางแถวถัดไป);
        releaseSeedingFunction();
        analogWrite(stepMotor, หมุนจนปลายถาดเลย US Sensor ไป);
        roundSeeding = 0;
    }
}

void pullSeedingFunction(){
    digitalWrite(solenoidValve , ดูด);
    analogWrite(seedStepMotor, หมุนจาก B->A);
    // waiting for 2 sec
    analogWrite(seedStepMotor, หมุนจาก A->B);
}

void releaseSeedingFunction(){
    digitalWrite(solenoidValve , ปล่อย);
}