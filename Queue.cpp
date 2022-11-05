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

bool Queue::is_empty() const
{
    return count == 0;
}

bool Queue::is_full() const
{
    return count >= capacity;
}

void Queue::enqueue(Data* item)
{
  assert(!is_full());
  data[at(count)] = item;
  count++;
}

Data* Queue::dequeue()
{
  assert(!is_empty());
  auto item = data[start];  // automatic type deduction
  start = at(1);
  count--;
  return item;
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
