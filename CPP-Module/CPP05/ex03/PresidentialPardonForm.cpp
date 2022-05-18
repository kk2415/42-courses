#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form("PresidentialPardonForm", 25, 5), target(target)
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
	{
		throw Form::NotSignedException();
	}
	else if (executor.getGrade() > this->getSignGrade())
	{
		throw Form::GradeTooLowException();
	}
	std::cout << " * " << this->target << " has been pardoned by Zafod Beeblebrox * " << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
