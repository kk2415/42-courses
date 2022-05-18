#include "span.hpp"

/**
* 예외 클래스
*/
const char* MaximumException::what() const throw()
{
	return "Span is full";
}

const char* EmptyException::what() const throw()
{
	return "there are no numbers stored, or only one";
}


/**
* 생성자
*/
Span::Span() : maxSize(0)
{
}

Span::Span(unsigned int size) : maxSize(size)
{
}

Span::Span(Span& span) : maxSize(span.getSize())
{
	this->vec = span.vec;
}


/**
* 소멸자
*/
Span::~Span()
{
}


/**
* 연산자 오버로딩
*/
Span& Span::operator=(Span& rhs)
{
	this->maxSize = rhs.maxSize;
	this->vec = rhs.vec;
	return *this;
}


/**
* 핵심 메서드
*/
void Span::addNumber(int num) throw(MaximumException)
{
	if (this->vec.size() >= this->maxSize) {
		throw MaximumException();
	}

	this->vec.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) throw(MaximumException)
{
	while (begin != end) {
		try {
			Span::addNumber(*begin);
			begin++;
		}
		catch(const std::exception& e) {
			throw MaximumException();
		}
	}
}

long Span::longestSpan(void) throw(EmptyException)
{
	if (this->vec.size() <= 1) {
		throw EmptyException();
	}

	long min = *std::min_element(this->vec.begin(), this->vec.end());
	long max = *std::max_element(this->vec.begin(), this->vec.end());
	long result = min - max;


	return result >= 0 ? result : result * -1;
}

long Span::shortestSpan(void) throw(EmptyException)
{
	if (this->vec.size() <= 1) {
		throw EmptyException();
	}
	return calShortestNum();
}

long Span::calShortestNum(void)
{
	std::vector<int> tmpVector;

	tmpVector.assign(this->vec.begin(), this->vec.end());
	std::sort(tmpVector.begin(), tmpVector.end());
	long min = tmpVector.at(tmpVector.size() - 1);

	for (unsigned long i = 0; i < tmpVector.size(); i++) {
		long value = min;

		for (unsigned long j = i + 1; j < tmpVector.size(); j++) {
			value = (long)tmpVector[i] - (long)tmpVector[j];

			if (value < 0 ) {
				value = value * -1;
			}

			if (min > value) {
				min = value;
			}
		}
	}
	return min;
}

/**
* Getter
*/
unsigned int Span::getSize(void) const
{
	return this->maxSize;
}

std::vector<int>::iterator Span::begin(void)
{
	return this->vec.begin();
}

std::vector<int>::iterator Span::end(void)
{
	return this->vec.end();
}
