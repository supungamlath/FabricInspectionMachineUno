// @author - Supun Gamlath (supungamlath@outlook.com)

#include <Arduino.h>
#include <Types.h>
#include <Motors.h>
#include <Wire.h>
#include "SerialTransfer.h"

SerialTransfer serialTransfer;
MotorControlPacket motorPacket;

void setup()
{
  initializeMotors();
  Serial.begin(115200);
  serialTransfer.begin(Serial);
}

void loop()
{
  // setMotorsDirection(BACKWARD);
  // runMotors(500);
  if (serialTransfer.available())
  {
    serialTransfer.rxObj(motorPacket);

    // TODO - Add code to handle multiple motors
    setMotorsDirection(motorPacket.motor1dir);
    if (motorPacket.motor1speed > 0)
    {
      runMotors(motorPacket.motor1speed);
    }
    else
    {
      stopMotors();
    }
  }
}
