#include "Data.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

Data::Data(const std::string& value) : value(value)
{
  cout << "Data(" << value << ") constructed" << endl;
}

Data::~Data()
{
  cout << "~Data(" << value << ") deconstructed" << endl;
}

// conversion operator to std::string
Data::operator std::string() const
{
  cout << "Data:: operator string()" << endl;
  return value;
}

Data* operator""_Data(const char* s, size_t)
{
  return new Data(s);
}

std::ostream& operator<<(std::ostream& os, const Data& d)
{
  // TODO: hier return-Anweisung eingeben
  return os << '"' << d.value << '"' << std::flush;
}
