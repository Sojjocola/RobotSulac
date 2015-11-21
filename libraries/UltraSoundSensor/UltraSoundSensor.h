/*
  UltraSoundSensor_h.h - Library for sensor HC-SR04.
  Created by François Chevalier, July 3, 2014.
  Released into the public domain.
*/
#ifndef UltraSoundSensor_h
#define UltraSoundSensor_h

#include "Arduino.h";



#define MAX_SENSOR_DISTANCE 200


const long DISTANCE_FAR = 100;
const long DISTANCE_MEDIUM = 50;
const long DISTANCE_CLOSE = 20;



class UltraSoundSensor {
  
  
  public : 
      UltraSoundSensor();
      void attach(int trigger_pin, int echo_pin);
      long check_distance_in_cm();

  private:  
    int _triggerPin;
    int _echoPin;
    int _maxCmDistance;
  
};

#endif
