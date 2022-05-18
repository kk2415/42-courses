#include "Converter.hpp"

Converter::Converter(Validator* validator) : validator(validator)
{
	target = validator->getTarget();
}

std::string Converter::getTarget(void) const
{
	return target;
}

void Converter::setValidator(Validator* validator)
{
	this->validator = validator;
}

void Converter::showChar(void) const
{
	std::cout << "char: ";
	try
	{
		long long num = std::stoi(target);

		if (num > 255 || num < 0)
			std::cout << "impossible" << std::endl;
		else if (isprint(num))
			std::cout << static_cast<char>(num) << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void Converter::showInt(void) const
{
	std::cout << "int: ";
	try
	{
		long long num = std::stoi(target);

		if (2147483647 < num || num < -2147483648)
			std::cout << "impossible" << std::endl;
		else
			std::cout << num << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void Converter::showFloat(void) const
{
	std::cout << "float: ";
	if (target.find_first_of("0123456789") == std::string::npos)
	{
		std::cout << target;
	}
	else
	{
		try
		{
			float num = std::stof(target);

			std::cout << num;
			if ((target.find('.') == std::string::npos || target.find(".0") != std::string::npos) && num < 1000000)
				std::cout << ".0";
		}
		catch(const std::exception& e)
		{
			std::cout << "impossible" << std::endl;
			return ;
		}
	}

	if (target.find("ff") == std::string::npos && target != "nanf")
	{
		std::cout << "f";
	}
	std::cout << std::endl;
}

void Converter::showDouble(void) const
{
	std::cout << "double: ";

	/* 문자열에 숫자가 포함되어있지 않으면, ex) "nan", "-inf" */
	if (target.find_first_of("0123456789") == std::string::npos)
	{
		if (target.find("ff") != std::string::npos || target == "nanf")
			std::cout << target.substr(0, target.length() - 1) << std::endl;
		else
			std::cout << target << std::endl;
	}
	else
	{
		try
		{
			double num = std::stod(target);

			std::cout << num;
			if ((target.find('.') == std::string::npos || target.find(".0") != std::string::npos) && num < 1000000)
				std::cout << ".0";
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "impossible" << std::endl;
			return ;
		}
	}
}

Converter::~Converter()
{
	delete validator;
}
