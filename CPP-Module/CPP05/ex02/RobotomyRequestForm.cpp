#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("RobotomyRequestForm", 72, 45), target(target)
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
	{
		throw Form::NotSignedException();
	}
	else if (executor.getGrade() > this->getSignGrade())
	{
		throw Form::GradeTooLowException();
	}

	std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<int> dis(0, 1);

	if ((dis(gen) % 2) == 0)
	{
		std::cout << " *"  << this->target << " has been robotomized successfully 50% of the time. *" << std::endl;
	}
	else
	{
		std::cout <<  " *"  << this->target << " has not been robotomized successfully 50% of the time. *" << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
