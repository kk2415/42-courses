#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(0)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
}

std::string Bureaucrat::getName(void) const
{
	return this->name;
}

int Bureaucrat::getGrade(void) const
{
	return this->grade;
}

void Bureaucrat::incrementGrade(int value) throw(GradeTooHighException)
{
	if (this->grade - value < MAX_GRADE)
	{
		throw GradeTooHighException();
	}
	this->grade -= value;
}

void Bureaucrat::decrementGrade(int value) throw(GradeTooLowException)
{
	if (this->grade + value > MIN_GRADE)
	{
		throw GradeTooLowException();
	}
	this->grade += value;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << "name : " << bureaucrat.getName() << std::endl << "grade : " << bureaucrat.getGrade() << std::endl;
	return os;
}
