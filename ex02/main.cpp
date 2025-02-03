# include "Base.hpp"

int main()
{
	std::srand(std::time(0)); // Inicializa la semilla aleatoria

	Base* obj = generate(); // Generamos un objeto aleatorio

	std::cout << "Identificacion con puntero: " << std::endl;
	identify(obj); // Identica usando un puntero

	std::cout << "Identificacion con referencia: " << std::endl;
	identify(*obj); // Identifica usando una referencia

	delete obj; // Liberamos la memoria

	return 0;
}
