//================================================
// Dev by : Pagon Game Dev
// PagonGameDev@gmail.com
//================================================

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

  if (lMillisCurrent - lMillisPrevious >= iMillisIntervalDelayTime) {

    //Skip Delay Time
    iMillisDelayTime = ((lMillisCurrent - lMillisPrevious) - (iMillisInterval - iMillisDelayTime )) % iMillisInterval;
    iMillisIntervalDelayTime = iMillisInterval - iMillisDelayTime;
    //Serial.println("T : "+((String)TimeInterval.lTestMillis)+" D : "+((String)TimeInterval.iMillisDelayTime)+" + "+((String)TimeInterval.iMillisIntervalDelayTime)+" = "+((String)(TimeInterval.iMillisDelayTime+ TimeInterval.iMillisIntervalDelayTime)));

    DeltaTime = (lMillisCurrent - lMillisPrevious) / 1000.0d;
    //Serial.println("run : "+(String)(lMillisCurrent - lMillisPrevious));

    lMillisPrevious = lMillisCurrent;
    functionInterval();

  }
}

//================================================================
GameInput::GameInput()
{
}

bool GameInput::getKey(int iPinInput, bool isTrueState)
{
  bool isRe = false;

  if (digitalRead(iPinInput) == isTrueState)
  {
    isRe = true;
  } else {
    isRe = false;
  }

  return isRe;
}

bool GameInput::getKeyDown(int iPinInput, bool isTrueState, byte& bInputBuffRead)
{
  bool isRe = false;

  bool isBtnUp = HIGH;
  bool isBtnDown = LOW;

  if (isTrueState == HIGH)
  {
    isBtnUp = LOW;
    isBtnDown = HIGH;
  } else {
    isBtnUp = HIGH;
    isBtnDown = LOW;
  }

  byte bInputRead  = digitalRead(iPinInput);

  if (bInputRead == isBtnDown && bInputBuffRead == isBtnUp)
  {
    //Serial.println(((String)bInputRead)+" == "+((String)isBtnDown)+" && "+((String)bInputBuffRead)+" == "+((String)isBtnUp));
    isRe = true;
  }
  bInputBuffRead = bInputRead;
  return isRe;
}

bool GameInput::getKeyUp(int iPinInput, bool isTrueState, byte& bInputBuffRead)
{ bool isRe = false;

  bool isBtnUp = HIGH;
  bool isBtnDown = LOW;

  if (isTrueState == HIGH)
  {
    isBtnUp = LOW;
    isBtnDown = HIGH;
  } else {
    isBtnUp = HIGH;
    isBtnDown = LOW;
  }

  byte bInputRead  = digitalRead(iPinInput);

  if (bInputRead == isBtnUp && bInputBuffRead == isBtnDown)
  {
    //Serial.println(((String)bInputRead)+" == "+((String)isBtnDown)+" && "+((String)bInputBuffRead)+" == "+((String)isBtnUp));
    isRe = true;
  }
  bInputBuffRead = bInputRead;
  return isRe;
}
