#ifndef _DOG_H
#define _DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(std::string name);
	Dog(const Dog& dog);
	~Dog();

	virtual void makeSound(void) const;
	Dog& operator=(const Dog& ref);
};

#endif