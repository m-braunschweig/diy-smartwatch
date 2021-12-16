
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
#include <Time.h>

bool showing_time = true;

void page_time_update() {
  display.firstPage();
  do {
    draw_triangle(DisplayArrow::LEFT | DisplayArrow::RIGHT | DisplayArrow::TOP);
    if (showing_time) {
      String cur_time;
      if (hour() < 10)
        cur_time = "0" + String(hour());
      else
        cur_time = String(hour());
      cur_time += ":";
      if (minute() < 10)
        cur_time += "0" + String(minute());
      else
        cur_time += String(minute());
      draw_center_str_prep(Fontsize::LARGE);
      draw_center_str_no_loop(cur_time.c_str());
    } else {
      String days[] = {"",
                       String("Sonntag"),
                       String("Montag"),
                       String("Dienstag"),
                       String("Mittwoch"),
                       String("Donnerstag"),
                       String("Freitag"),
                       String("Samstag")};
      String datum =
          String(day()) + "." + String(month()) + "." + String(year());

      draw_center_str_prep(Fontsize::LARGE);
      draw_center_str_no_loop(datum.c_str(), -8);
      draw_center_str_prep(Fontsize::MEDIUM);
      draw_center_str_no_loop(days[weekday()].c_str(), 12);
    }
  } while (display.nextPage());
}

bool page_time_touch_false() {
  return false;
}

bool page_time_touch_up() {
  return true;
}

bool page_time_touch_side() {
  showing_time = !showing_time;
  page_time_update();
  return false;
}

void setup_page_time() {
  page_time->update = page_time_update;
  page_time->update_interval = 5000;
  page_time->page_above = page_mid;
  page_time->touch_down_left = page_time_touch_false;
  page_time->touch_down_right = page_time_touch_false;
  page_time->touch_up = page_time_touch_up;
  page_time->touch_left = page_time_touch_side;
  page_time->touch_right = page_time_touch_side;
}
