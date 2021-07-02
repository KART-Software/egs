#include <M5Stack.h>

#ifndef _INIT_PINS_H_
#define _INIT_PINS_H_

#define ARDUINO_A0 0
#define SPS_PIN ARDUINO_A0

#define UP_SHIFT_PIN 35
#define DOWN_SHIFT_PIN 36

#define UP_SHIFT_BUTTON_PIN 39   // BUTTON A
#define DOWN_SHIFT_BUTTON_PIN 38 // BUTTON B

#define UP_SHIFT_BUTTON M5.BtnA
#define DOWN_SHIFT_BUTTON M5.BtnB

#define DC_MOTER_OUTPUT_PIN_1 25
#define DC_MOTOR_OUTPUT_PIN_2 26

#define CAN_BUS_I2C_ADDR
#define CAN_ADDR

void initPins();

#endif