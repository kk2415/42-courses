#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "called WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name)
{
	std::cout << "called WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& WrongCat) : WrongAnimal(WrongCat.type)
{
	std::cout << "called WrongCat constructor" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Naw!! Naw!!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& ref)
{
	WrongAnimal::operator=(ref);
	return *this;
}
