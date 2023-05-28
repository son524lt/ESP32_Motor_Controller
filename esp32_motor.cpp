#include "esp32_motor.h"

esp32_motor::esp32_motor(int8_t forward_pin, int8_t backward_pin, int8_t channel_number_forward, int8_t channel_number_backward, int frequency, int resolution) {
    ledcAttachPin(forward_pin, channel_number_forward);
    ledcAttachPin(backward_pin, channel_number_backward);
    forward = channel_number_forward;
    backward = channel_number_backward;
    ledcSetup(channel_number_backward, frequency, resolution);
    ledcSetup(channel_number_forward, frequency, resolution);
    maxPWM = (uint)pow(2,resolution)-1;
}

void esp32_motor::Run(int PWM) {
    Serial.print(maxPWM);
    Serial.print("\t");
    Serial.print(PWM);
    Serial.print("\t");
    if (PWM>maxPWM) {PWM = maxPWM;}
    if (PWM<-maxPWM) {PWM = -maxPWM;}
    Serial.println(PWM);
    ledcWrite(forward, (PWM>0)?(PWM):(0));
    ledcWrite(backward, (PWM>0)?(0):(-PWM));
}

void esp32_motor::Stop() {
    ledcWrite(forward,maxPWM);
    ledcWrite(backward,maxPWM);
}