#pragma once

#include <ostream>
#include <initializer_list>
#include "Data.h"

class Queue
{
private:
  // { xxx } --> "vereinheitliche initialisierung" erst seit c++11
  int start{ 0 };
  int count{ 0 };
  int capacity;
  Data** data; // think *data[]; (dynamic)

  /*constexpr*/ int at(int i) const { return (start + i) % capacity; }

public:
  explicit Queue(int capacity = 10); // explicit verhindert Contructor call z.B. Queue q = 1;

  // rule of three ------
  virtual ~Queue();
  Queue(const Queue& q);  
  Queue& operator= (const Queue& q);  // Queue& wegen mehrfachzuweisung z.B. a = b = c --> a=c, b=c, c=c
  // rule of three ------

  bool is_empty() const;
  bool is_full() const;

  bool operator==(const Queue& q) const;
  bool operator!=(const Queue& q) const { return !operator==(q); };

  void enqueue(Data* item);
  void enqueue(std::initializer_list<Data*> l);
  Data* dequeue();

  void delete_elements();

  friend std::ostream& operator<<(std::ostream& os, const Queue& q);
};

