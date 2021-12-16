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

#ifndef PAGE_HELPER_H
#define PAGE_HELPER_H

#include <DisplayPage.h>
#include <U8g2lib.h>

enum Fontsize { TINY, SMALL, MEDIUM, LARGE, HUGE };

#define FONT_TINY u8g2_font_profont11_tr
#define FONT_SMALL u8g2_font_profont15_tf
#define FONT_MEDIUM u8g2_font_profont17_tf
#define FONT_LARGE u8g2_font_profont22_tr
#define FONT_HUGE u8g2_font_profont29_tr
#define FONT_MESSAGE FONT_TINY

#define DISPLAY_WIDTH 128
#define DISPLAY_MID_H DISPLAY_WIDTH / 2
#define DISPLAY_HEIGHT 64
#define DISPLAY_MID_V DISPLAY_HEIGHT / 2

// This assumes a triangle with the longest side beeing vertical
#define TRIANGLE_SPACE 2
#define TRIANGLE_HEIGTH 14
#define TRIANGLE_WIDTH 5

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C display;

namespace DisplayArrow {
  extern uint8_t LEFT;
  extern uint8_t RIGHT;
  extern uint8_t TOP;
  extern uint8_t BOTTOM;
}

void draw_triangle(uint8_t);
void draw_center_str(const char*, const Fontsize&);
void draw_center_str(const char*, const Fontsize&, const int&);
void draw_center_str_no_loop(const char*);
void draw_center_str_no_loop(const char*, const int&);
void draw_center_str_prep(Fontsize);
void label_arrow(uint8_t, char*);

extern DisplayPage* page_mid;
extern DisplayPage* page_time;
extern DisplayPage* page_bme;

void setup_page_mid();
void setup_page_time();
void setup_page_bme();

inline void setup_pages() {
  setup_page_mid();
  setup_page_time();
  setup_page_bme();
}

#endif
