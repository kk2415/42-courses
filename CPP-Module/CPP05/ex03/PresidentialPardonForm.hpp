#ifndef PRESIDENTIALPARDONPORM_HPP
#define PRESIDENTIALPARDONPORM_HPP

#include "Form.hpp"
#include <iostream>

class PresidentialPardonForm : public Form
{
private:
	std::string target;

public:
	PresidentialPardonForm(const std::string& target);
	virtual void execute(Bureaucrat const & executor) const;
	virtual ~PresidentialPardonForm();
};

#endif