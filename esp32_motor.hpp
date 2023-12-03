#include <Arduino.h>
#ifndef _ESP32_MOTOR_H_
#define _ESP32_MOTOR_H_

class esp32_motor
{
private:
    int maxPWM;
    uint8_t forward, backward, forward_pin, backward_pin, res;
    uint32_t freq;
    double decimalMap(double, double, double, double, double);
public:
    esp32_motor(int8_t forward_pin, int8_t backward_pin, int8_t channel_number_forward, int8_t channel_number_backward, uint32_t frequency, uint8_t resolution);
    void init();
    void Run(int PWM);
    void RunPercentage(double percentage);
    void Stop();
};


#endif