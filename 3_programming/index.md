# programming

---
# 1. Setup
1. Download and install Arduino IDE 2.x
2. Add ESP32 Boards
3. Install serial port driver

---
# 2. Hello word!
1. what is function
2. what is ``` void setup() { // setup } ```
3. what is ``` void loop() { // loop code } ```
4. Serial port code
``` cpp
void setup() {
  Serial.begin(115200);
}
void loop() {
  Serial.println("Hi!");
  delay(5000);
}
```

---
# 3. PWM and GPIOs

# 3.1.1. Application: Servos (PWM)

# 3.1.2. Application: Servos with a GPIO as an input 

# 3.2. Drive MX1508

---
# 4. What are libraries and how to install them

# 4.1. Use libraries to drive MX1508 and Servos

# 4.2. Use libraries to set up a WiFi

---
# 5. Advanced: Class

# 5.1. Advanced: Head files

# 5.2. Advanced: Write your own libraries

# 5.3. Advanced: SDK - ESP-IDF
