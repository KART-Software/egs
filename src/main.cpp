#include <M5Stack.h>
#include "sensors.hpp"
#include "init_pins.hpp"
#include "dc_motor_controller.hpp"
#include "serial_logger.hpp"
#include "shifter.hpp"

TaskHandle_t canSendTask;

SerialLogger serialLogger;
Shifter shifter = Shifter();
Button upShiftPaddle = Button(UP_SHIFT_PIN, true, DEBOUNCE_MS);
Button downShiftPaddle = Button(DOWN_SHIFT_PIN, true, DEBOUNCE_MS);

void setup()
{
  M5.begin();
  serialLogger.initialize();
  initPins();
  gAdc.begin();
}

void loop()
{
  upShiftPaddle.read();
  downShiftPaddle.read();
  M5.update();
  if (UP_SHIFT_BUTTON.wasPressed() || upShiftPaddle.wasPressed())
  {
    shifter.upShift(SHIFT_TIMEOUT);
  }
  if (DOWN_SHIFT_BUTTON.wasPressed() || downShiftPaddle.wasPressed())
  {
    shifter.downShift(SHIFT_TIMEOUT);
  }
}