#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{

}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
	Cure* cure = new Cure();
	return cure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<"'s wounds *" << std::endl;
}