#pragma once
#include<ESP32Servo.h>

class Lid
{
  private:

    Servo leftServo;  //ServoクラスからインスタンスleftServoを生成
    Servo rightServo; //ServoクラスからインスタンスrightServoを生成
    int m_leftServo_pin;
    int m_rightServo_pin;
    int preferenceAngle = 60;  //初期設定角度


  public:
    Lid(int leftServo_pin, int rightServo_pin);
    void openLid();
    void closeLid();
    void init();
    int getPreferenceAngle();
    void setPreferenceAngle(int angle);


};
