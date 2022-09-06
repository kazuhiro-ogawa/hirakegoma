#include "Lid.h"
#include "UltraSonicSensor.h"
#include"Speaker.h"

/*人感センサーピン仮設定
#define humanSensor_IN 8*/

/*Lidクラスインスタンス生成*/
Lid lid = Lid(25,26); 
/*超音波センサーインスタンス生成*/
UltraSonicSensor ultrasonicsensor = UltraSonicSensor(17,16);
/*スピーカーのインスタンス生成*/
Speaker speaker = Speaker(33);
void setup() {
  //人感センサー設定
  pinMode(humanSensor_IN,INPUT);
   //サーボ初期設定
  lid.init();
}

void loop() {
  

}
