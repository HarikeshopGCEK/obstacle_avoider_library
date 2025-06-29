#include <Arduino.h>
#include "obstacle.h"

// Constructor
ObstacleAvoider::ObstacleAvoider(int trigPin, int echoPin, float maxDistance)
    : _trigPin(trigPin), _echoPin(echoPin), _maxDistance(maxDistance)
{
}

// Initialize sensor pins
void ObstacleAvoider::begin()
{
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(30);
}

// Measure distance
float ObstacleAvoider::getDistance()
{
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    _duration = pulseIn(_echoPin, HIGH, 30000);  // Timeout 30ms

    if (_duration == 0) {
        return _maxDistance + 1;
    }

    _distance = (_duration * 0.0343) / 2.0;
    return _distance;
}

// Detect obstacle
bool ObstacleAvoider::isObstacleDetected()
{
    return (getDistance() <= _maxDistance);
}

// Run logic with Serial output instead of driver control
void ObstacleAvoider::run()
{
    if (isObstacleDetected()) {
        Serial.println("Obstacle Detected!");
        Serial.println("Action: STOP");
        delay(200);
        Serial.println("Action: TURN LEFT");
        delay(400);
    } else {
        Serial.println("Path Clear");
        Serial.println("Action: MOVE FORWARD");
    }
}