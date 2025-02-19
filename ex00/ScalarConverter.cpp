#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
	(void)obj;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

// Convierte un numero double a un carácter imprimible
static void	toChar(double value, std::string &str)
{
	char c = static_cast<char>(value);

	if (std::isprint(c))
		str = "'" + std::string(1, c) + "'"; //Formatea como un caracter entre comillas
	else
		str = "Non displayable";
}

// Convierte un numero double a un entero en string
static void	toInt(double value, std::string &str)
{
	std::ostringstream oss;
	oss << static_cast<int>(value);
	str = oss.str();
}

// Convierte un numero double a un float con un decimal seguido de 'f'
static void	toFloat(double value, std::string &str)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
	str = oss.str();
}

// Convierte un numero double a una representacion en string con un decimal
void	toDouble(double value, std::string &str)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << value;
	str = oss.str();
}

void ScalarConverter::convert(const std::string &str)
{
	std::string char_str("impossible");
	std::string int_str("impossible");
	std::string float_str("impossible");
	std::string double_str("impossible");
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		float_str = str;
		double_str = str.substr(0, str.length() - 1);
	}
	else if (str == "-inf" || str == "+inf" || str == "nan")
	{
		float_str = str + "f";
		double_str = str;
	}
	else
	{
		char *end;
		double value(std::strtod(str.c_str(), &end));
		if (*end == 'f' && *(end + 1) == '\0')
			value = static_cast<float>(value);
		else if (*end != '\0')
		{
			if (str.length() == 1)
				value = static_cast<double>(str[0]);
			else
				value = std::numeric_limits<double>::infinity();
		}
		if (std::isinf(value) == 0)
		{
			toChar(value, char_str);
			toInt(value, int_str);
			toFloat(value, float_str);
			toDouble(value, double_str);
		}
	}
	std::cout << "char: " << char_str << "\n";
	std::cout << "int: " << int_str << "\n";
	std::cout << "float: " << float_str << "\n";
	std::cout << "double: " << double_str << "\n";
}
