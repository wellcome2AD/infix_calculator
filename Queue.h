#pragma once
#include "LinkedList.h"

template <typename T>
class Queue {
 public:
  Queue();
  ~Queue();

  void push(T data);
  T pop();
  int size() const;
  T front() const;
  T back() const;
  bool empty() const;

 private:
  List<T> list;
};

template <typename T>
Queue<T>::Queue() = default;

template <typename T>
Queue<T>::~Queue() = default;

template <typename T>
int Queue<T>::size() const {
  return list.getSize();
}

template <typename T>
bool Queue<T>::empty() const {
  return list.getSize() == 0;
}

template <typename T>
void Queue<T>::push(T data) {
  list.push_back(data);
}

template <typename T>
T Queue<T>::pop() {
  if (list.getSize() > 0) {
    T data = list[0];
    list.pop_front();
    return data;
  } else {
    throw std::runtime_error("Queue is empty");
  }
}

template <typename T>
T Queue<T>::front() const {
  if (list.getSize() > 0) {
    return list[0];
  } else {
    throw std::runtime_error("Queue is empty");
  }
}

template <typename T>
T Queue<T>::back() const {
  if (list.getSize() > 0) {
    return list[list.getSize() - 1];
  } else {
    throw std::runtime_error("Queue is empty");
  }
}
