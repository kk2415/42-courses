#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
public:
	ScavTrap(std::string name);
	~ScavTrap();
	void	attack(std::string const & target);
	void	guardGate( void );

};

#endif
