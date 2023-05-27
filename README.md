# ESP32_Motor_Controller

Description: Class esp32_motor for ESP32 motor controlling with 2 PWM channels for each motor

## Usage:
    // Init motor:
        esp32_motor motor1(forward_pin, backward_pin, 
            forward_pwm_channel, backward_pwm_channel, 
            pwm_frequency, pwm_resolution);

    // Run motor:
        motor1.Run(PWM); // set PWM value negative to reverse motor
    // Stop motor:
        motor1.Stop();
