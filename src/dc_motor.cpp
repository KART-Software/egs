#include "dc_motor.hpp"

DcMotor::DcMotor(uint8_t pwmPin, uint8_t dirPin)
    : _pwmPin(pwmPin), _dirPin(dirPin)
{

    pinMode(_pwmPin, OUTPUT);
    pinMode(_dirPin, OUTPUT);

    digitalWrite(_pwmPin, LOW);
    digitalWrite(_dirPin, LOW);
}

void DcMotor::setPwm(uint8_t pwmChannel, double pwmFreqency, uint8_t pwmResolutionBits)
{
    _pwmChannel = pwmChannel;
    _pwmFrequency = pwmFreqency;
    _pwmResolutionBits = pwmResolutionBits;
    _pwmMaxOutput = pow(2, pwmResolutionBits) - 1;
    ledcSetup(pwmChannel, pwmFreqency, pwmResolutionBits);
    ledcAttachPin(_pwmPin, _pwmChannel);
}

void DcMotor::setSpeed(int32_t speed)
{
    // Make sure the speed is within the limit.
    speed = constrain(speed, -int32_t(_pwmMaxOutput), int32_t(_pwmMaxOutput));

    // Set the speed and direction.
    if (speed >= 0)
    {
        ledcWrite(_pwmChannel, speed);
        digitalWrite(_dirPin, LOW);
    }
    else
    {
        ledcWrite(_pwmChannel, -speed);
        digitalWrite(_dirPin, HIGH);
    }
}
uint16_t DcMotor::getPwmMaxOutput()
{
    return _pwmMaxOutput;
}