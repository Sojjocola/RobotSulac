//
//  MotorRobot.cpp
//  
//
//  Created by François Chevalier on 10/07/14.
//
//
#include "Arduino.h"
#include "MotorRobot.h"




MotorRobot::MotorRobot()
{
    
}

void MotorRobot::attachChannel(int channel,int side,int speed) {
    
    // On défini les variables de classe
    _channel = channel;
    _side = side;
    _speed = speed;
    // On défini les entrée et sortie en fonction du channel utilisé
    if (_channel == CHANNEL_A) {
        
        pinMode(vitesseMotorA,OUTPUT);
        pinMode(freinMotorA,OUTPUT);
        pinMode(sensMotorA,OUTPUT);
        
    } else {
        
        pinMode(vitesseMotorB,OUTPUT);
        pinMode(freinMotorB,OUTPUT);
        pinMode(sensMotorB,OUTPUT);
    
    }
    
    //On initialise le moteur à l'arrêt
    if (_channel == CHANNEL_A) {
        
        analogWrite(vitesseMotorA,0);
        digitalWrite(freinMotorA,LOW);
        digitalWrite(sensMotorA,LOW);
        
    } else {
        
        analogWrite(vitesseMotorB,0);
        digitalWrite(freinMotorB,LOW);
        digitalWrite(sensMotorB,LOW);
        
    }
    
}



void MotorRobot::goForward() {
    
    
    if (_channel == CHANNEL_A) {
        
        digitalWrite(freinMotorA,LOW);
        if(_side == RIGHT_SIDE){
            digitalWrite(sensMotorA,HIGH);
        } else {
            digitalWrite(sensMotorA,LOW);
        }
        analogWrite(vitesseMotorA,_speed);
        
    } else {
        
        
        digitalWrite(freinMotorB,LOW);
        if(_side == RIGHT_SIDE){
            digitalWrite(sensMotorB,HIGH);
        } else {
            digitalWrite(sensMotorB,LOW);
        }
        analogWrite(vitesseMotorB,_speed);
    }
    
    
}


void MotorRobot::goBack() {
    
    if (_channel == CHANNEL_A) {
        
        
        digitalWrite(freinMotorA,LOW);
         if(_side == RIGHT_SIDE){
             digitalWrite(sensMotorA,LOW);
         } else {
             digitalWrite(sensMotorA,HIGH);
         }
        analogWrite(vitesseMotorA,_speed);
        
    } else {
        
        
        digitalWrite(freinMotorB,LOW);
        if(_side == RIGHT_SIDE){
            digitalWrite(sensMotorB,LOW);
        } else {
            digitalWrite(sensMotorB,HIGH);
        }
        analogWrite(vitesseMotorB,_speed);
    }
    
    
}



void MotorRobot::stop() {
    
    if (_channel == CHANNEL_A) {
        
        analogWrite(vitesseMotorA,0);
        digitalWrite(freinMotorA,HIGH);
        
        
    } else {
        
        analogWrite(vitesseMotorB,0);
        digitalWrite(freinMotorB,HIGH);
                
    }
    
}

