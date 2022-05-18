#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T* array;
	unsigned int arrLength;

public:
	Array(void) : arrLength(0)
	{
		array = new T[0];
	}

	Array(unsigned int len) : arrLength(len)
	{
		array = new T[len];
	}

	Array(const Array& arr)
	{
		arrLength = arr.arrLength;
		array = new T[arrLength];
		for (unsigned int i = 0; i < arrLength; i++)
			array[i] = arr.array[i];
	}

	~Array(void)
	{
		delete [] array;
	}

	T& operator[] (unsigned int idx)
	{
		if (idx < 0 || idx >= arrLength)
			throw std::exception();
		return array[idx];
	}

	T operator[] (unsigned int idx) const
	{
		if (idx < 0 || idx >= arrLength)
			throw std::exception();
		return array[idx];
	}

	unsigned int size(void)
	{
		return this->arrLength;
	}

	Array<T>& operator=(const Array<T>& ref)
	{
		arrLength = ref.arrLength;

		if (array != NULL)
			delete [] array;

		array = new T[arrLength];

		for (unsigned int i = 0; i < arrLength; i++)
			array[i] = ref.array[i];
		return *this;
	}
};

#endif
