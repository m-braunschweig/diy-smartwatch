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

#include <DisplayManager.h>
#include <TimedTask.h>

DisplayPage* DisplayManager::current_page = nullptr;

void DisplayManager::setup() {
  display.begin();
  current_page = page_mid;
}

void DisplayManager::touch_up() {
  if (current_page->touch_up())
    change_page(current_page->page_up);
}

void DisplayManager::touch_left() {
  current_page->touch_left();
}

void DisplayManager::touch_right() {
  current_page->touch_right();
}

void DisplayManager::touch_down() {
  current_page->touch_down();
}

void DisplayManager::update() {
  current_page->update();
}

void DisplayManager::change_page(DisplayPage* new_page) {
  current_page = new_page;
  new_page->update();
  timed_task_scheduler->refresh_delay_times();
}

unsigned long DisplayManager::update_interval() {
  return current_page->update_interval;
}
