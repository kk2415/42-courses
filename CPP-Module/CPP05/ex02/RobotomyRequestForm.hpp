#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>
#include <random>
#include <ctime>

class RobotomyRequestForm : public Form
{
private:
	std::string target;

public:
	RobotomyRequestForm(const std::string& target);
	virtual void execute(Bureaucrat const & executor) const;
	virtual ~RobotomyRequestForm();
};

#endif