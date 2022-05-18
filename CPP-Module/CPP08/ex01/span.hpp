#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

class MaximumException : public std::exception
{
public:
	virtual const char* what() const throw();
};

class EmptyException : public std::exception
{
public:
	virtual const char* what() const throw();
};

class Span
{
private:
	std::vector<int> vec;
	unsigned int maxSize;
	long calShortestNum(void);

public:
	Span();
	Span(unsigned int size);
	Span(Span& span);
	virtual ~Span();

	void addNumber(int num) throw(MaximumException);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) throw(MaximumException);
	long longestSpan(void) throw(EmptyException);
	long shortestSpan(void) throw(EmptyException);

	unsigned int getSize(void) const;
	std::vector<int>::iterator begin(void);
	std::vector<int>::iterator end(void);

	Span& operator=(Span& rhs);
};

#endif
