#include <Arduino.h>
#include "obstacle.h"
#include "driver.h"

// Constructor
ObstacleAvoider::ObstacleAvoider(int trigPin, int echoPin, float maxDistance)
    : _trigPin(trigPin), _echoPin(echoPin), _maxDistance(maxDistance),
      _ena(ena), _enb(enb), _in1(in1), _in2(in2), _in3(in3), _in4(in4),
      motorDriver(_in1, _in2, _in3, _in4, _ena, _enb, true, true)
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

    _duration = pulseIn(_echoPin, HIGH, 30000); // Timeout 30ms

    if (_duration == 0)
    {
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
    if (isObstacleDetected())
    {
        Serial.println("Obstacle Detected!");
        Serial.println("Action: STOP");
        delay(200);
        Serial.println("Action: TURN LEFT");
        delay(400);
    }
    else
    {
        Serial.println("Path Clear");
        Serial.println("Action: MOVE FORWARD");
    }
}

// Constructor for dual ultrasonic sensors
ObstacleAvoiderDouble::ObstacleAvoiderDouble(int leftTrigPin, int leftEchoPin, int rightTrigPin, int rightEchoPin, float maxDistance)
    : _leftTrigPin(leftTrigPin), _leftEchoPin(leftEchoPin), _rightTrigPin(rightTrigPin), _rightEchoPin(rightEchoPin), _maxDistance(maxDistance)
{
}
// Initialize dual sensor pins
void ObstacleAvoiderDouble::begin()
{
    pinMode(_leftTrigPin, OUTPUT);
    pinMode(_leftEchoPin, INPUT);
    digitalWrite(_leftTrigPin, LOW);
    delayMicroseconds(30);

    pinMode(_rightTrigPin, OUTPUT);
    pinMode(_rightEchoPin, INPUT);
    digitalWrite(_rightTrigPin, LOW);
    delayMicroseconds(30);
}
// Measure distance from left sensor
float ObstacleAvoiderDouble::getDistanceLeft()
{
    digitalWrite(_leftTrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_leftTrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_leftTrigPin, LOW);

    _duration = pulseIn(_leftEchoPin, HIGH, 30000); // Timeout 30ms

    if (_duration == 0)
    {
        return _maxDistance + 1;
    }

    _distance = (_duration * 0.0343) / 2.0;
    return _distance;
}
// Measure distance from right sensor
float ObstacleAvoiderDouble::getDistanceRight()
{
    digitalWrite(_rightTrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_rightTrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_rightTrigPin, LOW);

    _duration = pulseIn(_rightEchoPin, HIGH, 30000); // Timeout 30ms

    if (_duration == 0)
    {
        return _maxDistance + 1;
    }

    _distance = (_duration * 0.0343) / 2.0;
    return _distance;
    // Detect obstacle using left sensor
    bool ObstacleAvoiderDouble::run()
    {
        float leftDistance = getDistanceLeft();
        float rightDistance = getDistanceRight();
        if (leftDistance <= _maxDistance && rightDistance > _maxDistance)
        {
            Serial.println("Obstacle Detected!");
            Serial.println("Action: STOP");
            delay(200);
            Serial.println("Action: TURN RIGHT");
            motorDriver.turnRight();
            delay(400);
            return true; // Obstacle detected
        }
        else if (rightDistance <= _maxDistance && leftDistance > _maxDistance)
        {
            Serial.println("Obstacle Detected!");
            Serial.println("Action: STOP");
            delay(200);
            Serial.println("Action: TURN LEFT");
            motorDriver.turnLeft();
            delay(400);
            return true; // Obstacle detected
        }
        else if (rightDistance <= _maxDistance && leftDistance < _maxDistance)
        {
            Serial.println("Obstacle Detected!");
            Serial.println("Action: STOP");
            delay(200);
            Serial.println("Action: TURN LEFT");
            motorDriver.stop();
            delay(400);
            return true; // Obstacle detected
        }
        else
        {
            Serial.println("Path Clear");
            Serial.println("Action: MOVE FORWARD");
            motorDriver.moveForward();
            delay(200);
            return false; // No obstacle detected
        }
    }
}