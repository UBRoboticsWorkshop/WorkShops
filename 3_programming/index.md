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
## 1.3. [Install serial port driver](./driver_issue.md)

---
# 2. Hello word!
## 2.1. Serial port (UART) code

<img width="600" src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitc-functional-overview.jpg">

> we can communicate with ESP32 through UART. For convenience, the USB to UART bridge is embedded in the board.
* **Code:** We can use the Serial [class](https://www.w3schools.com/cpp/cpp_classes.asp) to transfer data between PC and ESP32. Go to `File` > `New Sketch`, and copy the following code:

``` cpp
void setup() { // setup function returns nothing
  Serial.begin(115200); // call Serial class, begin function. BaudRate 115200
}

void loop() { // loop function
  Serial.println("Hi!"); // call Serial class, print line function. Print "Hi!"
  delay(5000); // delay for 5s
}
```

- **In the setup function:**
1. `void setup()` is a special function in Arduino programming that is called once when the microcontroller starts. It's used for initializing things that only need to be done once.
2. `Serial.begin(115200)` is a function call that initializes the serial communication with a baud rate of 115,200. The serial communication is a way for the microcontroller to send and receive data with an external device like a computer.

- **In the loop function:**
1. `void loop()` is another special function in Arduino programming that runs continuously after the setup function. Any code placed in this function will be executed in a loop until the microcontroller is turned off.
2. `Serial.println("Hi!")` is a function call that sends the text "Hi!" to the serial port. This is a way to communicate with a connected computer or other devices via a serial monitor.
3. `delay(5000)` is a function call that pauses the program for 5,000 milliseconds, which is equivalent to 5 seconds. This means that after printing "Hi!" to the serial monitor, the program will wait for 5 seconds before repeating the process.

## 2.2. Uploading the Code
- **Select the board you’re using:** Go to Tools > Board > ESP32 > ESP32 Dev Module. 
![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/61526569/b4bae2d8-02d4-477d-9ec8-9fb411a3fef5)

- Go to Tools > Port and select the COM port the ESP32 is connected to.

- Then, press the upload button and wait for the “Done uploading” message.

![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/61526569/b27423db-8f20-49be-9616-8209eac704bb)

> If you see a lot of dots (...) on the debugging window and the “Failed to connect to ESP32: Timed out waiting for packet header” message, that means you need to press the ESP32 on-board BOOT button after the dots start appearing.

## 2.3. Now Go to `Tools` > `Serial Monitor` to check the message send form ESP32

---
# 3. PWM and GPIOs

## 3.1.1 [ESP32 Pinout](pinout.md): 
<img width="600" src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitC-v4-pinout.png">

## 3.1.2. [Definition of PWM](https://en.wikipedia.org/wiki/Pulse-width_modulation)

## 3.2.1. Application: [Servo motor](https://www.youtube.com/watch?v=tHOH-bYjR4k) sweep

- **Go to `File` > `New Sketch`, and copy the following code:**

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


## 3.2.2. Advanced Application: [Control Servos by a input GPIO]()

## 3.3. Advanced Application: [Drive MX1508]()

---
# 4. What are libraries and how to install them
> Libraries are collections of pre-written code and functions that serve a specific purpose. They are designed to be reused and integrated into your own programs to perform common tasks or add specific functionalities without having to write all the code from scratch.
## 4.1. Use libraries to drive MX1508 and Servos
- **To drive MX1508 we need:** [ESP32MX1508@1.0.5](https://github.com/ElectroMagus/ESP32MX1508)
- **right click..., search ESP32MX1508, click install**
- **open the example**
- **Upload and test**

## 4.2. Use libraries to set up a WiFi / AP (ESP32 only supports 2.4GHz WiFi.)
- **WiFi:**
```cpp
#include <WiFi.h>

const char* ssid = "YourNetworkSSID"; // Replace with your Wi-Fi network SSID
const char* password = "YourNetworkPassword"; // Replace with your Wi-Fi network password

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  // Your code here
}

```

- **AP:**
```cpp
#include <WiFi.h>

const char* ssid = "YourSSID";  // Replace with your desired SSID
const char* password = "YourPassword";  // Replace with your desired password

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.println("ESP32 AP Started");
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);
}

void loop() {
  // Your code here
}

```
---
# 5. Advanced:

## 5.1. Class

## 5.2. Advanced: Head files

## 5.3. Advanced: Write your own libraries

## 5.4. Advanced: SDK - ESP-IDF
