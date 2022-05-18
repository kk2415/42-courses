#ifndef _ANIMAL_HPP
#define _ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string name);
	Animal(const Animal& animal);
	virtual ~Animal();

	std::string getType(void) const;
	virtual Brain* getBrain(void) const = 0;
	virtual void makeSound(void) const;
	virtual Animal& operator=(const Animal& ref);
};

#endif
