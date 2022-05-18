#ifndef _ANIMAL_HPP
#define _ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string name);
	Animal(const Animal& animal);
	~Animal();

	std::string getType(void) const;
	virtual void makeSound(void) const;
	Animal& operator=(const Animal& ref);
};

#endif