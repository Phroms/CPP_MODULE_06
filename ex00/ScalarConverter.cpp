# include "ScalarConverter.hpp"


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
	char *end;

	std::strtol(str.c_str(), &end, 10); // Convierte a base 10
		
	return (*end == '\0'); // Retorna true si toda la cadena fue convertida
}

static bool isFloat(std::string const &str)
{
	if (str.find('.') != std::string::npos && str[str.length() - 1] == 'f') // std::string::npos == static_cast<std::size_t>(-1)
			return true;
		return false;
}

static bool isDoble(std::string const &str)
{
	if (str.find('.') != std::string::npos && str[str.length() - 1] != 'f')
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
	floatValue = std::strtof(str.c_str(), NULL); // c_str() convierte una string(std::string) en un puntero "const char*" 
	doubleValue = std::strtod(str.c_str(), NULL); // strtof y strtod convierten la cadena a floar o double
}

static void detectTypeAndConvert(std::string const &str, char &charValue, int &intValue, float &floatValue, double &doubleValue)
{
	char *endPointer;

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
	else if (isInt(str))
	{
		errno = 0; // Variable global que almacena codigo de Error
		intValue = std::strtol(str.c_str(), &endPointer, 10); // Base 10 para enteros
		if (errno == ERANGE) // ERRANGE indica desbordamiento o subdesbordamiento en conversiones numericas 
		{
			std::cerr << "Error: Integer out of range" << std::endl;
		}
		charValue = static_cast<char>(intValue);
		floatValue = static_cast<float>(intValue);
		doubleValue = static_cast<double>(intValue);
	}
	else if (isFloat(str))
	{
		errno = 0;
		floatValue = std::strtof(str.c_str(), &endPointer);
		if (errno == ERANGE)
		{
			std::cerr << "Error: Float out of range" << std::endl;
		}
		intValue = static_cast<int>(floatValue);
		charValue = static_cast<char>(floatValue);
		doubleValue = static_cast<float>(floatValue);
	}
	else if (isDoble(str))
	{
		errno = 0;
		doubleValue = std::strtod(str.c_str(), &endPointer);
		if (errno == ERANGE)
		{
			std::cerr << "Error: Double out of range" << std::endl;
		}
		intValue = static_cast<int>(doubleValue);
		charValue = static_cast<char>(doubleValue);
		floatValue = static_cast<float>(doubleValue);
	}
}

static void printMessage(std::string const &str, char &charValue, int &intValue, float &floatValue, double &doubleValue)
{
	std::cout << std::fixed << std::setprecision(1);

	if (isprint(charValue))
		std::cout << "char: '" << charValue << "'" << std::endl;
	if (isChar(str))
		std::cout << "char: '" << str[0] << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (isSpecialString(str))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intValue << std::endl;

	std::cout << "float: " << floatValue << "f" << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
}

void ScalarConverter::convert(const std::string &input)
{
	char	charValue = 0;
	int		intValue = 0;
	float	floatValue = 0;
	double	doubleValue = 0;

	try
	{
		detectTypeAndConvert(input, charValue, intValue, floatValue, doubleValue);
	}
	catch(std::exception &e)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return ;
	}

	printMessage(input, charValue, intValue, floatValue, doubleValue);
}
