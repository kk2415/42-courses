#include <iostream>

#include <stack>
#include "mutantstack.hpp"

class Tiger
{
private:
	std::string name;
public:
	Tiger() : name("tiger") {}
	Tiger(std::string name) : name(name) {}
	~Tiger() {}

	std::string getName(void) const
	{
		return this->name;
	}
};

std::ostream& operator<<(std::ostream& os, const Tiger& rhs)
{
	os << rhs.getName();
	return os;
}

void subjectTest(void)
{
	MutantStack<int> mstack;

	std::cout << "@@ Input Value @@" << std::endl;
	std::cout << " (5,17,3,5,737,0)" << std::endl;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "========>>top(" << mstack.top() << ")" << std::endl;

	std::cout << "========>>pop()" << std::endl;
	mstack.pop();

	std::cout << "========>>size(" << mstack.size() << ")" << std::endl;

	std::cout << "========>>print all" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "===================" << std::endl;
}

void myTest(void)
{
	MutantStack<Tiger> mstack;

	Tiger tiger1("Tiger1");
	Tiger tiger2("Tiger2");
	Tiger tiger3("Tiger3");
	Tiger tiger4("Tiger4");
	Tiger tiger5("Tiger5");

	mstack.push(tiger1);
	mstack.push(tiger2);
	mstack.push(tiger3);
	mstack.push(tiger4);
	mstack.push(tiger5);

	MutantStack<Tiger>::iterator it = mstack.begin();
	MutantStack<Tiger>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "===================" << std::endl;
}

void operatorTest(void)
{
	MutantStack<int> mstack;
	MutantStack<int> mstack2;

	mstack2.push(1);
	mstack2.push(2);
	mstack2.push(3);
	mstack2.push(4);
	mstack2.push(5);
	mstack2.push(6);

	mstack = mstack2;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main(void)
{
	subjectTest();
	myTest();
	operatorTest();
}
