#include "Arduino.h"
#include "Button.h"

Button :: Button(int p, unsigned long delay){
  	pin = p;
  	pinMode(pin, INPUT_PULLUP);
  	debounceDelay = delay;
  
  	lastRead = HIGH;
  	currentState = HIGH;
  	previousState = HIGH;
  
	pressEvent = false;
	releaseEvent = false;
	doubleEventP = false;
	doubleEventR = false;

  
  	lastDebounceTime = 0;
}


void Button :: buttonUpdate(){
	bool reading = digitalRead(pin);
	int doubleClickWindow = 500;	

	pressEvent = false;
	releaseEvent = false;
	doubleEventP = false;
	doubleEventR = false;

	if (reading != lastRead){
		lastDebounceTime = millis();
	}
	
	if ((millis()-lastDebounceTime) > debounceDelay){
		if (reading != currentState){
			previousState = currentState;
			currentState = reading;
			
			if (previousState == HIGH && currentState == LOW){
				if ((millis()-lastPressed) < doubleClickWindow){
					doubleEventP = true;
				}
				else{ 
					pressEvent = true;
					lastPressed = millis();
				}
			}

			if (previousState == LOW && currentState == HIGH){
				if (doubleClickWindow > (millis()-lastReleased)){
					doubleEventR = true;
				}
				else{
					releaseEvent = true;
					lastReleased = millis();
				}
			}
		}
	}
	lastRead = reading;
}

bool Button :: isPressed(){
  return digitalRead(pin) == LOW;
}

bool Button :: wasPressed(){
	return pressEvent;
}

bool Button :: wasReleased(){
	return releaseEvent;
}

bool Button :: doublePress(){
	 return doubleEventP;
}

bool Button :: doubleRelease(){
	return doubleEventR;
}