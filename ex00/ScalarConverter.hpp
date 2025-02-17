#pragma once
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#define RED \033[91m

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &obj);
	ScalarConverter &operator=(ScalarConverter const &rhs);
	~ScalarConverter();

  public:
	static void convert(std::string const &input);
};
