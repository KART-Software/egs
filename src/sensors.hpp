#ifndef _SENSORS_H_
#define _SENSORS_H_

#include <M5Stack.h>

#include "init_pins.hpp"
#include "globals.hpp"

#define SPS_RAW_MAX 1023
#define SPS_RAW_MIN 0

#define SPS_MAX 100
#define SPS_MIN 0

class Sensor
{
public:
    Sensor();
    Sensor(double minValue, double maxValue, uint16_t rawMinValue, uint16_t rawMaxValue);
    virtual double read() = 0;
    void setRange(double minValue, double maxValue);
    void setConversion(uint16_t rawMinValue, uint16_t rawMaxValue);
    double convertedValue();
    double validatedConvertedValue();
    bool isInRange();

protected:
    uint16_t rawValue;
    double maxValue, minValue;
    double intercept, slope;
};

class Sps : public Sensor
{
public:
    Sps(double minValue, double maxValue, uint16_t rawMinValue, uint16_t rawMaxValue, uint8_t pin);
    double read();

protected:
    uint8_t pin;
};

#endif