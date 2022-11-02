// file: Data.cpp
#include "Data.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

Data::Data(std::string value)
   : value(value) {
  cout << "Data(" << value << ") constructed" << endl;
}

Data::~Data() {
  cout << "~Data(" << value << ") destructed" << endl;
}

std::ostream & operator << (std::ostream &os, const Data &d) {
  return os << '"' << d.value << '"' << std::flush;
}

Data* operator"" _Data(const char *s, size_t) {
  return new Data(s);
}