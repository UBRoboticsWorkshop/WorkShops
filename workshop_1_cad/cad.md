# CAD 

<a href="./Parts.zip" download>Download link: parts.zip</a>

## 1. Save And Import 

<iframe width="560" height="315" src="https://www.youtube.com/embed/8OIQU_GrG-s?si=HaoUaSb4ia84N3Du" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

One of the most effective methods to create a robot frame is to make models of each component, then position them in your CAD software. This allows for easy construction of structure, using the models to generate interfaces. 

## 2. Position Parts 

<iframe width="560" height="315" src="https://www.youtube.com/embed/5J_Dr3YX3OU?si=Mq_t82H2p2sShoLt" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Hide parts in order to make sure they don’t get in the way of what you’re working on by clicking the “eye” symbol. The isolate tool, found by right clicking a part, can hide everything except that part too.  

Select the move tool, and make sure to use the “component” mode. The move tool is very versatile, and can position sketch objects, bodies, component and faces. Here, using component mode makes sure that a body is not accidentally disjointed from others in the same component. 

Rotate the breadboard model, and move it out of the way of the battery holder. Likewise, move the TT motors below the battery carrier and give it enough clearance to fit wheels later. When moving the TT motors set pivot can be used to make sure that when the motors rotate, they stay central. 

When setting pivot, clicking on an arc/circle will select its centre. 

Finally, use the move tool to position the MG996R servo motor. Again, setting pivot can be used to keep the motor’s output shaft central. 

## 3. Draw Base 

<iframe width="560" height="315" src="https://www.youtube.com/embed/qsoxGKsrJ8c?si=RdBj8p6OfIwwpDmT" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Hide the motors, and look at the bottom of the robot. Use new sketch, and select “capture position”. This creates a sketch where components are visible in the positions you moved them to. The camera will move to be perpendicular to the sketch plane. 

Draw a rectangle. Here, I used a three point rectangle but any type could be used. When drawing the bottom line, a faint blue icon is displayed. This is an inferred constraint- Fusion can see that the line is close to orthogonal, and will lock it as such. Here, this is useful but sometimes it can get in the way. If it’s unwanted, just click the icon after the line is drawn and press delete. 

Make the rectangle roughly the size of the components, but don’t worry about accuracy. Now select the line tool, and switch to construction mode. Construction lines can be used to position sketch objects, but don’t affect anything outside the sketch. Position the end of the line so that a midpoint icon (small triangle) appears. Do the same on the other side, where another midpoint icon appears. There should also be a small square- a perpendicular constraint. 

The rectangle isn’t centred, so we’ll need to manually add a constraint to achieve this. By clicking the origin and the construction line, the coincident constraint can be used to align the centre line of the rectangle and the origin. 

Press D to use the dimension tool. This tool can also be found under the “create” menu. This tool is contextual- clicking two parallel lines will set width, a circle will set radius, two lines will set angle and so on. Use this to set the width and height of the rectangle. Finally select the origin and the bottom of the rectangle, and place a dimension. This will allow you to position the base vertically. 

As you’ve added dimensions and constraints, the lines have become black. This means that they’re fully constrained- some people view this as necessary to avoid unexpected behaviour later on, but it’s not mandatory to create a part. 

## 4. Extrude Base 

<iframe width="560" height="315" src="https://www.youtube.com/embed/cCgHcuK4o28?si=L7P8mOCX5u6lnuVh" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

One of the most used tools to create a body from a sketch is the extrude tool. Select the base, but leave the bolt holes of the battery carrier unselected. Drag out the arrow to 6mm- Fusion adjusts increments based on zoom, so finer adjustments can be made by zooming in. Alternatively, type 6mm into the “distance” field. 

This part will be laser cut, so it must stay 2D. 

Finally, rotate the camera to ensure that the clearance between the base and the motors is sufficient. 

## 5. Draw Motor Mount 

<iframe width="560" height="315" src="https://www.youtube.com/embed/3d6b3hN4p7w?si=TjKpIHkx3MikH3aR" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Create a new sketch, this time on the symmetry plane down the middle of the robot. Click the mounting face of the motor, and press P in order to project it onto the sketch plane. As with the base plate, create an L bracket and constrain it to fit the parts. This time, we’ll make use of the colinear constraint, which makes lines lock along the same axis. If a part gets in the way of the sketch, hide it with the browser. You can also make an existing object a construction line by selecting it, then hitting the construction icon. 

## 6. Create Motor Mount 

<iframe width="560" height="315" src="https://www.youtube.com/embed/kAB2gUaBiuI?si=qeomx9fV14NFjLJ9" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Now we’ll make a body from the motor mount. However, the projection lines complicate the extrude. Here, it’s easy to fix but in complex models it can be annoying. We’ll go back into the sketch to make these lines construction, so they won’t affect the extrude. 

