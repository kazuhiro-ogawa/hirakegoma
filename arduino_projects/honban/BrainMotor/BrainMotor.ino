#include "Lid.h"
#include "UltraSonicSensor.h"
#include"Speaker.h"

/*Lidクラスインスタンス生成*/
Lid lid = Lid(25,26); 
/*超音波センサーインスタンス生成*/
UltraSonicSensor ultrasonicsensor = UltraSonicSensor(17,16);
/*スピーカーのインスタンス生成*/
Speaker speaker = Speaker(33);
void setup() {
   //サーボ初期設定
  lid.init();
}

void loop() {
  // put your main code here, to run repeatedly:

}
