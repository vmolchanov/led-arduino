#include "led-controller.h"

LedController::LedController(uint8_t pin, uint16_t count)
  : Adafruit_NeoPixel(count, pin, NEO_GRB + NEO_KHZ800)
{
  _ledCount = count;
  _mode = "light";
  _lastTime = 0;
}

void LedController::tick(uint32_t time) {
  if (_mode == "light") {
    _lightTick();
  }

  if (_mode == "flicker") {
    _flickerTick(time);
  }

  if (_mode == "carousel") {
    _carouselTick(time);
  }
}

void LedController::_lightTick() {
  for (int i = 0; i < _ledCount; i++) {
    setPixelColor(i, _color);
  }
  show();
}

void LedController::_flickerTick(uint32_t time) {
  static bool isEven = true;

  if (time - _lastTime > FLICKER_TIME) {
    for (int i = 0; i < _ledCount; i++) {
      if ((isEven && i % 2 == 0) || (!isEven && i % 2 == 1)) {
        setPixelColor(i, _color);
      } else {
        setPixelColor(i, TURN_OFF_COLOR);
      }
    }
    show();

    _lastTime = time;

    isEven = !isEven;
  }
}

void LedController::_carouselTick(uint32_t time) {
  static int startIndex = 0;

  if (time - _lastTime > CAROUSEL_TIME) {
    for (int i = 0; i < _ledCount; i++) {
      bool isIndexInWindow = (i >= startIndex && i < startIndex + CAROUSEL_LED_COUNT);
      bool isWindowGreatThanLedLength = (startIndex + CAROUSEL_LED_COUNT >= _ledCount);
      bool isIndexInEndOfWindow = (i < startIndex + CAROUSEL_LED_COUNT - _ledCount);

      uint32_t color = isIndexInWindow || (isWindowGreatThanLedLength && isIndexInEndOfWindow)
        ? _color
        : TURN_OFF_COLOR;

      setPixelColor(i, color);
    }
    show();

    _lastTime = time;

    startIndex = startIndex < _ledCount - 1
      ? startIndex + 1
      : 0;
  }
}

void LedController::setColor(uint8_t r, uint8_t g, uint8_t b) {
  _color = Color(r, g, b);
}

void LedController::setColor(uint32_t c) {
  _color = c;
}

void LedController::setMode(char *mode) {
  _mode = mode;
}