Select the extrude, and then set “start” to object. Set the motor face to the offset and extrude 5mm.  

In the next step, we’ll be using the join function but the extrude we’re creating will be touching both- if left unchecked, this will fuse our motor mount and baseplate into one body. This can be avoided by setting the baseplate to invisible. 

Extrude again, this time setting “extent” to “to object”. Select the part of the motor mount you just created to link them. 

We’ll now use the mirror tool to create a symmetric part, set to join in order to make a single unit. 

## 7. Draw Skid 

<iframe width="560" height="315" src="https://www.youtube.com/embed/2ax8RhjHTac?si=UvWkT57BpzwhM3dx" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Create a sketch on the baseplate. Draw a circle for the skid, and a plate around it before adding a construction line to distance it from the edge of the base. Add a second circle to work as a mounting hole, with a construction line to position it. Then use the mirror tool to create a second symmetric mounting hole. 

Make sure the construction lines are constrained as vertical or horizontal, and that they are correctly dimensioned. 

## 8. Create Skid 

<iframe width="560" height="315" src="https://www.youtube.com/embed/oAGDPxz9Pug?si=SxbANKFeDcNUgMZL" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Use an offset again, to draw on the bottom of the base. Set the extrude to “new body” to avoid fusing incorrectly. On the next extrude, we want the pin and plate to fuse but not the base- again, hide the base during this operation. Finally, we’ll use the fillet tool on the bottom of the skid, so that it won’t catch on the floor (as much). 

## 9. Servo Tabs 

<iframe width="560" height="315" src="https://www.youtube.com/embed/hLYoFuXcJVo?si=mYV8d3ASalxnPzRQ" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Project the relevant parts of the servo, and draw the outline of a mount. Faces, vertices and edges can all be projected by clicking them and pressing P. 

## 10. Servo Mount 

<iframe width="560" height="315" src="https://www.youtube.com/embed/IE8Iu-8MiFM?si=cn8plJdxQnwFYldM" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Add some blocks with holes to mount the servo tabs, again centring the bolt holes with construction lines. 

## 11. Base Mounts 

<iframe width="560" height="315" src="https://www.youtube.com/embed/rZymE3rAf0g?si=ihMdaTOgnB4uJXNo" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Project and construct mounting holes to attach parts to the base using M3 bolts. 

## 12. TimeTravel

<iframe width="560" height="315" src="https://www.youtube.com/embed/6FvvDsl-n1I?si=X21qAFdNGcvWaRZV" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Using Time Travel to Unmake Your Mistakes Before They Ever Happen 

This is a somewhat useful trick. 

So far in the design, you’ll see that the servo mount clashes with the motor mount and has put a hole in it. Luckily, I planned this out ahead to demonstrate this feature. Look at my trustworthy, competent prose. You believe me, right? 

Moving swiftly onwards, at the bottom of the Fusion 360 window is a timeline of the actions you’ve performed. The indicator can be rolled back to undo actions, and then rolled back forward to redo them (this might take a minute for complex actions though). 

Go back to before you draw the sketch for the servo tabs, and move the servo forward. It’s very important to move the servo as a component, not a body, and to tick the “capture position” box. 

Sometimes changing a past action can cause issues with future features such as removing a body that is later chamfered, destroying a face later used to create a sketch or killing your parents before you were born. In these cases, affected features in the timeline are highlighted in yellow when affected, or red when critically broken. Right click these features to fix them, for example if we had removed the base we could redefine the mounting holes sketch to be defined by the origin plane- however, in this case the cut/extrude operation on the base would no longer have any purpose becoming red and requiring deletion. 

With any issues fixed, roll the timeline back forwards, and it’s like it never happened. 

What was this section about again? Anyway. 

## 13. Tolerances 

<iframe width="560" height="315" src="https://www.youtube.com/embed/ng8UrblULYY?si=sBvvEWbWTT5V9MfI" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

So you’ve printed your part, but it’s not quite right- something doesn’t quite fit, a bolt is too loose or tight etc. While this can be fixed physically with a file or hacksaw or digitally by using the timeline, this can be quite complicated or cause issues in some designs. In these cases, go go gadget press pull. 

The press pull is a contextual tool that can modify tolerances by offsetting faces while preserving features like fillets and chamfers. Here, we’ll use it to adjust the hole sizes on the servo mount to tightly hold an M4 bolt by moving the walls inwards 0.25mm. 

## 14. Reinforcement 

