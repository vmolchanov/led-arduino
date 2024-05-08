#pragma once

#include <Adafruit_NeoPixel.h>
#include <stdint.h>

typedef void (*Function)(void);

class LedController: public Adafruit_NeoPixel {
public:
  LedController(uint8_t pin, uint16_t count);

  void setColor(uint8_t r, uint8_t g, uint8_t b);
  void setColor(uint32_t c);
private:
  uint16_t _ledCount;
};
