#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{

}

AMateria::~AMateria()
{}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "this meteria affected " << target.getName() << std::endl;
}
