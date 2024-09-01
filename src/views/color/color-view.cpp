#include "../color/color-view.h"

ColorView::ColorView(const LiquidCrystal_I2C *lcd) : LcdView(lcd) {
}

void ColorView::showColor(char *name) {
  lcd->clear();
  lcd->setCursor(3, 0);
  lcd->print("Color");
  lcd->setCursor(3, 1);
  lcd->print(name);
}