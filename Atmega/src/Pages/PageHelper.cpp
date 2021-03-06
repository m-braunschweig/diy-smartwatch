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

U8G2_SSD1306_128X64_NONAME_F_HW_I2C display =
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C(U8G2_R0);

namespace DisplayArrow {
  uint8_t LEFT = (1 << 0);
  uint8_t RIGHT = (1 << 1);
  uint8_t TOP = (1 << 2);
  uint8_t BOTTOM = (1 << 3);
}

/*
 * Draw a c-string in the center of the screen.
 * It has an internal u8g2 loop.
 */
void draw_center_str(const char* str, const Fontsize& size) {
  draw_center_str(str, size, 0);
}

void draw_center_str(const char* str, const Fontsize& size,
                     const int& offset_y) {
  const uint8_t* font;
  switch (size) {
    case TINY:
      font = FONT_TINY;
      break;
    case SMALL:
      font = FONT_SMALL;
      break;
    case MEDIUM:
      font = FONT_MEDIUM;
      break;
    case LARGE:
      font = FONT_LARGE;
      break;
    default:
      font = FONT_TINY;
      break;
  }
  display.setFont(font);

  int str_width = display.getStrWidth(str);

  display.firstPage();
  display.setFontPosCenter();
  do {
    display.drawStr(DISPLAY_MID_H - str_width / 2, DISPLAY_MID_V + offset_y,
                    str);
  } while (display.nextPage());
}

/*
 * Prepares draw_center_str_no_loop
 */
void draw_center_str_prep(const Fontsize size) {
  const uint8_t* font;
  switch (size) {
    case TINY:
      font = FONT_TINY;
      break;
    case SMALL:
      font = FONT_SMALL;
      break;
    case MEDIUM:
      font = FONT_MEDIUM;
      break;
    case LARGE:
      font = FONT_LARGE;
      break;
    case HUGE:
      font = FONT_HUGE;
      break;
    default:
      font = FONT_TINY;
      break;
  }
  display.setFont(font);
  display.setFontPosCenter();
}
/*
 * Draw a c-string in the center of the screen.
 * It has no internal u8g2 loop.
 */
void draw_center_str_no_loop(const char* str) {
  draw_center_str_no_loop(str, 0);
}

void draw_center_str_no_loop(const char* str, const int& offset_y) {
  int str_width = display.getStrWidth(str);
  display.drawStr(DISPLAY_MID_H - str_width / 2, DISPLAY_MID_V + offset_y, str);
}

/*
 * Show triangles by using bitmasks (DisplayArrow::*).
 * This requires an external u8g2 loop!
 */
void draw_triangle(uint8_t directions) {
  if (DisplayArrow::LEFT & directions) {
    display.drawTriangle(
        TRIANGLE_SPACE, DISPLAY_MID_V, TRIANGLE_SPACE + TRIANGLE_WIDTH,
        DISPLAY_MID_V + TRIANGLE_HEIGTH, TRIANGLE_SPACE + TRIANGLE_WIDTH,
        DISPLAY_MID_V - TRIANGLE_HEIGTH);
  }
  if (DisplayArrow::RIGHT & directions) {
    display.drawTriangle(DISPLAY_WIDTH - TRIANGLE_SPACE, DISPLAY_MID_V,
                         DISPLAY_WIDTH - TRIANGLE_SPACE - TRIANGLE_WIDTH,
                         DISPLAY_MID_V + TRIANGLE_HEIGTH,
                         DISPLAY_WIDTH - TRIANGLE_SPACE - TRIANGLE_WIDTH,
                         DISPLAY_MID_V - TRIANGLE_HEIGTH);
  }
  if (DisplayArrow::BOTTOM & directions) {
    display.drawTriangle(DISPLAY_MID_H, DISPLAY_HEIGHT - TRIANGLE_SPACE,
                         DISPLAY_MID_H + TRIANGLE_HEIGTH,
                         DISPLAY_HEIGHT - TRIANGLE_SPACE - TRIANGLE_WIDTH,
                         DISPLAY_MID_H - TRIANGLE_HEIGTH,
                         DISPLAY_HEIGHT - TRIANGLE_SPACE - TRIANGLE_WIDTH);
  }
  if (DisplayArrow::TOP & directions) {
    display.drawTriangle(
        DISPLAY_MID_H, TRIANGLE_SPACE, DISPLAY_MID_H + TRIANGLE_HEIGTH,
        TRIANGLE_SPACE + TRIANGLE_WIDTH, DISPLAY_MID_H - TRIANGLE_HEIGTH,
        TRIANGLE_SPACE + TRIANGLE_WIDTH);
  }
}

void label_arrow(uint8_t direction, char* str) {
  display.setFontPosCenter();
  display.setFont(FONT_SMALL);
  int str_width = display.getStrWidth(str);
  if (DisplayArrow::TOP & direction) {
    display.drawStr(DISPLAY_MID_H - str_width / 2,
                    TRIANGLE_HEIGTH + 2 * TRIANGLE_SPACE, str);
  }
  if (DisplayArrow::BOTTOM & direction) {
    display.drawStr(DISPLAY_MID_H - str_width / 2,
                    DISPLAY_HEIGHT - (TRIANGLE_HEIGTH + 2 * TRIANGLE_SPACE),
                    str);
  }
  if (DisplayArrow::LEFT & direction) {
    display.drawStr(TRIANGLE_WIDTH + 2 * TRIANGLE_SPACE + 2, DISPLAY_MID_V,
                    str);
  }
  if (DisplayArrow::RIGHT & direction) {
    display.drawStr(DISPLAY_WIDTH -
                        (TRIANGLE_WIDTH + 2 * TRIANGLE_SPACE + 2 + str_width),
                    DISPLAY_MID_V, str);
  }
}
