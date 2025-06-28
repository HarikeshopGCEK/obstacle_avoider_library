#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include <Arduino.h>
#include <driver.h>
class ObstacleAvoider
{
public:
    ObstacleAvoider(int trigPin, int echoPin, float maxDistance = 20.0);
    void begin();
    bool isObstacleDetected();
    float getDistance();

private:
    int _trigPin;
    int _echoPin;
    long _duration;
    float _distance;
    float _maxDistance;
};

#endif