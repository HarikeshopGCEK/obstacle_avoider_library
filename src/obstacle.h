#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <Arduino.h>
#include <driver.h>

class Obstacle
{
public:
    Obstacle(
        uint8_t ltrig, uint8_t rtrig,
        uint8_t lecho, uint8_t recho,
        float maxDistance = 30.0f,
        int speed = 255,
        uint8_t lin1 = 0, uint8_t lin2 = 0, uint8_t rin1 = 0, uint8_t rin2 = 0, uint8_t ena = 0, uint8_t enb = 0);

    void begin();
    void run();

private:
    int leftTrigger;
    int rightTrigger;
    int leftEcho;
    int rightEcho;
    float maxDistance;
    float leftDistance;
    float rightDistance;
    int speed;
    // Motor pins
    uint8_t lin1, lin2, rin1, rin2, ena, enb;
    MotorDriver motorDriver;

    float measureDistance(int trig, int echo);
};

#endif // OBSTACLE_H