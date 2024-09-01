#include "brightness-model.h"

BrightnessModel::BrightnessModel() : AbstractModel() {
}

void BrightnessModel::setBrightness(uint8_t brightness) {
  if (brightness < MIN_BRIGHTNESS) {
    _brightness = MIN_BRIGHTNESS;
  } else if (brightness > MAX_BRIGHTNESS) {
    _brightness = MAX_BRIGHTNESS;
  } else {
    _brightness = brightness;
  }

  emit("change");
}

uint8_t BrightnessModel::getBrightness() {
  return _brightness;
}
