#pragma once

#include <Adafruit_NeoPixel.h>
#include <stdint.h>

const uint16_t FLICKER_TIME = 500;

const uint16_t CAROUSEL_TIME = 15;

const uint8_t CAROUSEL_LED_COUNT = 20;

const uint32_t TURN_OFF_COLOR = 0x000000;

class LedController: public Adafruit_NeoPixel {
public:
  LedController(uint8_t pin, uint16_t count);

  void tick(uint32_t time);

  void setColor(uint8_t r, uint8_t g, uint8_t b);
  void setColor(uint32_t c);

  void setMode(char *mode);
private:
  uint16_t _ledCount;
  uint32_t _color;
  char *_mode;
  uint32_t _lastTime;

  void _lightTick();
  void _flickerTick(uint32_t time);
  void _carouselTick(uint32_t time);
};
