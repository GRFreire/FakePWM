#include <Arduino.h>

#include <fakePWM.h>

#define PWM_PORT 8

byte parseAnalog(unsigned int val)
{
    int parsed = map(val, 0, 1002, 0, 255);
    if (parsed < 0)
        parsed = 0;
    if (parsed > 255)
        parsed = 255;

    return parsed;
}

void setup()
{
    Serial.begin(9600);

    pinMode(PWM_PORT, OUTPUT);
    digitalWrite(PWM_PORT, HIGH);

    initPWM();
}

void loop()
{
    byte val = parseAnalog(analogRead(A0));
    setPWM(PWM_PORT, val);
    Serial.println(val);
}