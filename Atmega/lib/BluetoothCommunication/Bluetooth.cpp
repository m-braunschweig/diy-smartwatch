#include "Bluetooth.h"
#include <Arduino.h>

SoftwareSerial* bluetooth_serial = nullptr;

void flush_response() {
  while (bluetooth_serial->available() > 0)
    bluetooth_serial->read();
}

void setup_bluetooth(int key, int rx, int tx, const char* name,
                     const char* pin) {
  bluetooth_serial = new SoftwareSerial(rx, tx);
  pinMode(key, OUTPUT);
  digitalWrite(key, HIGH);
  bluetooth_serial->begin(9600);
  delay(2000);
  bluetooth_serial->write("AT+NAME");
  bluetooth_serial->write(name);
  bluetooth_serial->write("\r\n");
  delay(50);
  flush_response();
  bluetooth_serial->write("AT+PASS");
  bluetooth_serial->write(pin);
  bluetooth_serial->write("\r\n");
  delay(50);
  flush_response();
  bluetooth_serial->write("AT+TYPE1\r\n");
  delay(50);
  flush_response();
}
