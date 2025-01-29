# pragma once
# include <iostream>
# include <exception>
# include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
		ScalarConverter &operator=(ScalarConverter const &rhs);
		~ScalarConverter();
	public:
		void convert(std::string const &input);
};
