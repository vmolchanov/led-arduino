#pragma once

template<typename T>
class Vector {
public:
  Vector() {
    _length = 0;
    _capacity = 5;
    _arr = new T[_capacity];
  }

  ~Vector() {
    delete[] _arr;
  }

  void push(T value) {
    if (_length == _capacity) {
      _capacity *= 2;

      T *cache = new T[_length];

      for (int i = 0; i < _length; i++) {
        cache[i] = _arr[i];
      }

      delete[] _arr;
      _arr = new T[_capacity];

      for (int i = 0; i < _length; i++) {
        _arr[i] = cache[i];
      }

      delete[] cache;
    }

    _arr[_length++] = value;
  }

  T pop() {
    return _arr[_length--];
  }

  T at(int index) {
    return _arr[index];
  }

  int length() {
    return _length;
  }

  bool isEmpty() {
    return _length == 0;
  }

private:
  int _length;
  int _capacity;
  T *_arr;
};