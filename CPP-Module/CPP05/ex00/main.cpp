#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bureaucrat("tom", 20);
	std::cout << bureaucrat << std::endl;

	bureaucrat.incrementGrade(2);
	std::cout << bureaucrat << std::endl;

	bureaucrat.decrementGrade(10);
	std::cout << bureaucrat << std::endl;

	try
	{
		bureaucrat.incrementGrade(100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		bureaucrat.decrementGrade(200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << bureaucrat << std::endl;
}
