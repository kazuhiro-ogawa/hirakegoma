#pragma once

class RealTimeClock
{
  private :
  unsigned long m_currentTime;

  public :
  unsigned long getRealTime();
  void setRealTime(unsigned long currentTime);
  
};
