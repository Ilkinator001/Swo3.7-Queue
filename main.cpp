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
    //DEBUG(*q1.dequeue());
    Data* d = q1.dequeue();
    DEBUG(*d);
    delete d;
  }
  DEBUG(q1);

} // ~q1



static void test_implicit_constructor_call() {
  cout << "---- ---- ---- test_implicit_constructor_call ---- ---- ----" << endl;

  Queue q(1); // Queue q{1};
  q.enqueue("data"_Data);
  DEBUG(q);
  DEBUG(q.is_full());
  delete q.dequeue();
}

Data* demo_data[] = {
  "zero"_Data, "one"_Data, "two"_Data
};

static void test_dynamic_queue() {
  cout << "---- ---- ---- test_dynamic_queue ---- ---- ----" << endl;

  Queue *q = new Queue(11); // Queue q{1};
  DEBUG(*q);

  for (Data* item : demo_data) {
    q->enqueue(item);
    DEBUG(*q);
  }

  while (!q->is_empty()) {
    DEBUG(*q->dequeue());
  }

  delete q;
}

static void cleanup() {
  for (auto item : demo_data) {
    delete item;
  }
}

static void test_copying() {
  cout << "---- ---- ---- test_copying ---- ---- ----" << endl;

  Queue q1;
  q1.enqueue(demo_data[0]);
  Queue q2 = q1;

  DEBUG(q1);
  DEBUG(q2); // seems to work fine

  cout << "enqueue to q1" << endl;
  q1.enqueue(demo_data[1]);
  DEBUG(q1);
  DEBUG(q2); // seems to work fine

  cout << "enqueue to q2" << endl;
  q2.enqueue(demo_data[2]);
  DEBUG(q1);
  DEBUG(q2);  // NOTE:
}


static void test_assignment() {
  cout << "---- ---- ---- test_assignment ---- ---- ----" << endl;

  Queue q1;
  Queue q2;
  q1.enqueue(demo_data[0]);
  q2.enqueue(demo_data[1]);
  q2 = q1;

  DEBUG(q1);
  DEBUG(q2); // seems to work fine

  cout << "enqueue to q1" << endl;
  q1.enqueue(demo_data[1]);
  DEBUG(q1);
  DEBUG(q2); // seems to work fine

  cout << "enqueue to q2" << endl;
  q2.enqueue(demo_data[2]);
  DEBUG(q1);
  DEBUG(q2);  // NOTE:
}


int main() {
  test_basics();
  test_implicit_constructor_call();
  test_dynamic_queue();
  test_copying();
  test_assignment();

  cleanup();
  return 0;
}
