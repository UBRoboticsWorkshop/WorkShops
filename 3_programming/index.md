# Programming Actuators on ESP32

---
# 0. Intro
**[ESP32 Modules by Espressif](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf):**
The ESP32 is a highly versatile microcontroller. It has a lot of built-in functionality (listed). This makes it perfect for many projects, especially when prototyping as it is quick to set up, and features can be tested easily. For instance, testing Wi-Fi capability on your robot will be much easier than with many other microcontrollers as the required hardware is built-in already. 
It also has a small form factor especially considering these features and number of GPIO pins. Overall, the ESP32 is an excellent choice for a project that has many systems in place, while saving space in the circuit.
- **Xtensa dual-core 32-bit LX6 microprocessor, up to 240 MHz**
- **4 MB Flash**
- **Wi­Fi**
- **Bluetooth® + Bluetooth LE module**
- **26 GPIOs**
- **Many interfaces:** SD card, UART, SPI, SDIO, I2C, LED PWM, Motor PWM, I2S, IR, pulse counter, GPIO, capacitive touch sensor, ADC, DAC, TWAI®
Make sure to use a new file for each section.
---
# 1. Setup
## 1.1. [Download and install Arduino IDE 2.x, Add ESP32 Boards](./install_Arduino.md)
## 1.2. [Install serial port driver](./driver_issue.md)

---
# 2. Hello word!

## 2.1. Serial port (UART) code

<img width="600" src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitc-functional-overview.jpg">

> we can communicate with ESP32 through UART.
* **Code:** Go to `File` > `New Sketch`, and copy the following code:
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

Although the ESP32 does support an external debugger for advanced debugging, using Serial.println() can be a very useful way to see what a variable is doing. Just make sure you have Serial.begin() in the setup function of your code!

**If your serial port is printing random symbols, make sure that the baud rate on your veiwer matches the number in serial.begin(). It's likely that it will be set to 9600 by default, however this is a very slow speed for data transfer and the ESP32 can go much faster (>1000000)**

