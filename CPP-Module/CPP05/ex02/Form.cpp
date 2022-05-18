#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade)
	: name(name), signGrade(signGrade), executeGrade(executeGrade), isSigned(false)
{
}

std::string Form::getName (void) const
{
	return this->name;
}

int Form::getExecuteGrade(void) const
{
	return this->executeGrade;
}

int Form::getSignGrade(void) const
{
	return this->signGrade;
}

bool Form::getIsSigned(void) const
{
	return this->isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat) throw(GradeTooLowException)
{
	if (bureaucrat.getGrade() <= this->signGrade)
	{
		this->isSigned = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

const char* Form::NotSignedException::what() const throw()
{
	return "It's not signed";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "name : " << form.getName() << std::endl
		<< "signGrade : " << form.getSignGrade()  << std::endl
		<< "ExecuteGrade : " << form.getExecuteGrade()  << std::endl
		<< "IsSigned : " << form.getIsSigned()  << std::endl;
	return os;
}