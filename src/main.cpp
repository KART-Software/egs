#include <M5Stack.h>
#include "sensors.hpp"
#include "init_pins.hpp"
#include "dc_motor_controller.hpp"
#include "serial_logger.hpp"
#include "shifter.hpp"

TaskHandle_t canSendTask;

Sps sps(SPS_MIN, SPS_MAX, SPS_RAW_MIN, SPS_RAW_MAX, SPS_PIN);
DcMotorController dcMotorController(&sps);
SerialLogger serialLogger;
Shifter shifter(&sps, &dcMotorController);

void setup()
{
  M5.begin();
  serialLogger.initialize();
  initPins();
  gAdc.begin();
}

void loop()
{
  M5.update();
  if (M5.BtnA.wasPressed())
  {
    shifter.upShift();
  }
  if (UP_SHIFT_BUTTON.wasPressed())
  {
    shifter.downShift();
  }
}