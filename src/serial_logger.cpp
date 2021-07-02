#include "serial_logger.hpp"

SerialLogger::SerialLogger() {}

void SerialLogger::initialize()
{
    Serial.begin(SERIAL_SPEED);
}

void SerialLogger::log(unsigned int cycleTime, double spsValue, GearPosition gearPosition)
{
    String logStr = "Cycle: " + String(cycleTime) +
                    ", SPS: " + String(spsValue) +
                    ", GearPosition: " + String(int(gearPosition));
    Serial.println(logStr);
}