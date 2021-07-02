#include <M5Stack.h>

class DcMotor
{
public:
    DcMotor(uint8_t pin1, uint8_t pin2);
    void rotate(float angle);

private:
};