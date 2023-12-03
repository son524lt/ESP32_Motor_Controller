#include <Arduino.h>
#ifndef _ESP32_MOTOR_H_
#define _ESP32_MOTOR_H_

class esp32_motor
{
private:
    int maxPWM;
    double decimalMap(double, double, double, double, double);
public:
    uint8_t forward, backward;
    esp32_motor(int8_t forward_pin, int8_t backward_pin, int8_t channel_number_forward, int8_t channel_number_backward, int frequency, int resolution);
    void Run(int PWM);
    void RunPercentage(double percentage);
    void Stop();
};


#endif