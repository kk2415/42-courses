#include "Intern.hpp"

Form* Intern::makeForm(const std::string& formName, const std::string& target) throw(FormNotFoundException)
{
	std::string formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	ConcreteForm enumFormList[3] = {SHRUBBERYCREATION, ROBOTOMYREQUEST, PRESIDENTIALPARDON};

	for (int i = 0; i < 3; i++)
	{
		if (formList[i] == formName)
		{
			ConcreteForm enumForm = enumFormList[i];

 			switch (enumForm)
			{
			case SHRUBBERYCREATION:
				return new ShrubberyCreationForm(target);
				break;
			case ROBOTOMYREQUEST:
				return new RobotomyRequestForm(target);
				break;
			case PRESIDENTIALPARDON:
				return new PresidentialPardonForm(target);
				break;
			}
		}
	}
	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "!! Form Not Found : form name of target is irregular !!";
}