<iframe width="560" height="315" src="https://www.youtube.com/embed/0BEzVnps5Gw?si=D3ci2vWa6Mg8Jxjq" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

The motor mount is far too weak around the bolts (and in general). We can simply add another extrude to add a little extra material around the holes. 

## 15.	How strong are my parts?
* 15A. Not very lol.
  
<iframe width="560" height="315" src="https://www.youtube.com/embed/GkWsAbYjP2w?si=twZVmdXcVITHD61y" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

The design has a lot of sharp corners, which concentrate stress. These can combine with layer lines and part defects, causing parts to fail under very little loading. Careful consideration must be taken, especially with FDM 3D printing, to minimize this.
* 15B. But how weak are they?

<iframe width="560" height="315" src="https://www.youtube.com/embed/b3roq59fNag?si=nQAw5i5kqYvhNDT9" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For students, you can use powerful cloud computing to simulate and generatively design components for free. Whilst a lot of this is far out of scope of this session, especially when it comes to calculating dynamic loading and behaviour of non-isometric materials, you can see here how to add loads and constraints to simulate the forces on the motor bracket.

A few ways to easily improve strength:
* Bulk up the part: the most obvious option, most parts here could benefit from just being a bit wider/deeper. Saving 3g of plastic won’t win matches if your wheels are no longer connected to your robot
*	Fillets and chamfers: a gentle curve or small angle doesn’t cause stress to build up as badly as a sharp one, making features much less likely to snap off
*	Better materials: PLA is very brittle. Polymers like nylon, polycarbonate, ABS and enhanced tough PLA are much less likely to snap suddenly

## 16. Wheels

<iframe width="560" height="315" src="https://www.youtube.com/embed/XZ35LbfHFSo?si=jeg3CVB8_ogFqmTk" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Create a sketch on the end of the wheel shaft, then project the end of the skid. Draw a construction line past the motor to make sure the wheel and the skid are level. Draw a circle from the centre of the shaft, which should have a snap point, and connect it tangentially to the construction line. Next, create an offset by selecting the flattened parts of the shaft and hitting “O”. This way, we can make sure that the wheels fit snugly but aren’t too small. Extrude a collar along the shaft, then extrude the disk to create the wheel. Finally, we’ll add an offset to the screw hole so that it’s easy to secure the wheel.
Tires
Create a sketch on the face of the wheel, then hit “O” to create an 8mm offset from the rim. Create two radii and link them with an arc. Hit “T” or select the trim tool to cut the radii down. Now select the circular pattern, and create 4 identical features. We’ll next extrude the tire to 6mm, and the features to 4mm with an offset of 2mm. We can then use the combine tool to cut out the tire from the hub, leaving an interlocking interface.
Why create this complex structure? This part can be created in one operation using an S5 or S3 dual nozzle 3D printer using TPU and PLA for the tire and the hub respectively. However, TPU will not bond to PLA so if printed without interlocking geometry the tire will simply slip off.

## 17. Fabrication - 3D printing

<iframe width="560" height="315" src="https://www.youtube.com/embed/ywA3E8H6pBs?si=WSrdw_xPYuiIoj6x" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

To use the printers in the makerspace, you’ll need a PPMS account and also an STL of the part.
 Switch to the utilities tab, and select the printer icon in the “make” section. Select the part you want to fabricate, and then hit OK. I have my Fusion linked to a specific slicer, so I have to uncheck a tickbox. You can use 3MF files as well, which carry additional benefits over STLs but may not work on all slicers.
You can also see the process of loading it into Cura and getting it ready to print. When you get your printer training by booking through PPMS, we’ll go over this in greater depth.

* 17A.	Fabrication- Install shaper Utilities
  
<iframe width="560" height="315" src="https://www.youtube.com/embed/qI9KOSoGpUE?si=DZEd_Emh5HLMViKy" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

To use the laser cutter, you’ll need an SVG file. Fusion doesn’t have a great way to export these, and the export SVG plugin is paid for. To get around this, we’ll use a plug in for the Shaper routing tool. 
Under the utilities tab, select the Fusion app store under add ins. Search Shaper Utilities, and download it before running the .msi file. Finally, restart fusion 360.

* 17B.	Fabrication- Laser Cutting (Using Shaper)
  
<iframe width="560" height="315" src="https://www.youtube.com/embed/1Gpue-ACcZg?si=urwPnGEHtgsIiQNp" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

You should now have a triangular icon available under “Make”. Select the face you want to cut, and hit OK to make an SVG. You can view this file by opening it- the laser cutter will cut along the edges seen in the file. Only flat stuff, and no pocketing on the laser cutter. I tried to pocket on a laser cutter once, and the Mechanical Engineers laughed at me.
