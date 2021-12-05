
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

bool showing_time = true;

void page_time_update() {
  display.firstPage();
  do {
    draw_triangle(DisplayArrow::LEFT | DisplayArrow::RIGHT | DisplayArrow::TOP);
    label_arrow(DisplayArrow::TOP, (char*)"Zur\xfc"
                                          "ck");
  } while (display.nextPage());
}

bool page_time_touch_false() {
  return false;
}

bool page_time_touch_up() {
  return true;
}

void setup_page_time() {
  page_time->update = page_time_update;
  page_time->update_interval = 5000;
  page_time->page_above = page_mid;
  page_time->touch_down = page_time_touch_false;
  page_time->touch_up = page_time_touch_up;
  page_time->touch_left = page_time_touch_false;
  page_time->touch_right = page_time_touch_false;
}
