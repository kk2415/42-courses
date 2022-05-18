#ifndef _WrongAnimal_HPP
#define _WrongAnimal_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string name);
	WrongAnimal(const WrongAnimal& WrongAnimal);
	~WrongAnimal();

	std::string getType(void) const;
	void makeSound(void) const;
	WrongAnimal& operator=(const WrongAnimal& ref);
};

#endif