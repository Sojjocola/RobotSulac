//
//  DualMotorRobot.h
//  
//
//  Created by François Chevalier on 11/07/14.
//
//

#ifndef DualMotorRobot_h
#define DualMotorRobot_h

#include "Arduino.h"
#include "MotorRobot.h"



class DualMotorRobot {
    
    
public:
    DualMotorRobot();
    void attachMotors(int speed);
    void goForward();
    void turnLeft();
    void turnRight();
    void goBack();
    void stop();
private:
    MotorRobot _motorRight;
    MotorRobot _motorLeft;
};


#endif
