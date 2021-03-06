#include "shifter.hpp"

Shifter::Shifter()
    : sps(Sps(SPS_MIN, SPS_MAX, SPS_RAW_MIN, SPS_RAW_MAX, SPS_PIN)),
      dcMotorController(DcMotorController(&sps))
{
}

GearPosition Shifter::getGearPosition()
{
    return gearPosition;
}

ShiftStatus Shifter::getShiftStatus()
{
    return shiftStatus;
}

bool Shifter::upShift(unsigned long timeout)
{
    GearPosition targetGearPosition = higherGear();
    if (gearPosition != targetGearPosition)
    {
        dcMotorController.goTo(shiftPosition(targetGearPosition));
        gearPosition = targetGearPosition;
    }
    // TODO タイムアウト処理
    // statusの更新
}

bool Shifter::downShift(unsigned long timeout)
{
    GearPosition originalGearPosition = gearPosition;
    GearPosition targetGearPosition = lowerGear();
    if (gearPosition != targetGearPosition)
    {
        dcMotorController.goTo(shiftPosition(targetGearPosition));
        gearPosition = targetGearPosition;
    }
}

GearPosition Shifter::higherGear()
{
    int positionNumber = (int)gearPosition;
    if (positionNumber == (int)GearPosition::Top)
    {
        return gearPosition;
    }
    else
    {
        return (GearPosition)(positionNumber + 1);
    }
}

GearPosition Shifter::lowerGear()
{
    int positionNumber = (int)gearPosition;
    if (positionNumber == 0)
    {
        return gearPosition;
    }
    else
    {
        return (GearPosition)(positionNumber - 1);
    }
}

double Shifter::shiftPosition(GearPosition gearPosition)
{
    return shiftPositions[(int)gearPosition];
}