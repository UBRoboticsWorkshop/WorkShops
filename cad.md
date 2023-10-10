# Save And Import 

One of the most effective methods to create a robot frame is to make models of each component, then position them in your CAD software. This allows for easy construction of structure, using the models to generate interfaces. 

# Position Parts 

Hide parts in order to make sure they don’t get in the way of what you’re working on by clicking the “eye” symbol. The isolate tool, found by right clicking a part, can hide everything except that part too.  

Select the move tool, and make sure to use the “component” mode. The move tool is very versatile, and can position sketch objects, bodies, component and faces. Here, using component mode makes sure that a body is not accidentally disjointed from others in the same component. 

Rotate the breadboard model, and move it out of the way of the battery holder. Likewise, move the TT motors below the battery carrier and give it enough clearance to fit wheels later. When moving the TT motors set pivot can be used to make sure that when the motors rotate, they stay central. 

When setting pivot, clicking on an arc/circle will select its centre. 

Finally, use the move tool to position the MG996R servo motor. Again, setting pivot can be used to keep the motor’s output shaft central. 

# Draw Base 

Hide the motors, and look at the bottom of the robot. Use new sketch, and select “capture position”. This creates a sketch where components are visible in the positions you moved them to. The camera will move to be perpendicular to the sketch plane. 

Draw a rectangle. Here, I used a three point rectangle but any type could be used. When drawing the bottom line, a faint blue icon is displayed. This is an inferred constraint- Fusion can see that the line is close to orthogonal, and will lock it as such. Here, this is useful but sometimes it can get in the way. If it’s unwanted, just click the icon after the line is drawn and press delete. 

Make the rectangle roughly the size of the components, but don’t worry about accuracy. Now select the line tool, and switch to construction mode. Construction lines can be used to position sketch objects, but don’t affect anything outside the sketch. Position the end of the line so that a midpoint icon (small triangle) appears. Do the same on the other side, where another midpoint icon appears. There should also be a small square- a perpendicular constraint. 

The rectangle isn’t centred, so we’ll need to manually add a constraint to achieve this. By clicking the origin and the construction line, the coincident constraint can be used to align the centre line of the rectangle and the origin. 

Press D to use the dimension tool. This tool can also be found under the “create” menu. This tool is contextual- clicking two parallel lines will set width, a circle will set radius, two lines will set angle and so on. Use this to set the width and height of the rectangle. Finally select the origin and the bottom of the rectangle, and place a dimension. This will allow you to position the base vertically. 

As you’ve added dimensions and constraints, the lines have become black. This means that they’re fully constrained- some people view this as necessary to avoid unexpected behaviour later on, but it’s not mandatory to create a part. 

# Extrude Base 

One of the most used tools to create a body from a sketch is the extrude tool. Select the base, but leave the bolt holes of the battery carrier unselected. Drag out the arrow to 6mm- Fusion adjusts increments based on zoom, so finer adjustments can be made by zooming in. Alternatively, type 6mm into the “distance” field. 

This part will be laser cut, so it must stay 2D. 

Finally, rotate the camera to ensure that the clearance between the base and the motors is sufficient. 

# Draw Motor Mount 

Create a new sketch, this time on the symmetry plane down the middle of the robot. Click the mounting face of the motor, and press P in order to project it onto the sketch plane. As with the base plate, create an L bracket and constrain it to fit the parts. This time, we’ll make use of the colinear constraint, which makes lines lock along the same axis. If a part gets in the way of the sketch, hide it with the browser. You can also make an existing object a construction line by selecting it, then hitting the construction icon. 

# Create Motor Mount 

Now we’ll make a body from the motor mount. However, the projection lines complicate the extrude. Here, it’s easy to fix but in complex models it can be annoying. We’ll go back into the sketch to make these lines construction, so they won’t affect the extrude. 

Select the extrude, and then set “start” to object. Set the motor face to the offset and extrude 5mm.  

