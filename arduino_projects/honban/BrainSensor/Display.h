/* インクルードガード */
#pragma once

#define LCD_ADRS 0x3E

class Display
{
  private :
    String errorMsg = "\x21\x21\xCA\xDD\xB2\xB6\xDE\xB2\xC3\xDE\xBD\x21\x21";
    String warningMsg = "\xBA\xDE\xD0\xB6\xDE\xB2\xAF\xCA\xDF\xB2\xC0\xDE\xD6";
    String warningChar = "(xox)";
    String character = "(^o^)";
    String garbageCategory = "\xB7\xAE\xB3\xCA\xBA\xDE\xD0\xC9\xCB\xC0\xDE\xD6";
  
    void init_LCD();                    // LCDの初期化処理
    void writeData(byte t_data);        // 文字データ送信処理
    void writeCommand(byte t_command);  // コマンド送信処理
    void cursorMove(int place);         // カーソル移動処理
    void printString(String str);       // 文字列表示処理
    void printData(int data);           // 数値表示処理
    
  public :
    void init();                        // 初期化処理
    void printErrorMsg();               // 角度調整時エラーメッセージ表示
    void printWarningMsg();             // ごみ取り換えメッセージ表示
    void printCharacter();              // 開口時の顔文字表示
    void printAngle(int angle);         // 角度調整時の設定角度表示
    void printGarbageCategory();        // ゴミ出し日を表示
    void offLcd();                      // LCDを非表示
};
