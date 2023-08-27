#include "Arduino.h"

extern int roundSeeding;

// conveyor belt step motor
const int stepPin = 9;
const int dirPin = 8;
const int enPin = 10;

int cmWant;           // ต้องการให้เคลื่อนที่กี่ cm
int stepPerCM = 1600; // หมุนกี่สเต็ปถึงเคลื่อนที่ได้ 1 cm
int stepSetup = 800;
int controlStep ;
int stepSpeed = 500;

void Conveyor_Step_Setup(){
    // conveyor belt step motor
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(enPin, OUTPUT);
    digitalWrite(enPin, LOW);
}

void cal_controlStep(){
    controlStep = cmWant * stepPerCM;
}

void Conveyor_Step_Clockwise()
{
    digitalWrite(dirPin, HIGH); // หมุนตามเข็ม
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepSpeed);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepSpeed);
}

void Conveyor_Step_ROW1()
{
    // หมุนจนถึงจุดกึ่งกลางแถวแรก
    Serial.print("Starting ROW ");
    Serial.println(roundSeeding);


    Serial.println(stepPerCM);
    cmWant = 8;             // สมมุติว่า 8 cm ถึงจุดกึ่งกลาง
    cal_controlStep();
    Serial.println(cmWant);
    Serial.println(controlStep);


    digitalWrite(dirPin, HIGH); // หมุนตามเข็ม
    for (int x = 0; x < controlStep; x++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepSpeed);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepSpeed);
    }
    
}


void Conveyor_Step_ROW1UP()
{
    // หมุนจนถึงจุดกึ่งกลางแถวถัดไป
    Serial.print("Starting ROW ");
    Serial.println(roundSeeding);


    Serial.println(stepPerCM);
    cmWant = 5;             // สมมุติว่า 5 cm ถึงจุดกึ่งกลาง
    cal_controlStep();
    Serial.println(cmWant);
    Serial.println(controlStep);


    digitalWrite(dirPin, HIGH); // หมุนตามเข็ม
    for (int x = 0; x < controlStep; x++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepSpeed);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepSpeed);
    }
    
}


void Conveyor_Step_New_Tray()
{
    // หมุนจนปลายถาดเลย Ultra Sensor ไป
    //จริงๆควรรีเช็คจาก Ultra มากกว่า ไม่ควรสั่งให้หมุนเป็น cm
    //เพราะถ้าทำแบบนี้ จะทำให้วางถาดชิดกันเกินที่ตั้งไม่ได้
    //ถ้าวางถาดชิดกันเกินจะทำให้ โปรแกรมไม่รู้ว่าเริ่มถาดใหม่แล้ว
    Serial.println("New Tray ");


    Serial.println(stepPerCM);
    cmWant = 10;             // สมมุติว่า 10 cm เลย sensor
    cal_controlStep();
    Serial.println(cmWant);
    Serial.println(controlStep);


    digitalWrite(dirPin, HIGH); // หมุนตามเข็ม
    for (int x = 0; x < controlStep; x++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepSpeed);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepSpeed);
    }
    
}