#include "Validator.hpp"

Validator::Validator(const char* target)
{
	std::string tmp(target);
	this->target = tmp;
}

Validator::Validator(const std::string& target) : target(target)
{}

bool Validator::validate(void)
{
	if (isNumber(this->target))
		return true;
	else if(isDecimal(this->target))
		return true;
	else if(this->target == "nan" || this->target == "nanf")
		return true;
	else if(this->target == "inf" || this->target == "inff")
		return true;
	else if(this->target == "-inf" || this->target == "+inf")
		return true;
	else if(this->target == "-inff" || this->target == "+inff")
		return true;
	return false;
}

bool Validator::isNumber(const std::string& str)
{
	return str.find_first_not_of( "0123456789" ) == std::string::npos;
}

bool Validator::isDecimal(const std::string& str)
{
	if (str.find_first_not_of( "0123456789.f" ) != std::string::npos)
		return false;
	else if(str.at(0) == '.' ||
			str.at(0) == 'f' ||
			str.at(str.length() - 1) == '.')
		return false;
	else if (isDuplicated(str, '.') || isDuplicated(str, 'f'))
		return false;
	return true;
}

bool Validator::isDuplicated(const std::string& str, char c)
{
	size_t count = 0;
	size_t idx = 0;
	std::string tmpStr = str;

	if (tmpStr.find_first_not_of( "0123456789.f" ) != std::string::npos)
	{
		return false;
	}
	while ((idx = tmpStr.find(c)) != std::string::npos)
	{
		count++;
		tmpStr = tmpStr.substr(idx + 1);
	}

	return count > 1;
}

std::string Validator::getTarget(void) const
{
	return this->target;
}
