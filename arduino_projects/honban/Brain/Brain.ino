#include "Lid.h"
#include "UltraSonicSensor.h"
#include "RealTimeClock.h"
/*Lidクラスインスタンス生成*/
Lid lid = Lid(4,5); //(4,5)仮
/*超音波センサーインスタンス生成*/
UltraSonicSensor ultrasonicsensor = UltraSonicSensor(13,12);//(13,12)仮
/*RealTimeClockインスタンス生成*/
RealTimeClock realtimeclock;

void setup() {
  
  lid.init();//サーボ初期設定

}

void loop() {
 

}
