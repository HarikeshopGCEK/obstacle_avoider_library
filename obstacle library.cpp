#include "ObstacleAvoider.h"
#include <Arduino.h>

ObstacleAvoider::ObstacleAvoider(int t, int e, int m1, int m2, int m3, int m4, int ea, int eb) {
  trigPin = t; echoPin = e;
  in1 = m1; in2 = m2; in3 = m3; in4 = m4;
  enableA = ea; enableB = eb;
}

void ObstacleAvoider::begin() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  pinMode(enableA, OUTPUT); pinMode(enableB, OUTPUT);
}

long ObstacleAvoider::readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void ObstacleAvoider::moveForward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enableA, 150);
  analogWrite(enableB, 150);
}

void ObstacleAvoider::turnLeft() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  delay(500);
  stop();
}

void ObstacleAvoider::stop() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
}

void ObstacleAvoider::avoidObstacle() {
  long dist = readDistance();
  if (dist < 15) {
    stop();
    turnLeft();
  } else {
    moveForward();
  }
}
