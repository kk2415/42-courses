#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	std::string target;

public:
	ShrubberyCreationForm(const std::string& target);
	virtual void execute(Bureaucrat const & executor) const;
	virtual ~ShrubberyCreationForm();
};

#endif