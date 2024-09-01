#pragma once

#include <stdint.h>
#include "../abstract/abstract-model.h"

#define COLORS_COUNT 10

struct Color {
  char *name;
  uint32_t color;
  Color(char *name, uint32_t color): name(name), color(color) {}
};

class ColorModel : public AbstractModel {
public:
  ColorModel();
  void setColor(char *color);
  char* getColorName();
  uint32_t getColorValue();
  char* getNextColor(char *sourceColor);
  char* getPrevColor(char *sourceColor);

private:
  char *_color;
  Color *_colors;

  uint8_t _findColorIndexByName(char *name);
};
