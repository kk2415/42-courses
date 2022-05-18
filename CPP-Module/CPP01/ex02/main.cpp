#include <iostream>
#include <iomanip>

int	main( void )
{
	std::string str;
	std::string	*stringPTR;
	std::string	&stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;

	std::cout << std::setw(20) << "str address: " << &str << std::endl;
	std::cout << std::setw(20) << "stringREF address: " << &stringREF << std::endl;
	std::cout << std::setw(20) << "stringPTR address: " << &stringPTR << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(20) << "str : " << str << std::endl;
	std::cout << std::setw(20) << "stringREF : " << stringREF << std::endl;
	std::cout << std::setw(20) << "stringPTR : " << *stringPTR << std::endl;
}
