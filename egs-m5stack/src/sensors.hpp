#ifndef _SENSORS_H_
#define _SENSORS_H_

#include <M5Stack.h>

#include "init_pins.hpp"
#include "globals.hpp"
#include "statuses.hpp"

#define SPS_RAW_MAX 1023
#define SPS_RAW_MIN 0

#define PI 3.14159265358979

#define SPS_MAX PI * 2
#define SPS_MIN 0

class Sensor
{
public:
    Sensor();
    Sensor(double minValue, double maxValue, double margin, int16_t rawMinValue, int16_t rawMaxValue);
    virtual double read() = 0;
    void setRange(double minValue, double maxValue);
    void setConversion(int16_t rawMinValue, int16_t rawMaxValue);
    double convertedValue();
    double validatedConvertedValue();
    GearPosition getGearPosition();
    bool isInRange();
    double getMaxValue();
    double getMinValue();

protected:
    int16_t rawValue;
    double maxValue, minValue;
    double margin;
    double intercept, slope;
};

class Sps : public Sensor
{
public:
    Sps(double minValue, double maxValue, int16_t rawMinValue, int16_t rawMaxValue, uint8_t pin);
    double read();

protected:
    uint8_t pin;
};

#endif