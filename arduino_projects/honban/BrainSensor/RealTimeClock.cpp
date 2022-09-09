#include <Arduino.h>
#include"RealTimeClock.h"

// 現在日時のゲッター
unsigned long RealTimeClock::getRealTime()
{
  return m_currentTime;
}

// 現在日時のセッター
void RealTimeClock::setRealTime(unsigned long currentTime)
{
  m_currentTime = currentTime;
}
