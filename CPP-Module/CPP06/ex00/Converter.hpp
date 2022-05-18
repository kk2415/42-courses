#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include "Validator.hpp"

class Converter
{
private:
	Validator* validator;
	std::string target;

public:
	Converter(Validator* validator);
	~Converter();

	std::string getTarget(void) const;
	void setValidator(Validator* validator);
	
	void showChar(void) const;
	void showInt(void) const;
	void showFloat(void) const;
	void showDouble(void) const;
};

#endif