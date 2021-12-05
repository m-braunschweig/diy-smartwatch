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

#ifndef DISPLAY_PAGE_H
#define DISPLAY_PAGE_H

/*
 * The methods touch_* return a boolean, whether current_page should be updated
 * to the correspondig page. True means it should be overriden
 */

class DisplayPage {
 public:
  bool (*touch_up)();
  bool (*touch_down)();
  bool (*touch_left)();
  bool (*touch_right)();
  DisplayPage* page_above;
  void (*update)();
  unsigned long update_interval;
};

#endif
