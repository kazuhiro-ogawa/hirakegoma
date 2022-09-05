#include <Arduino.h>
#include "Display.h"
#include <Wire.h>

Display display;

void setup() {
  // put your setup code here, to run once:
  display.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  display.printErrorMsg();               // 角度調整時エラーメッセージ表示
  delay(5000);
  display.printWarningMsg();             // ごみ取り換えメッセージ表示
    delay(5000);
  display.printCharacter();              // 開口時の顔文字表示
    delay(5000);
  display.printAngle(60);         // 角度調整時の設定角度表示
    delay(5000);
  display.printGarbageCategory();        // ゴミ出し日を表示
    delay(5000);
  display.offLcd();                      // LCDを非表示
    delay(5000);
}
