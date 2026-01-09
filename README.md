# Formula Student ECU Simulator – Start/Stop Button

## Description
This project simulates a simple Electronic Control Unit (ECU) system for a Formula Student vehicle using Arduino.  
It implements a toggle logic for a Start/Stop button, with visual feedback via LEDs or a dashboard, and is designed to be easily extendable with telemetry and safety systems.

---

## Features

- Start/Stop toggle controlled with a single button  
- Visual feedback through LEDs or a dashboard display  
- Software debounce implemented for reliable button reading  
- Easily extendable for telemetry, safety systems, and embedded vehicle control  

---

## Hardware Requirements

- Arduino Uno or ESP32  
- Push button (tactile switch)  
- LEDs for dashboard indication (optional)  
- 10kΩ resistors (if not using internal pull-up)  
- Breadboard and jumper wires  

---

## Circuit Connections

- Button → Digital Pin 2 → GND (using internal pull-up)  
- LEDs → Digital pins → GND through resistors  
