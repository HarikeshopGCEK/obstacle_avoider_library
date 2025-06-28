#include "ObstacleAvoider.h"

ObstacleAvoider::ObstacleAvoider(int trigPin, int echoPin, float maxDistance)
    : _trigPin(trigPin), _echoPin(echoPin), _maxDistance(maxDistance)
{
}

void ObstacleAvoider::begin()
{
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(30);
}

float ObstacleAvoider::getDistance()
{
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    long duration = pulseIn(_echoPin, HIGH, 30000);  // 30 ms timeout

    if (duration == 0) {
        return _maxDistance + 1;  // Assume no obstacle detected
    }

    float distance = (duration * 0.0343) / 2.0;  // Convert to cm
    return distance;
}

bool ObstacleAvoider::isObstacleDetected()
{
    float distance = getDistance();
    return (distance <= _maxDistance);
}
