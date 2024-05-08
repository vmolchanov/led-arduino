#pragma once

#include <LiquidCrystal_I2C.h>
#include "lcd-view.h"

class ColorView : public LcdView {
public:
  ColorView(const LiquidCrystal_I2C *lcd);
  void showColor(char *name);
};