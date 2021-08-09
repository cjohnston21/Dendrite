# Dendrite

This code controls the color and pattern of LEDs on the Dendrite Sculpture Located at the Duke Smart Home. It contains the naming conventions and basic functions for controlling the LEDs on the tree. It is meant as an open source tool to be improved upon and altered to make the tree perform whatever light shows you want!

# Lighting Control
- The tree uses both addressable (1 branch bundle) and non-addressable LEDs (4 branch bundles).
- The RGB of the non-addressable LEDs are all wired together and thus only the color of the entire bundle can be changed and not individuals LED light strips.
- In contrast, the addressable LED light strips can be controlled independently using the [FastLED.h](https://github.com/FastLED/FastLED) library.

# Hardware Design
- An Arduino Mega is used to control the LEDs
- All 16 analog pins on the Arduino Mega are used to control the LEDs (12 are connected to logic-level MOSFETS to control the amount of current passing through the non-addressable LEDs in different bundles, 4 are used to control the addressable LEDs)
- The LEDs and Arduino are powered by 4 independent power transformers. The top bundle on the side with two branches takes 24V, the addressable branch requires 5V, and the rest require 12V.

# Possible Innovations
- Adding a small microphone to the hardware and adjusting the brightness of the LEDs based on sound (could be fun for a backyard concert!)
- Adding infrared lasers / piezo electric disks / photoresistor so people can physically interact with the tree to change it's color
- Adding a timer so the tree lights up at a specific time each night
- Adding solar panels so the tree literally photosynthesizes

# Contact
I'm always happy to help and please reach out to me at cstujo5@gmail.com for any questions you might have! For additional design questions, see [Dendrite Sculpture](https://connorjohnstonduke.wordpress.com/led-tree-sculpture/)
