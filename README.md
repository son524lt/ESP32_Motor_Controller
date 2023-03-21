# ESP32_Motor_Controller

Description: Class esp32_motor for ESP32 motor control with 2 PWM channels for each motor

## Usage:
    // Init motor:
        esp32_motor motor1(forward_pin, backward_pin, channel_forward, channel_backward, pwm_frequency, pwm_resolution);

    // Run motor:
        motor1.Run(PWM); //PWM can be negative to run motor backward
