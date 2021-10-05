#ifndef _STATUSES_H_
#define _STATUSES_H_

#define SHIFT_POSITION_NEUTRAL 0 * PI / 180
#define SHIFT_POSITION_FIRST 72 * PI / 180
#define SHIFT_POSITION_SECOND 144 * PI / 180
#define SHIFT_POSITION_THIRD 216 * PI / 180
#define SHIFT_POSITION_TOP 288 * PI / 180

#define NUM_OF_SHIFT 5

double shiftPositions[NUM_OF_SHIFT] = {SHIFT_POSITION_NEUTRAL,
                                       SHIFT_POSITION_FIRST,
                                       SHIFT_POSITION_SECOND,
                                       SHIFT_POSITION_THIRD,
                                       SHIFT_POSITION_TOP};

enum class GearPosition
{
    Neutral,
    First,
    Second,
    Third,
    Top,
};

enum class ShiftStatus
{
    Shifting,
    Idle,
};

#endif