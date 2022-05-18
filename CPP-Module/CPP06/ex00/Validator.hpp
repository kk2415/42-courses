#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <iostream>
#include <string>

class Validator
{
private:
	std::string target;

public:
	Validator(const char* target);
	Validator(const std::string& target);
	bool validate(void);
	bool isDecimal(const std::string& str);
	bool isNumber(const std::string& str);
	bool isDuplicated(const std::string& str, char c);

	std::string getTarget(void) const;
};

#endif