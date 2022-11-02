// file: Queue.cpp
#include "Queue.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

// NOTE: =new= throws exception when out of memory
Queue::Queue(int capacity)
  : capacity(capacity), data(new Data*[capacity]) {
  cout << "Queue(" << capacity << ") constructed" << endl;
}

Queue::~Queue() {
  delete[] data; // works on nullptr
  // data = nullptr // not necessary
  cout << "~Queue(" << capacity << ") destructed" << endl;
}

Queue::Queue(const Queue &q)
    : start(q.start),
      count(q.count),
      capacity(q.capacity),
      data(new Data*[capacity]) {
  for (int i = 0; i<count; i++) {
    data[at(i)] = q.data[q.at(i)];
  }
  cout << "Queue(" << capacity << ") copied" << endl;
}

Queue & Queue::operator = (const Queue &q) {
  cout << "Queue::operator=(const Queue &q)" << endl;

  // check self assignment
  if (this == &q) {
    return *this;
  }

  if (capacity != q.capacity) {
    Data **new_data = new Data*[q.capacity];
    capacity = q.capacity;
    delete[] data;
    data = new_data;
  }

  start = q.start;
  count = q.count;

  for(int i = 0; i<count; i++) {
    data[at(i)] = q.data[q.at(i)];
  }

  return *this;
}

bool Queue::operator == (const Queue &q) const {
  if (this == &q)
    return true;

  if (count != q.count)
    return false;

  if (capacity != q.capacity)
    return false;

  for (int i = 0; i<count; i++) {
    Data *d1 = data[at(i)];
    Data *d2 = q.data[q.at(i)];
    if (*d1 != *d2)
      return false;
  }
  return true;
}

bool Queue::is_empty() const {
  return count == 0;
}

bool Queue::is_full() const {
  return count >= capacity;
}

void Queue::enqueue(Data *item) {
  assert(not is_full());
  data[at(count)] = item; // take ownership?
  ++count;
}

void Queue::enqueue(std::initializer_list<Data*> l) {
  for (const auto& d : l) {
    enqueue(d);
  }
}

Data * Queue::dequeue() {
  assert(not is_empty());
  Data *item = data[start];
  start = at(1);
  --count;
  return item;
}

void Queue::delete_elements() {
  while (!is_empty()) {
    delete dequeue();
  }
}

std::ostream & operator << (std::ostream &os, const Queue &q) {
  os << '[';
  for (int i = 0; i < q.count; i++) {
    if (i > 0) os << ", ";
    os << *(q.data[q.at(i)]);
  }
  return os << ']' << std::flush;
}