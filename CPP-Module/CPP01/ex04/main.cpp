#include <iostream>
#include <string>
#include <fstream>
#include "File.hpp"

bool	isCorrectArg( int argc )
{
	if (argc < 4)
	{
		std::cout << "too few arguments" << std::endl;
		return (false);
	}
	return (true);
}

int main( int argc, char *argv[] )
{
	std::string	fileName;
	std::string	fileContents;

	if (!isCorrectArg(argc))
		exit(1);
	fileName = argv[1];

	File file(fileName);
	fileContents = file.replace(argv[2], argv[3]);
	file.write(fileContents);
	file.close();
}