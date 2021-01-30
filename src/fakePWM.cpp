#include <Arduino.h>
#include <TimerOne.h>

#include "fakePWM.h"

volatile uint8_t step = 0;
volatile int val[NUM_DIGITAL_PINS];

void updatePWM()
{
  for (unsigned int i = 0; i < NUM_DIGITAL_PINS; i++)
  {
    if (val[i] != -1)
    {
      digitalWrite(8, step < val[i] ? HIGH : LOW);
    }
  }

  step++;
  if (step > 255)
    step = 0;
}

void initPWM(unsigned int updateTime)
{
  Timer1.initialize(updateTime);
  Timer1.attachInterrupt(updatePWM);

  step = 0;
  for (unsigned int i = 0; i < NUM_DIGITAL_PINS; i++)
  {
    val[i] = -1;
  }
}

void setPWM(unsigned int port, uint8_t value)
{
  val[port] = value;
}