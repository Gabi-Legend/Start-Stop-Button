# Formula Student ECU Simulator – Start/Stop Button

---

## Description

This project simulates a basic Electronic Control Unit (ECU) system for a Formula Student vehicle using Arduino.  
It implements a Start/Stop button with toggle logic, gear shifting, and speed control, serving as a foundation for more advanced vehicle control systems.

The project is designed to be modular and easily extendable with dashboards, telemetry, safety logic, and custom PCBs.

---

## Features

- Start/Stop toggle controlled with a single button  
- Visual feedback using LEDs or a dashboard display  
- Software debounce for reliable button and encoder input  
- Sequential gear shifting (upshift / downshift)  
- Speed control using a rotary encoder  
- Speed limitation based on selected gear  
- Designed for easy extension toward telemetry and safety systems  

---

## Hardware Requirements

- Arduino Uno or ESP32  
- Push button (tactile switch)  
- Rotary encoder (CLK, DT, SW optional)  
- LEDs for dashboard indication (optional)  
- 10kΩ resistors (if not using internal pull-up)  
- Breadboard and jumper wires  

---

## Circuit Connections

### Start / Stop Button
- Button → Digital Pin 2  
- Button → GND  
- Internal pull-up resistor enabled  

### Rotary Encoder
- CLK → Digital Pin 7  
- DT → Digital Pin 6  
- VCC → 5V  
- GND → GND  

### Gear Shift Buttons
- Upshift button → Digital Pin 3 → GND  
- Downshift button → Digital Pin 4 → GND  
- Internal pull-up resistors enabled  

### LED Indicator
- LED → Digital Pin 8 → GND (through resistor)

---

## System Behavior

- The vehicle can only accelerate when the system is started  
- Speed control is disabled in Neutral gear  
- Speed is limited based on the current gear  
- Gear shifting is only possible when the system is active  
- Turning the system off resets speed and gear to safe defaults  

---

## Roadmap / Future Improvements

- RPM simulation and rev limiter  
- Shift-light LED bar  
- OLED or TFT dashboard display  
- ESP32-based wireless telemetry  
- Data visualization dashboard (e.g. Next.js)  
- Custom PCB for ECU prototype  

---

## Learning Outcomes

- Embedded system state management  
- Button and rotary encoder handling with edge detection  
- Software debounce techniques  
- Modular ECU-style logic design  
- Foundations of motorsport vehicle electronics  
