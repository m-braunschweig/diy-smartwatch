#include "Touch.h"
#include <Adafruit_MPR121.h>
#include <DisplayManager.h>
#include <Globals.h>

Adafruit_MPR121 mpr = Adafruit_MPR121();

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

DisplayManager* display_manager_;
uint64_t timeout = 0;

void set_display_manager(DisplayManager* d) {
  display_manager_ = d;
  mpr.begin(MPR_ADDRESS);
}

void update_touch() {
  if (millis() < timeout) {
    return;
  }
  uint16_t cur = mpr.touched();
  if (cur & _BV(TOUCH_UP)) {
    display_manager_->touch_up();
  } else if (cur & _BV(TOUCH_LEFT)) {
    display_manager_->touch_left();
  } else if (cur & _BV(TOUCH_RIGHT)) {
    display_manager_->touch_right();
  } else if (cur & _BV(TOUCH_DOWN_LEFT)) {
    display_manager_->touch_down_left();
  } else if (cur & _BV(TOUCH_DOWN_RIGHT)) {
    display_manager_->touch_down_right();
  }
  if (cur) {
    timeout = millis() + TOUCH_TIMEOUT;
  }
}
