# include "Serializer.hpp"

int main()
{
	s_data* ptr = new s_data;

	ptr->nbr = 42;

	uintptr_t raw = Serializer::serializer(ptr);
	std::cout << "\033[92m\nSerialized pointer: \033[0m" << raw << std::endl;

	s_data* newPtr = Serializer::deseralize(raw);
	std::cout << "\033[92mDeserialized pointer points to value: \033[0m" << newPtr->nbr << "\n" << std::endl;

	delete ptr;
	return 0;
}
