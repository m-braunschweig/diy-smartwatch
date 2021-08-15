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

#ifndef TIMED_TASK_H
#define TIMED_TASK_H

/*
 * This is a small library that allows to run functions periodically. To
 * achive this it uses the millis() function to check, if a task needs to
 * be run. After a task ran it sets the next_run time to millis() + delay.
 *
 * Internally it uses a linked list to store the tasks. To use it you have to
 * periodically call update() of the TimedTaskScheduler. New Tasks are added by
 * creating a TimedTask object, setting it's task-pointer and adding it to the
 * TimedTaskScheduler with add_task();
 *
 * An example can be found in the TimedTask.cpp Unit-Test.
 */

class TimedTask {
  public:
    TimedTask(unsigned long);
    void (*task)();
    void update_next_run();
    bool check_run();
    TimedTask* next = nullptr;

  private:
    unsigned long delay_;
    unsigned long next_run_ = 0;
};

class TimedTaskScheduler {
  public:
    void add_task(TimedTask*);
    void update();

  private:
    TimedTask* first_ = nullptr;
};

#endif
