#pragma once

class Lid
{
  private:
  int m_leftServo_pin;
  int m_rightServo_pin;

  public:
  Lid(int leftServo_pin,int rightServo_pin);
  void openLid();
  void closeLid();
  void init();
  int getPreferenceAngle();
  void setPreferenceAngle(int angle);
  
  
};
