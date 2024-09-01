#include <LiquidCrystal_I2C.h>

#include "brightness-view.h"

BrightnessView::BrightnessView(const LiquidCrystal_I2C *lcd)
  : LcdView(lcd)
{
}

void BrightnessView::showBrightnessLevel(uint8_t value) {
  lcd->clear();
  lcd->setCursor(3, 0);
  lcd->print("Brightness");
  for (uint8_t i = 0; i < (value - 16) / 16; i++) {
    lcd->setCursor(1 + i, 1);
    lcd->write(255);
  }
}
