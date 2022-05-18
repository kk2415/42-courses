#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template < typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
public:
	typedef typename std::stack<T, C>::container_type::iterator iterator;
	typedef typename std::stack<T, C>::container_type::reverse_iterator reverseIterator;

	MutantStack(void) : std::stack<T, C>() {}
	MutantStack(const MutantStack &ref) : std::stack<T, C>(ref) {}
	virtual ~MutantStack() {}

	iterator begin(){ return this->c.begin(); }
	iterator end(){ return this->c.end(); }
	reverseIterator rbegin() { return this->c.rbegin(); }
	reverseIterator rend() { return this->c.rend(); }

	MutantStack<T>& operator=(const MutantStack<T>& rhs) {
		std::stack<T>::operator=(rhs);
		return *this;
	}
};

#endif
