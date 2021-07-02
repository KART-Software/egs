#ifndef _SERIAL_LOGGER_H_
#define _SERIAL_LOGGER_H_

#define SERIAL_SPEED 28800

#include <M5Stack.h>
#include "statuses.hpp"

class SerialLogger
{
public:
    SerialLogger();
    void initialize();
    void log(unsigned int cycleTime, double spsValue, GearPosition gearPosition);
};

#endif
