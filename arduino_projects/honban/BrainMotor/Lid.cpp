
#include <Arduino.h>
#include"Lid.h"
#include"BrainMotor.h"
/*テスト*/
//#define leftServo_PIN 4　　
//#define rightServo_PIN 5



Lid::Lid(int leftServo_pin,int rightServo_pin){
  m_leftServo_pin = leftServo_pin;
  m_rightServo_pin = rightServo_pin;
}


//設定角度を取得
int Lid::getPreferenceAngle()
{
  return preferenceAngle;
}


//設定角度を設定
void Lid::setPreferenceAngle(int angle)
{
  preferenceAngle = angle;
}

//初期値設定
void Lid::init()
{
  leftServo.attach(m_leftServo_pin);
  rightServo.attach(m_rightServo_pin);
  leftServo.write(0);
 rightServo.write(0);
}
//蓋の開口
void Lid::openLid()
{
  leftServo.write(preferenceAngle);
  rightServo.write(preferenceAngle);
}


//蓋の閉口
void Lid::closeLid()
{
 leftServo.write(0);
 rightServo.write(0);
}
