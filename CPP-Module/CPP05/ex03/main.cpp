#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat* Lowbureaucrat = new Bureaucrat("Lowbureaucrat", 150);
	Bureaucrat* Highbureaucrat = new Bureaucrat("Highbureaucrat", 1);
	Intern someRandomIntern;
	Form* form;

	try
	{
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		Highbureaucrat->signForm(*form);
		Highbureaucrat->executeForm(*form);

		std::cout << std::endl;

		form = someRandomIntern.makeForm("shrubbery creation", "shrubbery");
		Highbureaucrat->signForm(*form);
		Highbureaucrat->executeForm(*form);

		std::cout << std::endl;

		form = someRandomIntern.makeForm("robotomy", "Bender");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}