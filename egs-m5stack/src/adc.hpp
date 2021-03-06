#ifndef _ADC_H_
#define _ADC_H_

#include <M5Stack.h>
#include <Wire.h>

#define ADC_ARDUINO_ADDRESS 9
#define READ_BYTE_LENGTH 2
#define READ_DATA_LENGTH 1

class Adc
{
public:
    Adc(uint8_t address, TwoWire *wire = &Wire);
    bool begin();
    void read();
    uint16_t value[READ_DATA_LENGTH];

private:
    const uint8_t address;
    TwoWire *wire;
};

#endif