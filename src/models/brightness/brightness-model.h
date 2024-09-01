#pragma once

#include <stdint.h>
#include "../abstract/abstract-model.h"
#include "../../utils/vector.h"

#define MIN_BRIGHTNESS 32
#define MAX_BRIGHTNESS 255
#define BRIGHTNESS_STEP 16

class BrightnessModel : public AbstractModel {
public:
  BrightnessModel();

  void setBrightness(uint8_t brightness);
  uint8_t getBrightness();

private:
  uint8_t _brightness;

  void _onModelChange();
};