In the next step, we’ll be using the join function but the extrude we’re creating will be touching both- if left unchecked, this will fuse our motor mount and baseplate into one body. This can be avoided by setting the baseplate to invisible. 

Extrude again, this time setting “extent” to “to object”. Select the part of the motor mount you just created to link them. 

We’ll now use the mirror tool to create a symmetric part, set to join in order to make a single unit. 

# Draw Skid 

Create a sketch on the baseplate. Draw a circle for the skid, and a plate around it before adding a construction line to distance it from the edge of the base. Add a second circle to work as a mounting hole, with a construction line to position it. Then use the mirror tool to create a second symmetric mounting hole. 

Make sure the construction lines are constrained as vertical or horizontal, and that they are correctly dimensioned. 

# Create Skid 

Use an offset again, to draw on the bottom of the base. Set the extrude to “new body” to avoid fusing incorrectly. On the next extrude, we want the pin and plate to fuse but not the base- again, hide the base during this operation. Finally, we’ll use the fillet tool on the bottom of the skid, so that it won’t catch on the floor (as much). 

# Servo Tabs 

Project the relevant parts of the servo, and draw the outline of a mount. Faces, vertices and edges can all be projected by clicking them and pressing P. 

# Servo Mount 

Add some blocks with holes to mount the servo tabs, again centring the bolt holes with construction lines. 

# Base Mounts 

Project and construct mounting holes to attach parts to the base using M3 bolts. 

Using Time Travel to Unmake Your Mistakes Before They Ever Happen 

This is a somewhat useful trick. 

So far in the design, you’ll see that the servo mount clashes with the motor mount and has put a hole in it. Luckily, I planned this out ahead to demonstrate this feature. Look at my trustworthy, competent prose. You believe me, right? 

Moving swiftly onwards, at the bottom of the Fusion 360 window is a timeline of the actions you’ve performed. The indicator can be rolled back to undo actions, and then rolled back forward to redo them (this might take a minute for complex actions though). 

Go back to before you draw the sketch for the servo tabs, and move the servo forward. It’s very important to move the servo as a component, not a body, and to tick the “capture position” box. 

Sometimes changing a past action can cause issues with future features such as removing a body that is later chamfered, destroying a face later used to create a sketch or killing your parents before you were born. In these cases, affected features in the timeline are highlighted in yellow when affected, or red when critically broken. Right click these features to fix them, for example if we had removed the base we could redefine the mounting holes sketch to be defined by the origin plane- however, in this case the cut/extrude operation on the base would no longer have any purpose becoming red and requiring deletion. 

With any issues fixed, roll the timeline back forwards, and it’s like it never happened. 

What was this section about again? Anyway. 

# Tolerances 

So you’ve printed your part, but it’s not quite right- something doesn’t quite fit, a bolt is too loose or tight etc. While this can be fixed physically with a file or hacksaw or digitally by using the timeline, this can be quite complicated or cause issues in some designs. In these cases, go go gadget press pull. 

The press pull is a contextual tool that can modify tolerances by offsetting faces while preserving features like fillets and chamfers. Here, we’ll use it to adjust the hole sizes on the servo mount to tightly hold an M4 bolt by moving the walls inwards 0.25mm. 

# Reinforcement 

The motor mount is far too weak around the bolts (and in general). We can simply add another extrude to add a little extra material around the holes. 

How strong are my parts? 

Not very lol. 

The design has a lot of sharp corners, which concentrate stress. These can combine with layer lines and part defects, causing parts to fail under very little loading. Careful consideration must be taken, especially with FDM 3D printing, to minimize this. 

But how weak are they? For students, you can use powerful cloud computing to simulate and generatively design components for free. Whilst a lot of this is far out of scope of this session, especially when it comes to calculating dynamic loading and behaviour of non-isometric materials, you can see here how to add loads and constraints to simulate the forces on the motor bracket. 
