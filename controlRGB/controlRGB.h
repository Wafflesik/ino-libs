#ifndef controlRGB_h
#define controlRGB_h

class controlRGB {
	private:
		int redPin;
		int greenPin;
		int bluePin;
		int red;
		int green;
		int blue;
	public:
		controlRGB(int rPin, int gPin, int bPin);
		void setColor(int r, int g, int b);
		void rainbowCycle(int delaytime);
		void fadeOUT(int delaytime);
		void fadeIN(int r, int g, int b, int delayTime);
};


#endif