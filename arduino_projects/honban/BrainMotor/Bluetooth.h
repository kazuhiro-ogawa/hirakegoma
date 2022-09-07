#pragma once

class Bluetooth
{
  private:
  uint8_t address[6]={0x8C,0x4B,0x14,0x16,0x76,0xF6};//MCアドレス仮
  bool connected;
  
  public:
  //定数
  const char CLOSE = 'c';
  const char OPEN = 'o';
  const char FULL = 'f';
  const char EMPTY = 'e';
  //メソッド
  void initWrite();
  void initRead();
  int BluetoothRead();
  void BluetoothWrite(char sendCode);
};
