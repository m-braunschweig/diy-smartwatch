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

DisplayPage page_mid = DisplayPage();

void update() {
  display.firstPage();
  do {
    draw_triangle(DisplayArrow::LEFT |
                  DisplayArrow::RIGHT |
                  DisplayArrow::BOTTOM |
                  DisplayArrow::TOP);
    char testSTR[] = "Nachrichten";
    char testSTR_2[] = "BME";
    char testSTR_3[] = "Zeit";
    label_arrow(DisplayArrow::TOP, testSTR);
    label_arrow(DisplayArrow::BOTTOM, testSTR);
    label_arrow(DisplayArrow::LEFT, testSTR_2);
    label_arrow(DisplayArrow::RIGHT, testSTR_3);
  } while (display.nextPage());
}

void setup_page_mid() {
  page_mid.update = update;
  page_mid.update_interval = 20000;
}

