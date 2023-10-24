# Control Servos With a Switch
Combine this code with the code from the previous to make the servo move between two positions when the button is pressed.

```cpp
#include <Arduino.h>

const int servoPin = 2;  // GPIO pin where servo is connected
uint8_t pulseWidth = 50;
unsigned long lastInterruptTime = 0;

void handleInterrupt() {
  // This function will be called when the falling edge of GPIO 0 is detected.

  // Record the current time
  unsigned long currentMillis = millis();

  // Check if the interrupt occurred after a debounce delay
  if (currentMillis - lastInterruptTime >= 100) {
    ledcWrite(0, pulseWidth);
    pulseWidth += 10;
    if (pulseWidth < 50) { pulseWidth = 50;}
  }

  // Update the last interrupt time
  lastInterruptTime = currentMillis;
}

void setup() {
  pinMode(servoPin, OUTPUT);
  ledcSetup(0, 500, 8);  // Configure PWM channel 0, 500 Hz, 8-bit resolution
  ledcAttachPin(servoPin, 0);  // Attach the PWM channel to the GPIO pin

  pinMode(0, INPUT_PULLUP); // Configure GPIO 0 as input with internal pull-up resistor
  attachInterrupt(digitalPinToInterrupt(0), handleInterrupt, FALLING);
}

void loop() {
  delay(10000);
}


```
