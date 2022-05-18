#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bureaucrat1("top", 1);
	Bureaucrat bureaucrat2("low", 120);
	Form form("form", 20, 19);

	std::cout << form << std::endl;

	std::cout << "====bureaucrat1(grade 1) sign the form====" << std::endl;
	std::cout << "---->";
	bureaucrat1.signForm(form);
	std::cout << "------------------------------------------" << std::endl;

	std::cout << "====bureaucrat2(grade 120) sign the form====" << std::endl;
	std::cout << "---->";
	bureaucrat2.signForm(form);
	std::cout << "------------------------------------------" << std::endl;
}
