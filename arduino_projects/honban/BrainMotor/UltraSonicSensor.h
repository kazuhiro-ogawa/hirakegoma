#pragma once

class UltraSonicSensor     // classの定義
{
  private :               // privateはクラス内からしかアクセスできない
    int echo;
    int trig;
    
  public :                // publicはどこからでもアクセス可能
    UltraSonicSensor(int echo_pin, int trig_pin);   // コンストラクター
    float measureDistance();             // 距離測定関数
    bool checkDistance();                 // 人通過チェック
    
};
