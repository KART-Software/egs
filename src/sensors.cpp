#include "sensors.hpp"

Sensor::Sensor(double minValue, double maxValue, uint16_t rawMinValue, uint16_t rawMaxValue)
{
    setRange(minValue, maxValue);
    setConversion(rawMinValue, rawMaxValue);
}

void Sensor::setRange(double minValue, double maxValue)
{
    this->minValue = minValue;
    this->maxValue = maxValue;
}

void Sensor::setConversion(uint16_t rawMinValue, uint16_t rawMaxValue)
{
    this->slope = (maxValue - minValue) / (rawMaxValue - rawMinValue);
    this->intercept = (rawMaxValue * minValue - rawMinValue * maxValue) / (rawMaxValue - rawMinValue);
}

double Sensor::convertedValue()
{
    return rawValue * slope + intercept;
}

double Sensor::validatedConvertedValue()
{
    return constrain(convertedValue(), minValue, maxValue);
}

bool Sensor::isInRange()
{
    double value = convertedValue();
    if (value < minValue || value > maxValue)
    {
        return false;
    }
    return true;
}

Sps::
    Sps(double minValue, double maxValue, uint16_t rawMinValue, uint16_t rawMaxValue, uint8_t pin)
    : Sensor(minValue, maxValue, rawMinValue, rawMaxValue),
      pin(pin)
{
}

double Sps::read()
{
    // rawValue = analogRead(pin);
    rawValue = gAdc.value[pin];
    return validatedConvertedValue();
}