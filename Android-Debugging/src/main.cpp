#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <Bluetooth.h>
#include <Globals.h>
#include <SoftwareSerial.h>

void setup() {
  setup_bluetooth(BT_KEY_PIN, BT_RX, BT_TX, BLUETOOTH_NAME, BLUETOOTH_PIN);
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  while (bluetooth_serial->available() > 0)
    Serial.write(bluetooth_serial->read());
  while (Serial.available() > 0) {
    bluetooth_serial->write(Serial.read());
  }
}
