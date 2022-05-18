#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

class ValueNotFound : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Not Found";
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int target) throw(ValueNotFound)
{
	typename T::iterator result = std::find(container.begin(), container.end(), target);


	if (result == container.end()) {
		throw ValueNotFound();
	}
	return result;
}

#endif
