#include <Arduino.h>
#include <driver.h>
#include "obstacle.h"
float measureDistance(int trig, int echo)
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    `digitalWrite(trig, LOW);

    long duration = pulseIn(echo, HIGH);
    float distance = (duration * 0.0343) / 2; // Convert to cm
    return distance;
}
Obstacle::Obstacle(int ltrig, int rtrig, int lecho, int recho, float maxDistance)
    : leftTrigger(ltrig), rightTrigger(rtrig), leftEcho(lecho), rightEcho(recho), maxDistance(maxDistance),
      leftDistance(0.0f), rightDistance(0.0f), speed(speed),
      motorDriver(lin1, lin2, rin1, rin2, ena, enb, speed, speed, true, true) {}
void Obstacle::begin()
{
    Serial.begin(9600);
    pinMode(leftTrigger, OUTPUT);
    pinMode(rightTrigger, OUTPUT);
    pinMode(leftEcho, INPUT);
    pinMode(rightEcho, INPUT);
}

Obstacle::leftDistance = measureDistance(leftTrigger, leftEcho);
Obstacle::rightDistance = measureDistance(rightTrigger, rightEcho);
void Obstacle::run()
{
    leftDistance = measureDistance(leftTrigger, leftEcho);
    rightDistance = measureDistance(rightTrigger, rightEcho);
    Serial.print("Left Distance: ");
    Serial.print(leftDistance);
    Serial.print(" cm, Right Distance: ");
    Serial.println(rightDistance);
    delay(100);

    if (leftDistance > maxDistance && rightDistance > maxDistance)
    {
        Serial.println("Move forward, path is clear.");
        // Add obstacle avoidance logic here
        motorDriver.moveForward();
    }
    else if (leftDistance <= maxDistance && rightDistance > maxDistance)
    {
        Serial.println("Obstacle detected on the left, turn right.");
        // Add logic to turn right
        motorDriver.turnRight();
    }
    else if (leftDistance > maxDistance && rightDistance <= maxDistance)
    {
        Serial.println("Obstacle detected on the right, turn left.");
        // Add logic to turn left
        motorDriver.turnLeft();
    }
    else
    {
        Serial.println("Obstacles detected on both sides, stop or reverse.");
        // Add logic to stop or reverse
        motorDriver.stop();
    }
}