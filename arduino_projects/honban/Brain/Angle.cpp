
#include <Arduino.h>
#include "Angle.h"

//角度上昇
int Angle::incrementAngle(int preferenceAngle)  {
  preferenceAngle += 5;
  Serial.print("上昇：");
  Serial.println(preferenceAngle);
  return preferenceAngle;
}

//角度下降
int Angle::decrementAngle(int preferenceAngle) {
  preferenceAngle -= 5;
  Serial.print("下降：");
  Serial.println(preferenceAngle);
  return preferenceAngle;
}
