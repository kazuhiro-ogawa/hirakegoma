#pragma once
/*スピーカーピン設定*/
#define speaker_PIN 33
/*Lidのサーボピン設定*/
#define leftServo_PIN 25
#define rightServo_PIN 26
/*超音波センサーのピン設定*/
#define ECHO_PIN 17
#define TRIG_PIN 16
/*mode*/
typedef enum{
  OPEN,
  ANGLE_CHANGE,
  WAIT,
}MODE;

typedef enum{
  ENTRY,
  DO,
  EXIT,
}ACTION_STATE;
