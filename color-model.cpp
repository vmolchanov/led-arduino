#include "color-model.h"

ColorModel::ColorModel() : AbstractModel() {
  _colors = new Color[COLORS_COUNT] {
    Color("cold", 0xfcfcfc),
    Color("warm", 0xc4aa34),
    Color("neon", 0xff073a),
    Color("tomato", 0xff0000),
    Color("lemon", 0xffd700),
    Color("coral", 0xff7f50),
    Color("aqua", 0x00ffff),
    Color("orange", 0xffa500),
    Color("orchid", 0x9932cc),
    Color("fuchsia", 0xff00ff)
  };
}

void ColorModel::setColor(char *color) {
  _color = color;
  emit("change");
}

char* ColorModel::getColorName() {
  return _color;
}

uint8_t ColorModel::_findColorIndexByName(char *name) {
  for (uint8_t i = 0; i < COLORS_COUNT; i++) {
    if (_colors[i].name == name) {
      return i;
    }
  }

  return -1;
}

uint32_t ColorModel::getColorValue() {
  uint8_t index = _findColorIndexByName(_color);

  if (index == -1) {
    return -1;
  }

  return _colors[index].color;
}

char* ColorModel::getNextColor(char *sourceColor) {
  uint8_t index = _findColorIndexByName(sourceColor);

  return _colors[index == COLORS_COUNT - 1 ? 0 : (index + 1)].name;
}

char* ColorModel::getPrevColor(char *sourceColor) {
  uint8_t index = _findColorIndexByName(sourceColor);

  return _colors[index == 0 ? (COLORS_COUNT - 1) : (index - 1)].name;
}
