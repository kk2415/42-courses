#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void ShrubberyCreationFormTest(Bureaucrat& bureaucrat)
{
	Form* shrubberycreation = new ShrubberyCreationForm("tree");

	bureaucrat.signForm(*shrubberycreation);
	bureaucrat.executeForm(*shrubberycreation);
}

void RobotomyRequestFormTest(Bureaucrat& bureaucrat)
{
	Form* robotomyRequestForm = new RobotomyRequestForm("robot");
	
	bureaucrat.signForm(*robotomyRequestForm);
	bureaucrat.executeForm(*robotomyRequestForm);
}

void PresidentialPardonFormTest(Bureaucrat& bureaucrat)
{
	Form* presidentialPardonForm = new PresidentialPardonForm("president");

	bureaucrat.signForm(*presidentialPardonForm);
	bureaucrat.executeForm(*presidentialPardonForm);
}

int main(void)
{
	Bureaucrat* Lowbureaucrat = new Bureaucrat("Lowbureaucrat", 150);
	Bureaucrat* Highbureaucrat = new Bureaucrat("Highbureaucrat", 1);

	std::cout << "=============== ShrubberyCreationForm Test ===============" << std::endl; 
	ShrubberyCreationFormTest(*Lowbureaucrat);
	std::cout << std::endl;
	ShrubberyCreationFormTest(*Highbureaucrat);
	std::cout << "==========================================================" << std::endl << std::endl; 


	std::cout << "============== RobotomyRequestFormTest Test ===============" << std::endl; 
	RobotomyRequestFormTest(*Lowbureaucrat);
	std::cout << std::endl;
	RobotomyRequestFormTest(*Highbureaucrat);
	std::cout << "===========================================================" << std::endl << std::endl; 


	std::cout << "=============== PresidentialPardonFormTest Test ==============" << std::endl; 
	PresidentialPardonFormTest(*Lowbureaucrat);
	std::cout << std::endl;
	PresidentialPardonFormTest(*Highbureaucrat);
	std::cout << "==============================================================" << std::endl; 
}