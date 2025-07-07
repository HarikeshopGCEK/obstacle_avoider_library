#include <Arduino.h>
#include <obstacle.h>
Obstacle obstacleAvoider(
    6, 7,              // Left trigger and echo pins
    12, 13,            // Right trigger and echo pins
    30.0f,             // Maximum distance in cm
    255,               // Speed
    2, 3, 4, 5, 10, 11 // Motor control pins
);
void setup()
{
    Serial.begin(9600);
    obstacleAvoider.begin();
    Serial.println("Obstacle Avoider Bot Initialized");
}

void loop()
{
    obstacleAvoider.run();
}