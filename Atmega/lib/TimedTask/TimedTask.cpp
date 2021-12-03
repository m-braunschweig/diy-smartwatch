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

#include <Arduino.h>
#include <TimedTask.h>

TimedTask::TimedTask(unsigned long delay) {
  delay_ = delay;
  delay_ptr_ = nullptr;
}

TimedTask::TimedTask(unsigned long (*delay_ptr)()) {
  delay_ = delay_ptr();
  delay_ptr_ = delay_ptr;
}

void TimedTask::update_next_run() {
  next_run_ = millis() + delay_;
}

bool TimedTask::check_run() {
  return (millis() > next_run_);
}

void TimedTask::refresh_delay_time() {
  if (delay_ptr_)
    delay_ = delay_ptr_();
}

void TimedTaskScheduler::add_task(TimedTask* task) {
  if (!first_) {
    first_ = task;
  } else {
    TimedTask* t = first_;
    while (t->next)
      t = t->next;
    t->next = task;
  }
}

void TimedTaskScheduler::update() {
  TimedTask* t = first_;
  while (t) {
    if (t->check_run()) {
      t->task();
      t->update_next_run();
    }
    t = t->next;
  }
}

void TimedTaskScheduler::refresh_delay_times() {
  TimedTask* t = first_;
  while (t) {
    if (t->delay_ptr_) {
      t->refresh_delay_time();
    }
    t = t->next;
  }
}

TimedTask* TimedTaskScheduler::first_ = nullptr;
