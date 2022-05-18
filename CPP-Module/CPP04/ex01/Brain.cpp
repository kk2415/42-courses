#include "Brain.hpp"

Brain::Brain()
{
	// std::cout << "called Brain constructor" << std::endl;
}

Brain::~Brain()
{
	// std::cout << "called Brain destructor" << std::endl;
}

std::string Brain::getFirstIdeas()
{
	return this->ideas[0];
}

void Brain::setFirstIdeas(std::string idea)
{
	this->ideas[0] = idea;
}