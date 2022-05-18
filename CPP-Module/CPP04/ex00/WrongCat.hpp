#ifndef _WrongCat_H
#define _WrongCat_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(std::string name);
	WrongCat(const WrongCat& WrongCat);
	~WrongCat();

	void makeSound(void) const;
	WrongCat& operator=(const WrongCat& ref);
};

#endif