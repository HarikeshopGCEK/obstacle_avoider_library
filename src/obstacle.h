#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include <Arduino.h>
#include <driver.h>
class ObstacleAvoider
{
public:
    ObstacleAvoider(int trigPin, int echoPin, float maxDistance = 20.0);
    ObstacleAvoiderDouble(int leftTrigPin, int leftEchoPin, int rightTrigPin, int rightEchoPin, float maxDistance = 20.0,
                          uint8_t in1 = 0, uint8_t in2 = 0, uint8_t in3 = 0, uint8_t in4 = 0,
                          uint8_t ena = 0, uint8_t enb = 0);
    void begin();
    void run();
    bool isObstacleDetected();
    float getDistance();
    float getLeftDistance();
    float getRightDistance();

private:
    int _trigPin;
    int _echoPin;
    int _leftTrigPin;
    int _leftEchoPin;
    int _rightTrigPin;
    int _rightEchoPin;
    long _duration;
    float _distance;
    float _maxDistance;
    uint8_t _in1, _in2, _in3, _in4, _ena, _enb; // Motor control pins
    MotorDriver motorDriver;
};

#endif