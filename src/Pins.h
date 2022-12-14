#pragma once
#include <Arduino.h>

// Motor Pins
const int stepPins[] = {2, 3, 4};
const int dirPins[] = {5, 6, 7};

// Rotary Encoder Pins
const int encoderDTPin = 51;  // DATA signal
const int encoderCLKPin = 50; // CLOCK signal