#include "dc_motor_controller.hpp"

DcMotorController::DcMotorController(Sps *sps)
    : sps(sps),
      dcMotor(DcMotor(DC_MOTOR_PWM_PIN, DC_MOTOR_DIR_PIN, DC_MOTOR_POWER_PIN)),
      pid(PID(PID_KP, PID_KI, PID_KD))
{
    dcMotor.setPwm(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION_BITS);
    pid.setOutputLimits(-1, 1);
}

void DcMotorController::setDcMotorOn()
{
    dcMotor.enable();
}

void DcMotorController::setDcMotorOff()
{
    dcMotor.disable();
}

void DcMotorController::goTo(double setpoint)
{
    pid.initialize(setpoint, sps->convertedValue());
    while (1)
    {
        control(setpoint);
    }
    delay(1);
    // TODO到達したかどうか判定
}

void DcMotorController::control(double setpoint)
{
    double duty = pid.calculate(setpoint, sps->convertedValue());
    dcMotor.setSpeed(dcMotor.getPwmMaxOutput() * duty);
    delay(DC_MOTOR_CYCLE_TIME);
}