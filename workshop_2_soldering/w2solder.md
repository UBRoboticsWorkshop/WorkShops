# Soldering and intro to SMD

## Setup

<img width="845" alt="Screenshot 2023-10-18 at 13 28 03" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/a04dae0f-e5e0-4d03-ab2c-8e5dd94de09f">
<img width="1125" alt="Screenshot 2023-10-18 at 13 28 35" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/c560d327-301c-48ab-a3be-fac3ccab1472">

Below the computer is your VirtualBench, press the power button located in the top left corner
Then press the Start button on you PCs and open up 'NI VirtualBnech'

![WhatsApp Image 2023-10-18 at 13 29 18](https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/f22a9f6e-fd13-4c0b-ab12-9efbb5c7a08f)

It'll then prompt you to search or connect to a device, there should only be one device availabe select it.

// Image of main picture
The application should then take you to a screen like the one shown above

![WhatsApp Image 2023-10-18 at 13 29 19](https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/ee66a5d8-f01a-4ee2-a222-eab04aa69e59)

Press the default button located in the top left corner of the screen, this will clear up an previously set configuration

//Image of connections
On the device itself connect 2 oscilloscope probes, one to channel 1 and the other to the function generator port
Oscilloscope probes typically consist of an alligator clip (ground) connected to the side, a witch's hat and the main probe itself

#### Next were going to generate a PWM signal

- A PWM signal is essentially a square wave signal that has 2 defining parameter, duty cycle and frequency.
- Frequency is the amount of cycles per second measured in Hz
- Duty cycle can be defined as the percentage of the period for which the signal is high.
- 0% -> OFF
- 50% -> On for half the time
- 100% -> being fully on
- During this lab we'll be showing you 2 similar yet unique ways to use these signals.

## Lets get started

Connect the grounds (alligator clips) of the Function generator and channel 1 probes and then connect the probes themself to one another.
When a signal is put through the function generator, it will now be displayed on the screen through channel 1.

### Generating a PWM signal //TRIGGER

1. In the Ni Virtual Bench environment find the frequency generator window

2. Press the power button located in the respective window
3. Change signal type to square and have a play around with the different settings
4. Change the offset to 2.5 and the amplitude to 5 - What does changing the frequency do? - What does changing the duty cycle do? Spend a maximum of 5 minutes on this

Undo the connections that you made in the 'Lets get started section'

### Controlling a DM996 Servo

1. Get 2 banana plug leads, plug one into the +6V port and the other into ground (make sure the other ends have alligator clips attached)

2. Grab 2 male to male jumpers and connect them to the 2 leads

3. Connect the positive jumper to the red servo port and the negative jumper to the brown servo port.
   You have now connected the power cables to the servo, the servo will draw all its actuating power from this source.

4. Now connect the ground of the function generator to the ground of the power leads.

5. Use another jumper to bridge between the function generator probe to the orange wire of the servo.
   You have now connected the signal cable, it will carry the PWM signal which you will encode with information (desired angle), through the variation of the duty cycle.

6. In the NI VirtualBench environment, change the frequency to 50Hz, amplitude to 5V, signal type to square and duty cycle to 0%
   Why? - Because that what the datasheet specifies, most actuators come with a datasheet that gives you all the information you need to know on operating the device.
   For the curious among you here's a link to a site with the datasheet 'https://components101.com/motors/mg996r-servo-motor-datasheet'

7. In the DC power window set voltage to 4.8V-7.2V and current to 2.5A

8. Click the power button for both the DC power and the function generator

9. Increment the duty cycle, the motor should rotate accordingly

10. Compare with the people around you are there any differences in the motors behaviour? Why?

11. Turn off the function generator and the DC supply

### Controlling a DC Motor using a half bridge

What is a Halfbridge
-blah blah
Tools
Wire
Wire stripper
TT motor
MX1508 Motor driver module
Soldering iron
Solder

1. Prepare your wires, cut them to length and strip them.

2. Solder 2 to the TT Motor contacts as shown

3. Solder the other 2 ends of the wires to MOTOR-A on the MX1508.

4. Now solder some more wires to IN1, IN2, positive and negative

5. Connect the function generator to probe to IN1 and ground to the ground (negative) of the MX1508

6. Connect the DC supply (via the banana plugs) to the positive and negative of the MX1508

7. In the NI VirtualBench environment change the frequency to 20kHz, amplitude 5V, offset 2.5V and duty cycle 0%

8. Turn on both the DC power supply and the function generator.

9. Increment the duty cycle, the motor should begin to spin around 45%
