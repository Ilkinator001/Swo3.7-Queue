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

Data::operator std::string() const {
  cout << "Data::operator string()" << endl;
  return value;
}

bool Data::operator==(const Data &d) const {
  return value == d.value; // delegate to std::string::operator==
}

std::ostream & operator << (std::ostream &os, const Data &d) {
  return os << '"' << d.value << '"' << std::flush;
}

Data* operator"" _Data(const char *s, size_t) {
  return new Data(s);
}