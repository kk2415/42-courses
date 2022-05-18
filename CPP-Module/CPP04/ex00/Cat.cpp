#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "called Cat constructor" << std::endl;
}

Cat::Cat(std::string name) : Animal(name)
{
	std::cout << "called Cat constructor" << std::endl;
}

Cat::Cat(const Cat& Cat) : Animal(Cat.type)
{
	std::cout << "called Cat constructor" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Naw!! Naw!!" << std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	Animal::operator=(ref);
	return *this;
}
