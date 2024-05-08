#pragma once

#include <LiquidCrystal_I2C.h>
#include "lcd-view.h"

class ModeView : public LcdView {
public:
  ModeView(const LiquidCrystal_I2C *lcd);
  void showMode(char *mode);
};
