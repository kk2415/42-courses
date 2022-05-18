#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	void	whoAmI( void );
	void	attack(std::string const & target);
private:
	std::string	name;
};

#endif
