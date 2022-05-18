#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "called Cat constructor" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string name) : Animal(name)
{
	std::cout << "called Cat constructor" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat) : Animal(cat.type)
{
	std::cout << "called Cat constructor" << std::endl;
	Brain* brain = new Brain();

	brain->setFirstIdeas(cat.brain->getFirstIdeas());

	this->brain = brain;
}

Brain* Cat::getBrain(void) const
{
	return this->brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Naw!! Naw!!" << std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << "cat operator" << std::endl;
	Animal::operator=(ref);

	Brain* refBrain = ref.getBrain();
	this->brain->setFirstIdeas(refBrain->getFirstIdeas());
	return *this;
}

Animal& Cat::operator=(const Animal& ref)
{
	std::cout << "cat operator" << std::endl;
	Animal::operator=(ref);

	Brain* refBrain = ref.getBrain();
	this->brain->setFirstIdeas(refBrain->getFirstIdeas());
	return *this;
}

Cat::~Cat()
{
	std::cout << "called Cat destructor" << std::endl;
	delete this->brain;
}