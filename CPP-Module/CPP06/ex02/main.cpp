#include "Base.hpp"

int main(void)
{
	Base* tmp = generate();
	identify(tmp);
	identify(*tmp);
}