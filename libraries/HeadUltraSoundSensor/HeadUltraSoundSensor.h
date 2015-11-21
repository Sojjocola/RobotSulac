//
//  HeadUltraSoundSensor.h
//  
//
//  Created by François Chevalier on 04/07/14.
//
//

#ifndef HeadUltraSoundSensor_h
#define HeadUltraSoundSensor_h

#include "Arduino.h"
#include "UltraSoundSensor.h"
#include "Servo.h"


const int GO_RIGHT = 1;
const int GO_STRAIGHT = 0;
const int GO_LEFT = -1;
const int GO_BACK = 2;
const int STOP = 3;


class HeadUltraSoundSensor {
    
    
public:
    HeadUltraSoundSensor();
    void attach(int servo_pin, int trigger_pin, int echo_pin);
    int give_me_a_direction();
    int path_is_clear();
private:
    UltraSoundSensor _sensor;
    Servo _servo;
};



#endif
