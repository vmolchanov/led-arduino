#pragma once

#include <stdint.h>
#include "abstract-model.h"

#define MODES_COUNT 3

class ModeModel : public AbstractModel {
public:
  ModeModel();
  void setMode(char *mode);
  char* getMode();
  char* getNextMode();
  char* getPrevMode();

private:
  char *_mode;
  char **_modes;

  uint8_t _findModeIndex();
};
