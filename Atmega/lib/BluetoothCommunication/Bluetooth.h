#ifndef BLUETOOTH_COMMUNICATION
#define BLUETOOTH_COMMUNICATION

#include <SoftwareSerial.h>

extern SoftwareSerial* bluetooth_serial;
void setup_bluetooth(int, int, int, const char*, const char*);

#endif
