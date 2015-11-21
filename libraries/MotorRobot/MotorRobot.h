//
//  MotorRobot.h
//  
//
//  Created by François Chevalier on 10/07/14.
//
//

#ifndef MotorRobot_h
#define MotorRobot_h
#include "Arduino.h"

const int vitesseMotorA = 3;
const int sensMotorA = 12;
const int freinMotorA = 9;
const int intensiteMotorA = A0;

const int vitesseMotorB = 11;
const int sensMotorB = 13;
const int freinMotorB = 8;
const int intensiteMotorB =A1;

const int CHANNEL_A = 0;
const int CHANNEL_B = 1;
const int RIGHT_SIDE = 0;
const int LEFT_SIDE = 1;


class MotorRobot {
    
public:
    MotorRobot();
    void attachChannel(int channel,int side,int speed);
    void goForward();
    void goBack();
    void stop();
    
private:
    int _channel;
    int _side;
    int _speed;
};


#endif
