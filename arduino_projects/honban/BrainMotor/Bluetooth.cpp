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

  if(isClosed()){
    while(!bluetoothserial.connected(10000)){
      connected = bluetoothserial.connect(address);
    }
  }
  
}

//Bluetooth受信の初期設定
void Bluetooth::initRead() {
  bluetoothserial.begin("ESP32_Sensor");
}

//Bluetoothの送信
void Bluetooth::BluetoothWrite(char sendCode) {
  bluetoothserial.write(sendCode);
}

//Bluetoothの受信
int Bluetooth::BluetoothRead() {
  //Lidの状態　０＝閉口　1=開口
  int lidStatus = -1;
  if (bluetoothserial.available()) {
    if (bluetoothserial.read() == OPEN) {
      lidStatus = 1;
    } else if (bluetoothserial.read() == CLOSE) {
      lidStatus = 0;
    } else {
      lidStatus = bluetoothserial.read();
    }
  }
  return lidStatus;
}
