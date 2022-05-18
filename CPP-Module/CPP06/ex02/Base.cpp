#include "Base.hpp"

Base::~Base()
{

}

Base	*generate(void)
{
	std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<int> dis(0, 2);

	int num = dis(gen);
	switch (num)
	{
		case 0:
			return new A();
			break;

		case 1:
			return new B();
			break;

		case 2:
			return new C();
			break;
	}
	return new A();
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "real type of this class is A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "real type of this class is B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "real type of this class is C" << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		Base base = dynamic_cast<A&>(p);
		std::cout << "real type of this class is A" << std::endl;
		return ;
	}
	catch(std::exception& e)
	{
	}

	try
	{
		Base base = dynamic_cast<B&>(p);
		std::cout << "real type of this class is B" << std::endl;
		return ;
	}
	catch(std::exception& e)
	{
	}

	try
	{
		Base base = dynamic_cast<C&>(p);
		std::cout << "real type of this class is C" << std::endl;
		return ;
	}
	catch(std::exception& e)
	{
	}
}
