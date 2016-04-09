#ifndef CMMCSnakeGameWS_h
#define CMMCSnakeGameWS_h

#include "Arduino.h"

class GameInterval
{
  public:
    GameInterval(int iInputInterval, void (funcInterval)());
    void update();
    float DeltaTime;


  private:
    int iMillisInterval;
    int iMillisDelayTime;
    int iMillisIntervalDelayTime;
    
    unsigned long lMillisPrevious;
    unsigned long lMillisCurrent;
    void(*functionInterval)();
};

#endif
