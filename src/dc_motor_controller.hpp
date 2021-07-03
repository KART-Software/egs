#ifndef _DC_MOTOR_CONTROLLER_H_
#define _DC_MOTOR_CONTROLLER_H_

#include "dc_motor.hpp"
#include "sensors.hpp"

class DcMotorController
{
public:
    DcMotorController(Sps *sps);
    void control();
    void setDcMotorOn();
    void setDcMotorOff();

private:
    DcMotor dcMotor;
    Sps *sps;
    void setOutputLimit();
    int validateOutput();
};

#endif