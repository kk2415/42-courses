#ifndef _DOG_H
#define _DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;

public:
	Dog();
	Dog(std::string name);
	Dog(const Dog& dog);
	~Dog();

	virtual Brain* getBrain(void) const;
	virtual void makeSound(void) const;
	Dog& operator=(const Dog& ref);
	virtual Animal& operator=(const Animal& ref);
};

#endif