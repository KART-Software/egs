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
    GearPosition originalGearPosition = gearPosition;
    GearPosition targetGearPosition = higherGear();
    if (gearPosition != targetGearPosition)
    {
        dcMotorController.control(shiftPosition(targetGearPosition));
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
        dcMotorController.control(shiftPosition(targetGearPosition));
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
    switch (gearPosition)
    {
    case GearPosition::Neutral:
        return SHIFT_POSITION_NEUTRAL;

    case GearPosition::First:
        return SHIFT_POSITION_FIRST;

    case GearPosition::Second:
        return SHIFT_POSITION_SECOND;

    case GearPosition::Third:
        return SHIFT_POSITION_THIRD;

    case GearPosition::Top:
        return SHIFT_POSITION_TOP;
    }
}