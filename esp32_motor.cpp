#include <esp32_motor.hpp>

esp32_motor::esp32_motor(int8_t forward_pin, int8_t backward_pin, int8_t channel_number_forward, int8_t channel_number_backward, int frequency, int resolution) {
    ledcAttachPin(forward_pin, channel_number_forward);
    ledcAttachPin(backward_pin, channel_number_backward);
    forward = channel_number_forward;
    backward = channel_number_backward;
    ledcSetup(channel_number_backward, frequency, resolution);
    ledcSetup(channel_number_forward, frequency, resolution);
    maxPWM = (unsigned int)pow(2,resolution)-1;
}

void esp32_motor::Run(int PWM) {
    if (PWM>maxPWM) {PWM = maxPWM;}
    if (PWM<-maxPWM) {PWM = -maxPWM;}
    ledcWrite(forward, (PWM>0)?(PWM):(0));
    ledcWrite(backward, (PWM>0)?(0):(-PWM));
}

void esp32_motor::RunPercentage(double percentage) {
    Run(decimalMap(percentage,0,100,0,maxPWM));
}

void esp32_motor::Stop() {
    ledcWrite(forward,maxPWM);
    ledcWrite(backward,maxPWM);
}

double esp32_motor::decimalMap(double x, double in_min, double in_max, double out_min, double out_max) {
    const double run = in_max - in_min;
    if(run == 0){
        log_e("decimalMap(): Invalid input range, min == max");
        return -1;
    }
    const double rise = out_max - out_min;
    const double delta = x - in_min;
    return (delta * rise) / run + out_min;
}