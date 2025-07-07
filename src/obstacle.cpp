#include <Arduino.h>
#include <driver.h>
#include "obstacle.h"

float Obstacle::measureDistance(int trig, int echo)
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long duration = pulseIn(echo, HIGH);
    float distance = (duration * 0.0343f) / 2.0f; // Convert to cm
    return distance;
}

Obstacle::Obstacle(
    uint8_t ltrig, uint8_t rtrig,
    uint8_t lecho, uint8_t recho,
    float maxDistance,
    int speed,
    uint8_t lin1, uint8_t lin2, uint8_t rin1, uint8_t rin2, uint8_t ena, uint8_t enb)
    : leftTrigger(ltrig), rightTrigger(rtrig), leftEcho(lecho), rightEcho(recho),
      maxDistance(maxDistance), leftDistance(0.0f), rightDistance(0.0f), speed(speed),
      lin1(lin1), lin2(lin2), rin1(rin1), rin2(rin2), ena(ena), enb(enb),
      motorDriver(lin1, lin2, rin1, rin2, ena, enb, speed, speed, true, true)
{
}

void Obstacle::begin()
{
    Serial.begin(9600);
    pinMode(leftTrigger, OUTPUT);
    pinMode(rightTrigger, OUTPUT);
    pinMode(leftEcho, INPUT);
    pinMode(rightEcho, INPUT);
}

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
        motorDriver.moveForward();
    }
    else if (leftDistance <= maxDistance && rightDistance > maxDistance)
    {
        Serial.println("Obstacle detected on the left, turn right.");
        motorDriver.turnRight();
    }
    else if (leftDistance > maxDistance && rightDistance <= maxDistance)
    {
        Serial.println("Obstacle detected on the right, turn left.");
        motorDriver.turnLeft();
    }
    else
    {
        Serial.println("Obstacles detected on both sides, stop or reverse.");
        motorDriver.stop();
    }
}