#include "abstract-model.h"

AbstractModel::AbstractModel() {
  _subscribers = new Vector<Event>();
}

int AbstractModel::_findEventIndex(char *eventName) {
  for (int i = 0; i < _subscribers->length(); i++) {
    if (_subscribers->at(i).name == eventName) {
      return i;
    }
  }

  return -1;
}

void AbstractModel::on(char *eventName, Function f) {
  int index = _findEventIndex(eventName);

  if (index != -1) {
    _subscribers->at(index).listeners->push(f);
  } else {
    Event event;
    event.name = eventName;
    event.listeners = new Vector<Function>();
    event.listeners->push(f);

    _subscribers->push(event);
  }
}

void AbstractModel::emit(char *eventName) {
  int index = _findEventIndex(eventName);

  if (index != -1) {
    for (int i = 0; i < _subscribers->at(index).listeners->length(); i++) {
      _subscribers->at(index).listeners->at(i)();
    }
  }
}