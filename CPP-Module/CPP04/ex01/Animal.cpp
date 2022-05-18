#include "Animal.hpp"

Animal::Animal() : type("animal")
{
	std::cout << "called Animal constructor" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
	std::cout << "called Animal constructor" << std::endl;
}

Animal::Animal(const Animal& animal) : type(animal.type)
{
	std::cout << "called Animal constructor" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound() const
{
	return ;
}

Animal& Animal::operator=(const Animal& ref)
{
	std::cout << "Animal operator" << std::endl;
	this->type = ref.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "called Animal destructor" << std::endl;
}
