#include "Angle.h"
#include "Display.h"
#include <Wire.h>
#include "RealTimeClock.h"
/*人感センサーピン仮設定
#define humanSensor_IN 0*/

/*RealTimeClockインスタンス生成*/
RealTimeClock realtimeclock;
/*Lcdインスタンス生成*/
Display display;
/*Angleインスタンス生成*/
Angle angle;
/*ブルートゥースから信号を受け取るメソッド*/
void mode_change(){
  
}

void setup() {
   //人感センサー設定
  attachInterrupt(PIN,mode_change,RISING);//割り込み
  // Lcd初期化処理
  display.init();

}

void loop() {
  
}
