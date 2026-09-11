#include "Arduino.h"
#include "Timer.h"

Timer::Timer(unsigned long i){
    interval = i;
    lastTime = millis();
}

bool Timer::isReady(){
    if (millis()-lastTime >= interval){
        lastTime = millis();
        return true;
    }
    return false;
}

void Timer::reset(){
    lastTime = millis();
}