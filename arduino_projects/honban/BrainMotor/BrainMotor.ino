#include "Lid.h"
#include "UltraSonicSensor.h"
#include"Speaker.h"
#include"Bluetooth.h"
#include"BrainMotor.h"


/*Lidクラスインスタンス生成*/
Lid lid = Lid(25,26); 
/*超音波センサーインスタンス生成*/
UltraSonicSensor ultrasonicsensor = UltraSonicSensor(17,16);
/*スピーカーのインスタンス生成*/
Speaker speaker = Speaker(33);
/*Bluetoothクラスのインスタンス生成*/
Bluetooth bluetooth;
/*モードの初期化*/
MODE g_mode = OPEN;
ACTION_STATE action = ENTRY;

void change_mode(MODE mode){
  g_mode = mode;
}


void setup() {
  //サーボ初期設定
  lid.init();
  //Bluetooth送信の初期設定
  bluetooth.initWrite();
  //Bluetooth受信の初期設定
  bluetooth.initRead(); 
}


void loop() {
 //調整角度
 int preferenceAngle;
 
  switch(g_mode){
  
  case OPEN:
   switch(action){
      case ENTRY:
      //Lidの開口
      lid.openLid();
       //音声出力
      speaker.playMelody(1);//数値仮
      action = DO;
      break;
      case DO:
      g_mode = WAIT;
      break;
      case EXIT:
      //Lidの閉口
      lid.closeLid();
      //音声出力
      speaker.playMelody(1);
      g_mode = WAIT;
      break;
    }
    break;

   case ANGLE_CHANGE:
    switch(action){
      case ENTRY:
      //Lidに渡ってきた数値を代入
      lid.setPreferenceAngle(preferenceAngle);
      //Lidの開口
      lid.openLid();
      action = DO;
      break;
      case DO:
      action = EXIT;
      break;
      case EXIT:
      g_mode = WAIT;
      break;
    }
    break;
    
     case WAIT:
     switch(action){
      case ENTRY:
      //Bluetoothの受信がOPENの時
      if(bluetooth.BluetoothRead()== 1){
        g_mode = OPEN;
       //Bluetoothの受信がCLOSEの時 
      }else if (bluetooth.BluetoothRead()== 0){
              //超音波センサーを起動させて距離測定と0cmから20cmの場合
              if(ultrasonicsensor.checkDistance()== true){
              //ゴミ出しサインをBrainSensorに送信する
              bluetooth.BluetoothWrite('f');
              //ゴミ出しのサイン音を出力
              speaker.playMelody(1);
              }else{
              //それ以外はEMPTY状態をBrainSensorに送信
              bluetooth.BluetoothWrite('e');
            }
        
         }else{
          //OPENとCLOSE以外の値がわたって来たときは角度数値と見なしprefernceAngleに角度を代入する
          preferenceAngle=bluetooth.BluetoothRead();
         }
      action = DO;
      break;
      case DO:
      action = EXIT;
      break;
      case EXIT:
      g_mode = WAIT;
      break;
    }
    break;
    
  }
  
  
  
  /*ごみ残量判定*/
//Bluetoothの受信がCLOSEのとき超音波センサー起動
  /*if(bluetooth.BluetoothRead()== 0)
  {
    //Lidの閉口
    lid.closeLid();
    //音声出力
    speaker.playMelody(1);
    
    //超音波センサーを起動させて距離測定と0cmから20cmの場合
    if(ultrasonicsensor.checkDistance()== true){
      //ゴミ出しサインを送信する
      bluetooth.BluetoothWrite('f');
      //ゴミ出しのサイン音を出力
      speaker.playMelody(1);
    }else{
      //それ以外はEMPTY状態を送信
      bluetooth.BluetoothWrite('e');
    }
  
  }*/
  /*蓋の開口*/
 //Bluetoothの受信がOPENのときLidとSpeakerを起動
 /* else if(bluetooth.BluetoothRead()== 1)
  {
    lid.openLid();
    speaker.playMelody(1);
    
  }
  else
  {
    
  }*/
 
  
}
