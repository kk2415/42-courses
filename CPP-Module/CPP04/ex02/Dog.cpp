#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "called Dog constructor" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string name) : Animal(name)
{
	std::cout << "called Dog constructor" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog) : Animal(dog.type)
{
	std::cout << "called Dog constructor" << std::endl;
	Brain* brain = new Brain();
	brain->setFirstIdeas(dog.brain->getFirstIdeas());

	this->brain = brain;
}

Brain* Dog::getBrain(void) const
{
	return this->brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Wal!! Wal!!" << std::endl;
}

Dog& Dog::operator=(const Dog& ref)
{
	std::cout << "dog operator" << std::endl;
	Animal::operator=(ref);

	Brain* refBrain = ref.getBrain();
	this->brain->setFirstIdeas(refBrain->getFirstIdeas());
	return *this;
}

Animal& Dog::operator=(const Animal& ref)
{
	std::cout << "dog operator" << std::endl;
	Animal::operator=(ref);

	Brain* refBrain = ref.getBrain();
	this->brain->setFirstIdeas(refBrain->getFirstIdeas());
	return *this;
}

Dog::~Dog()
{
	std::cout << "called Dog destructor" << std::endl;
	delete this->brain;
}