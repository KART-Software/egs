#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

#include <M5Stack.h>

class DcMotor
{
public:
  DcMotor(uint8_t pwmPin, uint8_t dirPin);
  void setPwm(uint8_t pwmChannel, double pwmFreqency, uint8_t pwmResolutionBits);
  void setSpeed(int32_t speed);
  uint16_t getPwmMaxOutput();

protected:
  uint8_t _pwmChannel;
  uint8_t _pwmPin;
  uint8_t _dirPin;
  double _pwmFrequency;
  uint8_t _pwmResolutionBits;
  uint16_t _pwmMaxOutput;
};

#endif
