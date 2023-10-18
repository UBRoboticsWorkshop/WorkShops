# Soldering and intro to SMD

## Setup

<img width="100%" alt="Screenshot 2023-10-18 at 13 28 03" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/a04dae0f-e5e0-4d03-ab2c-8e5dd94de09f">

Below the computer is your VirtualBench, press the power button located in the top left corner

1. press the Start button on you PCs and open up 'NI VirtualBnech'

![WhatsApp Image 2023-10-18 at 13 29 18](https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/f22a9f6e-fd13-4c0b-ab12-9efbb5c7a08f)

2. It'll then prompt you to search or connect to a device, there should only be one device availabe select it. The application should then take you to a screen like the one shown above.

![WhatsApp Image 2023-10-18 at 13 29 19](https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/ee66a5d8-f01a-4ee2-a222-eab04aa69e59)

3. Press the default button located in the top left corner of the screen, this will clear up an previously set configuration

https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/073db8e7-e66d-4dd9-986e-72c3535ebe6d

4. On the device itself connect 2 oscilloscope probes, one to channel 1 and the other to the function generator port
   Oscilloscope probes typically consist of an alligator clip (ground) connected to the side, a witch's hat and the main probe itself

<img width="100%" alt="Screenshot 2023-10-18 at 13 28 35" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/c560d327-301c-48ab-a3be-fac3ccab1472">

#### Next were going to generate a PWM signal

- A PWM signal is essentially a square wave signal that has 2 defining parameter, duty cycle and frequency.
- Frequency is the amount of cycles per second measured in Hz
- Duty cycle can be defined as the percentage of the period for which the signal is high.
- 0% -> OFF
- 50% -> On for half the time
- 100% -> being fully on
- During this lab we'll be showing you 2 similar yet unique ways to use these signals.

<img width="748" alt="Screenshot 2023-10-18 at 14 02 51" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/4ce19679-f436-4506-9dd1-3fe1717b4d76">

## Lets get started

Connect the grounds (alligator clips) of the Function generator and channel 1 probes and then connect the probes themself to one another.
When a signal is put through the function generator, it will now be displayed on the screen through channel 1.

<img width="308" alt="Screen Shot 2023-10-18 at 1 35 40 PM" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/92c7b042-ed68-41ad-92e0-78a160f2e3a2">

THESE ARE CROCODILE CLIPS BTW

<img width="115" alt="Screen Shot 2023-10-18 at 1 36 14 PM" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/f384fccc-c4c8-44b8-ae33-a7f9e13ca484">

### Generating a PWM signal

<img width="599" alt="Screen Shot 2023-10-18 at 1 36 54 PM" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/886ecfd7-e0a4-4c71-8993-8c5c50c4d9b7">

1. In the Ni Virtual Bench environment find the frequency generator window

2. Press the power button located in the respective window

3. Change signal type to square and have a play around with the different settings

   <img width="154" alt="Screen Shot 2023-10-18 at 1 37 56 PM" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/dc67d1b1-faed-496b-8998-fad1e6e97fb2">

4. Change the offset to 2.5 and the amplitude to 5

5. Turn on the function generator

![WhatsApp Image 2023-10-18 at 14 05 41](https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/64200be5-49cd-46ca-8b2b-b0e5580b2ec4)

6. change the trigger level around until the wave becomes stationairy

- What does changing the frequency do?
- What does changing the duty cycle do? Spend a maximum of 5 minutes on this

   <img width="445" alt="Screen Shot 2023-10-18 at 1 38 33 PM" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/aa7fc944-cad3-4afa-8158-f93a50e1deb7">

Undo the connections that you made in the 'Lets get started section'

### Controlling a DM996 Servo

1. Get 2 banana plug leads, plug one into the +6V port and the other into ground (make sure the other ends have alligator clips attached). these are banana plugs:

   <img width="317" alt="Screen Shot 2023-10-18 at 1 39 07 PM" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/df96c3bc-5391-4ff5-a4eb-19f17807eacf">

2. Grab 2 male to male jumpers and connect them to the 2 leads

   <img width="315" alt="Screen Shot 2023-10-18 at 1 40 05 PM" src="https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/841fe6a4-4409-406d-91c3-7c399da8f87f">

