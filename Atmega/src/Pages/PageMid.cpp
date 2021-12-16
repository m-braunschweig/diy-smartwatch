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

#include "PageHelper.h"
#include <DisplayManager.h>

DisplayPage* page_mid = new DisplayPage();
DisplayPage* page_bme = new DisplayPage();
DisplayPage* page_time = new DisplayPage();

int page_mid_index = 0;
DisplayPage* page_order[] = {page_time, page_bme, nullptr};
const char* page_names[] = {"Zeit", "BME"};

void page_mid_update() {
  display.firstPage();
  do {
    draw_triangle(DisplayArrow::LEFT | DisplayArrow::RIGHT | DisplayArrow::TOP);
    label_arrow(DisplayArrow::TOP, (char*)page_names[page_mid_index]);
  } while (display.nextPage());
}

bool page_mid_touch_up() {
  return true;
}

bool page_mid_touch_false() {
  return false;
}

void page_mid_scroll(bool right) {
  if (right)
    ++page_mid_index;
  else
    --page_mid_index;
  if (page_mid_index < 0) {
    page_mid_index = 0;
    while (page_order[page_mid_index] != nullptr) {
      ++page_mid_index;
    }
    --page_mid_index;
  } else if (page_order[page_mid_index] == nullptr) {
    page_mid_index = 0;
  }
  page_mid->page_above = page_order[page_mid_index];
  page_mid_update();
}

bool page_mid_touch_right() {
  page_mid_scroll(true);
  return false;
}

bool page_mid_touch_left() {
  page_mid_scroll(false);
  return false;
}

void setup_page_mid() {
  page_mid->update = page_mid_update;
  page_mid->update_interval = 20000;
  page_mid->page_above = page_time;
  page_mid->touch_down_left = page_mid_touch_false;
  page_mid->touch_down_right = page_mid_touch_false;
  page_mid->touch_up = page_mid_touch_up;
  page_mid->touch_left = page_mid_touch_left;
  page_mid->touch_right = page_mid_touch_right;
}
