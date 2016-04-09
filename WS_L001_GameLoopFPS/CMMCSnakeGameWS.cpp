#include "Arduino.h"
#include "CMMCSnakeGameWS.h"

GameInterval::GameInterval(int iInputInterval, void (funcInterval)())
{
  iMillisInterval = iInputInterval;
  functionInterval = funcInterval;

  iMillisIntervalDelayTime = iInputInterval;
}

void GameInterval::update()
{
  lMillisCurrent = millis();

  if (lMillisCurrent - lMillisPrevious >=iMillisIntervalDelayTime) {

    //Skip Delay Time
    iMillisDelayTime = ((lMillisCurrent - lMillisPrevious) - (iMillisInterval - iMillisDelayTime ))%iMillisInterval;
    iMillisIntervalDelayTime = iMillisInterval - iMillisDelayTime;
    
    //Serial.println("T : "+((String)TimeInterval.lTestMillis)+" D : "+((String)TimeInterval.iMillisDelayTime)+" + "+((String)TimeInterval.iMillisIntervalDelayTime)+" = "+((String)(TimeInterval.iMillisDelayTime+ TimeInterval.iMillisIntervalDelayTime)));

    DeltaTime = (lMillisCurrent - lMillisPrevious) / 1000.0d;
    //Serial.println("run : "+(String)(lMillisCurrent - lMillisPrevious));

    lMillisPrevious = lMillisCurrent;
    functionInterval();

  }
}
