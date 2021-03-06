#ifndef _SERIAL_LOGGER_H_
#define _SERIAL_LOGGER_H_

#define SERIAL_SPEED 115200

#include <M5Stack.h>
#include "statuses.hpp"

class SerialLogger
{
public:
    void initialize();
    void log(unsigned int cycleTime, double spsValue, GearPosition gearPosition);
};

#endif
