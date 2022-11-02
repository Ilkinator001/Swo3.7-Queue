#include <iostream>

#include "Queue.h"

using std::cout;
using std::endl;

#define DEBUG(X) cout << (#X) << " = " << (X) << endl

void test_basics() {
  cout << "---- ---- ---- basics ---- ---- ----" << endl;
  Queue q1; // default arguments
  DEBUG(q1);
  q1.enqueue(new Data("Hello"));
  q1.enqueue("World"_Data);
  DEBUG(q1);
  while (not q1.is_empty()) {
    Data* d = q1.dequeue();
    DEBUG(*d);
    delete d;
  }
  DEBUG(q1);
}

void test_implicit_constructor_call() {
  Queue q(1);
  q.enqueue("data"_Data);
  DEBUG(q);
  DEBUG(q.is_full());
  delete q.dequeue();
}

Data *demo_data[] = {
  "zero"_Data, "one"_Data, "two"_Data
};

void test_dynamic_queue() {
  cout << "---- ---- ---- dynamic queue ---- ---- ----" << endl;

  Queue *q = new Queue(11);
  DEBUG(*q);

  for (Data *item: demo_data) {
    q->enqueue(item);
    DEBUG(*q);
  }

  while(not q->is_empty())
    DEBUG(*q->dequeue());

  delete q;
}

void cleanup() {
  for (const auto &item: demo_data) {
    delete item;
  }
}

int main() {
  test_basics();
  test_implicit_constructor_call();
  test_dynamic_queue();
  cleanup();
  return 0;
}