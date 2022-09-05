#include <Arduino.h>
#include "Display.h"
#include <Wire.h>
#include"BrainSensor.h"

/* LCDの初期化処理 */
void Display::init_LCD() {
  delay(100);
  writeCommand(0x38);
  delay(20);
  writeCommand(0x39);
  delay(20);
  writeCommand(0x14);
  delay(20);
  writeCommand(0x73);
  delay(20);
  writeCommand(0x52);
  delay(20);
  writeCommand(0x6C);
  delay(20);
  writeCommand(0x38);
  delay(20);
  writeCommand(0x01);
  delay(20);
  writeCommand(0x0C);
  delay(20);
}

/* 文字データ送信処理 */
void Display::writeData(byte t_data)
{
  Wire.beginTransmission(LCD_ADRS);
  Wire.write(0x40);
  Wire.write(t_data);
  Wire.endTransmission();
  delay(1);
}

/* コマンド送信処理 */
void Display::writeCommand(byte t_command)
{
  Wire.beginTransmission(LCD_ADRS);
  Wire.write(0x00);
  Wire.write(t_command);
  Wire.endTransmission();
  delay(10);
}

/*LCDのカーソルを自由に移動させる関数*/
void Display::cursorMove(int place){     //返却値なし　引数　整数型(カーソルを移動させたいアドレス)
  writeCommand(place + 0x80);   //インストラクションコード 0x80 カーソル移動
                                //それに移動させたいアドレスを足し合わせることで　そのアドレスにカーソルを移動させる
                                // writeCommand(place + 0x80);　が  プログラム中に出てきてもインストラクションコードを分からないと読めない
                                // cursorMoveなら名前から意味が想像しやすく　可読性　を上げることができる
}

/* 文字列表示処理 */
void Display::printString(String str){
  int i  = 0;
  int len = str.length();

  for(i = 0; i < len; i++){
    writeData(str.charAt(i)); //CharAt()...引数で指定した位置の文字を返す
    delay(1);
  }
}

/* 数値表示処理 */
void Display::printData(int data){
  String dataStr = (String)data;
  printString(dataStr);
}

/* 初期化処理 */
void Display::init(){
  Wire.begin();
  init_LCD();
}

/* 角度調整時エラーメッセージ表示 */
void Display::printErrorMsg(){
  // 画面をクリア
  writeCommand(0x01);

  // カーソル移動
  cursorMove(0x02);

  // エラーメッセージ表示
  printString(errorMsg);
}

/* ごみ取り換えメッセージ表示 */
void Display::printWarningMsg(){
  // 画面をクリア
  writeCommand(0x01);

  // カーソル移動
  cursorMove(0x02);

  // ごみ取り換えメッセージ表示
  printString(warningMsg);

  // カーソル移動
  cursorMove(0x46);

  // 顔文字表示
  printString(warningChar);
}

/* 開口時の顔文字表示 */
void Display::printCharacter(){
  // 画面をクリア
  writeCommand(0x01);

  // カーソル移動
  cursorMove(0x06);

  // 顔文字表示
  printString(character);
}

/* 角度調整時の設定角度表示 */
void Display::printAngle(int angle){
  // 画面をクリア
  writeCommand(0x01);

  // カーソル移動
  cursorMove(0x07);

  // 数値を表示
  printData(angle);
}

/* ゴミ出し日を表示 */
void Display::printGarbageCategory(){
  // 画面をクリア
  writeCommand(0x01);

  // カーソル移動
  cursorMove(0x02);

  // ゴミ出し日を表示
  printString(garbageCategory);
}

/* LCDを非表示 */
void Display::offLcd(){
  // 画面をクリア
  writeCommand(0x01);
}
