# A Diy-Smartwatch using the Atmega-1284P/644P (WIP)
This project aims to make a DIY-Smartwatch. It uses a ``MIC5205`` for power regulation, a ``MPR121`` for Touch-Electrodes, a ``HM-11`` for a Bluetooth-Low-Energy (BLE) connection, a ``BME280`` for
Temperature, Humidity and Pressure, a ``TP4056`` as charging-circuit and as Microcontroller a Atmega-1284P or 644P. The Display is a more or less generic 128x64px OLED-Display, connected with I2C.

**Please note that this Project is still Work in Progress and is not nearly finished yet**

This project originates from this [project](https://github.com/RatsgymnasiumPeine/2016-07-diy-smartwatch), but it's completly rewritten and on a PCB.

## Language
This project is written in C++, but for the learning aspect I try to keep it very close to C (excluding classes). In the future this might get fully ported to pure C.

## Debugging
You can debug this using gdb with simavr. An example ``.gdbinit`` is given. You then have to run ``pio run -e Debug && simavr -m atmega1284 -f 8000000 .pio/build/Debug/firmware.elf -g & avr-gdb`` (on
Linux Systems).

You might have to add the ``Atmega`` directory to your gdb's safe-path to run the gdbinit (or you run the commands of the file manually).

## Android-Development
As I don't know a lot about Android/Bluetooth I am going to implement it following this order:
- [x] Get a basic app (and a small PlatformIO Firmware exposing the Serial connection)
- [ ] Add "pairing" → saving the device in the app
- [ ] Send some data via a buttonpress
- [ ] Develop small expandable protocol (starting by sending the time; later notifications might get added)
- [ ] Add checks for failed communication
- [ ] Run the data transmission periodically in background
