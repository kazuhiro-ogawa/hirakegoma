#pragma once

class RealTimeClock
{
  private :
  unsigned long m_currentTime;  // 現在日時情報

  public :
  unsigned long getRealTime();                  // 現在日時のゲッター
  void setRealTime(unsigned long currentTime);  // 現在日時のセッター
  
};
