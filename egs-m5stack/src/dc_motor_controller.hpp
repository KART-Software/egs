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

#define SAME_POSITION_THRESHOLD 5 * PI / 180
#define SAME_POSITION_THRESHOLD_TIME 100

class ArrivalChecker
{
public:
    ArrivalChecker(Sps *sps);
    void setSetpoint(double setpoint);
    void update();
    bool hasArrived();

private:
    Sps *sps;
    double setpoint;
    bool isOnTargetPosition;
    uint32_t ms;
    uint32_t lastDifferentPositionTime;
};

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
    ArrivalChecker arrivalChecker;
    double sp, speed, setpoint;
    void setOutputLimit();
};

#endif