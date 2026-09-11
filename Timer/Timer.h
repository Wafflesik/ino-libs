#ifndef Timer_h
#define Timer_h

class Timer{
    private:
        unsigned long interval;
        unsigned long lastTime;

    public:
        Timer(unsigned long i);
        bool isReady();
        void reset();
};

#endif