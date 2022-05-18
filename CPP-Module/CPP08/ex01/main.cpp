#include <iostream>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>

#include "span.hpp"

void subjectTest(void)
{
	Span sp(1000);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortestSpan --> ";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan --> ";
	std::cout << sp.longestSpan() << std::endl;
}

void deepTest()
{
	Span sp(10000);

	for (int i = 0; i < 10000; i++)
	{
		sp.addNumber(i);
	}

	std::cout << "shortestSpan --> ";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan --> ";
	std::cout << sp.longestSpan() << std::endl;
}

void emptyTest()
{
	Span sp(3);

	try
	{
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

void addNumberTest()
{
	Span sp(8);
	std::vector<int> tempList;

	tempList.push_back(1);
	tempList.push_back(2);
	tempList.push_back(3);
	tempList.push_back(4);
	tempList.push_back(5);
	tempList.push_back(6);
	tempList.push_back(7);
	tempList.push_back(8);

	sp.addNumber(tempList.begin(), tempList.end());

	std::vector<int>::iterator begin = sp.begin();
	std::vector<int>::iterator end = sp.end();

	while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

void constructorTest(void)
{
	Span sp1(3);
	sp1.addNumber(1);
	sp1.addNumber(2);
	sp1.addNumber(3);

	Span sp2(sp1);
	std::vector<int>::iterator begin = sp2.begin();
	std::vector<int>::iterator end = sp2.end();

	while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

void operatorTest(void)
{
	Span sp1(3);
	sp1.addNumber(1);
	sp1.addNumber(2);
	sp1.addNumber(3);

	Span sp2(3);
	sp2.addNumber(4);
	sp2.addNumber(5);
	sp2.addNumber(6);

	sp2 = sp1;

	std::vector<int>::iterator begin = sp2.begin();
	std::vector<int>::iterator end = sp2.end();

	while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

int main(void)
{
	std::cout  << "============Subject Test============" << std::endl;
	std::cout  << "->Input value(6,3,17,9,11)<-" << std::endl;
	subjectTest();

	std::cout  << "============Deep Test===============" << std::endl;
	std::cout  << "->Input value(0 ~ 9,999)<-" << std::endl;
	deepTest();

	std::cout  << "============EmptyTest Test===============" << std::endl;
	std::cout  << "->Input value()<-" << std::endl;
	emptyTest();

	std::cout  << "============AddNumber Method Test===============" << std::endl;
	std::cout  << "->Input value(1,2,3,4,5,6,7,8)<-" << std::endl;
	addNumberTest();

	std::cout  << "============Copy constructor Test===============" << std::endl;
	std::cout  << "->Input value(1,2,3)<-" << std::endl;
	constructorTest();

	std::cout  << "============Operator Test===============" << std::endl;
	std::cout  << "->Input value(1,2,3)<-" << std::endl;
	operatorTest();
}
