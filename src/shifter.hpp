#include "sensors.hpp"
#include "dc_motor_controller.hpp"
#include "statuses.hpp"

class Shifter
{
public:
    Shifter(Sps *sps, DcMotorController *dcmotorcontroller);
    bool upShift();
    bool downShift();
    GearPosition getGearPosition();
    ShiftStatus getShiftStatus();

private:
    GearPosition gearPosition;
    ShiftStatus shiftStatus;
};