#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

#include <M5Stack.h>
#include <CytronMotorDriver.h>

class DcMotor : public CytronMD
{
public:
    DcMotor(MODE mode, uint8_t pin1, uint8_t pin2);
    void rotate(float angle);

private:
};

#endif