#include <Arduino.h>
#include <obstacle.h>
#include <driver.h>
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
    digitalWrite();
}
