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

int main() {
  test_basics();
  return 0;
}