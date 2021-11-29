# Ditto x4 midi footswitch
Arduino based footswitch for ditto-x4 looper to send custom midi commands

* Button one press = stop loop 1
* Button one long press = clear loop 1
* Button two press = stop loop 2
* Button two long press = clear loop 2

## Libraries used:
* Arduino MIDI Library ( https://github.com/FortySevenEffects/arduino_midi_library/releases/tag/5.0.2 )
* OneButton ( https://github.com/mathertel/OneButton/tree/1.5.0 )


## Prototype Parts 

* 2.1 X 5.5MM 12V DC POWER BARREL JACK SOCKET PCB
* ABS PROJECT BOX, PLASTIC PROJECT CASE120 x 70 x 35 mm
* MIDI Serial Interface [Arduino Breakout Board](https://datapoint.uk/product/hoodie-with-logo/)
* 2 x Momentary Push Button Foot Switch SPST
* Arduino Nano Board 340/ATmega Nano328P
* 5.5V DC Voltage Regulator Step Down Power Supply Module 4.75V-12V to 5V 800mA

![Prototype Board](/doc/bradboard.jpg)
![Prototype Board Pins](/doc/bradboard_pins.jpg)

## Final Assembly

TBC

## Ditto x4 midi reference commands

* Responds to MIDI Channel 4 (hardcoded – can’t be changed)
* CC3 Looper 1 Rec/Dub/Start
* CC9 Looper 1 Stop
* CC14 Looper 1 Clear
* CC15 Looper 1 Level
* CC20 Looper 1 Hold to Store
* CC21 Looper 1 Clear Backtrack
* CC22 Looper 2 Rec/Dub/Start
* CC23 Looper 2 Stop
* CC24 Looper 2 Clear
* CC25 Looper 2 Level
* CC26 Looper 2 Hold to Store
* CC27 Looper 2 Clear Backtrack
* CC28 Decay “Level”
* CC29 All Loops Stop
* CC30 All Loops Clear
* CC31 FX On/Off
* CC85 Parallel/Serial Toggle

[Source](https://www.youtube.com/watch?v=1mpWTgW0XQU)