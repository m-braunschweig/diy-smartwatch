/*
 *  diy-smartwatch - a diy smartwatch
 *  Copyright (C) 2021  Mika Braunschweig
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <SPI.h>
#include <Wire.h>
#include <Arduino.h>
#include <WString.h>
#include <Gloabls.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_Sensor.h>
#include <DisplayManager.h>
#include "Pages/PageHelper.h"

TimedTaskScheduler* timed_task_scheduler = new TimedTaskScheduler;
DisplayManager display_manager;
void setup_tasks();

void setup() {
  setup_pages();
  display_manager.setup();
  setup_tasks();
}

void loop() {
  timed_task_scheduler->update();
  delay(TASK_DELAY);
}

void setup_tasks() {
  TimedTask* display_task = new TimedTask(display_manager.update_interval());
  display_task->task = display_manager.update;
  timed_task_scheduler->add_task(display_task);
}