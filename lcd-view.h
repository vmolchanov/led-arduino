#pragma once

#include <LiquidCrystal_I2C.h>

class LcdView {
public:
  LcdView(const LiquidCrystal_I2C *lcd);
protected:
  LiquidCrystal_I2C *lcd;
};