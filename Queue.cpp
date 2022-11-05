#include "Queue.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

Queue::Queue(int capacity) : capacity{capacity},data(new Data*[capacity])
{
  cout << "Queue(" << capacity << ") constructed" << endl;
}

Queue::~Queue()
{
  delete[] data; // because we used new[]
  cout << "~Queue(" << capacity << ") deconstructed" << endl;
}

Queue::Queue(const Queue& q) : start(q.start), count(q.count), capacity(q.capacity), data (new Data*[q.capacity])
{
  for (int i = 0; i < count; i++) {
    data[at(i)] = q.data[at(i)];
  }
  cout << "Queue(" << capacity << ") copied" << endl;
}

Queue& Queue::operator=(const Queue& q)
{
  // TODO: hier return-Anweisung eingeben
  cout << "Queue::operator(const Queue& q)" << endl;

  // check self assignment
  if (this == &q)
    return *this; // dereference pointer, because return value is reference

  if (capacity != q.capacity) {
    // store data temporarilly, to be safe in case of exeption
    Data** new_data = new Data * [q.capacity];
    capacity = q.capacity;

    delete[] data; // delete only after new data has been successfully allocated (exeption safety)
    data = new_data;
  }

  start = q.start;

  for (int i = 0; i < count; i++) {
    data[at(i)] = q.data[at(i)];
  }
  return *this;
}

bool Queue::is_empty() const
{
    return count == 0;
}

bool Queue::is_full() const
{
    return count >= capacity;
}

bool Queue::operator==(const Queue& q) const
{
  if (this == &q)
    return true;

  if (count != q.count)
    return false;

  if (capacity != q.capacity)
    return false;

  for (int i = 0; i < capacity; i++) {
    Data* d1 = data[at(i)];
    Data* d2 = q.data[at(i)];
    if (*d1 != *d2)
      return false;
  }

  return true;
}

void Queue::enqueue(Data* item)
{
  assert(!is_full());
  data[at(count)] = item;
  count++;
}

void Queue::enqueue(std::initializer_list<Data*> l)
{
  for (const auto d : l) {
    enqueue(d);
  }
}

Data* Queue::dequeue()
{
  assert(!is_empty());
  auto item = data[start];  // automatic type deduction
  start = at(1);
  count--;
  return item;
}

void Queue::delete_elements()
{
  while (!is_empty()) {
    delete data;
  }
}

std::ostream& operator<<(std::ostream& os, const Queue& q)
{
    // TODO: hier return-Anweisung eingeben
  os << '[';
  for (int i = 0; i < q.count; i++) {
    if (i > 0) os << ", ";
    os << *(q.data[q.at(i)]);
  }
  return os << ']' << std::flush;
}
