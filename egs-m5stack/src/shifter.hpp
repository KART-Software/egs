#ifndef _SHIFTER_H_
#define _SHIFTER_H_

#include "sensors.hpp"
#include "dc_motor_controller.hpp"
#include "statuses.hpp"

#define SHIFT_TIMEOUT 1000

class Shifter
{
public:
    Shifter();
    bool upShift(unsigned long timeout);
    bool downShift(unsigned long timeout);
    GearPosition getGearPosition();
    ShiftStatus getShiftStatus();

private:
    Sps sps;
    DcMotorController dcMotorController;
    GearPosition gearPosition;
    ShiftStatus shiftStatus;
    GearPosition higherGear();
    GearPosition lowerGear();
    double shiftPosition(GearPosition);
};

#endif