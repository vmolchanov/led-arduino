#pragma once

#include "../../utils/vector.h"

typedef void (*Function)(void);

struct Event {
  char *name;
  Vector<Function> *listeners;
};

class AbstractModel {
public:
  AbstractModel();
  void on(char *eventName, Function f);
  void emit(char *eventName);
protected:
  char *_value;
private:
  Vector<Event> *_subscribers;

  int _findEventIndex(char *eventName);
};