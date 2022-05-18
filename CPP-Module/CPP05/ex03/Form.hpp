#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

enum ConcreteForm
{
	SHRUBBERYCREATION = 0,
	ROBOTOMYREQUEST,
	PRESIDENTIALPARDON
};

class Bureaucrat;

class Form
{
private:
	const std::string name;
	const int signGrade;
	const int executeGrade;
	bool isSigned;

public:
	Form(std::string name, int signGrade, int executeGrade);

	std::string getName (void) const;
	int getExecuteGrade(void) const;
	int getSignGrade(void) const;
	bool getIsSigned(void) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	void beSigned(const Bureaucrat& bureaucrat) throw(GradeTooLowException);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif