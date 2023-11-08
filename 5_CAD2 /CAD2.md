# CAD 2
It's so nice, we're doing it twice.

Well, not quite. In this session, we'll be showing you ways you might use your actuators to enhance your robot.

This is the best time to get creative- an extremely professional and well engineered, but predictable, robot may find itself easily dispatched by an unusual and innovative concept that is 20%HMGBV (Hot Melt Glue By Volume).

We'll also be touching on sequencing and control, but we'll have more of a deep dive on that next week.

There are 3 main mechanisms here: grappler, flipper and righter.

<details> <summary> <h2>Grappler</h2>

</summary>

This device will grab onto your opponent. If you have very good forward pushing force, you can use this to force them into a pushing match. You could also use this to snag the side of their robot, so that they are unable to push you backwards even if they can generate more force.

Import the MG996r model, and position it for the addition of the cogs.

Next, set an offset plane 15.5mm from the mounting tags, as this is how far away the top of the mounting point we will be using here is.

Create a gear using the add-in tab, and input the parameters shown. 



<details> <summary> <h4>What do these parameters do?</h4>

</summary>
The modulus of a gear determines tooth size- the number of teeth times modulus will be related to pitch diameter. For two gears to mesh properly, the pitch diameters should be contacting.

Root fillet changes how the teeth are anchored, with a greater radius leading to better strength.

Backlash offsets the teeth's faces, making them slimmer. This means the gears can move a few fractions of a degree before touching one another. For 3D printing, this should be kept quite high.
</details>


<details> <summary> <h4>Printing gears?</h4>

</summary>
Printing gears is something of a questionable decision, but a printed gear is often better than no gear. Due to the short service life, low speed and comparably low forces at play, you should get away with it here.

The ideal material for FDM gears is nylon, however PLA and Tough PLA perform suprisingly well due to high UTS and rigidity. In the makerspace, you'll need to use PLA.
</details>


Next, use P to open the project tool and project the mounting features of the servo onto the sketch. A frame to the left of the servo will create a mounting point for the gears. Here, PLA has a low enough coeffecient of friction that the mechanism will work without a bearing- it could be significantly improved by one though.

Extrude the base, taking care to make sure that the gear teeth do not cut into the extrude. A large column will support the gear, with 0.4mm clearance either side to reduce friction between the two surfaces.

Cut some holes out of the gear to allow screws from the servo horns to be screwed onto it- you may want to cut down the servo horn to reduce the risk of it hitting into the frame.

Add some bars to the gears, to act as the jaws of the gripper. If you choose to use this mechanism, you'll probably want to add some sort of claw to the end of this.

Add a quadbolt to the back of the bracket, so that it can be bolted onto the robot frame. Again, if you choose to use this you might want to mount it differently, to fit with your robot.

Finally, we'll add some fillets to reduce the risk of the grabber snapping off.

</details>

<details> <summary> <h2>Flipper</h2>

</summary>

As before, import the MG996r.

Next, we'll position a block below the servo so that the servo can be bolted to it using two M4 bolts. Extend the block out behind the servo, and add a quad bolt.

Again, we'll construct a plane offset at the distance the servo horn will be at. Two screw holes 15mm apart will allow the screws that come with the servos to connect to the servo horn. Draw a slot to work as the arm, before extruding the arm. We'll also add a hole to the end, to allow for the fitting of a scoop later.

last off, we'll set all of the mounts to the proper tolerances to fit the mounting bolts.

</details>

<details> <summary> <h2>Righter</h2>

</summary>

The dawgs, the grippers

</details>

<details> <summary> <h2>Sequencing</h2>

</summary>

When stuff happens, it's best your robot can do stuff.

We'll be looking at how you can make your robot do this without touching it next week, but this week I'll show you how to do this with the Serial interface. Here's an easy way to talk to your robot:

```cpp
void setup() {
  Serial.begin(115200);
}

void loop() {
  while (!Serial.available()) {
  }
  char letter;
  letter = Serial.read();

  Serial.println(letter);
}
```
Open a Serial port, running at a speed of 115200 bits per second. If you're getting nonsense in your terminal, make sure both the ESP32 and the terminal have the same baud rate.

Do nothing until there is something in the Serial buffer, and when there is print the first character in the buffer. Repeat.

This should now have your ESP32 echoing back what you send, one character at a time. Next, let's change the main loop to make it look for certain characters:

```cpp
void loop() { //make sure to delete your old main loop before pasting this one in
  while (!Serial.available()) {
  }
  while (Serial.available()) {
    char letter;

    letter = Serial.read();
    if (letter == 'a'){
      Serial.println("Oh yea yep that's an a");
    }
  }
}
```
Now it will ignore anything that isn't an 'a', and print some text everytime it recieves one. With the "if" statement, there's "==" instead of "="- that's because one equals means setting a variable, while two means comparing two values. Also, make sure to use ' ' for characters instead of " ".

This code is just for testing, and there's a few ways it can be improved. For example the ESP32 is doing nothing unless there is Serial data, when it could be doing other tasks. Instead of waiting for Serial, we could simply check periodically for new serial data and then act if it happens to be there.

We can also use a switch case statement to interpret various different values, with a default case if nothing matches:

