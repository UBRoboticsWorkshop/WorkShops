# Code

# 1. Servo
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

const int frequency = 50; //Set frequency of the PWM wave
const int minPulse = 820; //Minimum pulse length in arbitary PWM units
const int maxPulse = 1638; //Max pulse length
const int servoPin1 = 27; //Which pin to put the servo on 
const int resolutionPWM = 14; //Number of bits for the PWM to indicate fully on- 2^14=16384

void writeAngle(int _channel, int _angle){ //Why the underscores? It's just naming convention- you could change the name and it'd work just the same. Here, the underscore means it's a parameter variable
  int angleDuty = map(_angle, 0,180, minPulse, maxPulse); //The map function scales the input variable from the first range to the second
  ledcWrite(_channel, angleDuty); //Set the selected channel to the calculated duty from above
}

void setup() {
  pinMode(servoPin1, OUTPUT); //Set the pin we connected the signal wire as an output

  ledcSetup(0, frequency, resolutionPWM); //Here, the zero is which timer we want to use- each servo needs a different timer
  ledcAttachPin(servoPin1, 0); //Set the pwm channel to output on the pin which the servo is connected to
}

void loop() {
  writeAngle(0, 0); //Set channel zero- connected to servoPin1- to zero degrees
  delay(750); //Do nothing for 750ms
  writeAngle(0, 180); //Set channel zero to 180 degrees
  delay(750);
}
```

# 2. Class
```cpp
class Servo{
  const int frequency = 50;
  const int resolution = 14;
  int channel;
  int minPulse;
  int maxPulse;
  int pin;

public:
  Servo(int _pin, int _minPulseMicros, int _maxPulseMicros, int _channel){
    int periodus = 1000000/50; //1 sec = 1 000 000 micros
    minPulse = float(1<<resolution)*(float(_minPulseMicros)/float(periodus));
    maxPulse = float(1<<resolution)*(float(_maxPulseMicros)/float(periodus));
    pin = _pin;
    channel = _channel;
    ledcSetup(channel, frequency, resolution);
    ledcAttachPin(_pin, channel);
  }

  Servo(int _pin, int _channel){
    int periodus = 1000000/50; //1 sec = 1 000 000 micros
    int minPulse = float(1<<resolution)*(float(1000)/float(periodus));
    int maxPulse = float(1<<resolution)*(float(2000)/float(periodus));
    pin = _pin;
    channel = _channel;
    ledcSetup(channel, frequency, resolution);
    ledcAttachPin(_pin, channel);
  }

  void writeAngle(int _angle){
    int angleDuty = map(_angle, 0,180, minPulse, maxPulse); //The map function scales the input variable from the first range to the second
    ledcWrite(channel, angleDuty);
  }
};

Servo newServo(27, 500, 2500, 0);

void setup() {
  
}

void loop() {
  newServo.writeAngle(0);
  delay(500);
  newServo.writeAngle(180);
  delay(500);
}
```
