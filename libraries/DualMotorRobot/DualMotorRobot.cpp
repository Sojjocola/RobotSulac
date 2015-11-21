//
//  DualMotorRobot.cpp
//  
//
//  Created by François Chevalier on 11/07/14.
//
//
#include "Arduino.h"
#include "DualMotorRobot.h"
#include "MotorRobot.h"


DualMotorRobot::DualMotorRobot()
{
    
    
}


void DualMotorRobot::attachMotors(int speed)
{
    _motorRight.attachChannel(CHANNEL_A,RIGHT_SIDE,speed);
    _motorLeft.attachChannel(CHANNEL_B,LEFT_SIDE,speed);
}


void DualMotorRobot::goForward()
{
    //TODO Check the instensity to know if the motor is stopped
    _motorLeft.goForward();
    _motorRight.goForward();
    
}


void DualMotorRobot::turnLeft()
{
    //TODO Check the instensity to know if the motor is stopped
    _motorRight.goForward();
    _motorLeft.goBack();
    
}

void DualMotorRobot::turnRight()
{
    //TODO Check the instensity to know if the motor is stopped
    _motorRight.goBack();
    _motorLeft.goForward();
    
}

void DualMotorRobot::goBack()
{
    //TODO Check the instensity to know if the motor is stopped
    _motorRight.goBack();
    _motorLeft.goBack();
    
}

void DualMotorRobot::stop()
{
    //TODO Check the instensity to know if the motor is stopped
    _motorRight.stop();
    _motorLeft.stop();
    
}