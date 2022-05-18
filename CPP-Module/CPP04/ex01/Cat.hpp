#ifndef _CAT_H
#define _CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain* brain;

public:
	Cat();
	Cat(std::string name);
	Cat(const Cat& cat);
	~Cat();
	
	virtual Brain* getBrain(void) const;
	virtual void makeSound(void) const;
	Cat& operator=(const Cat& ref);
	virtual Animal& operator=(const Animal& ref);
};

#endif