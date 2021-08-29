#include "dc_motor_controller.hpp"

DcMotorController::DcMotorController(Sps *sps)
    : dcMotor(DcMotor(DC_MOTOR_PWM_PIN, DC_MOTOR_DIR_PIN, DC_MOTOR_POWER_PIN)),
      sps(sps),
      pid(PID(PID_KP, PID_KI, PID_KD)),
      arrivalChecker(ArrivalChecker(sps))
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
    arrivalChecker.setSetpoint(setpoint);
    while (1)
    {
        control(setpoint);
        arrivalChecker.update();
        if (arrivalChecker.hasArrived())
        {
            break;
        }
    }
    delay(1);
}

void DcMotorController::control(double setpoint)
{
    double duty = pid.calculate(setpoint, sps->convertedValue());
    dcMotor.setSpeed(dcMotor.getPwmMaxOutput() * duty);
    delay(DC_MOTOR_CYCLE_TIME);
}

ArrivalChecker::ArrivalChecker(Sps *sps)
    : sps(sps)
{
    ms = millis();
    lastDifferentPositionTime = ms;
}

void ArrivalChecker::setSetpoint(double setpoint)
{
    this->setpoint = setpoint;
}

void ArrivalChecker::update()
{
    ms = millis();
    isOnTargetPosition = abs(sps->convertedValue() - setpoint) <= SAME_POSITION_THRESHOLD;
    if (!isOnTargetPosition)
    {
        lastDifferentPositionTime = ms;
    }
}

bool ArrivalChecker::hasArrived()
{
    return isOnTargetPosition && ms - lastDifferentPositionTime >= SAME_POSITION_THRESHOLD_TIME;
}