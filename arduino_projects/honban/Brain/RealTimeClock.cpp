#include <Arduino.h>
#include"RealTimeClock.h"

long RealTimeClock::getRealTime()
{
  return m_currentTime;
}

void RealTimeClock::setRealTime(unsigned long currentTime)
{
  m_currentTime = currentTime;
}
