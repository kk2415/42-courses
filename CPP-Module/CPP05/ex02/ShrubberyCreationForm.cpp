#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("ShrubberyCreationForm", 145, 137), target(target)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream fout;

	if (this->getIsSigned() == false)
	{
		throw Form::NotSignedException();
	}
	else if (executor.getGrade() > this->getSignGrade())
	{
		throw Form::GradeTooLowException();
	}
	fout.open(this->target + "_shrubbery", std::ios::out | std::ios::trunc);
	fout << 
	"     *\n"
	"    *#*\n"
	"   *#*#*\n"
	"  #*****#\n"
	" #########\n"
	"    !!!\n"
	"    !!!";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}
