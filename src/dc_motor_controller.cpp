#include "dc_motor_controller.hpp"
#include "init_pins.hpp"

DcMotorController::DcMotorController(Sps *sps)
    : sps(sps),
      dcMotor(DcMotor(DC_MOTOR_PWM_PIN, DC_MOTOR_DIR_PIN)),
      pid(PID(&sp, &speed, &setpoint, PID_KP, PID_KI, PID_KD, DIRECT))
{
    dcMotor.setPwm(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION_BITS);
    pid.SetOutputLimits(-dcMotor.getPwmMaxOutput(), dcMotor.getPwmMaxOutput());
    pid.SetMode(AUTOMATIC);
}

void DcMotorController::control(uint16_t setpoint)
{
    this->setpoint = setpoint;
    sp = sps->read();
    pid.Compute();
    dcMotor.setSpeed(speed);
}