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

Data * Queue::dequeue() {
  assert(not is_empty());
  Data *item = data[start];
  start = at(1);
  --count;
  return item;
}

std::ostream & operator << (std::ostream &os, const Queue &q) {
  os << '[';
  for (int i = 0; i < q.count; i++) {
    if (i > 0) os << ", ";
    os << *(q.data[q.at(i)]);
  }
  return os << ']' << std::flush;
}