#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T& ref)
{
	std::cout << ref << std::endl;
	return ;
}

int main(void)
{
	int intArr[] = {1,2,3,4,5};
	char charArr[] = {'a', 'b', 'c', 'd', 'e'};
	float floatArr[] = {1.0f, 1.1f, 1.2f, 1.3f, 1.4f};

	iter(intArr, 5, &print);
	for (int i = 0; i < 5; i++)
	{
		std::cout << intArr[i] << std::endl;
	}

	iter(charArr, 5, &print);
	for (int i = 0; i < 5; i++)
	{
		std::cout << charArr[i] << std::endl;
	}

	iter(floatArr, 5, &print);
	for (int i = 0; i < 5; i++)
	{
		std::cout << floatArr[i] << std::endl;
	}
}
