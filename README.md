# obstacle_avoider_library
Simple library for obstacle avoider bot for school students 

This is an Arduino-based obstacle avoidance bot using an ultrasonic sensor (HC-SR04). The bot detects obstacles in front of it and prints the required action via Serial output.

A project example code file is also present with the name example.cpp

Hardware requirements
- Arduino Uno/Nano/ESP32/etc.
- HC-SR04 Ultrasonic Sensor
- Breadboard & Jumper Wires
- (Optional) Motor Driver + Motors for movement

Setup instructions
- Step 1: Clone the Repository
- Step 2: Connect the Ultrasonic Sensor (HC-SR04)
- Step 3: Open Project in Arduino IDE
  - Launch the Arduino IDE.
  - Open the main.ino file located in the src/ folder.
  - Make sure obstacle.h and obstacle.cpp are in the correct lib/obstacle/ directory relative to the sketch.
- Step 4: Modify and Verify the Code
- Step 5: Upload the Code to Arduino
  - Connect your Arduino board via USB.
  - Select the correct Board and COM Port from the Tools menu.
  - Click Upload (→ arrow icon) to upload the code.
- Step 6: Open the Serial Monitor and ensure its working
  - Click on Tools > Serial Monitor or press Ctrl + Shift + M.
  - Set the baud rate to 9600.
  - The bot is working if the instructions are shown at the moment when the bot is tested. (the instructions shown below are for understanding purpose)
     - Path Clear → Action: MOVE FORWARD
     - Obstacle Detected → Action: STOP → Action: TURN LEFT

Project expansion
 - Replace the 'Serial.println()' statements with actual motor driver logic (e.g., using L298N or L9110S modules).
 - Add left and right side ultrasonic sensors to improve navigation and corner detection.
 - Implement more advanced logic like PID-based turning or SLAM (Simultaneous Localization and Mapping).
 - Integrate IR sensors or vision modules for enhanced obstacle detection in low-range or dynamic environments.

License
 - This project is licensed under the MIT License.
 - You are free to use, modify, and distribute this code for personal or commercial use with proper attribution.


