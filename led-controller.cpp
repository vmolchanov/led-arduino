#include "led-controller.h"

LedController::LedController(uint8_t pin, uint16_t count)
  : Adafruit_NeoPixel(count, pin, NEO_GRB + NEO_KHZ800)
{
  _ledCount = count;
}

void LedController::setColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < _ledCount; i++) {
    setPixelColor(i, Color(r, g, b));
  }
  show();
}

void LedController::setColor(uint32_t c) {
  for (int i = 0; i < _ledCount; i++) {
    setPixelColor(i, c);
  }
  show();
}
