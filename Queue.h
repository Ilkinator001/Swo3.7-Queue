// file: Queue.h
#pragma once
#include <ostream>
#include "Data.h"

class Queue {
private:
  int start {0};
  int count {0};
  int capacity;
  Data **data; // think *data[]; (dynamic)
  // helper for calculating indexes
  constexpr int at(int i) const { return (start+i) % capacity; }

public:
  explicit Queue(int capacity = 10);
  virtual ~Queue();

  bool is_empty() const;
  bool is_full() const;

  void enqueue(Data *item);
  Data* dequeue();

  // friends
  friend std::ostream & operator << (std::ostream &os, const Queue &q);
};