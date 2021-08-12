#ifndef _DC_MOTOR_CONTROLLER_H_
#define _DC_MOTOR_CONTROLLER_H_

#include "dc_motor.hpp"
#include "sensors.hpp"
#include "init_pins.hpp"
#include "pid.hpp"

#define PWM_CHANNEL 0
#define PWM_FREQUENCY 9600
#define PWM_RESOLUTION_BITS 8

#define PID_KP 0.5
#define PID_KI 0.0
#define PID_KD 0.0

#define DC_MOTOR_CYCLE_TIME 30

class DcMotorController
{
public:
    DcMotorController(Sps *sps);
    void control(double setpoint);
    void goTo(double setpoint);
    void setDcMotorOn();
    void setDcMotorOff();

private:
    DcMotor dcMotor;
    Sps *sps;
    PID pid;
    double sp, speed, setpoint;
    void setOutputLimit();
};

#endif