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
        uint8_t lin1, uint8_t lin2, uint8_t rin1, uint8_t rin2, uint8_t ena, uint8_t enb);

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
    MotorDriver motorDriver;
    void readLeftDistance();
    void readRightDistance();
};

#endif // OBSTACLE_H