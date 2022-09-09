#include <time.h>

#include "Angle.h"
#include "Display.h"
#include "RealTimeClock.h"
#include "BrainSensor.h"
#include "Bluetooth.h"

/* インスタンス生成 */
Display display;
Angle angle;
RealTimeClock realtimeclock;
Bluetooth bluetooth;

/* モードの初期化 */
MODE s_mode = WAIT;
MODE_STATE action = ENTRY;

/* タイマー割り込みで使用するグローバル変数 */
hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

/* タイマー割り込み初期設定 */
void init_inttimer()
{
  // タイマー初期設定（タイマー番号,分周比,タイマ―増加）
  timer = timerBegin(0, 80, true);

  // 割り込み関数登録（タイマー初期設定の戻り値,割り込む関数,エッジタイプ）
  timerAttachInterrupt(timer, &closeMode, true);

  // 割り込みタイミング設定（タイマー初期設定の戻り値,間隔（マイクロ秒）,自動再起）
  timerAlarmWrite(timer, INTTIM, true);
}

// ゴミ箱開口処理
void openMode(){
  s_mode = OPEN;
  action = ENTRY;
}

// ゴミ箱閉口処理
void closeMode(){
  portENTER_CRITICAL_ISR(&timerMux);  // タイマー設定処理

  /* ↓実際の処理↓ */
  
  action = EXIT;
  
  /* ↑実際の処理↑ */
  
  portEXIT_CRITICAL_ISR(&timerMux);   // タイマー設定処理
}

void setup() {
  init_inttimer();                  // タイマー割り込み初期設定
  display.init();                   // LCD初期化処理
  pinMode(humanSensor_PIN,INPUT);   // 人感センサーのピン設定
  pinMode(btnIncAngle_PIN,INPUT);   // 角度上昇ボタンのピン設定
  pinMode(btnDecAngle_PIN,INPUT);   // 角度下降ボタンのピン設定
  bluetooth.initWrite();            // Bluetooth送信の初期設定
  bluetooth.initRead();             // Bluetooth受信の初期設定
}

void loop() {

  switch (s_mode) {

    case OPEN:  // ごみ箱開口状態

      switch (action) {

        case ENTRY:

          // Bluetooth送信処理
          bluetooth.BluetoothWrite(bluetooth.OPEN);

          // LCDに顔文字出力
          display.printCharacter();

          // タイマースタート
          timerAlarmEnable(timer);

          action = DO;
          break;

        case DO:

          // 人感センサーが再び反応したらエントリーへ戻る
          if(digitalRead(humanSensor_PIN) == HIGH){
            action = ENTRY;
          }
          break;

        case EXIT:

          // タイマーストップ
          timerEnd(timer);

          // Bluetooth送信処理
          bluetooth.BluetoothWrite(bluetooth.CLOSE);

          s_mode = WAIT;
          action = ENTRY;
          break;
      }
      break;

    case ANGLE_CHANGE:  // 角度設定変更状態

      switch (action) {

        case ENTRY:

          // Bluetooth送信処理
          bluetooth.BluetoothWrite(angle.getPreferenceAngle());

          // LCDに設定角度を表示
          display.printAngle(angle.getPreferenceAngle());

          // MsTimerスタート
          timerAlarmEnable(timer);

          action = DO;
          break;

        case DO:

          // 角度上昇ボタンをもう一度押すと設定角度を上昇させてエントリーへ戻る
          if(digitalRead(btnIncAngle_PIN) == HIGH){
            angle.incrementAngle();
            action = ENTRY;
          }

          // 角度下降ボタンをもう一度押すと設定角度を下降させてエントリーへ戻る
          if(digitalRead(btnDecAngle_PIN) == HIGH){
            angle.decrementAngle();
            action = ENTRY;
          }

          break;

        case EXIT:

          // タイマーストップ
          timerEnd(timer);

          // Bluetooth送信処理
          bluetooth.BluetoothWrite(bluetooth.CLOSE);

          s_mode = WAIT;
          action = ENTRY;
          break;
      }
      break;

    case WAIT:  // 待機状態
    
      switch (action) {

        case ENTRY:
          // LCDをOFF
          display.offLcd();
          break;

        case DO:

          // BluetoothでFULLのサインを受信したら画面切り替え
          if(bluetooth.BluetoothRead() == -1){
            // 何もしない
          }
          else if(bluetooth.BluetoothRead() == 1){
            display.printWarningMsg();
          }
          else if(bluetooth.BluetoothRead() == 0){
            display.offLcd();
          }

          // 人感センサーが反応したらゴミ箱開口モードへ移行
          if(digitalRead(humanSensor_PIN) == HIGH){
            s_mode = OPEN;
            action = ENTRY;
          }

          // 角度上昇ボタンを押すと角度設定変更状態へモード移行
          if(digitalRead(btnIncAngle_PIN) == HIGH){
            s_mode = ANGLE_CHANGE;
            action = ENTRY;
          }

          // 角度下降ボタンを押すと角度設定変更状態へモード移行
          if(digitalRead(btnDecAngle_PIN) == HIGH){
            s_mode = ANGLE_CHANGE;
            action = ENTRY;
          }
          
          break;

        case EXIT:
          // 何もしない
          break;
      }
      break;

  }
}