```cpp
void loop() {//make sure to delete your old main loop before pasting this one in
  while (!Serial.available()) {
  }
  while (Serial.available()) {
    char letter;

    letter = Serial.read();

    

    switch (letter){
      case 'a':
        Serial.println("Oh yea yep that's an a");
        break;
      
      case 'b':
        Serial.println("Oh yea yep that's an b");
        break;

      case 'c':
        Serial.println("Oh yea yep that's an c");
        break;

      case 'd':
        Serial.println("Oh yea yep that's an d");
        break;

      case 'e':
        Serial.println("Oh yea yep that's an e");
        break;
      
      default:
        Serial.println("Hmmm not sure about this");
        break;        
        
    }
  }
}
```
Try extending this to cover the entire keyboard, doesn't count if you don't use a different case for every character.


The print statements here can be replaced with commands to move the servos, and this way you can have control of the effectors based on commands sent from the serial terminal- commands from your controller next week will arrive in a similar manner.

Try setting a servo to toggle positions, or move a certain distance each time a command is sent. You can also have each key set a different position.

</details>

<details> <summary> <h2>Mounting Parts</h2>

</summary>

A good way to mount parts onto your robot is to use four bolts in a square pattern. An easy way to add this is shown in the following video, although a similar tab can be added to whatever part of the robot it is needed on. Remember to keep your base 2D if you want to laser cut it.

A terrible, awful, unprofessional way to mount parts to your robot is hot melt glue. I do this often.

There's some in the Makerspace.

</details>

<details><summary> <h2>Generative design</h2>

</summary>

Generative design can use cloud computing to create designs with much better mechanical properties than traditionally constructed parts. It's important to use it in the correct manner though: consider how easily it can be fabricated, how it may handle unexpected/shock loading and perhaps most importantly if it's needed- there's no point creating a custom generative carbon fibre chassis with titanium inserts weighing 0.36 grams only to get thrown around by heavier robots!

Generative design can use cloud computing to create designs with much better mechanical properties than traditionally constructed parts. It's important to use it in the correct manner though: consider how easily it can be fabricated, how it may handle unexpected/shock loading and perhaps most importantly if it's needed- there's no point creating a custom generative carbon fibre chassis with titanium inserts weighing 0.36 grams only to get thrown around by heavier robots!

We'll begin by creating the bodies that we'll need to mount our arm to, here using a pattern of four bolts to provide a firm mount. 

Next we'll add a design suggestion body.


<details><summary> <h4>Suggestion body</h4>

</summary>
A suggestion body gives the process a place to start, and can speed up completion of your designs. However, it can sometimes funnel the process towards less optimal designs, and takes time to design well. As such most of the time, a suggestion body is redundant.
</details>


Next, we'll switch to the generative design environment.

Here, we'll contruct obstacle geometry to prevent the arm from colliding with a servo or creating an obstruction to getting under a robot.

Hide the obstacle geometry, and add a load to the end of the gripper. We'll also set the bolt holes as fixed points. Clone this load case twice, and set the loads to apply from the sides- this way the output will be able to handle forces from various directions, not just vertical. These loads are quite simple, in real world applications you may find that the load cases are hard to define.

We'll set the method of creation to additive and unrestricted. The former is more likley to create a usable part, but the latter can sometimes output parts that are worth considering. Set the targets to be as stiff as possible, and constrain weight to 10 grams.

We'll also set the materials to nylon and tough 2000 resin- only the latter is available with training on the Form 3B in the makerspace, so if using PLA make sure to set a high enough safety factor.

Run a precheck- we'll see a warning that some bodies are hidden, since we hid the obstacles earlier. This is generally fine to ignore, but we'll unhide the obstacles to make sure they make sense. Check again, and there should be no problems. This means we are ready to press generate.

After a while, many different models will appear and begin to iterate. There are various tools to help you consider cost, safety, performance and weight. 

Once you have a preferred option, open it and use create body to export it into it's own file. Quite often you may need to modify the output, so that it can be printed more easily or to better fit a part- you can do this here.

(1) Drawing the body
https://www.youtube.com/watch?v=bH-5e4h4fUU&list=PLkHek7ZiQ1lN-IS7YYxnCIRionaxeUwmy&index=5

(2) Drawing the body
https://youtu.be/J5j0P2gJ0jA?si=y-ynyfNV59hMldzx

(3) Creating generative design on Fusion - Navigate to Structural components 
https://youtu.be/tTVmAncgNWc?si=16EhPSogSyuSQloT

(4) Generative design addition
https://youtu.be/tTVmAncgNWc?si=16EhPSogSyuSQloT

(5) Navigating structural loads and constraints
https://youtu.be/9c7NHFj-JDE?si=PrcSSILe2QUYa7Lj

(6) (Additive) Manufacturing and assigning materials 
https://youtu.be/qMw8KhQ9DtE?si=7lVDy70mfKkNVp7h

(7) Precheck and Generate your design!
https://youtu.be/tFvw4hjYwTc?si=Rwi0wispH6vz1ZQZ

(8) Outcome view with all details of your part
https://youtu.be/uNK7A6M0SWk?si=28iDo5N7f0V8I2az

(9) Export your file
https://youtu.be/8D_wDlzmzYk?si=RcfoTAhF5pCbIU1s

</details>
