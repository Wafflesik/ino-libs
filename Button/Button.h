#ifndef Button_h
#define Button_h

class Button{
	private:
		int pin;
       		unsigned long debounceDelay;
        	unsigned long lastDebounceTime;
		unsigned long lastPressed;
		unsigned long lastReleased;

        	bool currentState;
        	bool previousState;
        	bool lastRead;
  	
        	bool pressEvent;
        	bool releaseEvent;
		bool doubleEventP;
		bool doubleEventR;

	public:
		Button(int pin, unsigned long delay = 50);
    		bool isPressed();
    		void buttonUpdate();
    		bool wasPressed();
    		bool wasReleased();
		bool doublePress();
		bool doubleRelease();
};

#endif