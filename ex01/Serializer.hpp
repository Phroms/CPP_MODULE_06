# pragma once
# include <iostream>
# include <string>

typedef struct s_data // Se usa la struct ya que es mas simple y adecuado para almacenar datos sin la necesidad de encapsulacion o funcionalidad opcional 
{
	int nbr; // Almacena un entero.
} data_t;

typedef unsigned long uintptr_t; // uintptr_t es un alias que define mediante typedef para no escribir unsigned long.

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer const &obj);
		Serializer &operator=(Serializer const &rhs);
	public:
		static uintptr_t serializer(s_data* ptr);
		static s_data* deseralize(uintptr_t raw);
};
