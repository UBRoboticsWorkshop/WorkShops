# programming

---
# 0. Intro

<img width="300" height="60" src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2022/10/espressif-logo.png?resize=300%2C60&amp;quality=100&amp;strip=all&amp;ssl=1">
<img width="600" src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitc-functional-overview.jpg">

## **what is an ESP32? Why are they so popular?**
* **Low-cost:** you can get an ESP32 starting at 6, which makes it easily accessible to the general public;
* **Low-power:** the ESP32 consumes very little power compared with other microcontrollers, and it supports low-power mode states like deep sleep to save power;
* **Wi-Fi capabilities:** the ESP32 can easily connect to a Wi-Fi network to connect to the internet (station mode), or create its own Wi-Fi wireless network (access point mode) so other devices can connect to it—this is essential for IoT and Home Automation projects—you can have multiple devices communicating with each other using their Wi-Fi capabilities;
* **Bluetooth:** the ESP32 supports Bluetooth classic and Bluetooth Low Energy (BLE)—which is useful for a wide variety of IoT applications;
* **Dual-core:** most ESP32 are dual-core— they come with 2 Xtensa 32-bit LX6 microprocessors: core 0 and core 1.
* **Rich peripheral input/output interface—** the ESP32 supports a wide variety of input (read data from the outside world) and output (to send commands/signals to the outside world) peripherals like capacitive touch, ADCs, DACs, UART, SPI, I2C, PWM, and much more.
* **Compatible with the Arduino “programming language”:** those that are already familiar with programming the Arduino board, you’ll be happy to know that they can program the ESP32 in the Arduino style.
* **Compatible with MicroPython:** you can program the ESP32 with MicroPython firmware, which is a re-implementation of Python 3 targeted for microcontrollers and embedded systems.

---
# 1. Setup
## 1.1. [Download and install Arduino IDE 2.x](./install_Arduino.md)
## 1.2. [Add ESP32 Boards](./install_Arduino.md)
## 1.3. [Install serial port driver]()

---
# 2. Hello word!
## 2.1. what is function
## 2.2. what is `void setup() { // setup }`
## 2.3. what is `void loop() { // loop code }`
## 2.4. Serial port code
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

## 3.1.1 [ESP32 Pinout](pinout.md): 
<img width="600" src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitC-v4-pinout.png">

## 3.1.2. [Definition of PWM](https://en.wikipedia.org/wiki/Pulse-width_modulation)

## 3.2.1. Application: Servos (PWM)

## 3.2.2. Application: Servos with a GPIO as an input 

## 3.3. Drive MX1508

---
# 4. What are libraries and how to install them

## 4.1. Use libraries to drive MX1508 and Servos

## 4.2. Use libraries to set up a WiFi

---
# 5. Advanced: Class

## 5.1. Advanced: Head files

## 5.2. Advanced: Write your own libraries

## 5.3. Advanced: SDK - ESP-IDF
