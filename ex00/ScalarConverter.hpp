# pragma once
# include <iostream>
# include <string>
# include <cerrno>
# include <cstdlib>
# include <iomanip>

# define RED \033[91m 

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
