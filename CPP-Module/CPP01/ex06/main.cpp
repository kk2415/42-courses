#include <iostream>
#include "Karen.hpp"

void	tolower( std::string &str )
{
	for(int i = 0; i < str.length(); i++)
	{
		str[i] = std::tolower(str[i]);
	}
}

void	init_map( t_map map[] )
{
	map[0].key = "debug";
	map[0].value = 0;
	map[1].key = "info";
	map[1].value = 1;
	map[2].key = "warning";
	map[2].value = 2;
	map[3].key = "error";
	map[3].value = 3;
}

int	getIdx(std::string command, t_map map[])
{
	int	idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (map[idx].key == command)
			break ;
	}
	return (idx);
}

void	printKaren( std::string command, t_map map[] )
{
	int	idx;

	idx = getIdx(command, map);
	if (idx >= 4)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	switch (map[idx].value)
	{
	case DEBUG:
		std::cout << "[ DEBUG ]" << std::endl
			<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." <<
			std::endl << "I just love it!" << std::endl << std::endl;
	case INFO:
		std::cout << "[ INFO ]" << std::endl
			<< "I cannot believe adding extra bacon cost more money." <<
			std::endl << "You don’t put enough! If you did I would not have to ask for it!" << std::endl
			<< std::endl;
	case WARNING:
		std::cout << "[ WARNING ]" << std::endl
			<< "I think I deserve to have some extra bacon for free." <<
			std::endl << "I’ve been coming here for years and you just started working here last month." << std::endl
			<< std::endl;
	case ERROR:
		std::cout << "[ ERROR ]" << std::endl
			<< "This is unacceptable, I want to speak to the manager now." << std::endl;
	}
}

int main( int argc, char *argv[] )
{
	std::string	command;
	t_map		map[4];

	if (argc < 2)
	{
		std::cout << "too few arguments" << std::endl;
		exit(1);
	}
	command = argv[1];
	tolower(command);
	init_map(map);
	printKaren(command, map);

	// std::cout << command << std::endl;
	// std::cout << map[0].key << std::endl;
}