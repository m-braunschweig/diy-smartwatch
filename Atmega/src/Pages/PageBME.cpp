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
#include <Adafruit_BME280.h>
#include <Globals.h>
#include <WString.h>

Adafruit_BME280 bme;
int page = 0;
#define PAGE_BME_NUM_PAGES 3

// Note: BME inaccuracys can be solved with the according values in Globals.h

void page_bme_update() {
  display.firstPage();
  draw_center_str_prep(MEDIUM);
  do {
    bme.takeForcedMeasurement();
    String s;
    switch (page) {
      case 0:
        s = String(bme.readTemperature() * BME_TEMPERATURE_OFFSET_M -
                   BME_TEMPERATURE_OFFSET_B) +
            "\xb0"
            "C";
        break;
      case 1:
        s = String(bme.readHumidity()) + "%";
        break;
      case 2:
        s = String(bme.readPressure() / 100.0) + "hPa";
        break;
      default:
        draw_center_str_no_loop("Fehler!");
        break;
    }
    draw_center_str_no_loop(s.c_str(), -2);
    draw_triangle(DisplayArrow::LEFT | DisplayArrow::RIGHT |
                  DisplayArrow::BOTTOM);
  } while (display.nextPage());
}

bool page_bme_touch_false() {
  return false;
}

bool page_bme_touch_down() {
  return true;
}

bool page_bme_touch_left() {
  --page;
  if (page < 0)
    page = PAGE_BME_NUM_PAGES - 1;
  page_bme_update();
  return false;
}

bool page_bme_touch_right() {
  ++page;
  if (page >= PAGE_BME_NUM_PAGES)
    page = 0;
  page_bme_update();
  return false;
}

void setup_page_bme() {
  bme.begin();
  bme.setSampling(bme.MODE_FORCED, bme.SAMPLING_X16, bme.SAMPLING_X16,
                  bme.SAMPLING_X16, bme.FILTER_OFF, bme.STANDBY_MS_1000);
  page_bme->update = page_bme_update;
  page_bme->update_interval = 5000;
  page_bme->page_above = page_mid;
  page_bme->touch_down_left = page_bme_touch_down;
  page_bme->touch_down_right = page_bme_touch_down;
  page_bme->touch_up = page_bme_touch_false;
  page_bme->touch_left = page_bme_touch_left;
  page_bme->touch_right = page_bme_touch_right;
}