3. Connect the positive jumper to the red servo port and the negative jumper to the brown servo port.
   You have now connected the power cables to the servo, the servo will draw all its actuating power from this source.

https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/3556e66e-9959-4549-88be-139fc55e54b5

7. Now connect the ground of the function generator to the ground of the power leads.

8. Use another jumper to bridge between the function generator probe to the orange wire of the servo.
   You have now connected the signal cable, it will carry the PWM signal which you will encode with information (desired angle), through the variation of the duty cycle.

https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/ed211b3d-04d6-45f8-b261-e30b6635ea74

6. In the NI VirtualBench environment, change the frequency to 50Hz, amplitude to 5V, signal type to square and duty cycle to 0%
   Why? - Because that what the datasheet specifies, most actuators come with a datasheet that gives you all the information you need to know on operating the device.
   For the curious among you here's a link to a site with the datasheet 'https://components101.com/motors/mg996r-servo-motor-datasheet'

7. In the DC power window set voltage to 6V and current to 2.5A

   ![WhatsApp Image 2023-10-18 at 14 09 20](https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/f21080d0-8946-42dc-b1a0-f3d47b29e9c2)


9. Click the power button for both the DC power and the function generator

10. Increment the duty cycle, the motor should rotate accordingly

11. Compare with the people around you are there any differences in the motors behaviour? Why?

12. Turn off the function generator and the DC supply

### Controlling a DC Motor using a half bridge

#### MOSFETs

A MOSFET is a type of transistor that allows for the resistance from drain to source to be controlled by the voltage at the gate.
The gate voltage can be modelled by a capacitor between the gate and the source. When this increases above a certain voltage, for an N channel depletion MOSFET, the resistance with become very high- to all purposes, an open circuit.
When this voltage is zero, the gate resistance will become quite low. However, unlike the off state, this is not negligible- heat will be generated according to which with enough current will destroy the MOSFET.
MOSFETs can be used in states other than off or on, with a significant resistance. However, this is not useful for power electronics since the power dissipated will be massive- like using a large resistor in series with a motor. This is why PWM is used, to minimize time in these regions.

#### Half bridge

A half bridge is a structure created by joining two MOSFETs, often N channel as these have lower resistance when on, connected in series as shown:
![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/f3b67147-8587-4d81-9f2b-f5ca6664c13d)

The load pin can be pulled either low or high by activating it’s gate, labelled Low/HighSwitch. This allows for each side of the motor to be disconnected, low or high.
A dangerous condition known as shoot through can occur if both gates are activated, and as such many drivers implement protections to prevent this.

In practice, to operate a half bridge a gate driver is required. This is because at boot, the load voltage and gate charge on the MOSFETs is unknown. If the load pin is high, then the gate of the MOSFET must be increased to a voltage higher than VCC to shut it off. A gate driver uses a charge pump to boost a capacitor above supply voltage to achieve this. This also means that the gate can be charged very rapidly, by discharging the capacitor into it and minimizing losses in partially conducting states.

#### Tools required
- Wire
- Wire stripper
- TT motor
- MX1508 Motor driver module
- Soldering iron
- Solder

1. Prepare your wires, cut them to length and strip them.

https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/38f59ecb-d824-4503-a773-c6ad78a16ca6

2. Solder 2 to the TT Motor contacts as shown

https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/224e4aec-bc99-4cbe-adfb-e135f3b38439

https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/8567bbf7-ad3e-4b11-b762-c2de2d423232

4. Solder the TT-motor wires to MOTOR-A and solder loose wires to IN1, IN2, positive, and negative on the MX1508.

![IMG_5796](https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/d77b86b0-56c5-47c5-8aec-b04f6ac4eb38)

![IMG_5797](https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/c52dde5d-eb0b-4bb5-99e1-56ef2b920222)

5. Connect the function generator to probe to IN1 and ground to the ground (negative) of the MX1508

6. Connect the DC supply (via the banana plugs) to the positive and negative of the MX1508

7. In the NI VirtualBench environment change the frequency to 20kHz, amplitude 5V, offset 2.5V and duty cycle 0%

8. Turn on both the DC power supply and the function generator.

9. Increment the duty cycle, the motor should begin to spin around 45%

https://github.com/UBRoboticsWorkshop/WorkShops/assets/54585720/6db79686-485e-442c-b09f-46c3eb9b0084

