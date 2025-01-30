# include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(Serializer const &obj)
{
	(void)obj;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return *this;
}

// Convierte el puntero 'ptr' a la dirección donde apunta, pero la convierte en un numero entero (uintptr_t)
uintptr_t Serializer::serializer(s_data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

// Toma un numero entero 'raw' que representa una dirección de memoria y la convierte de vuelta a un puntero a un objeto de tipo Data(recupera el puntero original)
s_data* Serializer::deseralize(uintptr_t raw)
{
	return reinterpret_cast<s_data*>(raw);
}

// reinterpret_cast es una conversion de tipo que te permite hacer conversiones entre tipos que no seria compatibles normalmente
// EJEMPLO:
//			int num = 42;
//			void* ptr = &num; // Puntero void, que puede apuntar a cualquier tipo de datos
//			char* charPtr = reinterpret_cast<char*>(ptr); // Convertimos un puntero a int a un puntero a char

// OJO:
// 		Si bien es poderoso, es necesario tener precaucion al usarlo ya que no hace ninguna verificacion de seguridad
// 		y no ganarantiza que la conversion sea valida.
