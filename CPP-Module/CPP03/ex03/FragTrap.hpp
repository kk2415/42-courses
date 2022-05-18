#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
public:
	FragTrap(std::string name);
	~FragTrap();
	void	highFivesGuys( void );
};

#endif
