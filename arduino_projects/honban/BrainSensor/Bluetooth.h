#pragma once

class Bluetooth
{
  private:
  uint8_t address[6]={0x3C,0x71,0xBF,0x99,0xFB,0x3A}; //MACアドレス仮
  bool connected;
  
  public:
  //定数
  const char CLOSE = 'c';   // 閉口のサイン
  const char OPEN = 'o';    // 開口のサイン
  const char FULL = 'f';    // 容量一杯のサイン
  const char EMPTY = 'e';   // 容量余裕のサイン
  
  //メソッド
  void initWrite();
  void initRead();
  int BluetoothRead();
  void BluetoothWrite(char sendCode);
};
