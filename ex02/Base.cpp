# include "Base.hpp"
#include <typeinfo>

Base::~Base()
{
	std::cout << "Base Constructor called" << std::endl;
}

Base* generate(void)
{
	int random = std::rand() % 3; // Genera un numero entre 0 y 2

	// Crea dinamicamente un objeto de A, B o C, y lo devuelve como Base*
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
}

// 'p' es un puntero de tipo 'Base'
// y 'A' tambien es puntero de tipo 'Base' porque se hereda de Base
// dynamic_cast<A*> intenta convertir 'p' a un puntero de tipo 'A'
// Si el casteo es exitoso, ambos apuntan a la misma direccion de memoria
// Si es exitoso, devuelve el puntero (A*) o nullptr NULL si no lo es
// Si el casteo es exitoso, 'A' puede acceder a los mienbros de 'A' y de 'Base'
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast&){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast&){}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast&){}
}
