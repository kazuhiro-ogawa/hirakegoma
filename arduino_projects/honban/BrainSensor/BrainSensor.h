#pragma once

/* ピン管理 */
// ディスプレイのピン設定
#define displaySCL_PIN 22
#define displaySDL_PIN 21
// 人感センサーのピン設定
#define humanSensor_PIN 27
// ボタンのピン設定
#define btnIncAngle_PIN 25 
#define btnDecAngle_PIN 26

/* 定数 */
// タイマー割り込み間隔
#define INTTIM 5000000  // 5秒

/* モード */
typedef enum{
  OPEN,         // ごみ箱開口状態
  ANGLE_CHANGE, // 角度設定変更状態
  WAIT          // 待機状態
}MODE;

typedef enum{
  ENTRY,        // エントリー
  DO,           // ドゥ
  EXIT          // イグジット
}MODE_STATE;
