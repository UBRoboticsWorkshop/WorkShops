# programming

---
# 0. Intro

<img width="300" height="60" src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2022/10/espressif-logo.png?resize=300%2C60&amp;quality=100&amp;strip=all&amp;ssl=1">

## **what is an ESP32? Why are they so popular?**
* **Low-cost:** You can get an ESP32 starting at 6, which makes it easily accessible to the general public;
* **Low-power:** The ESP32 consumes very little power compared with other microcontrollers, and it supports low-power mode states like deep sleep to save power;
* **Wi-Fi capabilities:** The ESP32 can easily connect to a Wi-Fi network to connect to the internet (station mode), or create its own Wi-Fi wireless network (access point mode) so other devices can connect to it—this is essential for IoT and Home Automation projects—you can have multiple devices communicating with each other using their Wi-Fi capabilities;
* **Bluetooth:** The ESP32 supports Bluetooth classic and Bluetooth Low Energy (BLE)—which is useful for a wide variety of IoT applications;
* **Dual-core:** most ESP32 are dual-core— they come with 2 Xtensa 32-bit LX6 microprocessors: core 0 and core 1.
* **Rich peripheral input/output interface—** The ESP32 supports a wide variety of input (read data from the outside world) and output (to send commands/signals to the outside world) peripherals like capacitive touch, ADCs, DACs, UART, SPI, I2C, PWM, and much more.
* **Compatible with the Arduino “programming language”:** Those who are already familiar with programming the Arduino board, ’ll be happy to know that they can program the ESP32 in the Arduino style.
* **Compatible with MicroPython:** You can program the ESP32 with MicroPython firmware, which is a re-implementation of Python 3 targeted for microcontrollers and embedded systems.

---
# 1. Setup
## 1.1. [Download and install Arduino IDE 2.x](./install_Arduino.md)
## 1.2. [Add ESP32 Boards](./install_Arduino.md)
## 1.3. [Install serial port driver]()

---
# 2. Hello word!
## 2.1. Serial port (UART) code

<img width="600" src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitc-functional-overview.jpg">

* **image above:** we can communicate with ESP32 through UART. For convenience, the USB to UART bridge is embedded in the board.
* **Code below:** We can use the Serial [class](https://www.w3schools.com/cpp/cpp_classes.asp) to transfer data between CP and ESP32. Go to File > New Sketch, and copy the following code.

``` cpp
void setup() { // setup function returns nothing
  Serial.begin(115200); // call Serial class, begin function. BaudRate 115200
}

void loop() { // loop function
  Serial.println("Hi!"); // call Serial class, print line function. Print "Hi!"
  delay(5000); // delay for 5s
}
```
## 2.2. Uploading the Code
- **Select the board you’re using:** Go to Tools > Board > ESP32 > ESP32 Dev Module. 
![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/61526569/b4bae2d8-02d4-477d-9ec8-9fb411a3fef5)

- Go to Tools > Port and select the COM port the ESP32 is connected to.

- Then, press the upload button and wait for the “Done uploading” message.

![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/61526569/b27423db-8f20-49be-9616-8209eac704bb)

`If you see a lot of dots (…__…__) on the debugging window and the “Failed to connect to ESP32: Timed out waiting for packet header” message, that means you need to press the ESP32 on-board BOOT button after the dots start appearing.`

## 2.3. Now Go to Tools > Serial Monitor to check the message send form ESP32

---
# 3. PWM and GPIOs

## 3.1.1 [ESP32 Pinout](pinout.md): 
<img width="600" src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitC-v4-pinout.png">

## 3.1.2. [Definition of PWM](https://en.wikipedia.org/wiki/Pulse-width_modulation)

## 3.2.1. Application: [Servo motor](https://www.youtube.com/watch?v=tHOH-bYjR4k) sweep

## 3.2.2. Advanced Application: Drive Servos with a GPIO as an input 

## 3.3. Advanced Application: Drive MX1508

---
# 4. What are libraries and how to install them

## 4.1. Use libraries to drive MX1508 and Servos

## 4.2. Use libraries to set up a WiFi

---
# 5. Advanced:

## 5.1. Class

## 5.2. Advanced: Head files

## 5.3. Advanced: Write your own libraries

## 5.4. Advanced: SDK - ESP-IDF
