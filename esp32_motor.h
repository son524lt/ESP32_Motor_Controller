#include "unistd.h"
#include <Arduino.h>
#include "esp32-hal-ledc.h"

#ifndef _ESP32_MOTOR_H_
#define _ESP32_MOTOR_H_

class esp32_motor
{
private:
public:
    uint maxPWM;
    uint8_t forward, backward;
    esp32_motor(int8_t forward_pin, int8_t backward_pin, int8_t channel_number, int8_t channel_number_backward, int frequency, int resolution);
    void Run(int PWM);
    void Stop();
};


#endif