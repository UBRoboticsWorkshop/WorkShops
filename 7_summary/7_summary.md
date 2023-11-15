# Summary Stuff
> [!NOTE]
> This is a super cool new addition to help you build your robot a bit faster - we've divided this section up into the main topics we've covered previously. This time we've included more visuals to help you follow along better.
>Topics have been divided into different drop-downs so just navigate through there for parts you're stuck on

Here is a video showing the A to Z of the robot assembly : 
https://www.youtube.com/watch?v=Bs8_F03P2fw
Refer to this to assemble your robot. If you have specific questions / confused about the codes etc, refer back to previous workshops.

---
<details>
  <summary>

  ## 1. Motor Drivers
  </summary>

**What are they and why do we need them?**

You might recognise this : 
![Annotation 2023-11-10 165841](https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/74099e9a-1269-4959-b7bf-f463680be36c)

They're kind of the middle man between motors and the control systems we use. Essentially what they do is convert the low-current signals inputted, to hgiher-current which is needed to drive the motors.
This module in particular (MX1508) can drive 2-Way DC motors ; which is exactly what we're trying to do .It's ideal for battery powered, smaller DC motors.

**Basic Components**

![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/a496e2bc-2bfb-4f57-a668-c794668e50cf)


**Wiring and Connections**

![Annotation 2023-11-10 165951](https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/59b09c31-e94e-464c-b615-de93f6b9c3d6)

Where L = LOGIC LOW, H = LOGIC HIGH

*IN1, IN2, IN3, IN4:*
These are input pins that control the motor driver.
You would need to input logic high/low signals here to these pins to determine the motor's behavior. This determines whether the motor rotates forward, backward, or stays still. 

*MOTOR A and MOTOR B:*
These are the output pins for the two motor channels (A and B).
The motor channels are where you connect the terminals of your DC motor. Depending on the signals applied to the input pins (IN1, IN2, IN3, IN4), these output pins control the direction and speed of the connected motors.
To simplify further:

>If you want MOTOR A to move forward, you'd set specific combinations of high and low signals on IN1 and IN2.
>If you want MOTOR A to move backward, you'd set a different combination of signals on IN1 and IN2.
>The same logic applies to MOTOR B.
</details>

---
<details>
  <summary>

 ## 2. CAD
  </summary>
  
Not going to lie, you're better off following step-by-step tutorials made by our tech team for this. Please navigate back to 'CAD' 1 & 2 and ask questions if you have any.
</details>

---
<details>
  <summary>

 ## 3. Wiring
  </summary>

*Connecting the servo motor and ESP32*
![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/8ef94b07-e5d8-4ef0-a16f-a747f9eac959)

With this diagram, you can see which pins are PWM-capable. If you're changing the pins, ensure you change your code too.
![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/9fbd100c-51a5-4517-be64-75bc45ff1b1d)

*Similarly, connecting the TT motors and ESP32*
![image](https://github.com/UBRoboticsWorkshop/WorkShops/assets/110237339/5329ccad-fe0a-4cde-9923-44b0c615c41e)

</details>

---
