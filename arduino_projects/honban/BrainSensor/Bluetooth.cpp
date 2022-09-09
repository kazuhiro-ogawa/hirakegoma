#include <BluetoothSerial.h>

// ↓自動追記
//#include <BTAddress.h>
//#include <BTAdvertisedDevice.h>
//#include <BTScan.h>

#include"Bluetooth.h"

BluetoothSerial bluetoothserial;



//Bluetooth送信の初期設定
void Bluetooth::initWrite() {
  bluetoothserial.begin("ESP32_Moter", true);
  connected =  bluetoothserial.connect(address);
}

//Bluetooth受信の初期設定
void Bluetooth::initRead() {
  bluetoothserial.begin("ESP32_Sensor");
}

//Bluetooth送信の初期設定
void Bluetooth::BluetoothWrite(char sendCode) {
  bluetoothserial.write(sendCode);
}

//Bluetoothの受信
int Bluetooth::BluetoothRead() {
  //UltraSonicSensorの状態　０＝通常　１＝満タン
  int USSStatus = -1;
  if (bluetoothserial.available()) {
    if (bluetoothserial.read() == FULL) {
      USSStatus = 1;
    } else if (bluetoothserial.read() == EMPTY) {
      USSStatus = 0;
    }
  }
  return USSStatus;
}
