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

void DisplayManager::setup() {
  display.begin();
  update = current_page->update;
}

void DisplayManager::touch_up() {
  current_page->touch_up();
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

void DisplayManager::changed_page() {
  update = current_page->update;
}

unsigned long DisplayManager::update_interval() {
  return current_page->update_interval;
}
