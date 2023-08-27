#include <Arduino.h>
#include "conveyorStep.h"
#include "sowing.h"
#include "detection.h"

extern int IR_Value;
int roundSeeding = 1;

// extern const int stepPin;

// vibration seed function
int vibrateMotor = 53;

void setup()
{
    Serial.begin(9600);

    detectionSetup();

    Conveyor_Step_Setup();

    sowingSetup();

    // vibration seed function
    pinMode(vibrateMotor, OUTPUT);
}

void loop()
{
    digitalWrite(vibrateMotor, HIGH);
    detectionTray();

    if (IR_Value == 1 && roundSeeding == 1)
    {
        Conveyor_Step_Clockwise();
    }
    else if (IR_Value == 0 && roundSeeding == 1)
    {
        // digitalWrite(stepPin, LOW); // สั่งให้ Step หยุด แต่จริงๆแล้วเหมือนบรรทัดนี้ไม่ต้องมีก็ได้
        // delay(2000);                // waiting for 2 sec

        pullSeedingFunction();

        Conveyor_Step_ROW1();

        releaseSeedingFunction();
        roundSeeding++ ;
    }
    else if (IR_Value == 0 && roundSeeding >= 2)
    {
        // digitalWrite(stepPin, LOW); // สั่งให้ Step หยุด แต่จริงๆแล้วเหมือนบรรทัดนี้ไม่ต้องมีก็ได้
        // delay(2000);                // waiting for 2 sec

        pullSeedingFunction();

        Conveyor_Step_ROW1UP();

        releaseSeedingFunction();
        roundSeeding++ ;
    }
    else if (IR_Value == 0 && roundSeeding == 10)
    {
        // digitalWrite(stepPin, LOW); // สั่งให้ Step หยุด แต่จริงๆแล้วเหมือนบรรทัดนี้ไม่ต้องมีก็ได้
        // delay(2000);                // waiting for 2 sec

        pullSeedingFunction();

        Conveyor_Step_ROW1UP();

        releaseSeedingFunction();

        Conveyor_Step_New_Tray();

        roundSeeding = 1 ;
    }
}
