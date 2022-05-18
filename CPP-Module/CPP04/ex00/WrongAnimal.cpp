#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
	std::cout << "called WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type(name) 
{
	std::cout << "called WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal) : type(WrongAnimal.type)
{
	std::cout << "called WrongAnimal constructor" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	this->type = ref.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "called WrongAnimal destructor" << std::endl;
}