#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon
{

public:
	std::string getType( void );
	void		setType( std::string );

	Weapon( void );
	Weapon( std::string type );

private:
	std::string	type;

};

#endif