## 2.2. Uploading the Code
- **Select the board:** Go to Tools > Board > ESP32 > ESP32 Dev Module. 
![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/61526569/b4bae2d8-02d4-477d-9ec8-9fb411a3fef5)
- Go to `Tools` > `Port` and select the COM port the ESP32 is connected to. (can't find the port? [click here](./driver_issue.md))
- Then, press the `upload` button and wait for the “Done uploading” message.
![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/61526569/b27423db-8f20-49be-9616-8209eac704bb)
> If you see a lot of dots (...) on the debugging window and the “Failed to connect to ESP32: Timed out waiting for packet header” message, that means you need to press the ESP32 on-board BOOT button after the dots start appearing.

## 2.3. Now Go to `Tools` > `Serial Monitor` to check the message send form ESP32

---

# 3. [ESP32 Pinout](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/): 

<img width="600" src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitC-v4-pinout.png">

---

# 4. Drive MX1508 and Servos
## 4.1. Drive MX1508, Using library: [ESP32MX1508@1.0.5](https://github.com/ElectroMagus/ESP32MX1508)

- Click on `Library Manger`. Search ESP32MX1508. Click install. (Second one)

![Alt text](image-5.png)

- Open examples: Go to `Files` > `Examples` > `ESP32MX1508` > `basic`

![Alt text](image-7.png)

- Connect the Wire, and upload the code. (In the Example: Pin9 and Pin10 are used. They are connected with internal SPI Flash. As a result, please change the pins. [ESP32 Pinout](pinout.md) If you don't know how to connect, click [Drive MX1508](./mx1508.md))

- Modify the code. (e.g. Drive 2 motors... feel free to ask for help. )

## 4.2. Move Servos Between 2 Points
> **Servo motor:** A servo motor is an actuator that uses feedback control to maintain its position. It works by receiving a [PWM](https://en.wikipedia.org/wiki/Pulse-width_modulation) signal, comparing it to its actual position, and making adjustments to minimize any error. This allows it to move to a specific position.
- **Go to `File` > `New Sketch`, and copy the following code:**
```cpp
/*
  The datasheet for these servos recommends 50Hz signal

  Period of waveform:
  1/50 = 20ms

  minimum pulse = 1000us
  max pulse = 2000us
  So max duty cycle is 10%
  Min duty cycle is 5%

  We've picked a 14 bit timer, so 2^14= 16384
  So max signal is 0.1*16384 = 1638
  Min signal is 0.05*16384 = 819

  This gives us ~800 steps- in practice, far more accuracy than the servo can deliver

  However, these servo motor makers just keep on lying to us- the min and max pulses are completely wrong. I don't know why everyone says they're 1-2ms.
  By tweaking the min and max values, you can get a whole 180 degrees out of these. This math will be left to you.
*/
```

>The code above is a multiline comment- when the code is converted into binary, anything between the /* and */ will be ignored. Here, the functionality of the code is introduced along with some of the maths behind it.

```cpp
const int frequency = 50; //Set frequency of the PWM wave
const int minPulse = 820; //Minimum pulse length in arbitary PWM units
const int maxPulse = 1638; //Max pulse length
const int servoPin1 = 27; //Which pin to put the servo on 
const int resolutionPWM = 14; //Number of bits for the PWM to indicate fully on- 2^14=16384
```
>This sets up some constants- these don't change during runtime, indicated by "const". The type of number is an integer, indicated by "int". We don't need decimal places here, so we save storage by not allowing them.
```cpp
void writeAngle(int _channel, int _angle){ //Why the underscores? It's just naming convention- you could change the name and it'd work just the same. Here, the underscore means it's a parameter variable
  int angleDuty = map(_angle, 0,180, minPulse, maxPulse); //The map function scales the input variable from the first range to the second
  ledcWrite(_channel, angleDuty); //Set the selected channel to the calculated duty from above
}
```

>This is a function- instead of typing out the whole angle to pulse code each time, we can just call this to do it automatically. "Void" means this function doesn't return anything, and the part inside the bracket is the variables we give to the function to tell it what to do. Here, we scale the range of angles (0-180) to the range of duty cycle (819-1638) so that we can control the servo in a more intuitive way. We then write the PWM channel selected by the variable to the scaled duty cycle with ledcWrite. The pulse value determines what percentage of time is spent on vs off- 16384 is always on, 0 is always off, 8192 would be a square wave with equal on time and off time. The servo will only respond to pulses of a certain duration, as calculated in the top comment section.

```cpp
void setup() {
  pinMode(servoPin1, OUTPUT); //Set the pin we connected the signal wire as an output

  ledcSetup(0, frequency, resolutionPWM); //Here, the zero is which timer we want to use- each servo needs a different timer
  ledcAttachPin(servoPin1, 0); //Set the pwm channel to output on the pin which the servo is connected to
}
```

>Setup is a function that only runs once, when the ESP32 turns on. We only need to set up PWM, set the pin as output and attach PWM to it once- otherwise, we're just wasting compute power.

```cpp
void loop() {
  writeAngle(0, 0); //Set channel zero- connected to servoPin1- to zero degrees
  delay(750); //Do nothing for 750ms
  writeAngle(0, 180); //Set channel zero to 180 degrees
  delay(750);
}
```

>This is the main loop- whenever the code gets to the botttom of the loop, it starts again at the top. Here, we use our custom function to set the servo between zero degrees and 180 degrees repeatedly. The servos don't have feedback- writeAngle() finishes near instantly, not when the servo gets to the position.


> For a Servo motor: <span style="color: red;">Red</span> - Vcc(5V), <span style="color: brown;">Brown</span> - GND, <span style="color: orange;">Orange</span> - Signal(PWM)
- Modify the example, Make the Servo Sweep. [Answer](./servo_sweep.md)

## 4.3. Advanced: [Control Servos by a button](./servo_with_interrupts.md)

## 4.4. Advanced: [Drive MX1508 without Lib](./mx1508.md)
---

# 5. Classes
> What's a class and why should you care? In robotics, classes are often used to describe a part- with a motor, we may have a set of things we need to do and know:
### Methods:
- Set speed
- Reverse
- Brake
- Freewheel
### Attributes:
- Current speed
- Target speed
- Voltage of supply
- Current draw
> And so on. With classes, we can wrap this up into one "Object", and create multiple "instances" of it. And if this hasn't made you care about classes... sorry :(
## 5.1.
```cpp
class Servo{
```
>This line indicates the start of the class, which is everything inside the curly brackets.

```cpp
  const int frequency = 50;
  const int resolution = 14;
  int channel;
  int minPulse;
  int maxPulse;
  int pin;
```
>Here, we set up the different variables we'll use to control the Servo. Frequency and resolution are unlikely to vary between servos, but they can be adjusted here if need be. The other four are declared, but not given a value. We'll sort them later. These variables can't be accessed outside the class, we have to use a function to access them. If you want to access them outside the class, move them below the "public:" tag.

```cpp
  public:
  Servo(int _pin, int _minPulseMicros, int _maxPulseMicros, int _channel){
    int periodus = 1000000/50; //1 sec = 1 000 000 micros
    minPulse = float(1<<resolution)*(float(_minPulseMicros)/float(periodus));
    maxPulse = float(1<<resolution)*(float(_maxPulseMicros)/float(periodus));
    pin = _pin;
    channel = _channel;
    ledcSetup(channel, frequency, resolution);
    ledcAttachPin(pin, channel);
  }
```
>Here is the start of the "public:" tag. This means that anything below it can be accessed outside the object, while any variables or functions above can only be called inside the class.
>We also have a "constructor"- this is a neat way to tell an object its attributes when we create it- as seen later in the code. Unlike the previous code, here we can put in the pulse length in microseconds- the code does all of the maths for us. It will also adjust automatically to changes in other parameters such as resolution or frequency, making the code easier to work with. You'll also notice that some variables are wrapped in "float()"- this converts them into values that tolerate decimal points. Otherwise integer division would be performed, ie 3/10=0- a loss of accuracy that is very likely to cause problems.

```cpp
  Servo(int _pin, int _channel){
    int periodus = 1000000/50; //1 sec = 1 000 000 micros
    int minPulse = float(1<<resolution)*(float(1000)/float(periodus));
    int maxPulse = float(1<<resolution)*(float(2000)/float(periodus));
    pin = _pin;
    channel = _channel;
    ledcSetup(channel, frequency, resolution);
    ledcAttachPin(pin, channel);
  }
```
>Overloading, as seen here, is where two identical function names are used with different parameters. Here, one allows for you to calibrate pulse length while the other defaults to 1-2ms- for a servo that just needs to "move", you probably don't care about accuracy and so a simpler setup is useful. When we call it, it'll automatically use the right one depending on the parameters we give it. The variables _pin and _channel will stop existing when the constructor is done, so we copy them to the class's variables pin and channel to store them.
>Periodus denotes the period in microseconds. Micro is generally Mu, but using u saves time. If you're subscribed to UBRobotics premium available for a reasonable £500 per year, you can copy paste in this "mu". 
```cpp
μ
```
>Don't try to use it if you're not subscribed to UBRobotics premium available for a reasonable £500 per year, it won't compile.
```cpp
  void writeAngle(int _angle){
    int angleDuty = map(_angle, 0,180, minPulse, maxPulse); //The map function scales the input variable from the first range to the second
    ledcWrite(channel, angleDuty);
  }
```
>Same function as before, but now attatched to the specific servo- we don't need to pass a channel number, we can call the servo by name. If you have a project with 20 servos, it's much easier to remember "frontLeftKnee" than channel 15. 
```cpp
};
```
>Close the class off

```cpp
Servo newServo(27, 500, 2500, 0);
```
>Here we use the constructor. If you hover over "newServo" in the IDE 2.0, you'll get a window showing you the variable name of each parameter. We've also defined the pulse width manually, to make the servo more accurate.

```cpp
void setup() {
  
}

```
>Nothin' to set up.


```cpp
void loop() {
  newServo.writeAngle(0);
  delay(500);
  newServo.writeAngle(180);
  delay(500);
}
```
>Beep Boop
---

# 6. Header files

## 6.1.
```cpp
#include "file_name.h"
```
---

# 7. Libraries
> Libraries are collections of pre-written code and functions that serve a specific purpose. They are designed to be reused and integrated into your own programs to perform common tasks or add specific functionalities without having to write all the code from scratch.
