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

  operator std::string() const; // cast operator
  bool operator ==(const Data &d) const;
  // NOTE: will be =inline= defined
  bool operator != (const Data &d) const { return !operator==(d); }

  friend std::ostream & operator << (std::ostream &os, const Data &d);
};
Data* operator"" _Data(const char *s, size_t); // NOTE: user defined literal