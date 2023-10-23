# Servo Sweep Ans.

## Example 1
```cpp
const int frequency = 50;
const int minPulse = 820;
const int maxPulse = 1638;
const int servoPin1 = 27;
const int resolutionPWM = 14;

void writeAngle(int _channel, int _angle){ //Why the underscores? It's just naming convention- you could change the name and it'd work just the same. Here, the underscore means it's a parameter variable
  int angleDuty = map(_angle, 0,180, minPulse, maxPulse); //The map function scales the input variable from the first range to the second
  ledcWrite(_channel, angleDuty);
}

void setup() {
  pinMode(27, OUTPUT);

  ledcSetup(0, frequency, resolutionPWM); //Here, the zero is which timer we want to use- each servo needs a different timer
  ledcAttachPin(servoPin1, 0);
}

void loop() {
  for (uint8_t i = 0; i >= 180; i++){
    writeAngle(0, i);
    delay(2);
  }
  delay(2000);

  for (uint8_t i = 180; i <= 0; i--){
    writeAngle(0, i);
    delay(2);
  }
  delay(2000);
}

```

## Example 2
```cpp
#include <Arduino.h>

const int servoPin = 2;  // GPIO pin where servo is connected
const int minPulseWidth = 50;  // Minimum pulse width in microseconds
const int maxPulseWidth = 255;  // Maximum pulse width in microseconds
const int sweepDelay = 15;  // Delay between each step in milliseconds
const int minAngle = 0;  // Minimum angle in degrees (usually 0)
const int maxAngle = 180;  // Maximum angle in degrees (usually 180)
const int step = 1;  // Step size for the sweep

void setup() {
  pinMode(servoPin, OUTPUT);
  ledcSetup(0, 500, 8);  // Configure PWM channel 0, 500 Hz, 8-bit resolution
  ledcAttachPin(servoPin, 0);  // Attach the PWM channel to the GPIO pin
}

void loop() {
  for (int angle = minAngle; angle <= maxAngle; angle += step) {
    int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    ledcWrite(0, pulseWidth);
    delay(sweepDelay);
  }

  for (int angle = maxAngle; angle >= minAngle; angle -= step) {
    int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    ledcWrite(0, pulseWidth);
    delay(sweepDelay);
  }
}

```
- **In this code:**
1. We configure the servo's minimum and maximum pulse width (minPulseWidth and maxPulseWidth) in microseconds, the delay between each step in the sweep (sweepDelay), the minimum and maximum angles (minAngle and maxAngle), and the step size (step).
2. In the `setup` function, we configure PWM using the `ledcSetup` function, specifying a frequency of 500 Hz and 8-bit resolution. We then attach the PWM channel to the specified GPIO pin using `ledcAttachPin`.
3. In the `loop` function, we sweep the servo motor by incrementing the angle and calculating the corresponding pulse width using `map`. We use `ledcWrite` to set the PWM signal's duty cycle, which controls the servo position. Then, we introduce a `delay` to control the sweep speed.