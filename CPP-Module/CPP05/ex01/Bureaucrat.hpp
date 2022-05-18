// 예외클래스 : grade가 범위 초과할 때 발생.
// Bureaucrat::GradeTooHighException
// Bureaucrat::GradeTooLowException

// 프로퍼티 :
// name 
// grade(1~150)

//grade 프로퍼티 감소, 증감하는 메서드 작성(예외 던져야됨)

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
	const static int MAX_GRADE = 1;
	const static int MIN_GRADE = 150;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);

	std::string getName(void) const;
	int getGrade(void) const;

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

	void incrementGrade(int value) throw(GradeTooHighException);
	void decrementGrade(int value) throw(GradeTooLowException);

	void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif