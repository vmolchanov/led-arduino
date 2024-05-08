#include "mode-model.h"

ModeModel::ModeModel() : AbstractModel() {
  _modes = new char*[MODES_COUNT] {
    "light",
    "flicker",
    "carousel"
  };
}

void ModeModel::setMode(char *mode) {
  _mode = mode;
  emit("change");
}

char* ModeModel::getMode() {
  return _mode;
}

uint8_t ModeModel::_findModeIndex() {
  for (uint8_t i = 0; i < MODES_COUNT; i++) {
    if (_modes[i] == _mode) {
      return i;
    }
  }

  return -1;
}

char* ModeModel::getNextMode() {
  uint8_t index = _findModeIndex();

  if (index == MODES_COUNT - 1) {
    return _modes[0];
  }
  return _modes[index + 1];
}

char* ModeModel::getPrevMode() {
  uint8_t index = _findModeIndex();

  if (index == 0) {
    return _modes[MODES_COUNT - 1];
  }
  return _modes[index - 1];
}
