// file: Data.h
#pragma once
#include <string>
#include <ostream>

class Data {
private:
  std::string value;

public:
  Data(std::string value);
  virtual ~Data();

  friend std::ostream & operator << (std::ostream &os, const Data &d);
};
Data* operator"" _Data(const char *s, size_t); // NOTE: user defined literal