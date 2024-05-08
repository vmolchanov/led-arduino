#include "lcd-view.h"

LcdView::LcdView(const LiquidCrystal_I2C *lcd) {
  this->lcd = lcd;
}