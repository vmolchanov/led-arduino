#pragma once

#include <LiquidCrystal_I2C.h>
#include <stdint.h>

#include "../lcd/lcd-view.h"

class BrightnessView: public LcdView {
public:
  BrightnessView(const LiquidCrystal_I2C *lcd);
  void showBrightnessLevel(uint8_t value);
};