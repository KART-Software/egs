#include "sensors.hpp"

Sensor::Sensor(double minValue, double maxValue, double margin, int16_t rawMinValue, int16_t rawMaxValue)
{
    setRange(minValue, maxValue);
    setConversion(rawMinValue, rawMaxValue);
}

void Sensor::setRange(double minValue, double maxValue)
{
    this->minValue = minValue;
    this->maxValue = maxValue;
}

void Sensor::setConversion(int16_t rawMinValue, int16_t rawMaxValue)
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

GearPosition Sensor::getGearPosition()
{
    convertedValue();
}

bool Sensor::isInRange()
{
    double value = convertedValue();
    if (value < minValue - margin || value > maxValue + margin)
    {
        return false;
    }
    return true;
}

double Sensor::getMaxValue()
{
    return maxValue;
}

double Sensor::getMinValue()
{
    return minValue;
}

Sps::
    Sps(double minValue, double maxValue, int16_t rawMinValue, int16_t rawMaxValue, uint8_t pin)
    : Sensor(minValue, maxValue, margin, rawMinValue, rawMaxValue),
      pin(pin)
{
}

double Sps::read()
{
    // rawValue = analogRead(pin);
    rawValue = gAdc.value[pin];
    return rawValue;
}