#include "Speaker.h"
#include "Brain.h"
#include <Arduino.h>

//コンストラクタ
//スピーカのピン番号を設定
Speaker::Speaker(int speakerPin){
  speaker = speakerPin;
  pinMode(speaker, OUTPUT);
}

//音声出力メソッド
void Speaker::playMelody(int modeState){

  //０・・・ゴミ箱開閉時に出力する音声
  //１・・・超音波センサー反応時(ゴミがいっぱいの時)に出力する音声
  switch(modeState){
    case STATUS_WAIT:
      switch(preferenceMelody){
        case 0:
          for(int i = 0; i < sizeof(melody_1) / sizeof(int); i++){
            tone(speaker, melody_1[i]);
            delay(BEAT);
          }
          noTone(speaker);
          break;
        case 1:
          for(int i = 0; i < sizeof(melody_1) / sizeof(int); i++){
            tone(speaker, melody_2[i]);
            delay(BEAT);
          }
          noTone(speaker);
          break;
        case 2:
          for(int i = 0; i < sizeof(melody_1) / sizeof(int); i++){
            tone(speaker, melody_1[i]);
            delay(BEAT);
          }
          noTone(speaker);
          break;
      }
      break;
    case STATUS_FULLWAIT:
      for(int i = 0; i < sizeof(melody_1) / sizeof(int); i++){
        tone(speaker, melody_1[i]);
        delay(BEAT);
      }
      noTone(speaker);
      break;
  }
}

//出力する音声番号を設定するメソッド
void Speaker::setPreferenceMelody(int melodyNum){
  preferenceMelody = melodyNum;
  Serial.println(preferenceMelody);
}
