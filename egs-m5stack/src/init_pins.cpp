#include "init_pins.hpp"

void initPins()
{
    pinMode(DC_MOTOR_DIR_PIN, OUTPUT);
    pinMode(DC_MOTOR_PWM_PIN, OUTPUT);
}
