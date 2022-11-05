#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

#define DEBUG(x) cout << (#x) << " = " << (x) << endl;

static void test_basics() {
  cout << "---- ---- ---- basics ---- ---- ----" << endl;

  Queue q1;
  DEBUG(q1);
  q1.enqueue(new Data("Hello"));
  q1.enqueue("World"_Data);
  DEBUG(q1);
  while (!q1.is_empty()) {
    DEBUG(*q1.dequeue());
  }
  DEBUG(q1);

} // ~q1

int main() {
  test_basics();
  return 0;
}
