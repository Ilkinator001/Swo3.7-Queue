#pragma once

#include <string>
#include <ostream>

class Data
{
private:
  std::string value;

public:
  Data(const std::string& value);
  virtual ~Data();

  operator std::string() const;
  bool operator==(const Data& d) const { return value == d.value; };
  bool operator!=(const Data& d) const { return !operator==(d); };

  // friend definiert Methode von auﬂerhalb der Klasse
  friend std::ostream& operator<<(std::ostream& os, const Data& d);
};

//_Data --> User defined Literal
Data* operator"" _Data(const char *s, size_t);

