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

#ifndef GLOBALS_H
#define GLOBALS_H

#include <TimedTask.h>
#include <U8g2lib.h>

#define TASK_DELAY 10

#define MPR_ADDRESS 0x5A
#define TOUCH_DELAY 50
#define TOUCH_TIMEOUT 200

#define TOUCH_UP 7
#define TOUCH_LEFT 5
#define TOUCH_RIGHT 8
#define TOUCH_DOWN 3

#define BME_DELAY 500

extern TimedTaskScheduler* timed_task_scheduler;

#endif
