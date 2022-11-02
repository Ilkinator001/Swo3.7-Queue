// file: Queue.h
#pragma once
#include <ostream>
#include <initializer_list>
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
  Queue(const Queue &q);
  Queue & operator = (const Queue &q);

  bool operator == (const Queue &q) const;
  bool operator != (const Queue &q) const { return !operator==(q); }

  bool is_empty() const;
  bool is_full() const;

  void enqueue(Data *item);
  void enqueue(std::initializer_list<Data*> l);
  Data* dequeue();

  void delete_elements();

  // friends
  friend std::ostream & operator << (std::ostream &os, const Queue &q);
};