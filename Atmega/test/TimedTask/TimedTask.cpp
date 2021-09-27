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

#include <Adafruit_BusIO_Register.h>
#include <Arduino.h>
#include <TimedTask.h>
#include <unity.h>

static volatile int shared_int = -1;
static volatile unsigned int test_iteration = 0;

TimedTaskScheduler scheduler;
// The multiplyer is used to get a bigger delay for more accurate results
constexpr unsigned long multiplyer = 100;
constexpr unsigned long update_delay = 10;
static constexpr int expect_array[] = {3, 1, 2, 1, 3, 1, 2, 1, 2, 3, 1, 1, 2};

static TimedTask task1(7 * multiplyer);
static TimedTask task2(11 * multiplyer);
static TimedTask task3(17 * multiplyer);

void setup_task_1() {
  shared_int = 1;
}

void setup_task_2() {
  shared_int = 2;
}

void setup_task_3() {
  shared_int = 3;
}

void setup_tasks() {
  task1.task = &setup_task_1;
  task2.task = &setup_task_2;
  task3.task = &setup_task_3;
  TEST_ASSERT_NULL(task1.next);
  TEST_ASSERT_NULL(task2.next);
  TEST_ASSERT_NULL(task3.next);
  scheduler.add_task(&task1);
  scheduler.add_task(&task2);
  scheduler.add_task(&task3);
  TEST_ASSERT_NOT_NULL(task1.next);
  TEST_ASSERT_NOT_NULL(task2.next);
  TEST_ASSERT_NULL(task3.next);
}

void test_run_async() {
  setup_tasks();
  while (1) {
    while (shared_int == -1) {
      delay(update_delay);
      scheduler.update();
    }
    TEST_ASSERT_EQUAL_INT(expect_array[test_iteration], shared_int);
    shared_int = -1;
    ++test_iteration;
    if (test_iteration == (sizeof(expect_array) / sizeof(int)))
      return;
  }
}

void setup() {
  delay(2500);
  UNITY_BEGIN();
  RUN_TEST(test_run_async);
  UNITY_END();
}

void loop() {
}
