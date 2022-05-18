#include <iostream>
#include <algorithm>
#include <list>

#include "easyfind.hpp"

int main(void)
{
	std::cout << "* Initialization List --> (1, 2, 3, 4, 5) *" << std::endl << std::endl;

	std::list<int> intList(5);
	intList.push_back(1);
	intList.push_back(2);
	intList.push_back(3);
	intList.push_back(4);
	intList.push_back(5);

	std::cout << "=====easyfind(intList, 2)=====" << std::endl;
	std::list<int>::iterator iter = easyfind(intList, 2);
	std::cout << *iter << std::endl << std::endl;


	std::cout << "=====easyfind(intList, 8)=====" << std::endl;
	try
	{
		iter = easyfind(intList, 8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
