#include "Angle.h"
#include "Display.h"
#include <Wire.h>
#include "RealTimeClock.h"

/*RealTimeClockインスタンス生成*/
RealTimeClock realtimeclock;
/*Lcdインスタンス生成*/
Display display;
/*Angleインスタンス生成*/
Angle angle;

void setup() {
  // Lcd初期化処理
  display.init();

}

void loop() {
  
}
