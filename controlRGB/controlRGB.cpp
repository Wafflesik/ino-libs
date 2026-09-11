#include "Arduino.h"
#include "controlRGB.h"

controlRGB :: controlRGB(int rPin, int gPin, int bPin){
	redPin = rPin;
        greenPin = gPin;
        bluePin = bPin;
        pinMode(redPin, OUTPUT);
        pinMode(greenPin, OUTPUT);
        pinMode(bluePin, OUTPUT);
}

void controlRGB :: setColor(int r, int g, int b){
	red = r;
        green = g;
        blue = b;
          
        analogWrite(redPin, red);
        analogWrite(greenPin, green);
        analogWrite(bluePin, blue);
}

void controlRGB :: rainbowCycle(int delayTime){
	unsigned int rgbColour[3];

        // Start off with red.
        rgbColour[0] = 255;
        rgbColour[1] = 0;
        rgbColour[2] = 0;  

        // Choose the colours to increment and decrement.
        for (int decColour = 0; decColour < 3; decColour += 1) {
        	int incColour = decColour == 2 ? 0 : decColour + 1;

        // cross-fade the two colours.
        for(int i = 0; i < 255; i += 1) {
        	rgbColour[decColour] -= 1;
        	rgbColour[incColour] += 1;
      
        setColor(rgbColour[0], rgbColour[1], rgbColour[2]);
        delay(delayTime);
        }
    }
}

void controlRGB :: fadeOUT(int delayTime){
	while (red != 0 || green != 0 || blue != 0) {

        	if (red > 0)   red--;
        	if (green > 0) green--;
        	if (blue > 0)  blue--;

        	setColor(red, green, blue);
        	delay(delayTime);
    	}
}

void controlRGB :: fadeIN(int r, int g, int b, int delayTime){
	while (red != r || green != g || blue != b){
          	if (red < r)	red++;
              	if (green < g)	green++;
              	if (blue < b)	blue++;
            
        	setColor(red, green, blue);
        	delay(delayTime);
        }
}

