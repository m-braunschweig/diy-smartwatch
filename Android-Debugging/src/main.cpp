#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <Globals.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth_serial(BT_RX, BT_TX);

void setup() {
  pinMode(BT_KEY_PIN, OUTPUT);
  digitalWrite(BT_KEY_PIN, HIGH);
  Serial.begin(9600);
  bluetooth_serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  while (bluetooth_serial.available() > 0)
    Serial.write(bluetooth_serial.read());
  while (Serial.available() > 0) {
    bluetooth_serial.write(Serial.read());
  }
}
