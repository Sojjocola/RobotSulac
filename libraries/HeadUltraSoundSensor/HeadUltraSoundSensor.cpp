//
//  HeadUltraSoundSensor.cpp
//  
//
//  Created by François Chevalier on 04/07/14.
//
//
#include "Arduino.h"
#include "UltraSoundSensor.h"
#include "HeadUltraSoundSensor.h"
#include "Servo.h"



HeadUltraSoundSensor::HeadUltraSoundSensor()
{
        
}



void HeadUltraSoundSensor::attach(int servo_pin, int trigger_pin, int echo_pin)
{
    _servo.attach(servo_pin);
    _sensor.attach(trigger_pin,echo_pin);
    
}


int HeadUltraSoundSensor::give_me_a_direction()
{
    int distanceLeft;
    int distanceRight;
    int directionToFollow;
    
    _servo.write(5);
    delay(1000);
    distanceLeft = _sensor.check_distance_in_cm();
    
    
    _servo.write(170);
    delay(1000);
    distanceRight = _sensor.check_distance_in_cm();
    
    
    _servo.write(90);
    delay(1000);
    
    if(distanceLeft == distanceRight && distanceLeft > DISTANCE_CLOSE) {
        directionToFollow = GO_LEFT;
    } else if(distanceLeft > distanceRight && distanceLeft > DISTANCE_CLOSE) {
        directionToFollow = GO_LEFT;
    } else if(distanceRight > distanceLeft && distanceRight > DISTANCE_CLOSE){
        directionToFollow = GO_RIGHT;
    } else {
        directionToFollow = GO_BACK;
    }
    
    return directionToFollow;
}


int HeadUltraSoundSensor::path_is_clear() {
    
    int path_is_clear = 1;
    
    int distance = _sensor.check_distance_in_cm();
    
    if(distance < DISTANCE_CLOSE){
        path_is_clear = 0;
    }
    
    return path_is_clear;
}