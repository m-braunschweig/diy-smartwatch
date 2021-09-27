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

#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include "Pages/PageHelper.h"
#include <DisplayPage.h>

class DisplayManager {
 public:
  void setup();
  void touch_up();
  void touch_down();
  void touch_left();
  void touch_right();
  void changed_page();
  void (*update)();
  unsigned long update_interval();

 private:
  DisplayPage* current_page = &page_mid;
  DisplayPage* pages[2] = {&page_mid, nullptr};
};

#endif
