# obstacle_avoider_library

Simple library for obstacle avoider bot for school students

This is an Arduino-based obstacle avoidance bot using two ultrasonic sensors (HC-SR04) for left and right detection. The bot can control motors via a motor driver and will automatically avoid obstacles by turning left or right as needed.

A project example code file is also present with the name example.cpp

## Hardware requirements

- Arduino Uno/Nano/ESP32/etc.
- 2x HC-SR04 Ultrasonic Sensors (for left and right detection)
- Breadboard & Jumper Wires
- Motor Driver (e.g., L298N or compatible) + Motors for movement

## Default Motor Pin Mapping

By default, the library uses the following Arduino pins for the motor driver:

- Left Motor IN1: **2**
- Left Motor IN2: **3**
- Right Motor IN1: **4**
- Right Motor IN2: **5**
- ENA (Left Motor Enable): **10**
- ENB (Right Motor Enable): **11**

You can override these pins by specifying them in the `Obstacle` constructor if needed.

## Setup instructions

- Step 1: Clone the Repository
- Step 2: Connect the Ultrasonic Sensors (HC-SR04) for left and right detection
- Step 3: Connect the Motor Driver to the default pins (2, 3, 4, 5, 10, 11) or your custom pins
- Step 4: Open Project in Arduino IDE
  - Launch the Arduino IDE.
  - Open the main.ino file located in the src/ folder.
  - Make sure obstacle.h and obstacle.cpp are in the correct lib/obstacle/ directory relative to the sketch.
- Step 5: Modify and Verify the Code
- Step 6: Upload the Code to Arduino
  - Connect your Arduino board via USB.
  - Select the correct Board and COM Port from the Tools menu.
  - Click Upload (→ arrow icon) to upload the code.
- Step 7: Open the Serial Monitor and ensure it's working
  - Click on Tools > Serial Monitor or press Ctrl + Shift + M.
  - Set the baud rate to 9600.
  - The bot is working if the instructions are shown at the moment when the bot is tested. (the instructions shown below are for understanding purpose)
    - Path Clear → Action: MOVE FORWARD
    - Obstacle Detected on Left → Action: TURN RIGHT
    - Obstacle Detected on Right → Action: TURN LEFT
    - Obstacles on Both Sides → Action: STOP

## Project expansion

- Replace the 'Serial.println()' statements with actual motor driver logic (already implemented in this library using the Motor Driver Library).
- Add more sensors or advanced logic for improved navigation and corner detection.
- Implement more advanced logic like PID-based turning or SLAM (Simultaneous Localization and Mapping).
- Integrate IR sensors or vision modules for enhanced obstacle detection in low-range or dynamic environments.

## License

- This project is licensed under the MIT License.
- You are free to use, modify, and distribute this code for personal or commercial use with proper attribution.
