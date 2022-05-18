#include <iostream>
#include <string>

#include "Converter.hpp"
#include "Validator.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Please Input argument" << std::endl;
		return 1;
	}

	Validator* validator = new Validator(argv[1]);
	Converter* converter = new Converter(validator);

	if (!validator->validate())
	{
		std::cout << "Invalid Value" << std::endl;
		return 0;
	}

	converter->showChar();
	converter->showInt();
	converter->showFloat();
	converter->showDouble();

	delete converter;
}
