#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "called Dog constructor" << std::endl;
}

Dog::Dog(std::string name) : Animal(name)
{
	std::cout << "called Dog constructor" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog.type)
{
	std::cout << "called Dog constructor" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Wal!! Wal!!" << std::endl;
}

Dog& Dog::operator=(const Dog& ref)
{
	Animal::operator=(ref);
	return *this;
}
