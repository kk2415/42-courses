#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
	std::string	command;
	PhonBook	phonebook;

	while (true)
	{
		std::cout << "<<Input Command List>>		" << std::endl;
		std::cout << "1. EXIT" << std::endl << "2. ADD" << std::endl << "3. SEARCH" << std::endl;
		std::cout << "Command>>  ";
		std::getline(std::cin, command, '\n');
		if (command == "EXIT")
			phonebook.exit();
		else if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else
			std::cout << "<< Please input correct commnad >>" << std::endl;
	}
}
