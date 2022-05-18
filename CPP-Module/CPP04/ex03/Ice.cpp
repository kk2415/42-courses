#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{

}

Ice::~Ice()
{

}

AMateria* Ice::clone() const
{
	Ice* ice = new Ice();
	return ice;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}