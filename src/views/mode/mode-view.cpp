#include "mode-view.h"

ModeView::ModeView(const LiquidCrystal_I2C *lcd) : LcdView(lcd) {
}

void ModeView::showMode(char *mode) {
  lcd->clear();
  lcd->setCursor(3, 0);
  lcd->print("Mode");
  lcd->setCursor(3, 1);
  lcd->print(mode);
}