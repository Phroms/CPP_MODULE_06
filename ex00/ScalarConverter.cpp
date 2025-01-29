# include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
	(void)obj;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

// Los metodos son estaticos porque no necesitan ser instanciados en la clase para poder usarlos
static bool isChar(std::string const &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
			return true;
		return false;
}

static bool isInt(std::string const &str)
{
	try
	{
		std::stoi(str);
		return true;
	}
	catch (std::exception &e)
	{
		return false;
	}
}

static bool isFloat(std::string const &str)
{
	if (str.find('.') != std::string::npos && str.back() == 'f') // std::string::npos == static_cast<std::size_t>(-1)
			return true;
		return false;
}

static bool isDoble(std::string const &str)
{
	if (str.find('.') != std::string::npos && str.back() != 'f')
			return true;
		return false;
}

static bool isSpecialString(std::string const &str)
{
	if (str == "nan")
		return true;
	if (str == "nanf")
		return true;
	if (str == "+inf")
		return true;
	if (str == "+inff")
		return true;
	if (str == "-inf")
		return true;
	if (str == "-inff")
		return true;
	return false;
}

static void handleSpecialStrings(std::string const &str, float &floatValue, double &doubleValue)
{
	floatValue = std::strtof(str.c_str(), nullptr); // c_str() convierte una string(std::string) en un puntero "const char*" 
	doubleValue = std::strtod(str.c_str(), nullptr); // strtof y strtod convierten la cadena a floar o double
}

static void detectTypeAndConvert(std::string const &str, char &charValue, int &intValue, float &floatValue, double &doubleValue)
{
	if (isChar(str))
	{
		charValue = str[0];
		intValue = static_cast<int>(charValue);
		floatValue = static_cast<float>(charValue);
		doubleValue = static_cast<double>(charValue);
	}
	else if (isSpecialString(str))
	{
		handleSpecialStrings(str, floatValue, doubleValue);
	}
	if (isInt(str))
	{
		intValue = std::stoi(str);
		charValue = static_cast<char>(intValue);
		floatValue = static_cast<float>(intValue);
		doubleValue = static_cast<double>(intValue);
	}
	if (isFloat(str))
	{
		floatValue = std::stof(str);
		intValue = static_cast<int>(floatValue);
		charValue = static_cast<char>(floatValue);
		doubleValue = static_cast<float>(floatValue);
	}
	if (isDoble(str))
	{
		doubleValue = std::stod(str);
		intValue = static_cast<int>(doubleValue);
		charValue = static_cast<char>(doubleValue);
		floatValue = static_cast<float>(doubleValue);
	}
}

static void printMessage(std::string const &str, char &charValue, int &intValue, float &floatValue, double &doubleValue)
{

}
