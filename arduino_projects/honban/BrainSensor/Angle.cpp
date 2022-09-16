#include <Arduino.h>
#include "Angle.h"

// 設定角度のゲッター
int Angle::getPreferenceAngle(){
  return preferenceAngle;
}

//角度上昇
void Angle::incrementAngle()  {
  if(preferenceAngle >= 80){}
  else{preferenceAngle += 5;}
  Serial.print("上昇：");
  Serial.println(preferenceAngle);
}

//角度下降
void Angle::decrementAngle() {
  if(preferenceAngle <= 60){}
  else{preferenceAngle -= 5;}
  Serial.print("下降：");
  Serial.println(preferenceAngle);
}
