# ConnectFourShirt

Code for our Connect Four T-Shirt. Yell at me if I forget to upload all the details.

 * $12.49 [Conductive Thread - 60ft](http://amzn.com/B007R9UA4S)
 * $4.95 (x2) [LilyPad Coin Cell Battery Holder](https://www.sparkfun.com/products/11285)
 * $19.95 (x2) [LilyPad Arduino](https://www.sparkfun.com/products/9266)
 * $14.95 (x2) [LilyPad FTDI](https://www.sparkfun.com/products/10275)
 * $9.95 [Conductive Fabric](https://www.sparkfun.com/products/10056)
 * $0.24 (x250) [Blue LED's](http://www.digikey.com/product-detail/en/C5SMF-BJS-CS24Q4T2/C5SMF-BJS-CS24Q4T2CT-ND/3687788)
 * $0.25 (x250) [Green LED's](http://www.digikey.com/product-detail/en/C5SMF-GJS-CV0Y0792/C5SMF-GJS-CV0Y0792CT-ND/1987480)
 * $0.22 (x7) [390 Ohm 3W Resistors](http://www.digikey.com/product-detail/en/4-1625892-4/A105915CT-ND/3477466)
 * $0.45 (x7) [1M Ohm Resistors](http://www.digikey.com/product-detail/en/HVR2500001004FR500/PPCQF1.0MCT-ND/719864)
 * Sewing machine (borrow).

Resources:
 * [DIY Led Tank](http://web.media.mit.edu/~leah/grad_work/diy/diy_tank.html)
 * [DIY Electronic Sewing](http://web.media.mit.edu/~leah/grad_work/diy/diy_e_sewing.html)
 * [LED Theory](http://www.instructables.com/id/Charlieplexing-LEDs--The-theory/step1/Some-LED-theory/)
 * [LilyPad](http://arduino.cc/en/Main/ArduinoBoardLilyPad)
 * [LilyPad Getting Started](http://arduino.cc/en/Guide/LilyPadWindows)
 * [Detect Touch](https://www.youtube.com/watch?v=WDPTA0-fbNE)
 * [Resistor Calculator](http://led.linear1.org/1led.wiz)
 * [All About LED's](https://learn.adafruit.com/all-about-leds/)

6x7 grid, each with two states, so essentially 12x7 grid. Can be done in a row/col LED matrix with 19 I/O pins.

Two LilyPads, master and slave. Leader uses 6 input pins and 12 I/O pins, using the [SoftwareSerial](http://arduino.cc/en/Reference/softwareSerial) library to communicate with the slave, which uses 7 I/O pins and 1 input. Master reads data from slave and tells it what to do.

Stitching is very similar to the [DIY Led Tank](http://web.media.mit.edu/~leah/grad_work/diy/diy_tank.html). Wiring in LED's is similar to the [DIY Electronic Sewing](http://web.media.mit.edu/~leah/grad_work/diy/diy_e_sewing.html).

Input will be done with conductive fabric, similar to the [Detect Touch](https://www.youtube.com/watch?v=WDPTA0-fbNE) video.
