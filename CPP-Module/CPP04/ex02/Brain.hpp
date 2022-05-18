#ifndef _BRAIN_HPP
#define _BRAIN_HPP

#include <iostream>
#include <string>
#include <fstream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();

	void setFirstIdeas(std::string idea);
	std::string getFirstIdeas();
};

#endif