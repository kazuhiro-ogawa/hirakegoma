#pragma once

class Angle
{
  private :
    int preferenceAngle = 60;
    
  public :
    int getPreferenceAngle(); // 設定角度のゲッター
    void incrementAngle();  // 設定角度を上昇させる処理
    void decrementAngle();  // 設定角度を降下させる処理
};
