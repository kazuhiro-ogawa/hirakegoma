#include <Arduino.h>
#include "BrainMotor.h"
#include "UltraSonicSensor.h"

//コンストラクタでピン設定
UltraSonicSensor::UltraSonicSensor(int echo_pin, int trig_pin){
  echo = echo_pin;
  trig = trig_pin;
  pinMode(echo_pin,INPUT);
  pinMode(trig_pin,OUTPUT);
}


//超音波センサーの距離測定
float UltraSonicSensor::measureDistance(){
  float t; //ｔはμ秒単位
  float distance = 0;

   /*超音波の発生*/
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  /*返ってくるまでの時間測定*/
  t = pulseIn(ECHO,HIGH); //ECHOピンのパルスがHIGHになった時間を変数tに格納
  if(t >= 0){
    distance = (float)t * 340*(0.000001)*0.5*100;//m→cmなので100倍する
  }

  return distance;//戻り値
}


//センサーにて開口距離をチェック
bool UltraSonicSensor::checkDistance(){
  float distance;
  distance =measureDistance();
  //０cmから20cmの場合trueを返す
  if( 0 < distance && distance < 20){
    return true;
  }
  return false;
}
