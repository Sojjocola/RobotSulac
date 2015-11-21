#include <Servo.h>
#include <UltraSoundSensor.h>
#include <HeadUltraSoundSensor.h>
#include <MotorRobot.h>
#include <DualMotorRobot.h>




DualMotorRobot dualMotor;
HeadUltraSoundSensor sensor;


void setup() {
  dualMotor.attachMotors(200);
  sensor.attach(5,6,7);
  
}



void loop() {
  
    if(sensor.path_is_clear() == 1) {
        dualMotor.goForward();
    } else {
      
        dualMotor.stop();
        delay(50);
        int directionToTake = sensor.give_me_a_direction();
        
        if(directionToTake == GO_LEFT) {
              dualMotor.turnLeft();
              delay(1000);
              dualMotor.stop();
        } else if(directionToTake == GO_RIGHT) {
             dualMotor.turnRight();
              delay(1000);
              dualMotor.stop();
        } else if(directionToTake == GO_BACK) {
             dualMotor.goBack();
              delay(2000);
              dualMotor.stop();
              // We go back so we need to check again
              int newDirectionToTake = sensor.give_me_a_direction();
              
              if(newDirectionToTake == GO_LEFT) {
                  dualMotor.turnLeft();
                  delay(1000);
                  dualMotor.stop();
              } else if(newDirectionToTake == GO_RIGHT) {
                  dualMotor.turnRight();
                  delay(1000);
                  dualMotor.stop();
              }
        }
      
    }
  
    delay(1);
  
}


