#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern
{
private:

public:
	class FormNotFoundException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	Form* makeForm(const std::string& ConcreteForm, const std::string& target) throw(FormNotFoundException);
};

#endif