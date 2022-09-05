#include "Angle.h"
#include "Display.h"
#include <Wire.h>
#include "Lid.h"
#include "UltraSonicSensor.h"
#include "RealTimeClock.h"
/*Lidクラスインスタンス生成*/
Lid lid = Lid(4,5); //(4,5)仮
/*超音波センサーインスタンス生成*/
UltraSonicSensor ultrasonicsensor = UltraSonicSensor(13,12);//(13,12)仮
/*RealTimeClockインスタンス生成*/
RealTimeClock realtimeclock = new RealTimeClock();
/*Lcdインスタンス生成*/
Display display;

Angle angle;

void setup() {
  // put your setup code here, to run once:
  // Lcd初期化処理
  display.init();
  //サーボ初期設定
  lid.init();

void loop() {

}
