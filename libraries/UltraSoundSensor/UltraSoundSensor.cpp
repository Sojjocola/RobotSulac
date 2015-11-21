#include "Arduino.h";
#include "UltraSoundSensor.h";

UltraSoundSensor::UltraSoundSensor()
{
    _maxCmDistance = MAX_SENSOR_DISTANCE;
}



void UltraSoundSensor::attach(int trigger_pin, int echo_pin)
{
    _triggerPin = trigger_pin;
    pinMode(trigger_pin,OUTPUT);
    _echoPin = echo_pin;
    pinMode(echo_pin,INPUT);
}



long UltraSoundSensor::check_distance_in_cm()
{
    long distance;
    long duration;
    
    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(10);
    
    digitalWrite(_triggerPin, LOW);
    duration = pulseIn(_echoPin, HIGH);
    
    //Calculate the distance (in cm) based on the speed of sound.
    distance = duration/58.2;
    
    return distance;
}