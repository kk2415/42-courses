#ifndef _CAT_H
#define _CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(std::string name);
	Cat(const Cat& cat);
	~Cat();

	virtual void makeSound(void) const;
	Cat& operator=(const Cat& ref);
};

#endif