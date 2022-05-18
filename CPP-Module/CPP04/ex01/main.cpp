#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

typedef Animal * ANIMAL_PTR;

int main()
{
	ANIMAL_PTR * animallArr = new ANIMAL_PTR[10];
	
	for (int idx = 0; idx < 10; idx++)
	{
		if (idx < 5)
			animallArr[idx] = new Dog();
		else
			animallArr[idx] = new Cat();
	}

	for (int idx = 0; idx < 10; idx++)
	{
		if (idx < 5)
			delete animallArr[idx];
		else
			delete animallArr[idx];
	}

	Animal* dog1 = new Dog();
	Animal* dog2 = new Dog();

	*dog1 = *dog2;
	
	Brain* brain1 = dog1->getBrain();
	brain1->setFirstIdeas("dog1");

	Brain* brain2 = dog2->getBrain();
	brain2->setFirstIdeas("dog2");

	std::cout << brain1 << std::endl;
	std::cout << brain2 << std::endl;

	std::cout << brain1->getFirstIdeas() << std::endl;
	std::cout << brain2->getFirstIdeas() << std::endl;
}