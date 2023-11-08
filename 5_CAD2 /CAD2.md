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

The dawgs, the grippers

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

</details>
