#include <Arduino.h>
#include "obstacle.h"
#include "driver.h"  // Assuming you have a separate driver control library

// Constructor
ObstacleAvoider::ObstacleAvoider(int trigPin, int echoPin, float maxDistance)
    : _trigPin(trigPin), _echoPin(echoPin), _maxDistance(maxDistance)
{
}

// Initialize pins
void ObstacleAvoider::begin()
{
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(30);
}

// Measure distance using ultrasonic sensor
float ObstacleAvoider::getDistance()
{
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    _duration = pulseIn(_echoPin, HIGH, 30000);  // 30ms timeout

    if (_duration == 0) {
        return _maxDistance + 1; // no response
    }

    _distance = (_duration * 0.0343) / 2.0;  // convert to cm
    return _distance;
}

// Check if obstacle is within maxDistance
bool ObstacleAvoider::isObstacleDetected()
{
    return (getDistance() <= _maxDistance);
}

// Autonomous obstacle avoidance behavior
void ObstacleAvoider::run()
{
    if (isObstacleDetected()) {
        Driver::stop();      // Assuming your driver library has stop(), turnLeft(), etc.
        delay(200);
        Driver::turnLeft();  // Turn to avoid the obstacle
        delay(400);          // Adjust delay as needed
    } else {
        Driver::forward();
    }
}